/* Project 2: Corner Grocer
 * 2/24/24
 * Kaitlyn DiCesare
 * File 2/3: Declarations
 */

#include <iostream> //Allows access to input/output stream
#include <iomanip> //Allows access to output library
#include <string> //Allows access to string library
#include <vector> //Allows access to vector library
#include <fstream> //Allows access to files library
#include <cctype> //Allows access to character library
#include <algorithm> //Allows access to algorithm library
#include "Header.h"  //Integrates header file
using namespace std; //For access to standard library

Corner_Grocer::Corner_Grocer() { //Constructor
    unsigned int i = 0; //Initialize variable
    unsigned int k = 0; //Initialize variable
    unsigned int p = 0; //Initialize variable
    unsigned int l = 0; //Initialize variable
    unsigned int g = 0; //Initialize variable
    unsigned int q = 0;//Initialize variable
    int userChoice = 0; //Initialize variable
    string theitemName = ""; //Initialize variable
    string usersearchItem = ""; //Initialize variable
    string userItem = ""; //Initialize variable
    string vectorValue = ""; //Initialize variable
    string firstVariable = ""; //Initialize variable
    string searchedVariable = ""; //Initialize variable
    string transitionVariable = ""; //Initialize variable
    string itemName = ""; //Initialize variable
}

int Corner_Grocer::FileImport() //Imports .txt file
{
    ifstream inFS; //Input file stream

    inFS.open("Grocery_List.txt"); //Open required file for reading
    if (!inFS.is_open()) { //Attempt to open file
        cout << "Could not open the selected file." << endl;
        return 1; //Creates error
    }

    while (!inFS.eof()) { //Loop moves through file ends
        inFS >> itemName; //Read value from file

        if (!inFS.fail()) { //Continues if the file doesn't fail
            CreateVector(itemName); //Calls function to add values to vector
        }
    }

    inFS.close(); //Close file
}

void Corner_Grocer::PrintMenu() { //Print main menu

    userChoice = 0; //Initialize variable at beginning of function to clear input

    system("Color 02"); //Change console color green

    //Print menu options
    cout << "\n[ C O R N E R  G R O C E R ]" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Display frequency for a specific item" << endl;
    cout << "2. Display a list of all items and their frequencies" << endl;
    cout << "3. Display histogram of all items" << endl;
    cout << "4. Exit Application" << endl;
    cout << "Please enter your selection as a number 1-4:" << endl;


    try //Try/catch loop for user input
    {
        cin >> userChoice;  //Accept input
        cout << endl;

        if (!cin) //If input has error
        {
            cout << endl;
            throw runtime_error("Invalid value"); //Create runtime error and generator message
        }
    }
    catch (runtime_error& excpt) //Catch runtime error and exceptions
    {
        cout << excpt.what() << endl; //Print error message

        cin.clear(); //Clear input
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore until the end of input

    }

    MenuChoice(); //Call menu choice function
}

int Corner_Grocer::MenuChoice() //Print menu choices
{
    if (userChoice == 1) //First menu requirement
    {
        cout << "Please enter the name of the item you are searching for: " << endl; //Print info
        cin >> userItem;  //Accept input
        transform(userItem.begin(), userItem.end(), userItem.begin(), ::tolower); //Make lowercase
        userItem[0] = toupper(userItem[0]); //Uppercase first digit only
        SetUserInput(userItem); //Set value in mutator
        SearchVectorForFrequency(); //Search main vector for frequency
        PrintMenu(); //Print menu
    }
    else if (userChoice == 2) //Second menu requirement
    {
        CreateTableOfContents(); //Call function to create table of contents
        SearchMainVector(); //Search vector using table of contents
        PrintMenu(); //Print menu
    }
    else if (userChoice == 3) //Third menu requirement
    {
        CreateTableOfContents(); //Call function to create table of contents
        SearchMainVector();
        CreateHistogram(); //Creates histogram
        PrintMenu(); //Print menu
    }
    else if (userChoice == 4) //Exiting program menu option
    {
        cout << "Terminating program..." << endl; //Print info
        exit(1); //Exit program
    }
    else //Catches invalid input
    {
        cout << "Not a valid menu choice.  Please try again." << endl; //Print info
        PrintMenu(); //Calls function to print menu again
    }
}

int Corner_Grocer::ExportFile() //Export file occurs at start of program
{
    ofstream outFS; //Output file stream

    outFS.open("frequency.dat"); //Open file for writing

    if (!outFS.is_open()) { //Catch for if the file cannot be opened
        cout << "Could not open the selected file." << endl;
        return 1;//Creates error
    }

    for (g = 0; g < exportString.size(); g++) //Loop iterates through vector size
    {
        outFS << exportString.at(g) << " " << exportInt.at(g) << endl; //Output to file
    }

    cout << "[ ----> Backup file created. ]" << endl; //Print info

    outFS.close(); //Close file
}


