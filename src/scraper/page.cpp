#include "page.h"
#include "../util/util.h"
#include <iostream>
using namespace std;

Page::Page() {
    depth = 0;
    url = "/na";
}
  
Page::Page(int d, string u) {
    depth = d;
    url = u;

    html = get_page(url);
  
    //TODO error check
}



