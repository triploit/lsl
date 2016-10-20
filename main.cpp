#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

#include "cell.hpp"
#include "valS.hpp"
#include "sys.hpp"
#include "parser.cpp"

int main(int argc, char* argv[])
{

  if (argc < 2)
  {
    printf("[ ERR ] Es wurde keine Datei angegeben!\nEnter drücken um fortzufahren... ");
    cin.get();
    return 0;
  }

  char c;
  FILE *datei;
  char code[999999];

  datei=fopen(argv[1], "r");

  if(datei != NULL)
  {
    vinit();
    Kwords.kinit();
    printf("\n<<< ––––––––BEGIN––––––––– >>>\n\n");
    for (int i = 0; (c=fgetc(datei)) != EOF; i++)
    {
      code[i] = c;
      printf("%c", code[i]);
    }
    printf("\n<<< –––––––––ENDC––––––––– >>>\n\n");

    Parser.parse(code);
    Parser.print("\n[ END ]");
  }
  else
  {
    printf("[ ERR ] Konnte Datei \"%s\" nicht finden bzw. öffnen!\nEnter drücken um fortzufahren... ", argv[1]);
    cin.get();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

#endif
