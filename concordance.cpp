/* Lloyd Trinder
** trinderl@student.vvc.edu
** Professor tonning, cis 201
** Develop a concordance generator program.  The concordance will be a list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where  the word occurred.  For each line of text, all punctuation must be removed and all letters in the string forced to lowercase.  Then, separate out the words and check each word against your list.   Keep track of the current line number and check if the word has been found before.  If the word has not been seen before, put it in some sort of collection data structure (an array or vector for example) and keep track of the line number.  If the word has been found before, store the line number of where the word occurred.*/ 

#include "concordance.h"

Concordance::Concordance(std::string filename)
{
    m_filename = filename;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    while(!file.eof())
    {
        std::string word = next_word(file);

		// Finds the words
		int f = find_word(word);
		if (f != 0) 
		{
			m_word_stats[f].add_count(1);
			m_word_stats[f].add_line(__LINE__);
		}
		else 
		{
			Word n_word(word);
			m_word_stats.push_back(n_word);
			m_word_stats.back().add_line(__LINE__);
		}
		
      std::cout << word << std::endl;
    }
}

bool Concordance::is_whitespace(char c)
{
  return (c == ' ' || c == '\n' ||  c == '\t');
}

void Concordance::eat_whitespace(std::ifstream& input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream
            break;
        }
    }
}

std::string Concordance::next_word(std::ifstream& input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            word += c;
        }
        else
        {
            eat_whitespace(input);
            break;
        }
    }
    return word;
}

std::string Concordance::make_lower(std::string word)
{

	for (int i = 0; i< word.length(); i++) 
	{ 						
		word[i] = tolower(word[i]);
	}

	return word;
}

int Concordance::find_word(std::string word)
{
	
	// Checks for lower case
	int r = 0;
	for (int i = 0; i < m_word_stats.size(); i++)
	{
		if (make_lower(m_word_stats[i].get_word()) == make_lower(word)) 
		{
			r = i;
		}
	}
	return r;
	
}

void Concordance::print()
{
	// Prints the count
	for (int i = 0; i < m_word_stats.size(); i++)
	{
		std::cout << m_word_stats[i].get_word() << " : " << m_word_stats[i].get_count() << " : " << m_word_stats[i].get_lines() << "\n" << std::endl;
	}
	
}
