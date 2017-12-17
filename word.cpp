/* Lloyd Trinder
** trinderl@student.vvc.edu
** Professor tonning, cis 201
** Develop a concordance generator program.  The concordance will be a list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where  the word occurred.  For each line of text, all punctuation must be removed and all letters in the string forced to lowercase.  Then, separate out the words and check each word against your list.   Keep track of the current line number and check if the word has been found before.  If the word has not been seen before, put it in some sort of collection data structure (an array or vector for example) and keep track of the line number.  If the word has been found before, store the line number of where the word occurred.*/ 

#include "word.h"


Word::Word(std::string  word)
{
   m_word = word;
   m_count = 1;
}

//

std::string Word::get_word() 
{ 
	return m_word; 
}

int Word::get_count()
{
	return m_count;
}


std::string Word::get_lines()
{
	std::string lines;
	for (int i = 0; i < m_line.size(); i++)
	{
		lines += (m_line[i] + ", ");
	}
	return lines;
}



void Word::add_count(int count)
{
   m_count++;
}

void Word::add_line(int line)
{
   m_line.push_back(line);
}
