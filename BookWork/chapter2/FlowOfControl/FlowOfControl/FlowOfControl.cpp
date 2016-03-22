//FlowOfControl.cpp
//Andrew Ribeiro
//Testing the flow of control structures: do..while, while, for, if, if..else, if..else if...else,switch, and some boolean 
//truth testing/ logic testing. 


#include <iostream> 
using namespace std; 

//Function prototypes

void doWhile();
void whileLoop();
void ifStructure();
void ifElse();
void forLoop();
void multitierLoopStructures();
void switchStructure();
void booleanAlgebra();


int main()
{

	
	
	
	system("pause"); //Prompts user to press any key to end the program.

	return 0;
}


void doWhile()
{
	//This code segment increases the variable "number" -which is inititally at number 0- to five using the do while structure 
	//of recursion.

	int number =0; 
	int counter = 0;

	do
	{
		number++;
		counter++;

	}while(counter <= 4);

	cout<<"Do..While: The number = "<<number<<endl;

}

void whileLoop()
{
	//This code segment will perform the same function as the void doWhile function does. 
	int number =0; 
	int counter = 0;

	while(counter <=4)
	{
		number++;
		counter++;
	}

	cout<<"While: The number = "<<number<<endl;

}

void ifStructure()
{
	// This function will also raise number to 5.

	int number =0; 
	int counter = 0;

	if (number != 5)
	{
		number = 5;
	}
	
	cout<<"IF: The number = "<<number<<endl;
	
}

void ifElse()
{
	if
}

void forLoop()
{
	//This code segment fills an an array with values using the for loop.
	int arrayStructure[10]; 
	int count = 0;
	


	for(int i = 0; i <= 9;i++)
	{
		count++;
		arrayStructure[i] = count;
		cout<<arrayStructure[i]<<endl;
	}
}

void multitierLoopStructures()
{
}

void switchStructure()
{
	char userInput;
	char userExitChoice; 
	bool exitCondition = false; 

	do
	{
		cout<<"Please enter in a charicter to test the switch control structure: ";
		cin>>userInput;

		switch(userInput)
		{
			case 'A':
				cout<<"This letter is A"<<endl;
				break;
			case 'B':
				cout<<"This letter is B"<<endl;
				break;
			case 'C':
				cout<<"This letter is C"<<endl;
				break;
			case 'D':
				cout<<"This letter is D"<<endl;
				break;
			default:
				cout<<"The charicter is  not a capital letter or is not in"<<endl
					<<"the first 15.38% of the alphabet\n"<<endl;

		}

		cout<<"Would you like to exit(y/n): ";
		cin>>userExitChoice;
		
		//Can use the same statements for diferent cases. In this structure this feature is used to allow the user to 
		//use capital letter counterparts for the userExitChoiceVariable.

		switch(userExitChoice)
		{
			case 'Y':
			case 'y':
				exitCondition = true;
				break;

			case 'N':
			case 'n':
				break;

			default: 
				cout<<"Invalid entry."<<endl;
				
		}
	

	}while(!exitCondition); // When exitCondition = false, it is evaluated as true to keep the loop looping.
}

void booleanAlgebra()
{
	const bool AT = true ,BF = false , CT = true, DF= false;

	//bool k = true,f = false,g = true,x = flase;
	
	//Any number other than zero is considered to satisfy the if condition.
	if (!BF)
	{
		cout<<"This formula yeilded true."<<endl;
	}
	else 
	{
		cout<<"This formula yeilded false."<<endl;
	}

}