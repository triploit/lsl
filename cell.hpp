#ifndef CELL_C
#define CELL_C

#include <iostream>
using namespace std;

class cell
{
private:
  string name;
  string alias;
  bool isstr;
  bool isint;

  int ivalue = 0;
  string svalue = "";

public:
  string getSValue()
  {
    return svalue;
  }

  int getIValue()
  {
    return ivalue;
  }

  string getName()
  {
    return name;
  }

  string getAlias()
  {
    return alias;
  }

  void setSValue(string s)
  {
    svalue = s;
  }

  void setIValue(int i)
  {
    ivalue = i;
  }

  void setName(string s)
  {
    name = s;
  }

  void setAlias(string s)
  {
    alias = s;
  }

  void setInt()
  {
    if (isstr)
    {
      printf("[ SYS ] Diese Zelle \"%s\" ist schon ein String!", name.c_str());
      return;
    }

    isstr = true;
  }

  void setString()
  {
    if (isint)
    {
      printf("[ SYS ] Diese Zelle \"%s\" ist schon ein Integer!", name.c_str());
      return;
    }

    isstr = true;
  }

  bool isInt()
  {
    return isint;
  }

  bool isString()
  {
    return isstr;
  }
};

#endif
