/* 

#include <iostream>
#include <iomanip>
#include <vector>
#include <iostream>
#include "header.h" //Integrates header file
	 using namespace std;

 Bank::Bank() { // constructor for each variable, all doubles, so set to -1
	 bool loop_test; //please see "header" file for comments about what each variable does
	 double m_user_initial_investment = -1;
	 double initial_investment = -1;
	 double t_monthly = -1;
	 double monthly_deposit = -1;
	 double user_interest = -1;
	 double set_interest = -1;
	 double investment_years = -1;
	 double set_years = -1;
	 double t_months = -1;
	 double calculated_months = -1;
	 double total_amt = -1;
	 double calc_interest = -1;
	 double final_balance = -1;
	 double new_balance_final = -1;
	 double calc_interest_not_monthly = -1;
	 double final_balance_not_monthly = -1;
	 double interest_2 = -1;
	 double the_year = -1;
	 double year_vector = -1;
	 double vector_deposit_balance = -1;
	 double vector_deposit_interest = -1;
	 double vector_ND_balance = -1;
	 double vector_ND_interest = -1;

 }


 void Bank::user_set_initialInvestment() //User sets initial investment amount
 {
	 loop_test = true;

	 while (loop_test)
	 {
		 try
		 {
			 cout << "Enter the initial investment amount: " << endl;
			 cin >> initial_investment;

			 if (!cin)
			 {
				 throw runtime_error("Invalid value");
			 }
			 else
			 {
				 loop_test = false;
			 }

		 }
		 catch (runtime_error& excpt)
		 {
			 cout << excpt.what() << endl;

			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');

		 }
	 }

	 m_user_initial_investment = initial_investment;
 }



 void Bank::set_initialInvestment(double investment) //Used to set investment amount for math
 {
	 m_user_initial_investment = investment;
 }


 double Bank::getInvestment() const
 {
	 return m_user_initial_investment;
 }

 void Bank::user_set_monthlyDeposit()
 {
	 loop_test = true;

	 while (loop_test)
	 {
		 try
		 {
			 cout << "Enter your monthly deposit amount: " << endl;
			 cin >> monthly_deposit;

			 if (!cin)
			 {
				 throw runtime_error("Invalid value");
			 }
			 else
			 {
				 loop_test = false;
			 }

		 }
		 catch (runtime_error& excpt)
		 {
			 cout << excpt.what() << endl;

			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');

		 }
	 }

	 t_monthly = monthly_deposit;
 }


 double Bank::get_monthlyDeposit() const
 {
	 return monthly_deposit;

 }

 void Bank::user_set_Interest()
 {
	 loop_test = true;

	 while (loop_test)
	 {
		 try
		 {
			 cout << "Enter your annual interest (percent): " << endl;
			 cin >> user_interest;

			 if (!cin)
			 {
				 throw runtime_error("Invalid value");
			 }
			 else
			 {
				 loop_test = false;
			 }

		 }
		 catch (runtime_error& excpt)
		 {
			 cout << excpt.what() << endl;

			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');

		 }
	 }

	 set_interest = user_interest;
 }

 void Bank::user_set_Year()
 {
	 loop_test = true;

	 while (loop_test)
	 {
		 try
		 {
			 cout << "Enter your number of years: " << endl;
			 cin >> investment_years;

			 if (!cin)
			 {
				 throw runtime_error("Invalid value");
			 }
			 else
			 {
				 loop_test = false;
			 }

		 }
		 catch (runtime_error& excpt)
		 {
			 cout << excpt.what() << endl;

			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');

		 }
	 }

	 set_years = investment_years;

 }

 double Bank::get_user_Years() const
 {
	 return set_years;
 }

 double Bank::calculateMonths()
 {
	 calculated_months = set_years * 12;

	 return calculated_months;
 }

 double Bank::getMonth() const
 {
	 return calculated_months;
 }


 double Bank::total_amount(double initial, double monthly)
 {
	 total_amt = m_user_initial_investment + t_monthly;

	 return total_amt;
 }


 double Bank::calculated_interest(double initial, double monthly)
 {
	 calc_interest = total_amt * ((set_interest / 100.0) / 12.0);

	 return calc_interest;
 }

 double Bank::calculated_interest_no_monthly(double initial_2)
 {
	 calc_interest_not_monthly = initial_2 * (set_interest / 100.0);

	 return calc_interest_not_monthly;
 }

 void Bank::set_final_balance(double final)
 {
	 final_balance = final;
 }

 void Bank::set_final_balance_no_monthly(double final_value)
 {
	 final_balance_not_monthly = final_value;
 }

 double Bank::get_final_balance() const
 {
	 return final_balance;
 }

 double Bank::get_final_balance_no_monthly() const
 {
	 return final_balance_not_monthly;
 }

 void Bank::set_new_final_balance(double new_final)
 {
	 new_balance_final = new_final;
 }

 double Bank::get_new_final_balance() const
 {
	 return new_balance_final;
 }

 void Bank::vector_year(double new_year)
 {
	 year_vector = new_year;
 }

 void Bank::vector_balance_w_deposit(double vector_balance)
 {
	 vector_deposit_balance = vector_balance;

	 year_end_balance_with_deposit.push_back(vector_deposit_balance);
 }

 void Bank::vector_interest_w_deposit(double vector_interest)
 {
	 vector_deposit_interest = vector_interest;

	 interest_with_deposit.push_back(vector_deposit_interest);
 }

 void Bank::vector_balance_no_deposit(double vector_no_deposit_balance)
 {
	 vector_ND_balance = vector_no_deposit_balance;

	 year_end_balance_no_deposit.push_back(vector_ND_balance);
 }

 void Bank::vector_interest_no_deposit(double vector_no_deposit_interest)
 {
	 vector_ND_interest = vector_no_deposit_interest;

	 interest_no_deposit.push_back(vector_ND_interest);
 }


 void Bank::print_monthly_deposit_table()
 {
	 int unsigned k;

	 cout << "BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS" << endl;
	 cout << "--------------------------------------------------------" << endl;
	 cout << "--------------------------------------------------------" << endl;
	 cout << "Years       Year End Balance      Year End Earned Interest" << endl;

	 for (k = 0; k < year_vector; k++)
	 {
		 cout << k + 1 << "                "
			 << fixed << setprecision(2) << "$" << year_end_balance_with_deposit.at(k) << "                  "
			 << fixed << setprecision(2) << "$" << interest_with_deposit.at(k) << endl;
	 }

	 year_end_balance_with_deposit.clear();
	 interest_with_deposit.clear();
 }


 void Bank::print_no_deposit_table()
 {
	 int unsigned k;

	 cout << endl;

	 cout << "BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS" << endl;
	 cout << "--------------------------------------------------------" << endl;
	 cout << "--------------------------------------------------------" << endl;
	 cout << "Years       Year End Balance      Year End Earned Interest" << endl;

	 for (k = 0; k < year_vector; k++)
	 {
		 cout << k + 1 << "                "
			 << fixed << setprecision(2) << "$" << year_end_balance_no_deposit.at(k) << "                     "
			 << fixed << setprecision(2) << "$" << interest_no_deposit.at(k) << endl;
	 }

	 year_end_balance_no_deposit.clear();
	 interest_no_deposit.clear();

 }





	Bank(); //constructor
	void user_set_initialInvestment(); //user input for initial investment amount
	void set_initialInvestment(double investment);
	double getInvestment() const;
	void user_set_monthlyDeposit(); //user input monthly deposit
	double get_monthlyDeposit() const;
	void user_set_Interest();
	void user_set_Year();
	double get_user_Years() const;
	double getMonth() const;
	double calculateMonths();
	double total_amount(double initial, double monthly);
	double calculated_interest(double initial, double monthly);
	void set_final_balance(double final);
	double get_final_balance() const;
	void set_new_final_balance(double new_final);
	double get_new_final_balance() const;
	double calculated_interest_no_monthly(double initial_2);
	void set_final_balance_no_monthly(double final_value);
	double get_final_balance_no_monthly() const;
	void print_monthly_deposit_table();
	void print_no_deposit_table();
	void vector_year(double new_year);
	void vector_balance_w_deposit(double vector_balance);
	void vector_interest_w_deposit(double vector_interest);
	void vector_balance_no_deposit(double vector_no_deposit_balance);
	void vector_interest_no_deposit(double vector_no_deposit_interest);

private:
	bool loop_test;
	double m_user_initial_investment;
	double initial_investment;
	double monthly_deposit;
	double t_monthly;
	double user_interest;
	double set_interest;
	double investment_years;
	double set_years;
	double t_months;
	double calculated_months;
	double total_amt;
	double calc_interest;
	double final_balance;
	double new_balance_final;
	double calc_interest_not_monthly;
	double final_balance_not_monthly;
	double interest_2;
	double the_year;
	vector<double> year_end_balance_no_deposit;
	vector<double> year_end_balance_with_deposit;
	vector<double> interest_no_deposit;
	vector<double> interest_with_deposit;
	double year_vector;
	double vector_deposit_balance;
	double vector_deposit_interest;
	double vector_ND_balance;
	double vector_ND_interest;
};

 */
