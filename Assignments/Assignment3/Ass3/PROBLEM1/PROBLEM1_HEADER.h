//PROBLEM1_HEADER.H
//Andrew Ribeiro
//December 1, 2008


#ifndef PROBLEM1_HEADER_H
#define PROBLEM1_HEADER_H

//This should be changed if the user enters needs to enter more text. 
#define SIZE_OF_USER_INPUT 3000

void upperCaseStr(char *string);

int compare(const void *first, const void *second);

char **storeTokens(char *userInput,int &lengthOfArray);

void listTermsAlpha(char **tokens,int lengthOfArray);

int wordFrequency(char *tokenArray[],int startIndex,char *word,int arraySize);

#endif