#include "page.h"
#include "../util/util.h"

#include <boost/regex.hpp>

set<string> g_visited;
int g_page_i = 0;

Page::Page() {
    depth = 0;
    url = "/na";
    html = "";
    root = "";
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
  cout << url << endl;

  if (g_visited.find(url) == g_visited.end()) {
    html = get_page(url);
    root = get_page_root();
    g_visited.insert(url);
    write_page();
  }
  else {
    cout << "already visited" << endl;
  }
  //cout << "root " << root << endl;
    //TODO error check
}

Page::~Page() { }

bool Page::is_valid() {
  return (this->get_html() != "" && 
	  this->get_page_root() != "");
}

vector<string> Page::get_root_links() {
  vector<string> res;
  std::string::const_iterator start, end; 
  boost::regex re("<a href=\"(.+?)\"");
  boost::match_results<std::string::const_iterator> what; 
  string url;

  start = this->html.begin(); 
  end = this->html.end(); 
  
  while (boost::regex_search(start , end, what , re)) {
    start = what[1].second;
    url = string(what[1].first,what[1].second);

    if (url.find(this->root) != -1 && url.find("http") != -1)
      res.push_back(url);
  }
  
  return res;
}

void Page::find_children() {
  int i;
  vector<string> links = get_root_links();
  
  for (i = 0 ; i < 5 && i < links.size(); i++) {
    try {
      Page p(this->get_depth(), links.at(i));
      if (p.is_valid())
	this->get_children().push_back(p);
    }
    catch (exception& e) {
      cout << links.at(i) << " failed" << endl ;
    }
    
    SLEEP(i)
  }
  
}

void Page::find_rec_children(int maxdepth) {
  int i;
  if (this->depth < maxdepth-1) {
    this->find_children();

    for (i = 0; i < this->get_children().size(); i++) {
      this->get_children().at(i).find_rec_children(maxdepth);
    }
  }
}

void Page::write_page() {
  stringstream ss;
  ofstream w;

  ss << WRITE_DIR << g_page_i++ << ".html";
  w.open(ss.str().c_str());
  
  w << "<URL#" << this->url << "#URL>" << endl;
  w << this->html ;
  w.close();

}
