#include "word.h"



map<string, Word> word_map;


bool compare_words(Word a, Word b)  {  return a.get_df_score() >= b.get_df_score(); }

bool compare_articles(Article a, Article b) { return a.get_url() >= b.get_url(); }

Word get_or_create_word(string s) {
  map<string, Word>::iterator it;
  it = word_map.find(s);
  
  if (it == word_map.end()) {
    Word w = Word(s);
    word_map.insert(pair<string, Word>(s, w));
    return w;
  }
  else {
    return it->second;
  }
}

Word::Word() { }
Word::~Word() { }
Word::Word(string s) { word = s; }

void Word::add_article(Article a) {
  set<Article>::iterator it;
  it = this->articles.find(a);

 if (it == this->articles.end()) 
   this->articles.insert(a);
  
}
