#include "indexer.h"

boost::regex css_re("(<style.+?</style>)(?s)|(<script>.+?</script>)(?s)");
boost::regex html_re("(<.+?>)(?s)");
boost::regex word_re("[a-zA-Z]+");
boost::regex title_re("<title>(.+?)</title>");

int g_article_count = 0;

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
  string title("");
  boost::match_results<string::const_iterator> words;
  boost::match_results<string::const_iterator> title_res;
  string::const_iterator start, end;
  
  f.open(path.c_str());

  if (!f) {
    cout << "could not open " << path << endl;
  }
  else {
    
    getline(f, line);
    
    if((i = line.find("<URL#")) != string::npos) {
      j = line.find("#URL>");
      Article *a = new Article(line.substr(i, j), g_article_count++);
      articles.push_back(a);
	
      buf << f.rdbuf();
      string clean = buf.str();
      start = clean.begin();
      end = clean.end();

      if (boost::regex_search(start, end, title_res, title_re))
	title = string(title_res[1].first, title_res[1].second);

      a->set_title(title);

      clean = boost::regex_replace(clean, css_re, "");
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

    cout << path << " " << title << " is done" << endl;
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
      //if (g_article_count == 20)
      //break;
    }
    
    closedir(dp);
    
  }
}

void Indexer::out_xml(const char *path) {
  ofstream w(path);
  int i;
  map<string, Word*>::iterator word_it;
  set<Article*>::iterator art_it;
  

  w << "<articles>" << endl;

  for (i = 0; i < articles.size(); i++) {
    w << articles.at(i)->get_id() << ":" << articles.at(i)->get_title();
    w << ":" << articles.at(i)->get_url() << endl;
  }

  w << "</articles>" << endl;

  w << "<words>" << endl;

  for (word_it = word_map.begin(); word_it != word_map.end(); word_it++) {
    Word *word = (*word_it).second;
    w << word->get_word() << ":";
    
    for (art_it = word->get_articles().begin(); art_it != word->get_articles().end(); art_it++) 
      w << (*art_it)->get_id() << "#";
    
    w << "score:" << word->get_df_score() << endl;
  }

  w << "</words>" << endl;
  w.close();
}
