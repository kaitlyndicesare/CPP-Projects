/* Project 2: Corner Grocer
 * 2/24/24
 * Kaitlyn DiCesare
 * File 3/3: Header
 */

#ifndef Functions_H //Header guard
#define Functions_H //Header guard

#include <string> //Allows access to string library
#include <vector> //Allows access to vector library
using namespace std; //For access to standard library

class Corner_Grocer //Class
{
public: //Public member functions/function declarations
    Corner_Grocer(); //Constructor
    int FileImport(); //Mutator: imports information from .txt file
    void PrintMenu(); //Mutator: prints menu options, calls menuChoice
    int MenuChoice(); //Mutator: allows user to choose input
    void SetLowercaseItemName(string item_Name); //Mutator: gets user input and makes it lowercase
    string GetItemName() const; //Accessor: get item value
    void SetUserInput(string user_input); //Mutator: sets user input
    string GetUserInput() const; //Accessor: gets user input
    void CreateVector(string the_vector); //Mutator: create main vector that holds all values from import
    void CreateTableOfContents(); //Mutator: creates table of contents vector
    void SearchMainVector(); //Mutator: searches main vector using the table of contents vector
    void SearchVectorForFrequency(); //Mutator: searches main vector for user input value
    void CreateHistogram(); //Mutator: creates histogram
    int ExportFile(); //Mutator: export information to dat file


private: //Private data members
    unsigned int i; //Nonnegative number controls loop flow
    unsigned int k; //Nonnegative number controls loop flow
    unsigned int p; //Nonnegative number controls loop flow
    unsigned int l; //Nonnegative number controls loop flow
    unsigned int g; //Nonnegative number controls loop flow
    unsigned int q; //Nonnegative number controls loop flow
    int userChoice; //User input controls menu
    string theitemName; //Transferred variable for access in class functions: part of lowercase/uppercase process for user input
    string usersearchItem; //Transfer user search variable: search term input
    string userItem; //User input: stores user input
    string vectorValue; //Transfer variable for access to class functions: variable becomes part of main vector
    string firstVariable; //Variable value 0 for making table of contents vector
    string searchedVariable; //Variable used to search through table of contents vector
    string transitionVariable; //Variable is used for searches and adding values to vectors
    string itemName; //Variable used to help import values from .txt file
    vector <string> tableofContents; //Table of contents vector: provides a searching tool with only 1 value of each item from the imported list
    vector <string>::iterator iterationVariable; //Iteration search variable
    vector <string> mainVector; //Main vector with entire contents of imported file
    vector <string> exportString; //Secondary vector used to store string values for exporting
    vector <int>  exportInt; //Tertiary vector used to store int values for exporting
};

#endif //End Header guard