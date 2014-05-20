/* ----------------------------------------------------------------------------
Author:              Chad Duffey 
Contact:             chadduffey@hotmail.com

Date Created:        19th March 2010
Last Modification:

Program Description: Program to generate Jargon using three lists of words
File Description:    Function declarations and constants.
*/// --------------------------------------------------------------------------

//constant definitions


//function definitions

//--main_menu function
//No values passed in or returned, used to set up main menu screen
//Screen formatting function only
void main_menu();

//--bad_choice function
//If user types menu item that dosnt exist or bad syntax they are 
//directed to the bad choice function to let them know
//No values passed in or retured, screen formatting function only
void bad_choice();

//--add_function
//used to add words to the lists
//accepts the list that is to be modified as an argument
void add_entry(int);

//--delete_function
//used to remove words from a word list
//accepts the list to be modified as an input
void delete_entry(int);

//--list_make function
//creates random word lists for the user
//accepts to inputs
void list_make ();

//--show_list function
//takes in one integer value to decide which list to display
void show_list(int);

//quit_application command
//used to display exit message only
//screen formatting only
void quit_application();

//initialise function
//Used to Prepare Random Number generation using time as the seed
void initialise();





 
