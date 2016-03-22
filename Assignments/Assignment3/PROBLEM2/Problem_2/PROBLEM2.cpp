//PROBLEM2.cpp
//Andrew Ribeiro
//December 2, 2008

#include <iostream>
#include<fstream>
#include<string>
#include "ToolRecord.h"
using namespace std;

//How many records are allowed to be in the file. 
#define SIZE_OF_RECORD_ARRAY 101

//Global file object
fstream readFile; 


//************* Function prototypes ***************
char safeInput(string errorMessage,string prompt,const char validChars[]);

void mainMenu(ToolRecord *arrayOfRecordData);


//******** Global allowable charicter in the various menus *********

const char validChoicesForCreateMenu[] = {'Y','N'}; 

int main()
{


	//Print header
	cout<<"********************************************************"<<endl
		<<"*                 HARDWARE STORE INVENTORY             *"<<endl
		<<"* This program allows you to:                          *"<<endl
		<<"* 1.) Make a hardware.dat file if it does not exist    *"<<endl
		<<"* 2.) Create and destroy records                       *"<<endl
		<<"* 3.) Save record modifications to records.            *"<<endl
		<<"* 4.) Modify all data pertaining to the records.       *"<<endl
		<<"* Enjoy maintaining your inventory with this program!  *"<<endl
		<<"********************************************************"<<endl<<endl;
	
	bool createNewFile = false; 
	ToolRecord arrayOfRecords[SIZE_OF_RECORD_ARRAY];

	readFile.open("hardware.dat", ios::in | ios::binary);

	
	//Check and see if there is a file called hardware.dat
	if (!readFile)
    {
		char usersChoice ;
		cout<<" \n    WARNING: There is no existing inventory file!\n"<<endl
			<<"Would you like to create one(Y/N): ";
		usersChoice = safeInput("     \nWARNING: You have entered an invalid choice",
			                                              "Enter(Y/N): ",validChoicesForCreateMenu);

		switch(usersChoice)
		{
		case 'Y':
			createNewFile = true;
			break;
		case 'n':
			/*
			 * If the users does not want to create a inventory file and there is not one to read, there
			 * is nothing for the user to do in the program. So the program exits.
			 */
			cout<<"\nExiting the program. ";
			exit(0);
			break; 
		}
	}


	//close the file so it can be opened for reading or writing.
	readFile.close();
	

	if(createNewFile)
	{
		//Creates a new file will the pre-inserted records that are specified in the assignment.
		cout<<"Creating a new file..."<<endl;
		//open the file for writing
		readFile.open("hardware.dat",  ios::in | ios::out | ios::trunc | ios::binary);

		//Define preset items.
		ToolRecord temp; 

		//Electric Sander.
		temp.recordNumber = 3;
		temp.toolName = "Electric Sander";
		temp.quantity = 7;
		temp.cost = 57.98;
		arrayOfRecords[temp.recordNumber] = temp;

		//Hammer 
		temp.recordNumber = 17;
		temp.toolName = "Hammer";
		temp.quantity = 76;
		temp.cost = 11.99;
		arrayOfRecords[temp.recordNumber] = temp;

		//Jig Saw
		temp.recordNumber = 24;
		temp.toolName = "Jig Saw";
		temp.quantity = 21;
		temp.cost = 11.00;
		arrayOfRecords[temp.recordNumber] = temp;

		//Lawn Mower
		temp.recordNumber = 39;
		temp.toolName = "Lawn Mower";
		temp.quantity = 3;
		temp.cost = 79.50;
		arrayOfRecords[temp.recordNumber] = temp;

		//Power Saw
		temp.recordNumber = 56;
		temp.toolName = "Power Saw";
		temp.quantity =18;
		temp.cost = 99.99;
		arrayOfRecords[temp.recordNumber] = temp;

		//Screw-driver
		temp.recordNumber = 68;
		temp.toolName = "Screw-driver";
		temp.quantity = 106	;
		temp.cost = 6.99;
		arrayOfRecords[temp.recordNumber] = temp;

		//Sledge Hammer
		temp.recordNumber = 77;
		temp.toolName = "Sledge Hammer";
		temp.quantity = 11;
		temp.cost = 6.99;
		arrayOfRecords[temp.recordNumber] = temp;

		//Wrench
		temp.recordNumber = 83;
		temp.toolName = "Wrench";
		temp.quantity = 34;
		temp.cost = 7.50;
		arrayOfRecords[temp.recordNumber] = temp;

		readFile.seekg(0,ios::beg);
		readFile.write( (char *)&arrayOfRecords, sizeof(ToolRecord)*100);

		mainMenu(arrayOfRecords);
	
	}
	else
	{
		//If we do not want to create a file, we want to read an existing one.
		//open the file for reading.
		readFile.open("hardware.dat", ios::in |ios::out| ios::binary);

		readFile.seekg(0,ios::beg);
		readFile.read((char *)&arrayOfRecords, sizeof(ToolRecord)*100 );
		
		readFile.close();
		
		mainMenu(arrayOfRecords);
		
	}


	

	return 0;
}