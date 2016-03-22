//passwordProgram.cpp
/*Write a program that asks the user for a password number and checks to see if the password is valid.
	-use #define to hold a value for VALID_PASSWORD
	-use const to define ATTEMPTS_ALLOWED which is the number of tries the user is allowed
	-put the user in a loop that they can only get out of with a valid password or the error trap below
	-Error trap: each time the user enters an attempt at the password call a function which uses a static variable to count
		the number of attempts and if it becomes greater than the allowed number, give user a message and exit() the program*/

#include <iostream>
#include <string>
using namespace std;

#define VALID_PASSWORD "Andrew Ribeiro"
const int ATTEMPTS_ALLOWED = 3; 

void getInput(string &userInput);

void main()
{
	string userInput;

	do
	{
		getInput(userInput);

		
	}while( VALID_PASSWORD != userInput);

	cout<<"Correct password, you are now authorized."<<endl;

}

void getInput(string &userInput)
{
	static int loopCounter = 0; 
	loopCounter++;

	//Error trap
	if (loopCounter > ATTEMPTS_ALLOWED)
	{
		cout<<"\nUNAUTHORIZED USER!\nExiting the program..."<<endl;
		exit(0);
	}
	else if(loopCounter == 1)
	{
		char charInput[100];
		cout<<"Enter in a password: ";
		cin.getline(charInput,100,'\n'); //Get user input in a charicter array
		userInput = charInput; //convert the charicter array to a string.
	}
	else
	{
		char charInput[100];
		cout<<"\nWARNING: INVALID PASSWORD, "<<(ATTEMPTS_ALLOWED+1 - loopCounter)<<" TRIES LEFT.\n"<<endl;
		cout<<"Enter in a password: ";
		cin.getline(charInput,100,'\n'); //Get user input in a charicter array
		userInput = charInput; //convert the charicter array to a string.
	}
}