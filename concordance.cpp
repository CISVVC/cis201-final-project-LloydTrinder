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
		if (f != NULL) 
		{
			m_word_stats[f].add_count(1);
			m_word_stats[f].add_line(__LINE__);
		}
		else 
		{
			Word n_word = new Word(word);
			m_word_stats.push_back(n_word);
			m_word_stats.back.add_line(__LINE__);
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

	return(word);
}

int Concordance::find_word(std::string word)
{
	
	// Checks for lower case
	int r = NULL;
	for (int i = 0; i < m_word_stats.size; i++)
	{
		if (make_lower(m_word_stats[i].get_word()) == make_lower(word)) 
		{
			r = i;
		}
	}
	return(r);
	
}

void Concordance::print()
{
	// Prints the count
	for (int i = 0; i < m_word_stats.size; i++)
	{
		std::cout << m_word_stats[i].get_word() << " : " << m_word_stats[i].get_count() << " : " << m_word_stats[i].get_lines() << "\n" << std::endl;
	}
	
}


