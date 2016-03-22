//ControlStatementsHw_4.cpp
//Andrew Ribeiro
//September 30, 2008
//From the control statements lecture powerpoint. 

/*
Write a program that estimates the value of the mathematical constant e using the formula:
e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ….
Your program should stop iterating when the value calculated in the current iteration differs from 
the value calculated in the previous iteration by less than a given precision (e.g.  0.01)

*/

#include <iostream>
#include <iomanip>
using namespace std;
long double calculateE(long double precision);
long double safeGetDouble(double yMin);

int main()
{
	long double precision;
	cout<<"Enter in the precision: ";
	precision = safeGetDouble(0.00);
	cout.precision(20);
	cout<<"\nThe guessed value for e is: "<<calculateE(precision)<<endl;

	

	system("pause");
	return 0;

}

long double calculateE(long double precision)
{
	/* Peusdo Code
		 START LOOP
		 First tempStore = previous inerration. 
		 second evalue = inerration
		 third counter += 1.
		 factorial += 2 * factorial... factorial 1.0 / 2 .....factorial+= 3 * factorial ....factorial += 4 * factorial * 
		 CHECK CONDITION
	*/

	long double tempStore = 1,evalue = 1,factoral = 1,counter = 1;
	
	
	do
	{
		
		tempStore = evalue;
		evalue += (1.0 / factoral);
		counter++;
		factoral *= counter ;

	}while((evalue - tempStore)> precision);


	return evalue;
}

long double safeGetDouble(double yMin)
{
	//Used to check errors in input.  

	long double userIn;
	cin>>userIn; 

	while(!cin.good() || ( userIn < yMin))
	{
		cout<<"Enter a valid value: ";
		cin.clear();
		cin.ignore();
		cin>>userIn;
	}

	return userIn;
}
