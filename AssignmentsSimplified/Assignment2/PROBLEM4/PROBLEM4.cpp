//PROBLEM4.CPP
//Andrew Ribeiro
//November 6, 2008
/*
 *************************-FILE DISCRIPTION AND CONTENTS-*************************

  This file contains the function indexOfMax() and some tests with the function.
 
 ********************************-FUCTIONS-***************************************

  + template <class T> int indexOfMax(T arrayToBeSearched, int lowerIndex, int upperIndex)
		-Purpose: This function returns the indx of the maximum value in an array.
 		-Arguments: This function takes an array as an argument with the lower index
				    and upper indexes. 
		-Return: This function returns the index of the maximum value in the
				 array passed to the function on the interval [lowerIndex,upperIndex].
	    -Special features: This function is a template function; therefore, it can take
						   any type of array as its argument. 
  *********************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

template <class T> 
int indexOfMax(T arrayToBeSearched, int lowerIndex, int upperIndex);
void runTests();

int main()
{

	//runs the tests on the function indexOfMax
	runTests(); 

	return 0;
}


template <class T> 
int indexOfMax(T const arrayToBeSearched, int lowerIndex, int upperIndex)
{
	//Store the index--in arrayToBeSearched-- of the largest element staticaly. 
	static int indexOfLargestElement = lowerIndex; 
	

	//If all in the array has been checked, than return the indexOfLargest.
	if(upperIndex == lowerIndex)
	{
		//Make shure that the endpoint gets checked.
		if(arrayToBeSearched[lowerIndex] >= arrayToBeSearched[indexOfLargestElement])
		{
			indexOfLargestElement = lowerIndex;
		}

		//Store index of largest element so it can be reset before the return of the largest value. 
		int indexOfLargest = indexOfLargestElement;
		indexOfLargestElement = lowerIndex ; //Reset the largest element index.
		return indexOfLargest; 
	}

	if(arrayToBeSearched[lowerIndex] >= arrayToBeSearched[indexOfLargestElement])
	{
		indexOfLargestElement = lowerIndex;
	}

	//Increase the lower index.
	indexOfMax(arrayToBeSearched,lowerIndex+1,upperIndex);
}

void runTests()
{
	//Here are some tests for the function indexOfMax.
	
	cout<<"\t\t************************************************"<<endl
		<<"\t\t****** TESTS OF THE indexOfMax() FUNCTION ******"<<endl
		<<"\t\t************************************************"<<endl<<endl;

	int myArray[6] = {0, 1, 2, 3, 3, 4};
	cout<<"int myArray[6] = {0, 1, 2, 3, 3, 399}"<<endl;
	cout<<"indexOfMax(myArray,0,5) = "<<indexOfMax(myArray,0,5)<<endl<<endl;

	double myDoubleArray[5] = {4.3,43.4,44.29,43443.434,0};
	cout<<"double myDoubleArray[5] = {4.3,43.4,44.29,43443.434,0}"<<endl;
	cout<<"indexOfMax(myArray,0,3) = "<<indexOfMax(myDoubleArray,0,4)<<endl<<endl; 

	int longIntArray[18] = {34,   55,   33,   22, //Indexes 0-3, 55 being the largest.
							3,    45,    2,   45, //Indexes 4-7, 45 being the largest.
							2,    34,   56,  778, //Indexes 8-11, 11 being the largest of the whole array.
							223,  45,    3,    3, //Indexes 12-15, 223 being the largest. 
							5,     2};            //Indexes 16-17, 5 being the largest. 
	

	cout<<"\t\t\t *****************"<<endl
		<<"\t\t\t** INTERVAL TEST **"<<endl
		<<"\t\t\t *****************"<<endl<<endl
		<<"int longIntArray[18] = {34,   55,   33,   22, //Indexes 0-3"<<endl
		<<"                        3,    45,    2,   45, //Indexes 4-7"<<endl
	    <<"                        2,    34,   56,  778, //Indexes 8-11"<<endl
		<<"                        223,  45,    3,    3, //Indexes 12-15"<<endl
		<<"                        5,     2};            //Indexes 16-17"<<endl<<endl; 

	cout<<"The largest element in the array is: "<<longIntArray[indexOfMax(longIntArray,0,17)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,0,17)<<endl<<endl;

	cout<<"The largest element in range [0,3] is: "<<longIntArray[indexOfMax(longIntArray,0,3)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,0,3)<<endl<<endl;

	cout<<"The largest element in range [4,7] is: "<<longIntArray[indexOfMax(longIntArray,4,7)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,4,7)<<endl<<endl;

	cout<<"The largest element in range [8,11] is: "<<longIntArray[indexOfMax(longIntArray,8,11)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,8,11)<<endl<<endl;

	cout<<"The largest element in range [12,15] is: "<<longIntArray[indexOfMax(longIntArray,12,15)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,12,15)<<endl<<endl;

	cout<<"The largest element in range [16,17] is: "<<longIntArray[indexOfMax(longIntArray,16,17)]<<"."<<endl
		<<"At the index location: "<<indexOfMax(longIntArray,16,17)<<endl<<endl;

	cout<<"\t\t\t **********************"<<endl
		<<"\t\t\t**   Programmer Test   **"<<endl
		<<"\t\t\t **********************"<<endl<<endl;
	cout<<"Discription: You are going to enter integer values into an array"<<endl
		<<"Then the indexOfMax function will determine what position the largest value you enered was."
		<<"Example input: 34 55 333 ^Z"<<endl<<endl
		<<"NOTE: if you have two or more numbers that are the largest and are equal"<<endl
		<<"the position will indicate the second value position.Also, since this is a"<<endl
		<<"programers test, it is assumed that you will not enter any errors.        "<<endl;

	
	while(true)
	{
		int userInArray[11]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},indexOfArray = 0;

		cout<<"\nEnter a maximum of 10 integers(seperated by spaces,end with ^Z): ";

		while(cin>>userInArray[indexOfArray])
		{
			indexOfArray++;
		}

		cout<<"\nThe position of the largest value is: "<<1 + (indexOfMax(userInArray,0,indexOfArray-1))
			<<", which is "<<userInArray[indexOfMax(userInArray,0,indexOfArray-1)]<<endl;

		//Clear the stream and prepare for another entry. 
		cin.clear();
		cout<<"Press enter to continue...";
		cin.ignore(80,'\n');
	}

}
