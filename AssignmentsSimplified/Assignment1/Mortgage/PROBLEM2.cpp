//PROBLEM2.cpp
//Andrew Ribeiro
//October 6, 2008
//Additional files used: PROBLEM2_FUNCTIONS.cpp
/*File Discription: 
This program allows a user to calculate a mortgage payment schedule.
Additionaly, the functions used in this program are in the file: PROBLEM2_FUNCTIONS.cpp
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double safeInput(string errorMessage,string prompt,double minValue);
char safeInput(string errorMessage,string prompt,char validChar1,char validChar2);
void sub_calculateAndDisplayMortgagePaymentSchedule(double principal,double monthlyPayment,double monthlyIntrest);
void highIntrestRateLongPaymentsWarning(bool &printMortgagePaymentSchedule,\
								  double principal,double &monthlyPayment,double &monthlyIntrest);

int main()
{
	double principal = 0,monthlyPayment = 0,monthlyIntrest = 0;
	bool printMortgagePaymentSchedule = true;

	//Output purpose of the program and name.
	cout<<"|---------------------------------------------------|"<<endl
		<<"|               Mortgage Calculator V1.0            |"<<endl
		<<"|This program allows you to create a mortgage pay-  |"<<endl
		<<"|back schedule. Just enter in the principal,the     |"<<endl
		<<"|monthly payment,and interest rate. Then the        |"<<endl
		<<"|program will calculate what you will owe per month.|"<<endl
		<<"|___________________________________________________|"<<endl<<endl;


	//Error checking and getting the values from the user (see mortgage_functions.cpp) . 
	cout<<"Enter principal: ";
	principal = safeInput("Invalid principal!","Please enter a valid principal: ",1);
	cout<<"Enter monthly repayment: ";
	monthlyPayment = safeInput("Invalid monthly payment!","Please enter a valid monthly payment: ",1);
	cout<<"Enter monthly interest rate (%): ";
	monthlyIntrest = safeInput("Invalid interest rate!","Please enter a valid interest rate(%): ",0);
	
	//Set the output to display numbers to the second decimal place. 
	cout.precision(2);
	cout.setf(ios::fixed);
	
	/*Warn the user that the interest rate is too large- the mortgage will never be payed off
	  or that the schedule will be long.*/
	highIntrestRateLongPaymentsWarning(printMortgagePaymentSchedule,\
												principal,monthlyPayment,monthlyIntrest);

	//Print the mortgage payent scedule. 
	if(printMortgagePaymentSchedule)
	{
		sub_calculateAndDisplayMortgagePaymentSchedule(principal,monthlyPayment,monthlyIntrest);
	}

	cout<<"\nExiting the program. "<<endl;
	return 0;
}

