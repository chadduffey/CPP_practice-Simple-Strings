/* ----------------------------------------------------------------------------
Author:              Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        19th March 2010
Last Modification:

Program Description: Program to generate Jargon using three lists of words
File Description:    All program functions.
*/// --------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <stdlib.h>         //included for clear screen functionality http://support.microsoft.com/kb/99261
#include <fstream>          //included for file IO
#include <string>
#include "jargon-gen.h"

using namespace std;

void main_menu()
{
     system("cls");         
     cout << endl;
     cout << "\t################################################################\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   Jargon Generator                                           #\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   make   - Makes jargon list(s)                              #\n";
     cout << "\t#            Eg: 'make 3'                                      #\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   add    - Add words to the lists                            #\n";
     cout << "\t#            Eg: 'add 3 tortoise'                              #\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   delete - Remove a word from a list                         #\n";
     cout << "\t#            Eg: 'delete 1 red'                                #\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   show   - Show a list                                       #\n";
     cout << "\t#            Eg: 'show 2'                                      #\n";
     cout << "\t#                                                              #\n";
     cout << "\t#   quit   - Quit the application                              #\n";
     cout << "\t#            Eg: 'quit'                                        #\n";
     cout << "\t#                                                              #\n";
     cout << "\t################################################################\n";
     cout << endl;
     cout << "\tEnter Command: "; 
}

void bad_choice()
{
     system("cls");
     cout << endl;
     cout << "> INVALID SYNTAX.\n";
     cout << endl;
     system("PAUSE");
}

void quit_application()
{
     system("cls");
     cout << endl;
     cout << "> EXITING JARGON GENERATOR \n";
     cout << endl;
     system("PAUSE");
}   

void add_entry(int num)
{
      char     text[50];
      string   words[20];
      ofstream out_stream;
      

      cin >> text;
 
     //output file selection and opening 
     if (num == 1) 
     {
          out_stream.open("list-1-adj.txt",ios::app);
          if (out_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     }              
     else if (num == 2)
     {
          out_stream.open("list-2-adj.txt", ios::app);
          if (out_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     } 
     else if (num == 3)
     {
          out_stream.open("list-3-noun.txt", ios::app);
          if (out_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     }
     
     //write entry to the file
     out_stream << text << endl;
   
     //close the output file
     out_stream.close();
}

void delete_entry(int num)
{

      char    text[500];
      string  string_from_file;      
      string  words[30];             
      int     i, number_of_elements = 0;    
      
      // file streams
      ifstream in_stream;
      ofstream out_stream;
      
      cin >> text;
      
     //input file selection
     if (num == 1) 
     {
          in_stream.open("list-1-adj.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     }              
     else if (num == 2)
     {
          in_stream.open("list-2-adj.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     } 
     else if (num == 3)
     {
          in_stream.open("list-3-noun.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     } 
     else
         cout << "\tInvalid list selected, please choose list 1,2 or 3\n";
     
     //read the file into an array      
     while (! in_stream.eof())
     { 
       in_stream >> string_from_file;
       if (string_from_file != text)
          words[number_of_elements] = string_from_file;
          number_of_elements++;
     }
     
     //close the input file
     in_stream.close();
     
     //output file selection 
     if (num == 1) 
     {
          out_stream.open("list-1-adj.txt");
          if (out_stream.fail())
          {
             cout << "Error opening output file.\n";
             exit(1);
          }
     }              
     else if (num == 2)
     {
          out_stream.open("list-2-adj.txt");
          if (out_stream.fail())
          {
             cout << "Error opening output file.\n";
             exit(1);
          }
     } 
     else if (num == 3)
     {
          out_stream.open("list-3-noun.txt");
          if (out_stream.fail())
          {
             cout << "Error opening output file.\n";
             exit(1);
          }
     } 
     
     //write the modified list back to the file
     for (i = 0; i < number_of_elements; i++)
         out_stream << words[i] << endl;

     //close the output file
     out_stream.close();
}

void show_list(int num)
{
     ifstream in_stream;
     string   string_from_file, last_string;
     
     //input file selection
     if (num == 1) 
     {
          in_stream.open("list-1-adj.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     }              
     else if (num == 2)
     {
          in_stream.open("list-2-adj.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     } 
     else if (num == 3)
     {
          in_stream.open("list-3-noun.txt");
          if (in_stream.fail())
          {
             cout << "Error opening input file.\n";
             exit(1);
          }
     } 
     else
         cout << "Invalid list selected, please choose list 1,2 or 3\n";
     
     //show the whole contents of the file
     cout << "\n";
     while (! in_stream.eof())
     { 
           in_stream >> string_from_file;
           if (string_from_file != last_string)
              cout << "\t\t\t - " << string_from_file << "\n";
           string_from_file = last_string;
     }
     
     //close the input file
     in_stream.close();
     cout << endl;
     system("pause");
}

void initialise()
{
  //seed the random number generator using the current time
  srand ( time(NULL) );
}

void list_make()
{
     ifstream in_stream1, in_stream2, in_stream3;
     string list1[20],
            list2[20],
            list3[20];
     string phrase;
     int    list1_count = 0, list2_count = 0, list3_count = 0;
     int    list1_random, list2_random, list3_random;
         
     //open the three files ready to be read into an array
     //File 1
     in_stream1.open("list-1-adj.txt");
     if (in_stream1.fail())
     {
        cout << "Error opening input file.\n";
        exit(1);
     }
     //File 2
     in_stream2.open("list-2-adj.txt");
     if (in_stream2.fail())
     {
        cout << "Error opening input file.\n";
        exit(1);
     }
     //File 3
     in_stream3.open("list-3-noun.txt");
     if (in_stream3.fail())
     {
        cout << "Error opening input file.\n";
        exit(1);
     }
     
     //read the files into an array      
     //File 1
     while (! in_stream1.eof())
     { 
          in_stream1 >> list1[list1_count];
          list1_count++;
     }
     //File 2
     while (! in_stream2.eof())
     { 
          in_stream2 >> list2[list2_count];
          list2_count++;
     }
     //File 3
     while (! in_stream3.eof())
     { 
          in_stream3 >> list3[list3_count];
          list3_count++;
     }
        
     //Close input files
     in_stream1.close();
     in_stream2.close();
     in_stream3.close();

     //choose a random array element
     list1_random = rand() % list1_count + 0;
     list2_random = rand() % list2_count + 0;
     list3_random = rand() % list3_count + 0;

     phrase = list1[list1_random] + " " + list2[list2_random] + " " + list3[list3_random];
     cout << "\t" << phrase << endl;
}


