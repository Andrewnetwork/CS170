//PROBLEM1_FUNCTIONS.cpp
//Andrew Ribeiro 
//December 1, 2008

#include <iostream>
using namespace std;

#include "PROBLEM1_HEADER.h"

//Counts how many times a word is used in the tokenArray
int wordFrequency(char *tokenArray[],int startIndex,char *word,int arraySize)
{

	int frequencyCounter = 0;
	int counter = 0;
	while(counter < arraySize)
	{
		if(!strcmp(tokenArray[counter],word))
		{
			//If the words are the same, add to the frequency. 
			frequencyCounter++;
		}
		counter++;
	}

	

	return frequencyCounter; 
}
//Changes all the charicters in the string to uppercase letters
void upperCaseStr(char *string)
{
	for(int i = 0; string[i] != NULL ;i++)
	{
		string[i] = toupper(string[i]);
	}
}

//Compares two strings.
int compare(const void *first, const void *second)
{
	//Constant because it should not be changed.
    const char **firstStr = (const char **)first;

    const char **secondStr = (const char **)second;
	//The compare function returns values suited for qsort
    return strcmp(*firstStr, *secondStr); 

}
//Stores the tokens in an array and returns the size of the token array in lengthOfArray
char **storeTokens(char *userInput,int &lengthOfArray)
{
	
	char *storageArray[SIZE_OF_USER_INPUT];
	unsigned int elementCounter = 0;

	storageArray[0] = strtok(userInput," \n");
	char *tempValue = storageArray[0];
	elementCounter++;


	int i = 1;
	while(tempValue != NULL)
	{
		storageArray[i] = strtok(NULL," \n");
		tempValue = storageArray[i]; 
		elementCounter++;
		i++;
	}

	lengthOfArray = elementCounter-1; 

	
	char **newA = new char*[lengthOfArray];

	for(int i = 0; i < elementCounter; i++)
	{
		newA[i] = storageArray[i];
	}

	return newA; 
}

//Lists the words in the token array alphabeticaly.
void listTermsAlpha(char **tokens,int lengthOfArray)
{
	cout<<"***********************************************"<<endl
		<<"         ALPHABETIC ORDERING OF THE WORDS     *"<<endl
		<<"***********************************************"<<endl;
	int counter = 1;


	//Print first word header.
	char firstLetter = tokens[0][0];

	cout<<endl<<"   "<<firstLetter<<endl
		<<"***********************************"<<endl
		<<tokens[0]<<"("<<wordFrequency(tokens,0,tokens[0],lengthOfArray)<<")"<<"   ";


	while(counter < lengthOfArray)
	{
		char firstLetter = tokens[counter][0];
		char prevFirst = tokens[counter-1][0];

		//If the word has the same first letter.
		if(firstLetter == prevFirst)
		{
			if(strcmp(tokens[counter],tokens[counter-1]))
			{
				cout<<tokens[counter]<<"("<<wordFrequency(tokens,0,tokens[counter],lengthOfArray)<<")"<<"   ";
			}
		}
		else
		{
			cout<<endl<<endl<<endl<<"   "<<firstLetter<<endl
				<<"***********************************"<<endl
			    <<tokens[counter]<<"("<<wordFrequency(tokens,0,tokens[counter],lengthOfArray)<<")"<<"   ";
			
		}

		counter++;
		
	}

	cout<<endl<<endl
		<<"*******************************************************"<<endl;
 
}