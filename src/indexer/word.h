#ifndef _WORD_H
#define _WORD_H 1


#include <iostream>
#include <vector>
#include <string>
#include <boost/regex.hpp>
#include <map>
#include <algorithm>

using namespace std;

class Word;

class Article {
 private:
  vector<Word> word_heap;
  string url;

 public:

  string get_url() const { return url; }

  void add_word(string s);
  Word peek_top();
  Word pop_top();
 
 
  bool operator < (const Article& a2)  const { get_url() < a2.get_url() ;} 
  bool operator == (const Article& a2 ) const { get_url() == a2.get_url() ;} 
  

};


class Word {

 private:
  set<Article> articles;
  double df_score;
  string word;
  
 public:
   
  Word();
  ~Word();
  Word(string s);

  set<Article> get_articles() const   { return articles; }
  double get_df_score()       const    { return df_score; }
  string get_word()           const    { return word; }
  
  void set_df_score(double d)  { df_score = d; }

  bool operator < (const Word& w2)  const { get_df_score() < w2.get_df_score() ;}
  bool operator == (const Word& w2 ) const { get_df_score() == w2.get_df_score() ;}

  void add_article(Article a);
   
};

bool compare_words(Word a, Word b);  

bool compare_articles(Article a, Article b);

Word get_or_create_word(string s);

#endif
