//PROBLEM1.CPP
//Andrew Ribeiro 
//October 7, 2008 
//Additional files used: PROBLEM1_FUNCTIONS.cpp
/*File Discription:
This program allows the user to print out a callendar page of a month in a year
of the users choice.Also, the functions that are used in this program 
are in the file: PROBLEM1_FUNCTIONS.cpp.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function Prototypes;
void sub_printCalendar(int firstDayOfYear,int userSelectedMonthNumber,int year);
int safeInput(string errorMessage,string prompt,int minValue,int maxValue);


int main(int c, char d[])
{
	int year = 0,firstDayOfYear = 0,userSelectedMonthNumber = 0; 

	cout<<"****************************************************************************"<<endl
		<<"*                          Welcome to Callendar Pro v1.0!                  *"<<endl
		<<"* Callendar Pro enables you to print out a callendar page of a month in a  *"<<endl
		<<"*  year of your coice-given the first day of year,month number,and year.   *"<<endl
		<<"***************************************************************************"<<endl
		<<endl<<endl;

	//Prompt & get the information from the user.
	cout<<"Please enter in the year: ";
	year = safeInput("Invalid year.","Please enter a valid year: ",0,-1); //Ignoring max value limit. 
	
	//Function returns -1 if the user inputed the year wrong 3 times. 
	if (year == -1)
	{
		cout<<"\nYou have entered an invalid value three times.\nExiting program.."<<endl;
		return 0;
	}

	cout<<"\nPlease enter in the first day of the year(1=M,2=T,3=W,4=R,5=F,6=Sa,7=Su): ";
	firstDayOfYear = safeInput("Invalid first day of year choice.",\
									"Please enter a valid first day of the year(1=M,2=T,3=W,4=R,5=F,6=Sa,7=Su): ",1,7);
	if (firstDayOfYear == -1)
	{
		cout<<"\nYou have entered an invalid value three times.\nExiting program.."<<endl;
		return 0;
	}

	cout<<"\nEnter a month\n(1=Jan,2=Feb,3=Mar,4=Apr,5=May,6=Jun,7=Jul,8=Aug,9=Sep,10=Oct,11=Nov,12=Dec): ";
	userSelectedMonthNumber = safeInput("Invalid month.","Please enter a valid month: ",1,12);

	if (userSelectedMonthNumber == -1)
	{
		cout<<"\nYou have entered an invalid value three times.\nExiting program.."<<endl;
		return 0;
	}


	//Activate the subrotine that prints the calendar. 
	sub_printCalendar(firstDayOfYear,userSelectedMonthNumber,year); 

	return 0; 
	

}