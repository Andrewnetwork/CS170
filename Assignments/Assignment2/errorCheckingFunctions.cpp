//errorCheckingFunctions
//Andrew Ribeiro
//November 5, 2008
//USED IN FILES: PROBLEM1.CPP,
/*
 *DISCLAMER: I know some of these functions look like they are too advanced for the current level of the 
 *class, but as I have told you before, I have experience programing in C++ already. I assure you that
 *this is my own work.
 *#######################################################################################################
 *File contents and purpose: This file contains multiple functions that allow for an interesting system
 *of validating numerical data. This system allows all charicters from the input to be removed, the result 
 *is the numbers that were in the input. EX: 4jj45 = 445, EX: jfj-4jjj5 = -45
 */


#include <iostream>
#include <string>
#include <cmath>
using namespace std; 



int convertStringToNumber(string userInputString,int minValue);

string removeCharictersFromString(string userInputString);

//###############MAIN FUNCTIONS-TO BE CALLED IN OTHER FILES ###############
int safeInput(string errorMessage,string prompt,int minValue,int maxValue)
{
	/*This function gives the user the ability to enter in numbers entangled in text
	  while still being able to process the numbers. EX: -49u = -49. This
	  helps to prevent a error in the event of a mistyped charicter. */

	int userIn;

	string userInputString;
	cin>>userInputString;

	//userIn is -1 if the string is full of charicters, not numbers. 

	userIn = convertStringToNumber(removeCharictersFromString(userInputString),minValue);

	while(userIn < minValue || userIn > maxValue)
	{
		cout<<errorMessage<<prompt;
		

		userIn = convertStringToNumber(removeCharictersFromString(userInputString),minValue);
	}

	
	return userIn; 
}



//##############HELPER FUNCTIONS-NOT TO BE CALLED OUTSIDE THIS FILE #################

double convertStringToDouble(string userInputString)
{
	double  convertedStringNumber = 0; 

	return convertedStringNumber;
}
int convertStringToNumber(string userInputString,int minValue)
{
	int  convertedStringNumber = 0,charicter = 0,skipCharicter = 0,nonDigitCounter = 0;
	bool isNegative = false; 
	
	while (userInputString[charicter] != '\0')
	{
		if (userInputString[charicter] == 'F' || userInputString[charicter] == '-')
		{
			skipCharicter++;
		}

		charicter++;
	}

	charicter = 0; //Reset counter
	

	//Get the base of the number.
	int powerBase = (pow(10.0,static_cast<double>((userInputString.length()- skipCharicter)))/10);
																			
	
	while (userInputString[charicter] != '\0') //While the end of the array was not reached. 
	{
		//If the negitive sign is infront of a number, we assume the numbers following it are negitive aswell.
		if(userInputString[charicter+1] != 'F' && userInputString[charicter] == '-') 
		{
			isNegative = true;
		}
		else
		{
			if(userInputString[charicter] != 'F' &&  userInputString[charicter] != '-')
			{
				switch(userInputString[charicter]) //Transform into a number
				{
				case '0':
					convertedStringNumber += powerBase * 0;
					break;
				case '1':
					convertedStringNumber += powerBase * 1;
					break;
				case '2':
					convertedStringNumber += powerBase * 2;
					break;
				case '3':
					convertedStringNumber += powerBase * 3;
					break;
				case '4':
					convertedStringNumber += powerBase * 4;
					break;
				case '5':
					convertedStringNumber += powerBase * 5;
					break;
				case '6':
					convertedStringNumber += powerBase * 6;
					break;
				case '7':
					convertedStringNumber += powerBase * 7;
					break;
				case '8':
					convertedStringNumber += powerBase * 8;
					break;
				case '9':
					convertedStringNumber += powerBase * 9;
					break;
				default:
					nonDigitCounter++;

				}
				powerBase /= 10; //Decrease by one digit. 
			}
		}
		charicter++;
	}

	if(isNegative)
	{
		convertedStringNumber = (convertedStringNumber - (convertedStringNumber * 2));
	}

	//If the nonDigitCounter is equal to the amount of digits in the array, the array(string) does not contain numbers. 
	if((nonDigitCounter + skipCharicter) == (userInputString.size()))
	{
		//Return one less that the minimum value.
		return (minValue -1);
	}

	return convertedStringNumber;
}
string removeCharictersFromString(string userInputString)
{
	int charicter = 0;


		while (userInputString[charicter] != '\0')
		{
			//If the charicter is not equal to a number. Remove it from the string. 
			if (userInputString[charicter] != '0'&& userInputString[charicter] != '1'&&\
				userInputString[charicter] != '2'&& userInputString[charicter] != '3'&&\
				userInputString[charicter] != '4'&& userInputString[charicter] != '5'&&\
				userInputString[charicter] != '6'&& userInputString[charicter] != '7'&&\
				userInputString[charicter] != '8'&& userInputString[charicter] != '9'&& \
				userInputString[charicter] != '-'&& userInputString[charicter] != '\0')
			{
				userInputString[charicter] = 'F'; //Replace charicters with F.
			}

			charicter++;
		}

		return userInputString;
}