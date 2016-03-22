//PROBLEM3a.cpp
//Andrew Ribeiro
//December 6, 2008

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "gymMember.h"
using namespace std; 

const int MAX_SIZE_OF_MEMBER_NAME = 50;
const int SIZE_OF_MEMBER_ARRAY = 10;

//Funcion prototypes. 
ostream& operator<<(ostream& output,gymMember & member);
void getData(gymMember &member);
template<class T>
T safeInput(string errorMessage,string prompt,T minValue,T maxValue);


int main()
{
	//Output program discription.
	cout<<"****************************************************"<<endl
		<<"*                 GYM MEMBER PROGRAM               *"<<endl
		<<"* This program allows you to enter in data for gym *"<<endl
		<<"* members, which are all stored in one gymMember   *"<<endl
		<<"* array. This program also allows you to display   *"<<endl
		<<"* the data you inputed.                            *"<<endl
		<<"****************************************************"<<endl<<endl;

	//Declare the array of gym members.
	gymMember gymMemberArray[SIZE_OF_MEMBER_ARRAY];


	//Get data for each record in the array.
	for(int recordCounter = 0; recordCounter < SIZE_OF_MEMBER_ARRAY ; recordCounter++)
	{
		cout<<endl<<"Enter data for record "<<recordCounter+1<<endl<<endl;
		getData(gymMemberArray[recordCounter]); 
	}

	//Set output format, and print table header.
	cout<<"\n\n                               MEMBER DATA"<<endl<<endl;
	cout.setf(ios::left);
	cout<<endl
		<<setw(25)<<"Member Name"
	    <<setw(15)<<" Fitness score"
		<<setw(10)<<" Height"
		<<setw(10)<<" Join date"<<endl
		<<"***************************************************************"<<endl;


	//Output the data in each record using the overloaded << opperator.
	for(int recordCounter = 0; recordCounter < SIZE_OF_MEMBER_ARRAY ; recordCounter++)
	{
		cout<<gymMemberArray[recordCounter];
	}
	
	//print footer
	cout<<"***************************************************************"<<endl<<endl;
	
	return 0;
}
