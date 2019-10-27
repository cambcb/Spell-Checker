//Camryn Buonamassa
//Project 2
//Vector functions

void vwrongWords(std::vector<std::string> &dwords, std::vector<std::string> &words, std::vector<std::string> &wrong){
  int count = 0;
  bool found = false;
  for(int i = 0; i < words.size(); i++){
    for(int n = 0; n < dwords.size(); n++){
      if(words[i] == dwords[n]){
        found = true;
      }
      if(found == true){
        break;
      }
    }
    if(found == false){
      wrong.push_back(words[i]);
      count++;
    }
    found = false;
  }
}

void vreplace(std::vector<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
 for(int x = 97; x < 123; x++){
    for(int y = 0; y < wrong.size(); y++){
      tryword = wrong;
      tryword = wrong.substr(0, y) + char(x) + wrong.substr(y+1, wrong.size()-1);
      for(int z = 0; z < dwords.size(); z++){
        if(tryword == dwords[z]){
        result+= tryword + " ";

        }
      }
    }
  }
}

void vadd(std::vector<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
 for(int x = 97; x < 123; x++){
    for(int y = 0; y < wrong.size(); y++){
      tryword = wrong;
      tryword = wrong.substr(0, y) + char(x) + wrong.substr(y, wrong.size()-1);
      for(int z = 0; z < dwords.size(); z++){
        if(tryword == dwords[z]){
        result+= tryword + " ";
        }
      }
    }
  }
}

void vremove(std::vector<std::string> &dwords, std::string wrong, std::string &result){
  std::string tryword;
  for(int y = 0; y < wrong.size(); y++){
    tryword = wrong;
    tryword = wrong.substr(0, y) + wrong.substr(y+1, wrong.size()-1);
    for(int z = 0; z < dwords.size(); z++){
      if(tryword == dwords[z]){
        result+= tryword + " ";


      }
    }
  }
}

void vswap(std::vector<std::string> &dwords, std::string wrong, std::string &result){
 std::string tryword;
  for(int y = 0; y < wrong.size(); y++){
    tryword = wrong;
    std::swap(tryword[y], tryword[y+1]);
    for(int z = 0; z < dwords.size(); z++){
      if(tryword == dwords[z]){
        result+= tryword + " ";
      }
    }
  }
}