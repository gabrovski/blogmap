#ifndef _SCRAPER_H
#define _SCRAPER_H

#include <vector>
#include "page.h"
using namespace std;

class Scraper {

 private:
  vector<Page> pages;

 public:
  Scraper();
  Scraper(vector<string>);
  ~Scraper();
  vector<Page> get_pages() { return pages; }
  void run(int);
};

#endif
