//Camryn Buonamassa
//Project 2
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <chrono>
#include "vfuncs.cpp"
#include "sfuncs.cpp"
#include "usfuncs.cpp"
using Timer = std::chrono::steady_clock;
std::chrono::steady_clock::time_point vstart, vfinish;
std::chrono::steady_clock::time_point sstart, sfinish;
std::chrono::steady_clock::time_point usstart, usfinish;

int main(){
  std::string wfile;
  std::string dfile;
  std::cout << "Enter word file: " << std::endl;
  std::cin >> wfile;
  std::cout << "Enter dictionary file: " << std::endl;
  std::cin >> dfile;

  //read dictionary into data structures
  std::ifstream dictionary;
  std::string dword;
  std::vector<std::string> vdic;
  std::set<std::string> sdic;
  std::unordered_set<std::string> usdic;
  dictionary.open(dfile); 
  while(dictionary >> dword){ 
    vdic.push_back(dword);
  }
  dictionary.close();
  dictionary.open(dfile); 
  while(dictionary >> dword){ 
    sdic.insert(dword);
  }
  dictionary.close();
  dictionary.open(dfile);
  while(dictionary >> dword){ 
    usdic.insert(dword);
  }
  dictionary.close();

  //read words into data structures
  std::ifstream library;
  std::string word;
  std::string goodWord;
  std::vector<std::string> words;

  library.open(wfile); 
  while(library >> word){
    goodWord = "";
    char c;
    for(int i = 0; i < word.length(); i++){
      if(isupper(word[i])){
        c = std::tolower(word[i]);
        goodWord += c;
      }
      else if( word[i] == '-' || islower(word[i]) || word[i] == '\''){
          goodWord += word[i];   
      }
    } 
    words.push_back(goodWord);
  }
  //get all wrong words in each data structure
  std::vector<std::string> vwrong;
  vwrongWords(vdic, words, vwrong);
  std::set<std::string> swrong;
  swrongWords(sdic, words, swrong);
  std::unordered_set<std::string> uswrong;
  uswrongWords(usdic, words, uswrong);

  ///////////////////////////////////////////////////TEST VECTOR
  auto vstart{Timer::now()};
  std::ofstream outfile;
  outfile.open("suggestions.txt");

  for(int n = 0; n < vwrong.size(); n++){
    std::string newString = "";
    std::string oldString = "";
    vreplace(vdic, vwrong[n], newString);
    vremove(vdic, vwrong[n], newString);
    vadd(vdic, vwrong[n], newString);
    vswap(vdic, vwrong[n], newString);
    if (newString == oldString) {
      outfile << "No suggestions found for \"" << vwrong[n] << "\"" << std::endl;
    } else {
      outfile << "Instead of \"" << vwrong[n] << "\" did you mean: ";
      outfile << newString << std::endl;
    }
  }
  outfile.close();
  auto vfinish{Timer::now()};
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(vfinish-vstart).count() << "ms for vector\n";
  
  ///////////////////////////////////////////////////TEST SET
  auto sstart{Timer::now()};
  std::ofstream outfile2;
  outfile2.open("suggestions2.txt");

  for(std::string x : swrong){
    std::string newString = "";
    std::string oldString = "";
    sreplace(sdic, x, newString);
    sremove(sdic, x, newString);
    sadd(sdic, x, newString);
    sswap(sdic, x, newString);
    if (newString == oldString) {
      outfile2 << "No suggestions found for: " << x << std::endl;
    } else {
      outfile2 << "Instead of \"" << x << "\" did you mean: ";
      outfile2 << newString << std::endl;
    }
  }
  outfile2.close();
  auto sfinish{Timer::now()};
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(sfinish-sstart).count() << "ms for set\n";

  ///////////////////////////////////////////////////TEST UNORDERED SET
  auto usstart{Timer::now()};
  std::ofstream outfile3;
  outfile3.open("suggestions3.txt");

  for(std::string y : uswrong){
    std::string newString = "";
    std::string oldString = "";
    usreplace(usdic, y, newString);
    usremove(usdic, y, newString);
    usadd(usdic, y, newString);
    usswap(usdic, y, newString);
    if (newString == oldString) {
      outfile3 << "No suggestions found for: " << y << std::endl;
    } else {
      outfile3 << "Instead of \"" << y << "\" did you mean: ";
      outfile3 << newString << std::endl;
    }
  }
  outfile3.close();
  auto usfinish{Timer::now()};
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(usfinish-usstart).count() << "ms for unordered set\n";
}

