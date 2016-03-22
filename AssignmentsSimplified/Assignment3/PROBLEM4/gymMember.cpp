//gymMember.cpp
//Andrew Ribeiro
//December 9, 2008
//This file includes the definition of the methods of the class gymMember

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "gymMember.h"
using namespace std; 


//*************************************** METHODS OF GYMMEMBER CLASS **********************************

//Argumentless constructor
gymMember::gymMember()
{
	//Set default values.
	this->setHeight(0);

	this->setFitnessScore(0);

	unsigned short int tempDate[3] = {0,0,0};
	this->joinDate[0] = tempDate[0];
	this->joinDate[1] = tempDate[1];
	this->joinDate[2] = tempDate[2];


	this->setName("NO NAME");
	
}
//Constructor with arguments
gymMember::gymMember(char *name, float height, unsigned short *date, unsigned short fitnessScore)
{
	this->setName(name);
	this->setHeight(height);
	this->setDate(date);
	this->setFitnessScore(fitnessScore);
}
//Define the mutator functions
void gymMember::setName(char *name)
{
	strcpy_s(this->name,MAX_SIZE_OF_MEMBER_NAME,name);
}
void gymMember::setHeight(float height)
{
	//There is no one on earth that is taller than 20 feet, this I am sure of. 
	if(height >= 0 && height <= 20)
	{
		this->height = height;
	}
}
void gymMember::setDate(unsigned short int *date)
{
	//Does not change data unless if fits the criteria.

	//If the months are within the valid range.
	if(date[0] >= 1 && date[0] <= 12)
	{
		this->joinDate[0] = date[0];
	}
	
	//If the days of the month are within the valid range. This excludes month diferences.
	if(date[1] >= 1 && date[0] <= 31)
	{
		this->joinDate[1] = date[1];
	}
	
	//If the year is non-negative and is greater than a illogical join year.
	if(date[2] >= 1900 && date[2] <= 20000)
	{
		this->joinDate[2] = date[2];
	}
}

void gymMember::setFitnessScore(unsigned short int fitnessScore)
{
	if(fitnessScore >= 0 && fitnessScore <= 100)
	{
		this->fitnessScore = fitnessScore;
	}
	
}

//Define the accessor functions.
char *gymMember::getName()
{
	return this->name;
}
float gymMember::getHeight()
{
	return this->height;
}
unsigned short int *gymMember::getDate()
{
	return this->joinDate;
}
unsigned short int gymMember::getFitnessScore()
{
	return this->fitnessScore; 
}

//***********************************************************************************************

//********************** FREIND FUNCTIONS OF gymMember *****************************************

//Overloaded << operator for gymMember.
ostream& operator<<(ostream& output,gymMember & member)
{
	//Displays data. 
	output<<setw(25)<<member.getName()<<" "
	      <<setw(15)<<member.getFitnessScore()<<" "
		  <<setw(10)<<member.getHeight()<<" "
		  <<member.getDate()[0]<<"/"<<member.getDate()[1]<<"/"<<member.getDate()[2]<<endl;

	return output; 
}

//************************************************************************************************