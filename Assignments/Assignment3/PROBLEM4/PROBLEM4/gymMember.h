//gymMember.h
//December 9, 2008
//Andrew Ribeiro
//This file contains the Class that is required,for extra credit, by Assignment 3.

#ifndef GYMMEMBER_H
#define GYMMEMBER_H

#include<ostream> 
#include<iostream>
using namespace std;

//The size of the name array.
const int MAX_SIZE_OF_MEMBER_NAME = 50;

class gymMember 
{
public:

	//Constructors 
	gymMember();
	gymMember(char *name,float height,unsigned short int *date,unsigned short int fitnessScore);

	//Accessor functions
	char *getName();
	float getHeight();
	unsigned short int *getDate();
	unsigned short int getFitnessScore(); 

	//Mutator functions
	void setName(char *name);
	void setHeight(float height);
	void setDate(unsigned short int *date);
	void setFitnessScore(unsigned short int fitnessScore);

	//Class freinds.
	friend ostream& operator <<(ostream& output,gymMember &member);

private:

	//Contains the name of the member.
	char name[MAX_SIZE_OF_MEMBER_NAME]; 
	
	//Contains the height of the member.
	float height;

	//Contains the date of the member.
	unsigned short int joinDate[3]; //[0] = mm,[1] = dd, [2] = yyyy

	//Contains the fitness score of the member. 
	unsigned short int fitnessScore;
};

#endif


