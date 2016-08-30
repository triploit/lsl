#ifndef PARSER_C
#define PARSER_C
#define _REMOVED "LSL:[*R3M0V36]^oHGaM(SuR){STRaN}"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#include "valS.hpp"
#include "sys.hpp"
using namespace std;

class Parser
{
private:
  vector<string> cmds;
public:
  void printAC()
  {
    // I so lange höchzählen bis die "Höhe" von CMDS erreicht wurde
    for(int i = 0; i < cmds.size(); i++)
    {
      print("[ SYS ] Befehl ("+to_string(i)+"): "+cmds[i]); // Alle Befehle und Argumente ausgeben
    }
  }

  int print(string c, string c1 = "", string c2 = "", string c3 = "", string c4 = "", string c5 = "")
  {
    c = c+c1+c2+c3+c4+c5; // Alle Argumente zusammenzählen
    cout << c << endl; // Alle Argumente ausgeben
    return 0;
  }

  int parse(char code[])
  {
    // INITIIERE DIE PARSERVARIABLEN
    char c; // -> Der aktuelle Char
    string str = ""; // -> Der aktuelle Befehl
    int cmdc = 0; // -> Der Befehlszähler

    // VERGLEICHBAR MIT PRÄPROZESSOR, SOÄTER NÖTIG FÜR GOTO
    for (int i = 0; code[i] != '\0'; i++)
    {
      toupper(c);
      if (c == ' ' || c == ';' || c == '\n' || c == '\t' || c == '@' || c == ',' || c == '[' || c == ']')
      {
        str = "";
      }
      else
      {
        str+=c;
      }
    }

    // DER EIGENTLICHE PARSER
    str = "";
    for (int i = 0; code[i] != '\0'; i++)
    {
      c = code[i];

      // STRINGS ERKENNEN UND HINZUFÜGEN
      if (c == '\"')
      {
        // STRING ERKENNEN
        int x;
        for (x = i+1; code[x] != '\"'; x++)
        {
          str+=code[x];
          i = x;
        }
        i++;

        //STRING EINFÜGEN
        cmds.push_back(str);
        str = "";
      }
      // NACH TRENNZEICHEN TRENNEN
      if (c == ' ' || c == ']' || c == '\t' || c == ';' || c == '\n' || c == '@' || c == ',' || c == '\0')
      {
        int a = i + 1;

        // DOPPELTE TRENNZEICHEN IGNORIEREN
        for (a = a; code[a] == ' ' || code[a] == '\t' || code[a] == ';' || code[a] == '\n' || code[a] == '@' || code[a] == ',' || code[a] == '\0'; a++)
        {
          i++;
        }

        // DAS WORT WIRD ZURÜCKGEGEBEN UND IN cmds GESPEICHERT
        cmds.push_back(str);
        str = "";
      }
      else
      {
        str += c;
      }
    }

    // EIN LETZTES MAL ÜBERPRÜFEN
    for (int i = 0; i < cmds.size(); i++)
    {
      if (cmds[i] == "\"")
      {
        cmds[i] = _REMOVED;
      }
    }

    for (int i = 0; i < cmds.size(); i++)
    {
      for (int x = 0; x < cells.size(); x++)
      {
        if (cmds[i] == cells[i].getName())
        {
          print("Zelle ",cells[i].getName(), " gefunden!");
        }
      }
    }

    printAC();
    return 0;
  }

  // BEIM AUSFÜHREN NICHT VERGESSEN: "REMOVED" ZU IGNORIEREN

} Parser;

#endif
