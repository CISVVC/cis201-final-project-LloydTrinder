// concordance.cpp : Defines the entry point for the console application.
//
#include "concordance.h"




int main()
{
	Concordance con = new Concordance("alice.txt");
	con.parse();
	con.print();

	return 0;
}
