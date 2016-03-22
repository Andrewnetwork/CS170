//gymMember.h
//Andrew Ribeiro 
//December 6, 2008

#ifndef GYMMEMBER_H
#define GYMMEMBER_H

#include<ostream> 
#include<iostream>
using namespace std;

struct gymMember
{
	char name[50]; 
	float height;
	unsigned short int joinDate[3]; //[0] = mm,[1] = dd, [2] = yyyy
	unsigned short int fitnessScore;

	//Function prototypes
	friend ostream& operator <<(ostream& output,gymMember &member);
	friend void getData(gymMember &member); 

};

#endif