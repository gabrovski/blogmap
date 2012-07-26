#include "scraper.h"

Scraper::Scraper() {
  
}
Scraper::~Scraper() {

}

Scraper::Scraper(vector<string> seeds) {
  int i;
  for (i = 0; i < seeds.size(); i++) {
    Page p(0, seeds.at(i));
    if (p.is_valid()) {
      this->pages.push_back(p);
    }
    else 
      cout << "the page at " << seeds.at(i) << " is not valid" << endl ;
  }

  cout << "seed nest built" << endl << endl;
}

void Scraper::run(int maxdepth) {
  int i;
  for (i = 0; i < pages.size(); i++)
    pages.at(i).find_rec_children(maxdepth);
}
