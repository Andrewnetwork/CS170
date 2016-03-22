
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

//int *newA = concatArrays(a,b,sizeof(a),sizeof(b));
	//printArray(newA);
	//delete newA;
int* concatArrays(int *first,int *second,int sizeOfFirst,int sizeOfSecond)
{
	int positionCounter = 0; 
	sizeOfFirst = sizeOfFirst/sizeof(int);
	sizeOfSecond = sizeOfSecond/sizeof(int);
	int sizeOfArray = sizeOfFirst+ sizeOfSecond; 
	sizeOfArray++; //null char.
	int *newArray = new int[sizeOfArray];

	for(int i = 0; i < sizeOfFirst;i++)
	{
		newArray[i] = first[i];
	}

	for(int i = sizeOfFirst; i < sizeOfArray-1  ;i++)
	{
		newArray[i] = second[positionCounter];
		positionCounter++;
	}

	newArray[sizeOfArray-1] = '\0';
	return newArray;//pointer to the dynamicaly allocated array
}
void printArray(int *arry)
{
	for(int i = 0; arry[i] != '\0';i++)
	{
		cout<<arry[i]<<endl;
	}
}
