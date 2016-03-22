//PROBLEM4.CPP
//December 9, 2008
//Andrew Ribeiro
//Files used: gymMember.h and gymMember.cpp

#include <iostream>
#include <iomanip>
#include "gymMember.h"
using namespace std;

//The amount of elements in the array of gymMember's.
const unsigned short int SIZE_OF_MEMBER_ARRAY = 4;

int main()
{
	//Output title and discription.
    cout<<"****************************************************"<<endl
	<<"*                    GYM MEMBER PROGRAM            *"<<endl
	<<"* This program demonstrates the usage of the       *"<<endl
	<<"* gymMember data structure-- which is a class.     *"<<endl
	<<"****************************************************"<<endl<<endl;

	//Make array of gymMembers.
	gymMember *gymMemberArray = new gymMember[SIZE_OF_MEMBER_ARRAY];

	//Dates
	unsigned short int date1[3] = {12,13,2008};
	unsigned short int date2[3] = {4,5,2008};

	//Seting values via the constructor.
	gymMemberArray[0] = gymMember("Andrew Ribeiro",5.11,date1,4);

	//Setting values using the mutator functions.
	gymMemberArray[2].setDate(date2);
	gymMemberArray[2].setName("Danielle");
	gymMemberArray[2].setHeight(5.6);
	gymMemberArray[2].setFitnessScore(88);

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
	for(int recordCounter = 0; recordCounter < SIZE_OF_MEMBER_ARRAY; recordCounter++)
	{
		cout<<gymMemberArray[recordCounter];
	}
	
	//print footer
	cout<<"***************************************************************"<<endl<<endl;

	return 0;
}