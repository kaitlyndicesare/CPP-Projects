/* Project 1: 12 and 24 Hour Clock
 * 1/25/24
 * Kaitlyn DiCesare
 * File 4/4: Header file
 */

#ifndef Functions_H //Header guard
#define Functions_H //Header guard

using namespace std; //For access to the standard library

string Val_Det_Hour_AMorPM(int hour, int minute, int second, string amorpm); //Function for determining validity of user's time after increasing hour value
string Val_Det_Minute_AMorPM(int hour, int minute, int second, string amorpm); //Function for determining validity of user's time after increasing hour value
string Val_Det_Second_AMorPM(int hour, int minute, int second, string amorpm); //Function for determining validity of user's time after increasing hour value
int Val_Det_Hour_Update(int hour, int minute, int second, string amorpm); //Function for determining validity of user's time after increasing hour value
int Val_Det_Minute_Update(int hour, int minute, int second, string amorpm); //Function for determining validity of user's time after increasing hour value
int Val_Det_Second_Update(int hour, int minute, int second, string amorpm); // Function for determining validity of user's time after increasing hour value
void SetHour(int hour); //Void function for checking user's hour entry validity
void SetMinute(int minute); //Void function for checking user's minute entry validity
void SetSecond(int second); //Void function for checking user's second entry validity
void AMor_pm(string time_designation); //Void function for checking user's AM/PM entry validity
void ClockDisplay(int hour, int minute, int second, string amorpm); //Print function for displaying clock

#endif //End Header guard