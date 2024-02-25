/* Project 2: AirGead Baking
 * 2/10/24
 * Kaitlyn DiCesare
 * File 1/3: Main
 */

#include <iostream> //Allows access to input/output stream
#include <iomanip> //Allows access to output library
#include "Header.h" //Integrates header file
using namespace std; //For access to standard library

int main() //Start program
{
	Bank instance1; //Instantiate class object
	unsigned int i; //Declare and initialize variable
	unsigned int loopMenu = 100; //Declare and initialize variable
	double interesttotalwithDeposit = 0; //Declare and initialize variable
	double interesttotalwithoutDeposit = 0; //Declare and initialize variable
	double investmentYears = 0; //Declare and initialize variable
	double numMonths = 0; //Declare and initialize variable
	double valueInvestment = 0; //Declare and initialize variable
	double valueInvestment_2 = 0; //Declare and initialize variable
	double valueMonthly = 0; //Declare and initialize variable
	double interestwithDeposit = 0; //Declare and initialize variable
	double interestwihoutDeposit = 0; //Declare and initialize variable
	double totaluserInput = 0; //Declare and initialize variable
	double finalBalance = 0; //Declare and initialize variable
	double finalbalanceafterLoop = 0; //Declare and initialize variable
	double finalbalanceAfterFirst = 0; //Declare and initialize variable
	int menuValue = 0; //Declare and initialize variable


	while (loopMenu != 0) //While loop to control input through menu system
	{
		instance1.UserSetInitialInvestment(); //Using object to call class function for input of initial investment value
		instance1.UserSetMonthlyDeposit(); //Using object to call class function for input of initial monthly deposit value
		instance1.UserSetInterest(); //Using object to call class function for input of interest value
		instance1.UserSetYear(); //Using object to call class function for input of year valuw

		valueInvestment = instance1.GetInvestment(); //Using object to get investment value for math below
		valueInvestment_2 = instance1.GetInvestment(); //Using object to get unmanipulated investment value for math below
		valueMonthly = instance1.GetMonthlyDeposit(); //Using object to get monthly deposit value for math below
		numMonths = instance1.calculateMonths(); //Using object to get month value (from year) for math below
		investmentYears = instance1.GetUserYears(); //Using object to get year value for math below

		for (i = 1; i <= numMonths; i++) //Loops through based on the month calculation from years
		{
			instance1.SetInitialInvestment(valueInvestment); //Uses object to set updated investment value into class function (updated at bottom of loop)

			totaluserInput = instance1.totalAmount(valueInvestment, valueMonthly); //Gets total value (initial + monthly)

			interestwithDeposit = instance1.CalculatedInterestWithDeposit(valueInvestment, valueMonthly); //Gets calculated interest value (with monthly deposit)
			
			interesttotalwithDeposit = interestwithDeposit + interesttotalwithDeposit; //Calculates accruing interest

			finalBalance = interestwithDeposit + totaluserInput; //Calculates final balance (interest + total amount)
			instance1.SetFinalBalance(finalBalance); //Uses object to set value into function for later access

			if (i % 12 == 0) //If the month value is a multiple of 12
			{
				interestwihoutDeposit = instance1.CalculatedInterestWithoutDeposit(valueInvestment_2); //Gets fresh interest value

				interesttotalwithoutDeposit = valueInvestment_2 + interestwihoutDeposit; //Calculates interest with no deppsit

				instance1.vector_balance_without_deposit(interestwihoutDeposit); //Adds value to vector

				instance1.vector_interest_without_deposit(interesttotalwithoutDeposit); //Adds value to vector

				valueInvestment_2 = interesttotalwithoutDeposit; //Updates value after calculations are complete

				instance1.VectorYear(investmentYears); //Sets year value for vector control (pulled from unmanipulated user entry)

				instance1.vector_balance_with_deposit(finalBalance); //Adds value to vector

				if (i == 12) //For the first year
				{
					instance1.vector_interest_with_deposit(interesttotalwithDeposit); //Assigns value in vector

					interesttotalwithDeposit = 0; //Sets value to 0 to reset for additional user entry in the future (if loop is continued)
				}
				else //For other years
				{
					finalbalanceAfterFirst = (finalBalance - finalbalanceafterLoop) - (valueMonthly * 12); //Perform math to subtract yearly calculated interest value

					instance1.vector_interest_with_deposit(finalbalanceAfterFirst); //Adds value to vector
				}

			}

			valueInvestment = finalBalance; //Sets investment value after loop, because math accumulates

			if (i % 12 == 0) //Pulls original final value for math
			{
				finalbalanceafterLoop = instance1.GetFinalBalance(); //Uses object to call accessor
			}
		}

		instance1.PrintNoDepositTable(); //Call function to print values with no deposit
		cout << endl;
		instance1.PrintMonthlyDepositTable(); //Call function to print values with deposit

		instance1.SetMenuOption(); //Call function to  get loop menu

		menuValue = instance1.GetMenuOption(); //Get menu option value

		if (menuValue == 1) //If menu option is 1...
		{
			interesttotalwithDeposit = 0; //clear value for first year interest
		}
		if (menuValue == 2)
		{
			loopMenu = 0;
			cout << "Program exit." << endl;
		}
	}

	return 0; //End program
}