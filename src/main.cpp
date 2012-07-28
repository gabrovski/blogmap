#include "scraper/scraper.h"
#include "indexer/indexer.h"

#include <iostream>
#include <vector>
using namespace std;

void scrape();

int main() {
  Indexer ind;

  ind.parse_dir("data/");

  return 0;
}


void scrape() {
  vector<string> seeds;
  seeds.push_back("http://www.blue-kitchen.com/");
  seeds.push_back("http://80breakfasts.blogspot.com/");
  seeds.push_back("http://www.albioncooks.blogspot.com/");
  seeds.push_back("http://aapplemint.com/");
  seeds.push_back("http://www.101cookbooks.com/");
  //seeds.push_back("http://www.dartmouth.edu");
  Scraper s(seeds);
  
  s.run(4);
}
