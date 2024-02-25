/* Project 2: AirGead Baking
 * 2/10/24
 * Kaitlyn DiCesare
 * File 3/3: Header
 */

#ifndef Functions_H //Header guard
#define Functions_H //Header guard

#include <vector> //Allows access to vector library

using namespace std; //For access to the standard library

class Bank //Class
{
public: //Public member functions/function declarations
	Bank(); //Constructor
	void UserSetInitialInvestment(); //Mutator: User input for initial investment amount
	void SetInitialInvestment(double t_investment); //Mutator: User input set for math in main
	double GetInvestment() const; //Accessor: gets initial investment value
	void UserSetMonthlyDeposit(); //Mutator: user input monthly deposit
	double GetMonthlyDeposit() const; //Accessor: get monthly deposit value
	void UserSetInterest(); //Mutator: set interest value
	void UserSetYear(); //Mutator: set year value
	double GetUserYears() const; //Accessor: get year value
	double calculateMonths(); //Mutator: calculate months from years
	double totalAmount(double t_initial, double t_monthly); //Mutator: calculates total from initial investment + monthly deposit
	double CalculatedInterestWithDeposit(double t_initial, double t_monthly); //Mutator: calculates interest with monthly deposit
	double CalculatedInterestWithoutDeposit(double t_initialValue); //Mutator: calculates interest without monthly deposit
	void SetFinalBalance(double t_final); //Mutator: set final balance from interest + total amount
	double GetFinalBalance() const; //Accessor: get final balance value
	void SetFinalBalanceWithoutDeposit(double t_finalValue); //Mutator: set final balance (math in main)
	double GetFinalBalanceWithoutDeposit() const; //Accessor: get final balance with monthly deposit
	void VectorYear(double t_newYear); //Accessor: allows variable access and controls vector loops
	void vector_balance_with_deposit(double t_vector_balance); //Accessor: vector input for year end balance with deposit
	void vector_interest_with_deposit(double t_vector_interest); //Accessor: vector for year end interest with deposit
	void vector_balance_without_deposit(double t_vector_no_deposit_balance); //Accessor: vector for year end balance without deposit
	void vector_interest_without_deposit(double t_vector_no_deposit_interest); //Accessor: vector for year end balance without deposit
	void SetMenuOption(); //Accessor: sets menu option from input
	int GetMenuOption(); //Mutator: gets variable
	void PrintNoDepositTable(); //Mutator: print table without monthly deposit
	void PrintMonthlyDepositTable(); //Mutator: print table with monthly deposit

private: //Private data members
	bool loopTest; //While loop control variable for try/catch user input
	double m_inputinitialInvestment; //User input variable
	double m_setinitialInvestment; //Transferring variable for access in class functions 
	double m_inputmonthlyDeposit; //User input variable
	double m_setmonthlyDeposit; //Transferring variable for access in class functions
	double m_inputuserInterest; //User input variable
	double m_setInterest; //Transferring variable for access in class functions
	double m_inputinvestmentYears; //User input variable
	double m_setYears; //Transferring variable for access in class functions
	double m_calculatedMonths; //Years to month conversion variable
	double m_totalAmount; //Total amount variable (initial investment + monthly deposit)
	double m_calcinterestwithMonthly; //Calculated interest with monthly deposit
	double m_calcinterestwithoutMonthly; //Calculated interest without monthly deposit
	double m_finalbalancewithMonthly; //Final balance (with monthly deposit) calculated from interest + total amount
	double m_finalbalancewithoutMonthly; //Final balance (without monthly deposit) calculated from interest + total amount
	double m_yearcontrolVariable; //Vector control variable based on user input for year
	vector<double> m_year_end_balance_with_Deposit; //Vector for year end balance with deposit
	vector<double> m_year_end_balance_no_Deposit; //Vector for year end balance with no deposit
	vector<double> m_interest_no_Deposit; //Vector for interest with no deposit
	vector<double> m_interest_with_Deposit; //Vector for interest with deposit
	double m_vectordepositBalance; //Variable to input data into vector
	double m_vectordepositInterest; //Variable to input data into vector
	double m_vectorndBalance; //Variable to input balance with no deposit into vector
	double m_vectorndInterest; //Variable to input interest with no deposit into vector
	int menuChoice; //User input for menu value
	int usermenuValue; //Transferring variable for access in class functions
	int unsigned k; //Variable for loops
};

#endif //End Header guard
