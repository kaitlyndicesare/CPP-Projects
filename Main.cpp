/* Project 1: 12 and 24 Hour Clock
 * 1/25/24
 * Kaitlyn DiCesare
 * File 1/4: Main File
 */

#include <iostream> //Input/output stream access
#include <string> //Allows access to string library
#include <iomanip> //Allows access to input/output formatting
#include "Header.h" //Integrates header file
using namespace std; //For access to the standard library


void CallMenu() //Void function for menu
{
	cout << endl;
	cout << "           MENU       " << endl;
	cout << "**************************" << endl;
	cout << "* ";
	cout << "1 - Add One Hour"; //Selection 1 adds an hour
	cout << "       *" << endl;
	cout << endl;
	cout << "* ";
	cout << "2 - Add One Minute"; //Selection 2 adds a minute
	cout << "     *" << endl;
	cout << endl;
	cout << "* ";
	cout << "3 - Add One Second"; //Selection 3 adds a second
	cout << "     *" << endl;
	cout << endl;
	cout << "* ";
	cout << "4 - Exit Program"; //Selection 4 exits the program
	cout << "       *" << endl;
	cout << "**************************" << endl;

	cout << endl;

}


int main() { //Begins the program
	int hour = 0; //Declare and initialize variable
	int minute = 0; //Declare and initialize variable
	int second = 0; //Declare and initialize variable
	int validation_check = 0; //Declare and initialize variable
	int validation_check_2 = 0; //Declare and initialize variable
	int validation_check_3 = 0; //Declare and initialize variable
	int menu_choice = 0;//Declare and initialize variable
	bool control = true; //Declare and initialize variable
	string am_or_pm = ""; //Declare and initialize variable
	string menu_choice2 = ""; //Declare and initialize variable


	cout << "Welcome to the clock app." << endl;
	cout << "Set your hour value: " << endl;
	cin >> hour; //Accept user input for hour, store value
	SetHour(hour); //Call function to determine if user data is valid

	cout << "Set your minute value: " << endl;
	cin >> minute; //Accept user input for hour, store value
	SetMinute(minute); //Call function to determine if user data is valid

	cout << "Set your second value: " << endl;
	cin >> second; //Accept user input for hour, store value
	SetSecond(second); //Call function to determine if user data is valid

	cout << "AM or PM?" << endl;
	cin >> am_or_pm; //Accept user input for hour, store value
	AMor_pm(am_or_pm); //Call function to determine if user data is valid

	ClockDisplay(hour, minute, second, am_or_pm); //Display both 12 and 24 hour clocks

	cout << endl << endl;


	while (control) //Loop controls functionality for user's loop choices
	{

		CallMenu(); //Use function to call menu

		cout << "Please choose an option from the menu: " << endl;
		cin >> menu_choice; //Accept user input for hour, store value for menu choice

		if (menu_choice == 1) //Decision branching for menu choice, add one hour is option 1
		{
			hour += 1; //Important math: each time the branch is entered, +1 to hour is added

			cout << endl;
			cout << "Your new time is: " << endl; //Output: lets user know that a new time will be displayed
			cout << endl;

			hour = Val_Det_Hour_Update(hour, minute, second, am_or_pm); //Call function to check validations for hour

			am_or_pm = Val_Det_Hour_AMorPM(hour, minute, second, am_or_pm); //Call function to check validations for AM vs PM

			ClockDisplay(hour, minute, second, am_or_pm); //Display clock if valid
			
		}


		if (menu_choice == 2) //Menu choice is 2, which is add a minute to the time
		{
			minute += 1; //+1 added to variable minute when entering branch
			cout << endl;
			cout << "Your new time is: " << endl; //Output: lets user know that a new time will be displayed
			cout << endl;

			if (minute == 60) //If minute is 60, change other values accordingly
			{
				hour += 1;
				minute = 0;

			}

			hour = Val_Det_Minute_Update(hour, minute, second, am_or_pm); //Call function to check validations for hour

			am_or_pm = Val_Det_Minute_AMorPM(hour, minute, second, am_or_pm); //Call function to check validations for AM vs PM

			ClockDisplay(hour, minute, second, am_or_pm); //Display clock if valid

		}

		if (menu_choice == 3) //Menu choice is 3, which adds +1 to second value
		{
			second += 1; //+1 added to variable second when branch is entered
			cout << endl;
			cout << "Your new time is: " << endl; //Output: lets user know that a new time will be displayed
			cout << endl;

			if (second == 60) //If second is 60, change other values accordingly
			{
				minute += 1;
				second = 0;

				if (minute == 60) //If minute is 60, change other values accordingly
				{
					hour += 1;
					minute = 0;
					second = 0;
				}
			}

			hour = Val_Det_Second_Update(hour, minute, second, am_or_pm); //Call function to check validations for hour
			 
			am_or_pm = Val_Det_Second_AMorPM(hour, minute, second, am_or_pm); //Call function to check validations for AM vs PM

			ClockDisplay(hour, minute, second, am_or_pm); //Display clock if valid
			
		}

		if (menu_choice == 4) //Menu choice 4 allows user to exit
		{
			cout << "Are you sure you want to exit?  Type yes or no." << endl;
			cin >> menu_choice2; //Choice 2 allows for user to input string to declare choice

			if (menu_choice2 == "yes" || menu_choice2 == "YES" || menu_choice2 == "Yes") //If string is yes, then...
			{
				control = false; // Loop will not continue because control becomes false
			}
		}

	}

	return 0; //Ends program
}
