//gymMember.cpp
//Andrew Ribeiro
//December 6, 2008

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "gymMember.h"
using namespace std; 

//The size of the name array.
const int MAX_SIZE_OF_MEMBER_NAME = 50;

//Input function
template<class T>
T safeInput(string errorMessage,string prompt,T minValue,T maxValue)
{
	//If maxValue is less than min value, ignore max value. Else..... add it to the checker.
	T userIn = 0;
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

			cout<<errorMessage;
			cin.clear();
			cin.ignore(80,'\n');
			cout<<prompt;
			cin>>userIn;
		}

	}
	return userIn; 
}


//Overloaded << operator for gymMember.
ostream& operator<<(ostream& output,gymMember & member)
{
	//Displays data. 
	output<<setw(25)<<member.name<<" "
	      <<setw(15)<<member.fitnessScore<<" "
		  <<setw(10)<<member.height<<" "
		  <<member.joinDate[0]<<"/"<<member.joinDate[1]<<"/"<<member.joinDate[2]<<endl;

	return output; 
}

//Gets the data from the user for each of the feilds in the gymMember.
void getData(gymMember &member)
{

	cin.clear();
	cin.ignore(80,'\n');
	char name[MAX_SIZE_OF_MEMBER_NAME];
	cout<<"Please enter a name for this member: ";
	cin.getline(name,MAX_SIZE_OF_MEMBER_NAME);
	strncpy(member.name,name,MAX_SIZE_OF_MEMBER_NAME);
	

	cout<<"Please enter a fitness score for this member: ";
	member.fitnessScore = safeInput<int>("\n    WARNING: Invalid input!\n\n","Please enter a valid value: ",0,100);
	
	cout<<"Please enter the height of this member: ";
	member.height = safeInput<float>("\n    WARNING: Invalid input!\n\n","Please enter a valid value: ",0,-3);

	cout<<"Please enter the date the individual joined(mm dd yyyy): ";
	member.joinDate[0] = safeInput("\n    WARNING: Invalid date!\n\n","Please enter a valid date(mm dd yy): ",1,12);
	member.joinDate[1] = safeInput("\n    WARNING: Invalid date!\n\n","Please enter a valid date(dd yyyy): ",1,31);
	member.joinDate[2] = safeInput("\n    WARNING: Invalid date!\n\n","Please enter a valid date(yyyy): ",1900,0);


}

