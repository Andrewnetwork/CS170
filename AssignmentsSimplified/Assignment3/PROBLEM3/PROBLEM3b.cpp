//PROBLEM3b.cpp
//Andrew Ribeiro
//December 6, 2008

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "gymMember.h"
using namespace std; 

const int MAX_SIZE_OF_MEMBER_NAME = 50;

//Funcion prototypes. 
ostream& operator<<(ostream& output,gymMember & member);
void getData(gymMember &member);
template<class T>
T safeInput(string errorMessage,string prompt,T minValue,T maxValue);


int main()
{
	//Output program discription.
	cout<<"****************************************************"<<endl
		<<"*                 GYM MEMBER PROGRAM  B            *"<<endl
		<<"* This program allows you to enter in data for gym *"<<endl
		<<"* members, which are all stored in one gymMember   *"<<endl
		<<"* array. This program also allows you to display   *"<<endl
		<<"* the data you inputed.                            *"<<endl
		<<"****************************************************"<<endl<<endl;

	cout<<"How large would you like the array of gymMembers array to be: ";
	const int sizeOfArray = safeInput<int>("\n    WARNING: Invalid input!\n\n","Please enter a valid value: ",0,-1);

	//Declare the array of gym members, depending on how large the user would like the array to be.
	gymMember *gymMemberArray = new gymMember[sizeOfArray];


	//Get data for each record in the array.
	for(int recordCounter = 0; recordCounter < sizeOfArray; recordCounter++)
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
	for(int recordCounter = 0; recordCounter < sizeOfArray; recordCounter++)
	{
		cout<<gymMemberArray[recordCounter];
	}
	
	//print footer
	cout<<"***************************************************************"<<endl<<endl;
	
	delete gymMemberArray;
	return 0;
}
