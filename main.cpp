/* Project 1: Corner Grocer
 * 2/24/24
 * Kaitlyn DiCesare
 * File 1/3: Main
 */

#include "Header.h"  //Integrates header file
using namespace std; //For access to standard library

int main() //Begins program
{
    Corner_Grocer grocery_access; //Instantiate class object

    grocery_access.FileImport(); //Use object to call class function to import information from txt file

    grocery_access.CreateTableOfContents(); //Export file part 1: create table of contents
    grocery_access.SearchMainVector(); //Export file part 2: search vector
	grocery_access.ExportFile(); //Export file part 3: export file function

    grocery_access.PrintMenu(); //Use object to print menu information
	grocery_access.MenuChoice(); //Use object to call class that performs decision branching


    return 0; //Ends program
}