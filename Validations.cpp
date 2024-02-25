/* Project 1: 12 and 24 Hour Clock
 * 1/25/24
 * Kaitlyn DiCesare
 * File 2/4: Validation Functions
 */

#include <iostream> //Input/output stream access
#include <string> //Allows access to string library
#include <iomanip> //Allows access to input/output formatting
#include "Header.h" //Integrates header file
using namespace std; //For access to the standard library

void SetHour(int new_hour) //Print function determines validity of user's entry for hour
{

	if (new_hour < 0) //If hour entry is negative
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit

	}
	if (new_hour >= 13) //If hour entry is greater than 13
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit
	}
	else //If the input is valid
	{
		cout << "Valid response." << endl;
	}

}


void SetMinute(int new_minute) //allows user to set time and controls user's entries
{

	if (new_minute < 0) //If minute entry is negative
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit

	}
	if (new_minute > 59) //If hour entry is greater than 59
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit
	}
	else //If the input is valid
	{
		cout << "Valid response." << endl;
	}


}


void SetSecond(int new_second) //allows user to set time and controls user's entries
{

	if (new_second < 0) //If second entry is negative
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit

	}
	if (new_second > 59) //If second entry is greater than 59
	{
		cout << "Invalid, please try again." << endl;
		exit(0); //Exit
		 
	}
	else //If the input is valid
	{
		cout << "Valid response." << endl;
	}

}

void AMor_pm(string word) //Void function for checking user's AM/PM entry validity
{
	if (word == "am" || word == "AM" || word == "pm" || word == "PM") //If the input is valid
	{
		cout << "Valid response." << endl; //Print info
	}
	else //If entry is not valid
	{
		cout << "Invalid, please try again." << endl; //Print info
		exit(0); //Exit
	}
}


string Val_Det_Hour_AMorPM(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 12 && (ampm_value == "am" || ampm_value == "AM")) //Conversion from AM to PM
	{
		ampm_value = "PM";
	}

	else if (hour == 12 && (ampm_value == "pm" || ampm_value == "PM")) //Conversion from PM to AM
	{
		ampm_value = "AM";
	}

	return ampm_value; //Return string value

}


int Val_Det_Hour_Update(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 13 && (ampm_value == "am" || ampm_value == "AM")) //Converting from 12 AM to 1 AM
	{
		hour = 1;
	}

	else if (hour == 13 && (ampm_value == "pm" || ampm_value == "PM")) //Converting from 12 PM to 1 PM
	{
		hour = 1;
	}

	return hour; //Return integer value

}


int Val_Det_Minute_Update(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 13 && (ampm_value == "am" || ampm_value == "AM")) //Converting from 12 AM to 1 AM
	{
		hour = 1;
	}

	if (hour == 13 && (ampm_value == "pm" || ampm_value == "PM")) //Converting from 12 PM to 1 PM
	{
		hour = 1;
	}

	return hour; //Return integer value

}


string Val_Det_Minute_AMorPM(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 12 && minute == 0 && (ampm_value == "pm" || ampm_value == "pm")) //Conversion from AM to PM
	{
		ampm_value = "AM";
	}

	else if (hour == 12 && minute == 0 && (ampm_value == "am" || ampm_value == "am")) //Conversion from PM to AM
	{
		ampm_value = "PM";
	}

	return ampm_value; //Return string value

}


int Val_Det_Second_Update(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 13 && (ampm_value == "am" || ampm_value == "AM")) //Converting from 12 AM to 1 AM
	{
		hour = 1;
	}

	if (hour == 13 && (ampm_value == "pm" || ampm_value == "PM")) //Converting from 12 PM to 1 PM
	{
		hour = 1;
	}

	return hour; //Return integer value

}

string Val_Det_Second_AMorPM(int hour, int minute, int second, string ampm_value) //String for determining validity of user's time after increasing hour value
{

	if (hour == 12 && minute == 0 && second == 0 && (ampm_value == "am" || ampm_value == "AM")) //Conversion from AM to PM
	{
		ampm_value = "PM";
	}

	else if (hour == 12 && second == 0 && (ampm_value == "pm" || ampm_value == "PM")) //Conversion from PM to AM
	{
		ampm_value = "AM";
	}

	return ampm_value; //Return string value
}

