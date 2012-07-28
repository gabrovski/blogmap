#ifndef _WORD_H
#define _WORD_H 1


#include <iostream>
#include <vector>
#include <string>
#include <boost/regex.hpp>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

class Word;

class Article {
 private:
  vector<Word*> word_heap;
  string url;

 public:
  Article(string);
  Article();
  ~Article();

  string get_url() const { return url; } 
  bool operator < (const Article& a2)  const { get_url() < a2.get_url() ;} 
  bool operator == (const Article& a2 ) const { get_url() == a2.get_url() ;} 

  void add_word(string s);
  Word *peek_top();
  Word *pop_top();
  void init_heap();
};


class Word {

 private:
  set<Article*> articles;
  double df_score;
  string word;
  
 public:
   
  Word();
  ~Word();
  Word(string s);

  set<Article*> get_articles() const   { return articles; }
  double get_df_score()       const    { return df_score; }
  string get_word()           const    { return word; }
  
  void set_df_score(double d)  { df_score = d; }

  bool operator < (const Word& w2)  const { get_df_score() < w2.get_df_score() ;}
  bool operator == (const Word& w2 ) const { get_df_score() == w2.get_df_score() ;}

  bool add_article(Article *a);
   
};


Word* get_or_create_word(string s);
void compute_df_scores();

#endif
