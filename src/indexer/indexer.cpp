#include "indexer.h"

boost::regex css_re("(<style.+?</style>)(?s)|(<script>.+?</script>)(?s)");
boost::regex html_re("(<.+?>)(?s)");
boost::regex word_re("[a-zA-Z]+");

void Indexer::initialize() {
  int i;

  compute_df_scores();

  for (i = 0; i < this->articles.size(); i++)
    this->articles.at(i)->init_heap();
  
  init = true;
}

void Indexer::parse_file(string path) {
  ifstream f;
  string line;
  int i, j;
  stringstream buf;
  boost::match_results<string::const_iterator> words;
  string::const_iterator start, end;
  
  f.open(path.c_str());

  if (!f) {
    cout << "could not open " << path << endl;
  }
  else {
    
    getline(f, line);
    
    if((i = line.find("<URL#")) != string::npos) {
      j = line.find("#URL>");
      Article *a = new Article(line.substr(i, j));
      articles.push_back(a);
	
      buf << f.rdbuf();

      string clean = boost::regex_replace(buf.str(), css_re, "");
      clean = boost::regex_replace(clean, html_re, "");
      
      start = clean.begin();
      end = clean.end();
      while (boost::regex_search(start, end, words, word_re)) {
	start = words[0].second;
     
	a->add_word(string(words[0].first, words[0].second));
      }
    }
    
    else {
      cout << path << " did not have URL tag" << endl;
    }	
    
    f.close();

    cout << path << " is done" << endl;
  }
}

void Indexer::parse_dir(string path) {
  DIR *dp;
  struct dirent *dirp;

if((dp  = opendir(path.c_str())) == NULL) 
    cout << "Error opening " << path << endl;
  else {

    while ((dirp = readdir(dp)) != NULL) {
      parse_file(path+string(dirp->d_name));
    }

    closedir(dp);

  }
}