void Corner_Grocer::CreateVector(string the_vector) //Mutator: creates main vector
{
    vectorValue = the_vector;

    mainVector.push_back(vectorValue); //Main vector creation
}

void Corner_Grocer::SetLowercaseItemName(string item_Name) //Mutator that converts value to lowercase
{
    theitemName = item_Name;

    transform(theitemName.begin(), theitemName.end(), theitemName.begin(), ::tolower); //Lowercase conversion
}

string Corner_Grocer::GetItemName() const //Accessor: returns variable value
{
    return theitemName;
}

void Corner_Grocer::SetUserInput(string user_input) //Mutator: sets variable value
{
    usersearchItem = user_input;
}

string Corner_Grocer::GetUserInput() const //Accessor: returns variable value
{
    return usersearchItem;
}

void Corner_Grocer::SearchVectorForFrequency() //Mutator: searches main vector for frequency of user input
{
    g = 0; //Initialize variable
    k = 0; //Initialize variable

    sort(mainVector.begin(), mainVector.end()); //Sort function is essential for this to work

    for (i = 0; i < mainVector.size(); i++) //Iterate through main loop
    {
        if (usersearchItem == mainVector.at(i)) //If user input is equal to vector value
        {
            g++; //Add one to counter value
        }
        else if (usersearchItem != mainVector.at(i)) //If user input is not equal to vector value
        {
            k++; //Add one to counter value
        }
    }

    if (k >= mainVector.size()) //Print information only if k is not found
    {
        cout << "Item not found or invalid search item." << endl;
    }
    else //Print frequency information otherwise
    {
        cout << endl;
        cout << "[ Your item " << usersearchItem << " was found " << g << " times. ]" << endl;
    }
}

void Corner_Grocer::CreateTableOfContents() //Mutator: create table of contents vector
{
    tableofContents.clear(); //Clear vector to begin function

    sort(mainVector.begin(), mainVector.end()); //Sort vector is important

    firstVariable = mainVector.at(0); //Declare variable, first value of main vector
    tableofContents.push_back(firstVariable); //Push value into vector

    for (p = 0; p < mainVector.size(); p++) //Iterate through vector using loop
    {
        searchedVariable = mainVector.at(p); //Create variable to store main vector variables in

        iterationVariable = find(tableofContents.begin(), tableofContents.end(), searchedVariable); //Use find...
        //...to determine if value from main vector is in table of contents

        if (iterationVariable != tableofContents.end()) { //If main vector value is found in table of contents vector, do nothing
            //Block empty
        }
        else {
            tableofContents.push_back(searchedVariable); //If value is not found, add to table of contents
        }
    }
}

void Corner_Grocer::SearchMainVector() //Mutator: search main vector using table of contents with print
{
    exportString.clear(); //Clear export vector
    exportInt.clear(); //Clear export vector

    for (p = 0; p < tableofContents.size(); p++) //For loop iterates through vector
    {
        transitionVariable = tableofContents.at(p); //Store first value from table of contents in variable

        q = 0; //Make sure q resets to 0

        for (l = 0; l < mainVector.size(); l++) //Second for loop iterates through main vector
        {
            if (transitionVariable == mainVector.at(l)) //If table of contents value is in main vector
            {
                q++; //Add to count variable
            }
        }

        if (userChoice == 2) //If user choice from menu equals 2
        {
            cout << transitionVariable << " " << q << endl; //Print info
        }

        exportString.push_back(transitionVariable); //Add value to export vector
        exportInt.push_back(q); //Add value to export vector
    }
}

void Corner_Grocer::CreateHistogram() //Mutator: creates histogram
{
    string rawr = "*"; //Declare and initialize string variable, only used in this function

    for (p = 0; p < tableofContents.size(); p++) //For loop iterates through vector
    {
        transitionVariable = tableofContents.at(p); //Store first value from table of contents in variable

        q = 0;

        for (l = 0; l < mainVector.size(); l++) //Second for loop iterates through main vector
        {
            if (transitionVariable == mainVector.at(l)) //If table of contents value is in main vector
            {
                q++; //Add to count variable

            }
        }

        cout << transitionVariable << " "; //Print info

        for (k = 0; k < q; k++) //If k is less than the count variable
        {
            cout << "*"; //Print info
        }

        cout << endl;
    }
}
