/* ----------------------------------------------------------------------------
Author:              Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        19th March 2010
Last Modification:

Program Description: Program to generate Jargon using three lists of words
File Description:    Main Program flow.
*/// --------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <stdlib.h>         //included for clear screen - http://support.microsoft.com/kb/99261
#include <string>           //included to support string operations
#include "jargon-gen.h"

using namespace std;

int main()
{
    char        command[256];
    int         num, counter;
    string      text, phrase;
    
    initialise();
    while ((strcmp(command, "quit") != 0))
    { 
      main_menu();
      cin >> command;
      if (strcmp(command, "add")==0)
      {
            cin >> num;
            add_entry(num);
      }
      else if (strcmp(command, "delete") == 0)
      {
           cin >> num;
           delete_entry(num);
      }
      else if (strcmp(command, "make")   == 0)
      {     
            cin >> num;
            counter = 0;
            phrase = "nothing";
            cout << endl;
            while (counter < num)
            {
                  list_make();
                  counter++;
            }
            cout << endl;
            system("pause");                
      }
      else if (strcmp(command, "show")   == 0)
      {
           int num;
           cin >> num;
           show_list(num);
      }
      else if (strcmp(command, "quit") == 0)
           quit_application();
      else
           bad_choice();
    }
    return EXIT_SUCCESS;
}
