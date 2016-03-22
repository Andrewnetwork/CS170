//PROBLEM3.CPP
//Andrew Ribeiro
//November 6, 2008 
//Files used: PROBLEM3_FUNCTIONS.CPP
//This is a program that tabulates values on an user defined interval by a user defined function. 

#include <iostream>
#include <string>
using namespace std;

char safeInput(string errorMessage,string prompt,char validChars[]);
int safeInput(string errorMessage,string prompt,int minValue,int maxValue);
void tabulate(int (*pFunction)(int),int lowerBound,int upperBound);
int fourthPower(int value);
int cube(int value);
int square(int value);

int main()
{
	//contains the users input and a list of valid charicters for the menu.
	char userInput,validChars[4] = {'S','C','F','Q'};
	//contains the name of the users choice--such as cube.
	string nameOfChoice;
	//contains the pointer to the function that the user choses, and the two boundaries the user selects. 
	int (*pFunction)(int),lowerBound,upperBound; 

	cout<<"***************************************************"<<endl
		<<"*         Welcome to the powers program!          *"<<endl
		<<"* This program allows you to compute powers of    *"<<endl
		<<"*   numbers on an interval you define. Enjoy!     *"<<endl
		<<"***************************************************"<<endl<<endl;
	do
	{
		cout<<"                 ----MENU----                   "<<endl
			<<"Please select an option"<<endl<<endl
			<<"          Square: S"<<endl
			<<"          Cube: C"<<endl
			<<"          Forth power: F"<<endl
			<<"          Quit: Q"<<endl<<endl
			<<"Enter(S,C,F,or Q): ";
		userInput = safeInput("\n\tWARNING: INVALID CHOICE\n","Please enter a valid choice: ",validChars);

		/*Assign the function pointer a function of the users selection, and the name of the function to the 
		baneOfChoice*/
		switch(userInput)
		{
			case 'S':
				pFunction = square;
				nameOfChoice = "square";
				break;
			case 'C':
				pFunction = cube;
				nameOfChoice = "cube";
				break;
			case 'F':
				pFunction = fourthPower;
				nameOfChoice = "raise to the forth power";
				break;
			case 'Q':
				cout<<"\nThank you for using this program. Goodbye!"<<endl;
				exit(0); //Exit the program completely. 
				break; 
		}

		cout<<"\nYou have chosen to "<<nameOfChoice<<" values on an interval"<<endl;

		while(true)
		{
			cout<<"\nInterval Entry"<<endl
				<<"\tLower bound of interval(integer from 0 to 100) [X,...]: ";
			lowerBound = safeInput("\n\tWARNING: INVALID BOUNDARY\n","Lower bound: ",0,100);

			cout<<"\tUpper bound of interval(integer from 0 to 100) [...,Y]: ";
			//Do not let the user enter in a value less than the lower bound. 
			upperBound = safeInput("\n\tWARNING: INVALID BOUNDARY\n","Upper bound: ",lowerBound,100);

			if (lowerBound == 0 && upperBound ==0)
			{
				//Return to menu.
				cout<<endl;
				break;
			}
			else
			{
				tabulate(pFunction,lowerBound,upperBound);
			}
		}

	}while(true); 

	return 0;
}