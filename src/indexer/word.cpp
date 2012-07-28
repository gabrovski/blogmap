#include "word.h"

map<string, Word*> word_map;

Word* get_or_create_word(string s) {
  map<string, Word*>::iterator it;
  transform(s.begin(), s.end(), s.begin(), ::tolower);

  it = word_map.find(s);
  
  if (it == word_map.end()) {
    Word *w = new Word(s);
    word_map.insert(pair<string, Word*>(s, w));
    return w;
  }
  else {
    return it->second;
  }
}

Word::Word() { }
Word::~Word() { }
Word::Word(string s) { word = s; }

bool Word::add_article(Article *a) {
  set<Article*>::iterator it;
  it = this->articles.find(a);

  if (it == this->articles.end()) {
   this->articles.insert(a);
   return true;
  }
  
  return false;
}


Article::Article() { }
Article::~Article() { }
Article::Article(string s) { url = s; }

void Article::add_word(string s) {
  Word *w = get_or_create_word(s);
  if (w->add_article(this)) 
    this->word_heap.push_back(w);
    
}

void Article::init_heap() {
  make_heap(word_heap.begin(), word_heap.end());
}

Word* Article::peek_top() {
  return word_heap.front();
}

Word* Article::pop_top() {
  Word *w = word_heap.at(0);
  pop_heap(word_heap.begin(), word_heap.end());
  word_heap.pop_back();
  return w;
}

void compute_df_scores() {
  map<string, Word*>::iterator it;
  for (it = word_map.begin(); it != word_map.end(); it++) {
    Word *w = (*it).second;
    double score = w->get_articles().size();
    if (score == 0)
      score = 1;

    w->set_df_score(1 / log(score));
  }
}
