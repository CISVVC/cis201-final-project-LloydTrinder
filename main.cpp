/* Lloyd Trinder
** trinderl@student.vvc.edu
** Professor tonning, cis 201
** Develop a concordance generator program.  The concordance will be a list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where  the word occurred.  For each line of text, all punctuation must be removed and all letters in the string forced to lowercase.  Then, separate out the words and check each word against your list.   Keep track of the current line number and check if the word has been found before.  If the word has not been seen before, put it in some sort of collection data structure (an array or vector for example) and keep track of the line number.  If the word has been found before, store the line number of where the word occurred.*/ 

#include "concordance.h"

int main()
{
	Concordance con("alice.txt");
	con.parse();
	con.print();

	return 0;
}
