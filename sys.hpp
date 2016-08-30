
#ifndef SYS_C
#define SYS_C

#include <iostream>
#include <vector>
#include <sstream>

#include "cell.hpp"
#include "valS.hpp"
using namespace std;

class LSSys
{
public:
  int print(string c, string c1 = "", string c2 = "", string c3 = "", string c4 = "", string c5 = "")
  {
    c = c+c1+c2+c3+c4+c5;
    cout << c << endl;
    return 0;
  }

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

  /* WICHTIGE FUNKTIONEN WIE:
   * getCell() -> Zelle beim Namen bekommen
   * getValByName() -> Zelleninhalt beim Namen erhalten
   * setValByName() -> Zelleninhalt setzen
   * addValByName() -> Zelleninhalt mit Parameter addieren
   * remValByName() -> Zelleninhalt subtrahieren, replace bei String
   */
} LSSys;

#endif
