#ifndef _BLOG_PAGE_H
#define _BLOG_PAGE_H

#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <fstream>
#include <set>
#include <sstream>
using namespace std;
using namespace __gnu_cxx;

#define SLEEP_INT 10
#define SLEEP(i)  if (i+1 % SLEEP_INT == 0 ) sleep(1) ; 
#define WRITE_DIR "data/"

class Page {

 private:
  int depth;
  string url;
  string path;
  string html;
  string root;
  vector<Page> children;

  string get_page_root();
  void write_page();
  
 public:
  Page();
  Page(int, string);
  ~Page();

  int get_depth()               { return depth;     } 
  string get_url()              { return url;       }
  string get_html()             { return html;      }
  string get_path()             { return path;      }
  vector<Page> get_children()   { return children;  }
  string get_root()             { return root;      }

  bool is_valid();
  vector<string> get_root_links();
  void find_children();
  void find_rec_children(int);
};

#endif
