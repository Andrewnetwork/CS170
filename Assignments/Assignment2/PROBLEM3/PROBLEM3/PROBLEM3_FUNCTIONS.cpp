//PROBLEM3_FUNCTIONS.cpp
//Andrew Ribeiro 
//November 6, 2008
//Used in: PROBLEM3.CPP
//This file contains the functions used in PROBLEM3.cpp

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

bool isCharValid(char validChars[],char userInput);

//These functions validate input
int safeInput(string errorMessage,string prompt,int minValue,int maxValue)
{
	//If maxValue is less than min value, ignore max value. Else..... add it to the checker.
	int userIn = 0;
	cin>>userIn;

	if(maxValue <= minValue)
	{
		//Loop if there is errors. Be aware of the side effects. 
		
		while(!cin.good() || userIn < minValue||cin.eof())
		{
			cout<<errorMessage<<endl
				<<prompt;
			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
		}
	}
	else if( maxValue == minValue) // Ignore both min and max
	{
		while(!cin.good()||cin.eof() )
		{
			cout<<endl<<errorMessage<<endl
				<<prompt;

			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
		}
	}

	else
	{
		while(!cin.good() || userIn < minValue || userIn > maxValue ||cin.eof())
		{
		
			cout<<errorMessage<<endl
				<<prompt;

			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
		}
	}
	
	return userIn; 
}

char safeInput(string errorMessage,string prompt,char validChars[])
{
	//Will convert the user input to upper case charicters. 
	char userIn;

	cin>>userIn;
	userIn = toupper(userIn);

	//Loop if there is errors and if the users input is invalid. 
	
	while(!cin.good() || !isCharValid(validChars,userIn) )
	{
		cout<<errorMessage<<endl
			<<prompt;

		cin.clear();
		cin.ignore(80,'\n');
		cin>>userIn;
		userIn = toupper(userIn);
	}

	return userIn; 
}
bool isCharValid(char validChars[],char userInput)
{
	char ch = 'r';

	for(int index =0; ch != '\0'; index++)
	{
		ch = validChars[index];

		if(userInput == ch)
		{
			//If the users input is a valid charicter, return true for the function
			return true;
		}
	}

	return false; 

}



//These functions calculate their respective values.
int square(int value)
{
	return (value * value);
}
int cube(int value)
{
	return (value * value * value);
}
int fourthPower(int value)
{
	return (value * value * value * value); 
}

/*This function tabulates the values on the user defined interval, using the function passed by the
users selection.*/
void tabulate(int (*pFunction)(int),int lowerBound,int upperBound)
{
	//holds information about how many values have been printed(so that rows can be formed).
	int printCount = 0; 

	cout<<endl;

	//Show table of calculated values. 
	cout<<"TABULATING ["<<lowerBound<<","<<upperBound<<"]"<<endl;
	for(int i = lowerBound; i <= upperBound; i++)
	{
		cout<<setw(10)<<pFunction(i)<<setw(2)<<" | ";
		printCount++; 

		//Print in rows of 5
		if (printCount % 5 == 0)
		{
			cout<<endl;
			cout<<"-------------------------------------------------------------------"<<endl;
			
		}

	}
	cout<<endl;
}