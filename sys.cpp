#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#ifndef SYS_C
#define SYS_C

bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);

    if(start_pos == string::npos)
        return false;

    str.replace(start_pos, from.length(), to);
    return true;
}

vector<string> split(const string &text, char sep) {
  vector<string> tokens;
  size_t start = 0, end = 0;

  while ((end = text.find(sep, start)) != string::npos)
  {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }

  tokens.push_back(text.substr(start));
  return tokens;
}


#endif
