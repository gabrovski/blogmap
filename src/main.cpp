#include "scraper/page.h"
#include "scraper/scraper.h"

#include <iostream>
using namespace std;

int main() {

  Page p = Page(0, "http://www.dartmouth.edu");
  p.find_children();
  
  return 0;
}
