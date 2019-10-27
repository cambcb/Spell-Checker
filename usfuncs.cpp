//Camryn Buonamassa
//Project 2
//Unordered set functions

void uswrongWords(std::unordered_set<std::string> &dwords, std::vector<std::string> &words, std::unordered_set<std::string> &wrong){
  bool found = false;
  for(int i = 0; i < words.size(); i++){
    if(dwords.count(words[i]) == 1){
      found = true;
    }
    if(found == false){
      wrong.insert(words[i]);
    }
    found = false;
  }
}
void usreplace(std::unordered_set<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
 for(int x = 97; x < 123; x++){
    for(int y = 0; y < wrong.size(); y++){
      tryword = wrong;
      tryword = wrong.substr(0, y) + char(x) + wrong.substr(y+1, wrong.size()-1);
      if(dwords.count(tryword) == 1){
        result+= tryword + " ";
      }
    }
  }
}

void usadd(std::unordered_set<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
 for(int x = 97; x < 123; x++){
    for(int y = 0; y < wrong.size(); y++){
      tryword = wrong;
      tryword = wrong.substr(0, y) + char(x) + wrong.substr(y, wrong.size()-1);
      if(dwords.count(tryword) == 1){
        result+= tryword + " ";
      }
    }
  }
}

void usremove(std::unordered_set<std::string> &dwords, std::string wrong, std::string &result){
  std::string tryword;
  for(int y = 0; y < wrong.size(); y++){
    tryword = wrong;
    tryword = wrong.substr(0, y) + wrong.substr(y+1, wrong.size()-1);
    if(dwords.count(tryword) == 1){
      result+= tryword + " ";
    }
  }
}

void usswap(std::unordered_set<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
  for(int y = 0; y < wrong.size(); y++){
    tryword = wrong;
    std::swap(tryword[y], tryword[y+1]);
    if(dwords.count(tryword) == 1){
      result+= tryword + " ";
    }
  }
}