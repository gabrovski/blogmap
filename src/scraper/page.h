#ifndef _PAGE_H
#define _PAGE_H

#include <vector>
#include <string>
using namespace std;

class Page {

 private:
  int depth;
  string url;
  string path;
  string html;
  vector<string> children;

 public:
  Page();
  Page(int, string, string);

  int acquire_page();

  int get_depth()               { return this->depth;    } 
  string get_url()              { return this->url;      }
  string get_html()             { return this->html;     }
  string get_path()             { return this->path;     }
  vector<string> get_children() { return this->children; }

};

#endif
