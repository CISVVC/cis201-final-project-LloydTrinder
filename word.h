#ifndef WORD_H
#define WORD_H
#include<vector>
#include<string>

class Word
{
public:
   Word(std::string  word);
   void add_line(int line);
   void add_count(int count);
   std::string get_word();
   int get_count();
   std::string get_lines();
private:
   int m_count;
   std::string m_word;
   std::vector<int> m_line;
};


#endif
