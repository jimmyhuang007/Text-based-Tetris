#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdexcept>
#include <vector>
#include "Interpreter.h"
using namespace std;

int main(int argc, char* argv[]) {

  //Score s();
  
  int seed = 0;
  int lv = 0;
  string scFile = "sequence.txt";
  bool textOnly = false;
  
  if (argc > 1) {
    int iter = 1;

    while (iter < argc) {
      istringstream ss(argv[iter]);
      string arguments;
      ss >> arguments;
      if (arguments == "-text") {
        ++iter;
        textOnly = true;
      } else if (arguments == "-seed") {
        ++iter;
        istringstream ss2(argv[iter]);
        ss2 >> seed;
        ++iter;
      } else if (arguments == "scriptfile") {
        ++iter;
        istringstream ss2(argv[iter]);
        ss2 >> scFile;
        ++iter;
      } else if (arguments == "-startlevel") {
        ++iter;
        istringstream ss2(argv[iter]);
        ss2 >> lv;
        if (lv > 4) lv = 4;
        if (lv < 0) lv = 0;
        ++iter;
      }
    }
  }
  shared_ptr<Grid> g = make_shared<Grid>(textOnly);
  shared_ptr<Interpreter> in= make_shared<Interpreter>(*g, lv, seed, scFile, textOnly); 
  string input;
  while (cin >> input) {
    if (input == "sequence") {
      string fileName;
      cin >> fileName;
      ifstream myFile(fileName);
      while (myFile >> input) {
        in->update(input);
      }
      break;
    }
    in->update(input);
  }
}
