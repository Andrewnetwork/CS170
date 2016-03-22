//Problem1_B.cpp
//Andrew Ribeiro 
//December 1, 2008
//FILES USED: PROBLEM1_FUNCTIONS.cpp,PROBLEM1_HEADER.h
//File contents: This file contains the main() function for the Problem 1 program for Assignment 3.

#include <iostream>
#include<fstream>
using namespace std;

#include "PROBLEM1_HEADER.h"

//Global file object
fstream readFile; 

int main()
{

	//Output title
	cout<<"*******************************************************"<<endl
		<<"*                Alphapetic Sorter  B                 *"<<endl
		<<"* This program sorts all the words inputed by the     *"<<endl
		<<"* user alphabeticaly. Also, the program displays      *"<<endl
		<<"* word frequencies.                                   *"<<endl
		<<"*******************************************************"<<endl
		<<"Please enter your text:\n"<<endl;


	char fileName[200];
	cout<<"Enter the name of the file you wish to read: ";
	cin.getline(fileName,200,'\n');
	readFile.open(fileName,ios::in);
	if(readFile)
	{
		char userInput[SIZE_OF_USER_INPUT];

		readFile.getline(userInput,SIZE_OF_USER_INPUT);

		//The value for this variable is retreved by the the storeTokens function.
		int lengthOfTokenArray;

		//This function makes the users input upper case, so that case can be ignored. 
		upperCaseStr(userInput);

		//Stores the tokens of the users input, which has the spaces removed.
		char **tokenArray = storeTokens(userInput,lengthOfTokenArray);
		
		//If the length of the token array is not 0, sort and disp words.
		if(lengthOfTokenArray >= 1)
		{
			qsort(tokenArray,lengthOfTokenArray, sizeof(char *), compare);
			//This function lists the words inputed by the user alphbeticaly. 
			listTermsAlpha(tokenArray,lengthOfTokenArray);
		}
		else
		{
			cout<<"\nNo words to sort!"<<endl
				<<"Exiting program. ";
		}

		system("pause");
	}
	else
	{
		//If the file cannot be opened, the program will print this message and exit.
		cout<<"Could not open file.."<<endl;
	}
	return 0;
}