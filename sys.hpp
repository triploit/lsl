
#ifndef SYS_C
#define SYS_C

#include <iostream>
#include <vector>
#include <sstream>

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

  cell getCell(string name, string al = "")
  {
    for (int d = 0; d < cells.size(); d++)
    {
      if ((cells[d].getName() == name) && d < cells.size())
      {
        return cells[d];
      }
    }
  }

  string getSValByName(string name, string al = "")
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        return cells[i].getSValue();
      }
    }
  }

  int getIValByName(string name, string al = "")
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        return cells[i].getIValue();
      }
    }
  }

  string setSValByName(string name, string al = "", string val = "")
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        cells[i].setSValue(val);
      }
    }
  }

  int setIValByName(string name, string al = "", int val = 0)
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        cells[i].setIValue(val);
      }
    }
  }

  string addSValByName(string name, string al = "", string val = "")
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        cells[i].setSValue(cells[i].getSValue()+val);
      }
    }
  }

  int addIValByName(string name, string al = "", int val = 0)
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        cells[i].setIValue(cells[i].getIValue()+val);
      }
    }
  }

  string remSValByName(string name, string al = "", string val = "")
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        string d = cells[i].getSValue();
        replace(d, val, "");
        cells[i].setSValue(d);
      }
    }
  }

  int remIValByName(string name, string al = "", int val = 0)
  {
    for (int i = 0; i < cells.size(); i++)
    {
      if (cells[i].getName() == name || cells[i].getAlias() == al)
      {
        cells[i].setIValue(cells[i].getIValue()-val);
      }
    }
  }

  /* WICHTIGE FUNKTIONEN WIE:
   * remValByName() -> Zelleninhalt subtrahieren, replace bei String
   */
} LSSys;

void dof(string arg1, string arg2)
{
  if (arg1 == "ag")
  {
    printf("[ SYS ] AG in LSL gefunden!\n");
    cell f;

    for (int i = 0; i < cells.size(); i++)
    {
      if ((cells[i].getName() == arg2) && i < cells.size())
      {
        f = cells[i];
      }
    }

    printf("%s", f.getSValue().c_str());
  }
}

void movf(string arg1, string arg2)
{
  string name = arg2;

  for (int i = 0; i < cells.size(); i++)
  {
    if (cells[i].getName().compare(name) || cells[i].getAlias().compare(name))
    {
      //printf("V: %s\n", arg1.c_str());
      cells[i].setSValue(arg1);
    }
    else
    {
      //printf("%s: Diese Zelle ist es nicht...\n", arg2.c_str());
    }
  }
  //LSSys.getCell(arg1).setSValue(arg2);
}

void addf(string arg1, string arg2)
{
  for (int i = 0; i < cells.size(); i++)
  {
    string name = arg2;
    if (cells[i].getName().compare(name) || cells[i].getAlias().compare(name))
    {
      //printf("V: %s\n", arg1.c_str());
      if (cells[i].isInt())
         cells[i].setSValue(arg1);
    }
    else
    {
      //printf("%s: Diese Zelle ist es nicht...\n", arg2.c_str());
    }
  }
}

class kword
{
private:
  string name;
  void (*function)(string arg1, string arg2);
public:

  string getName()
  {
    return name;
  }

  void setName(string nme)
  {
    name = nme;
  }

  void setFunction(void (*functionf)(string arg1, string arg2))
  {
    function = functionf;
  }

  void runFunction(string arg1, string arg2)
  {
    function(arg1, arg2);
  }
};

class Kwords
{
public:
  vector<kword> allKeyWords;
  void kinit()
  {
    kword lsl;
    lsl.setName("do");
    lsl.setFunction(dof);

    kword mov;
    mov.setName("mov");
    mov.setFunction(movf);

    kword add;
    add.setName("add");
    add.setFunction(addf);

    allKeyWords.push_back(lsl);
    allKeyWords.push_back(mov);
  }

  //void (*kwords_func[1])(string arg1, string arg2) =
  //{
  //  &lslf
  //};

} Kwords;

#include "cell.hpp"
#endif
