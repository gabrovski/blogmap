#ifndef _PAGE_H
#define _PAGE_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Page {

 private:
  int depth;
  string url;
  string path;
  string html;
  string root;
  vector<string> children;

  string get_page_root();
  
 public:
  Page();
  Page(int, string);
  ~Page();

  int get_depth()               { return this->depth;     } 
  string get_url()              { return this->url;       }
  string get_html()             { return this->html;      }
  string get_path()             { return this->path;      }
  vector<string> get_children() { return this->children;  }
  string get_root()             { return this->root;      }

  bool is_valid(int);
  void find_children();

};

#endif
