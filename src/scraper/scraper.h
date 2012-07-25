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
  vector<Page> get_pages();
};

#endif
