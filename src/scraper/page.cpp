#include "page.h"
#include "../util/util.h"

Page::Page() {
    depth = 0;
    url = "/na";
}

string Page::get_page_root() {
  int i, j;
  string root(this->url);

  if ((i=root.find("http://", 0, 7)) > -1) {
    root.erase(i, 7);
    
    i = root.find("www.", 0, 4);
    if 
      (i < 0) i=0;
    else
      i+=4 ;

    j = root.find("/", i, 1);
    return root.substr(i,j-i);
  }
  
  return string("");
}
  
Page::Page(int d, string u) {
  depth = d;
  url = u;

  html = get_page(url);
  
  root = get_page_root();
  //cout << "root " << root << endl;
    //TODO error check
}

Page::~Page() { }

bool Page::is_valid(int maxdepth) {
  return (this->get_html() != "" && 
	  this->get_depth() < maxdepth && 
	  this->get_page_root() != "");
}

void Page::find_children() {
  
}
