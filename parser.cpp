#ifndef PARSER_C
#define PARSER_C

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#include "sys.cpp"
using namespace std;

int print(string c, string c1 = "", string c2 = "", string c3 = "", string c4 = "", string c5 = "")
{
  c = c+c1+c2+c3+c4+c5;
  cout << c << endl;
  return 0;
}

int parse_code(char code[])
{
  string c = "";
  int cmdc = 0;
  vector<string> cmds;

  for (int i = 0; code[i] != '\0'; i++)
  {
    toupper(code[i]);
    if (code[i] == ' ' || code[i] == ';' || code[i] == '\n' || code[i] == '\t' || code[i] == '@' || code[i] == ',' || code[i] == '[' || code[i] == ']')
    {
      c = "";
    }
    else
    {
      c+=code[i];
    }
  }

  c = "";

  for (int i = 0; code[i] != '\0'; i++)
  {
    toupper(code[i]);
    if (code[i] == ' ' || code[i] == ']' || code[i] == '\t' || code[i] == ';' || code[i] == '\n' || code[i] == '@' || code[i] == ',' || code[i] == '\0')
    {
      int a = i + 1;
      for (a; code[a] == ' ' || code[a] == '\t' || code[a] == ';' || code[a] == '\n' || code[a] == '@' || code[a] == ',' || code[a] == '\0'; a++)
      {
        i++;
      }

      replace(c, "[", "");
      cmds.push_back(c);
      c = "";
    }
    else
    {
      c += code[i];
    }
  }

  return 0;
}

#endif
