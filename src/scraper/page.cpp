#include "page.h"
#include <curl/curl.h>
using namespace std;

Page::Page() {
    depth = 0;
    url = "/na";
}
  
Page::Page(int d, string u, string text) {
    depth = d;
    url = u;
    html = text;
}

int Page::acquire_page() {
  
  return -1;
}
