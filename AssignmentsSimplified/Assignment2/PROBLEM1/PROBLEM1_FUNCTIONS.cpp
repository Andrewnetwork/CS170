//PROBLEM1_FUNCTIONS.cpp
//Andrew Ribeiro
//November 5, 2008
//Used in: PROBLEM1.CPP
//This file contains the functions and global constants for the file PROBLEM1.cpp

#include <ctime>
#include <iostream>
#include <string>

using namespace std;


//These two arrays store the random responce sets for each event(wrong or right answer). 
const string wrongResponces[5] = {"Wow, you need to practice!",
								  "Humm, you have not been practicing!",
								  "You learn best when you practice every day!",
								  "Practice makes perfect!",
								  "Math is fun, do it alot!"};

const string correctResponces[5] = {"Good job!",
								    "You are a first class mathemetican!",
								    "You have been practicing!",
								    "Keep up the good work!",
								    "You are a math wiz!"};


//************* HELPER FUNCTION(S)- NOT TO BE CALLED IN MAIN PROGRAM FILE *******************

//Validates userInput by checking if the input is in the validChars array. 
bool isCharValid(char const validChars[],char userInput)
{
	char ch = 'r'; //Charicter in the array, it is initilised to an arbirary value. 

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

//Produces a random number [min,max], the defalt domain is [0,9]. 
int randomNumber(int max = 9,int min = 0)
{
	max++;
	int randNum = (rand( )% max); 
	if((rand( )% max) == 0)
	{
		return min;
	}
	else
	{
		return randNum; //Produces a random number with a domain of [0,9]
	}
}

//This function returns a random responce based on if the users answer is wrong(0) or right(1)
string randomResponce(bool answerIsCorrect)
{
	int arrayIndex = randomNumber(4,0);

	if(answerIsCorrect)
		return correctResponces[arrayIndex];
	else
		return wrongResponces[arrayIndex];
}



//************** MAIN FUNCTIONS- TO BE CALLED IN MAIN PROGRAM ************************

//These functions validate the users input. 
int safeInput(string errorMessage,string prompt,int minValue,int maxValue)
{
	//If maxValue is less than min value, ignore max value. Else..... add it to the checker.
	int userIn = 0;
	cin>>userIn;

	if(cin.eof())
	{
		cout<<"\nThank you for using the program."<<endl<<"Now exiting the program. ";
		exit(0);
	}

	if(maxValue < minValue)
	{
		//Loop if there is errors. Be aware of the side effects. 
		
		while(!cin.good() || userIn < minValue||cin.eof())
		{
			if(cin.eof())
			{
				cout<<"\nThank you for using the program."<<endl<<"Now exiting the program. ";
				exit(0);
			}

			cout<<errorMessage;
			cin.clear();
			cin.ignore(80,'\n');
			cout<<prompt;
			cin>>userIn;
		}
	}
	else if( maxValue == minValue) // Ignore both min and max
	{
		while(!cin.good()||cin.eof() )
		{
			if(cin.eof())
			{
				cout<<"\nThank you for using the program."<<endl<<"Now exiting the program. ";
				exit(0);
			}

			cout<<errorMessage;
			cin.clear();
			cin.ignore(80,'\n');
			cout<<prompt;
			cin>>userIn;
		}
	}

	else if( maxValue > minValue)
	{
		while(!cin.good() || userIn < minValue || userIn > maxValue ||cin.eof())
		{
		
			if(cin.eof())
			{
				cout<<"\nThank you for using the program."<<endl<<"Now exiting the program. ";
				exit(0);
			}

			cout<<errorMessage;
			cin.clear();
			cin.ignore(80,'\n');
			cout<<prompt;
			cin>>userIn;
		}
	}
	else
	{

		while(!cin.good())
		{
			if(cin.eof())
			{
				cout<<"\nThank you for using the program."<<endl<<"Now exiting the program. ";
				exit(0);
			}

			cout<<errorMessage;
			cin.clear();
			cin.ignore(80,'\n');
			cout<<prompt;
			cin>>userIn;
		}

	}
	return userIn; 
}

char safeInput(string errorMessage,string prompt,const char validChars[])
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

//This subroutine allows the user to be tested on values [0,9].
void sub_normalMode()
{
	int rightAnswerCount = 0,wrongAnswerCount = 0; //counts the right and wrong answers. 
	bool exitLoop = false; //controls the mode loop. 

	//Print discription. 
	cout<<endl<<endl<<"******************************************"<<endl
		      <<"*            ---NORMAL MODE---           *"<<endl
			  <<"* This mode allows you to answer multip- *"<<endl
			  <<"* ication problems within a range of zero*"<<endl
			  <<"* to nine. Press -1 to return to the menu*"<<endl
			  <<"******************************************"<<endl<<endl;

	//Enter into the normal mode.
	while(!exitLoop)
	{
		//Generates numbers for the problem
		int randomNumbers[2] = {randomNumber(),randomNumber()},userAnswer=0; 

		cout<<randomNumbers[0]<<" * "<<randomNumbers[1]<<"= ";
		userAnswer =safeInput("","\n     = ",-1, -3);
		if (userAnswer == -1)
		{
			break; 
		}
		
		if(  (randomNumbers[0]*randomNumbers[1]) == userAnswer )
		{
			cout<<endl<<randomResponce(true)<<" Very good!\n"<<endl;
			rightAnswerCount++;
			if ((wrongAnswerCount + rightAnswerCount)%10 == 0)
				{
					cout<<endl<<"Percentage of correct answers(%): "
				        <<100* ((double)rightAnswerCount / (wrongAnswerCount + rightAnswerCount))<<endl<<endl;
				}
		}
		else
		{
			wrongAnswerCount++;

			do{
				cout<<endl<<randomResponce(false)<<" Please try again.\n"<<endl;
				cout<<randomNumbers[0]<<" * "<<randomNumbers[1]<<"= ";
				userAnswer = safeInput("","\n     = ",-1, -3);

				if (userAnswer == -1)
				{
					exitLoop = true; 
					break; 
				}

				wrongAnswerCount++;
				if ((wrongAnswerCount + rightAnswerCount)%10 == 0)
				{
					cout<<endl<<endl<<"Percentage of correct answers(%): "
				        <<100* ((double)rightAnswerCount / (wrongAnswerCount + rightAnswerCount))<<endl<<endl;
				}

			}while( userAnswer != (randomNumbers[0]*randomNumbers[1])); //while the users answer is still wrong

			if(userAnswer == (randomNumbers[0]*randomNumbers[1])) // if the users answer is correct.
			{
				cout<<endl<<randomResponce(true)<<" Very good!\n"<<endl<<endl; 
			}
		}	
	}
}

//This subroutine allows the user to enter in a range of values to be tested on. 
void sub_rangedMode()
{
	//variables for the interval(boundarys).
	int minValue = 0 ,maxValue = 0;
	cout<<endl<<"******************************************"<<endl
		      <<"*            ---RANGED MODE---           *"<<endl
			  <<"* This mode allows you to answer multip- *"<<endl
			  <<"* ication problems within a range that   *"<<endl
			  <<"* you chose. Enter two identical values  *"<<endl
			  <<"* for largest number in range and lowest *"<<endl
			  <<"* number in range to return to the menu. *"<<endl
			  <<"* Also, press -1 while in the range to   *"<<endl
			  <<"* enter another range.                   *"<<endl
			  <<"******************************************"<<endl<<endl;

	int rightAnswerCount = 0;
	int wrongAnswerCount = 0;

	while(true)
	{
		cout<<"\nPlease enter the lowest number in the range: ";
		minValue = safeInput("\n\tWARNING: INVALID VALUE\n","Enter a valid value: ",0, -1);

		cout<<"Please enter the largest number in the range: ";
		maxValue = safeInput("\n\tWARNING: INVALID VALUE\n","Enter a valid value: ",0, -1);


		if(minValue == maxValue)
		{
			//If values are identical, return to the main menu. 
			break;
		}

		while(true)
		{

			int randomNumbers[2] = {randomNumber(maxValue,minValue),randomNumber(maxValue,minValue)},userAnswer = 0; 

			cout<<randomNumbers[0]<<" * "<<randomNumbers[1]<<"= ";
			userAnswer =safeInput("","\n       = ",-1, -4);
			
			if(userAnswer == -1)
			{
				//Break out of the loop to enter a diferent range. 
				break;
			}
			
			if(  (randomNumbers[0]*randomNumbers[1]) == userAnswer )
			{
				cout<<endl<<randomResponce(true)<<" Very good!\n"<<endl;
				rightAnswerCount++;
				if ((wrongAnswerCount + rightAnswerCount)%10 == 0)
					{
						cout<<endl<<"Percentage of correct answers(%): "
							<<100* ((double)rightAnswerCount / (wrongAnswerCount + rightAnswerCount))<<endl<<endl;
					}
			}
			else
			{
				wrongAnswerCount++;

				do{
					cout<<endl<<randomResponce(false)<<" Please try again.\n"<<endl;
					cout<<randomNumbers[0]<<" * "<<randomNumbers[1]<<"= ";
					userAnswer = safeInput("","\n      = ",-1, -4);

					if(userAnswer == -1)
					{
						//Break out of the loop to enter a diferent range. 
						break;
					}

					wrongAnswerCount++;
					if ((wrongAnswerCount + rightAnswerCount)%10 == 0)
					{
						cout<<endl<<endl<<"Percentage of correct answers(%): "
							<<100* ((double)rightAnswerCount / (wrongAnswerCount + rightAnswerCount))<<endl<<endl;
					}

				}while( userAnswer != (randomNumbers[0]*randomNumbers[1]));

				if(userAnswer == (randomNumbers[0]*randomNumbers[1]))
				{
					//If the user entered the correct answer, enter a positive responce.
					cout<<endl<<randomResponce(true)<<" Very good!\n"<<endl<<endl; 
				}
			}	
		}
	}
	
}




