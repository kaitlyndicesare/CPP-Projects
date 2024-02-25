/* Project 1: 12 and 24 Hour Clock
 * 1/25/24
 * Kaitlyn DiCesare
 * File 3/4: Clock Display
 */


#include <iostream> //Input/output stream access
#include <string> //Allows access to string library
#include <iomanip> //Allows access to input/output formatting
#include "Header.h" //Integrates header file
using namespace std; //For access to the standard library


void ClockDisplay(int hour, int minute, int second, string ampm) // Void function for printing info, accepts all time parameters
{

	cout << endl << endl;

	// First line of clock display
	cout << "**************************" << "   " << "**************************" << endl;

	//Second line of clock display
	cout << "*" << "     12-Hour Clock" << "      *" << "   " << "*" << "      24-Hour Clock" << "     *" << endl;

	//Third line of clock display
	cout << endl;

	//Fourth line of clock display
	cout << "*      ";

	//---> 12 hour clock display
	// Decision branching determines how the clock will display output
	if (hour > 9) //If number is greater than 9, displayed full value w/ colon
	{
		cout << hour << ":";
	}
	else
	{
		cout << setfill('0') << setw(2) << hour << ":"; //If number is less than 0, set fill allows for a 0 to be added
	}

	if (minute > 9) //If number is greater than 9, displayed full value w/ colon
	{
		cout << minute << ":";
	}
	else
	{
		cout << setfill('0') << setw(2) << minute << ":"; //If number is less than 0, set fill allows for a 0 to be added
	}

	if (second > 9) //If number is greater than 9, displayed full value w/ colon
	{
		cout << second;
	}
	else
	{
		cout << setfill('0') << setw(2) << second; //If number is less than 0, set fill allows for a 0 to be added
	}

	cout << " " << ampm; //Prints am or pm user input
	cout << "       *";



	//---> 24 hour clock display
	//12 to 24 hour clock conversion
	if (hour == 12 && (ampm == "am" || ampm == "AM"))
	{
		hour = 0; //Converts 12 AM to 0
	}

	if (ampm == "pm" || ampm == "PM") {

		if (hour == 1) //Converts 1 PM to 13
		{
			hour = 13;
		}
		else if (hour == 2) //Converts 2 PM to 14
		{
			hour = 14;
		}
		else if (hour == 3) //Converts 3 PM to 15
		{
			hour = 15;
		}
		else if (hour == 4) //Converts 4 PM to 16
		{
			hour = 16;
		}
		else if (hour == 5) //Converts 5 PM to 17
		{
			hour= 17;
		}
		else if (hour == 6) //Converts 6 PM to 18
		{
			hour = 18;
		}
		else if (hour == 7) //Converts 7 PM to 19
		{
			hour = 19;
		}
		else if (hour == 8) //Converts 8 PM to 20
		{
			hour = 20;
		}
		else if (hour == 9) //Converts 9 PM to 21
		{
			hour = 21;
		}
		else if (hour == 10) //Converts 10 PM to 22
		{
			hour = 22;
		}
		else if (hour == 11) //Converts 11 PM to 23
		{
			hour = 23;
		}
		else if (hour == 12 && (ampm == "pm" || ampm == "PM")) //Converts 12 PM to 12
		{
			hour = 12;
		}
		else if (hour == 12 && (ampm == "am" || ampm == "AM")) //Converts 12 AM to 24
		{
			hour = 24;
		}

	}

	cout << "   *        ";

	if (hour > 9) // If number is greater than 9, displayed full value
	{
		cout << hour << ":";
	}
	else
	{
		cout << setfill('0') << setw(2) << hour << ":"; //If number is less than 0, set fill allows for a 0 to be added
	}

	if (minute > 9) // If number is greater than 9, displayed full value
	{
		cout << minute << ":";
	}
	else
	{
		cout << setfill('0') << setw(2) << minute << ":"; //If number is less than 0, set fill allows for a 0 to be added
	}

	if (second > 9) // If number is greater than 9, displayed full value
	{
		cout << second;
	}
	else
	{
		cout << setfill('0') << setw(2) << second; //If number is less than 0, set fill allows for a 0 to be added
	}

	cout << "        *" << endl;


	//Fifth line of clock display
	cout << "**************************" << "   " << "**************************" << endl;

}