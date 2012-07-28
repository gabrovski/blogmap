#ifndef _INDEXER_H 
#define _INDEXER_H 1

#include "word.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <boost/regex.hpp>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

class Indexer {

 private:
  vector<Article*> articles;
  bool init;
  
 public:
  Indexer()  { init = false; }
  ~Indexer() {}
  
  vector<Article*> get_articles() const { return articles; }
  bool is_initialized()          const { return init;     }


  void parse_file(string path);
  void parse_dir(string path);
  void parse_xml(string path);
  void out_xml(string path);
  void initialize();

};

#endif
