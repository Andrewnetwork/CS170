//PROBLEM2_FUNCTIONS.cpp
//Andrew Ribeiro
//December 2, 2008

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "ToolRecord.h"
using namespace std;  

//Global file object.
fstream saveFile;

//How large the ToolRecord array is. The zeroth element is a garbage value.
#define SIZE_OF_RECORD_ARRAY 101


//The arrays for the safeInput function. These are the charicters allowed.
const char validChars[] = {'1','2','3'}; 

const char validChoicesForEditMenu[] = {'1','2','3','4','5','6'};

const char validChoicesForMainMenu[] = {'1','2','3','4','5','6'};


const char validCharsYN[] = {'Y','N'}; 

//Gets numeric data and validates the input.
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

//Validates userInput by checking if the input is in the validChars array. 
bool isCharValid(char const validChars[],char userInput)
{
	char ch = 'r'; //Charicter in the array, it is initilised to an arbirary value. 

	for(int index =0; ch != '\0'; index++)
	{
		ch = validChars[index]; 

		if(userInput == ch)
		{
			//If the users input is a valid charicter, return true for the function
			return true;
		}
	}

	return false; 
}

//Asks a user to enter in values in the validChars array
char safeInput(string errorMessage,string prompt,const char validChars[])
{
	//Will convert the user input to upper case charicters. 
	char userIn;

	cin>>userIn;
	userIn = toupper(userIn);

	//Loop if there is errors and if the users input is invalid. 
	
	while(!cin.good() || !isCharValid(validChars,userIn) )
	{
		cout<<errorMessage<<endl
			<<prompt;

		cin.clear();
		cin.ignore(80,'\n');
		cin>>userIn;
		userIn = toupper(userIn);
	}

	return userIn; 
}

//Checks if a record exists, or if it has data.
bool recordExists(int recordNumber,ToolRecord *arrayOfRecordData)
{
	if(arrayOfRecordData[recordNumber].cost >= 0 && arrayOfRecordData[recordNumber].toolName.length() >= 1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

//The menu for editing record data.
void editRecord(ToolRecord record,ToolRecord *arrayOfRecordData)
{

	bool loopControl = true;
	
	do
	{
		char menuChoice;
		cout.precision(2);
		cout.setf(ios::fixed,ios::floatfield);
		cout<<endl
			<<"***************************** RECORD DATA *****************************"<<endl
			<<"* Record number: "<<record.recordNumber<<endl
			<<"* Tool name: "<<record.toolName<<endl
			<<"* Tool quanity: "<<record.quantity<<endl
			<<"* Tool cost: "<<record.cost<<endl
			<<"**********************************************************************"<<endl
			<<"**** EDIT RECORD DATA FOR RECORD "<<record.recordNumber<<" ***********"<<endl
			<<"* 1.)Edit record number."<<endl
			<<"* 2.)Edit tool name."<<endl
			<<"* 3.)Edit tool quantity."<<endl
			<<"* 4.)Edit tool cost."<<endl
			<<"* 5.)Edit all."<<endl
			<<"* 6.)Exit."<<endl
			<<"*"<<endl
			<<"* Please chose a number: ";
		menuChoice = safeInput("*\n*   WARNING: Please enter a vaild number!\n*",
			                                          "* Enter(1,2,3,4,5,or 6): ",validChoicesForEditMenu);

		switch(menuChoice)
		{
		case '1':
			//Edit record number.
				
			while(true)
			{
				int inputedRecordNumber;
				char usersContinuationChoice; 
				cout<<"\nPlease enter the number you would like this record to have: ";

				inputedRecordNumber  = safeInput("\n     WARNING: You have entered an invalid record number!",
															   "\nPlease enter a record number 1-100: ",1,100);

				if(!recordExists(inputedRecordNumber,arrayOfRecordData))
				{
					//If record does not exist... 

					//Make a blank record.
					ToolRecord blankRecord;

					//Assign the record to a diferent index location.
					arrayOfRecordData[inputedRecordNumber] = record;
					//Delete the record at the previous location, replace with a blank record.
					arrayOfRecordData[record.recordNumber] = blankRecord; 
					//Change the record ID/ number to ne new number.
					arrayOfRecordData[inputedRecordNumber].recordNumber = inputedRecordNumber;

					cout<<"\nRecord number/tool ID successfuly changed from "<<record.recordNumber<<" to "
						<<inputedRecordNumber<<endl;

					//For this menus display, we update the record number for this local copy of the record.
					record.recordNumber = inputedRecordNumber; 


					break;
				}
				else
				{
					//If a record exists with the record number that the user wants this record to be
					//warn the user and say the user cannot do it. The proper way would be to delete
					//a record first, then change the record ID.

					cout<<"\n    WARNING: A record with this id/number exists! "<<endl; 
					cout<<"Try again(Y/N)? ";
					usersContinuationChoice = safeInput("     \nWARNING: You have entered an invalid choice",
																					  "Enter(Y/N): ",validCharsYN);
					if(usersContinuationChoice == 'N')
					{
						break;
					}

				}
			}
			break;
		case '2':
			//Edit tool name.
				
			while(true)
			{
				string toolName; 
				cout<<"\n	NOTICE: You can press -1 to cancel the entry."<<endl
				    <<"\nPlease enter the new name for this tool: ";
				//No need for error checking... it is a string.

				
				
				//Clear the stream if there are any stray bits. 
				cin.clear();
				cin.ignore(80,'\n');
				getline(cin,toolName,'\n');
				
				//If toolName == -1, the user wants to cancel the entry. 
				if(!toolName.compare("-1"))
				{

					break;
				}

				cout<<endl<<"You changed this tools name from "<<record.toolName<<" to "
					<<toolName<<"."<<endl<<endl;

				//Update the main data array.
				arrayOfRecordData[record.recordNumber].toolName = toolName;

				//Update the local instance of the object.
				record.toolName = toolName;



				

				break;
			}

			break;
		case '3':
			//Edit tool quantity 

			
			int quantity;

			cout<<"\n	NOTICE: You can press -1 to cancel the entry."<<endl
			    <<"\nEnter the quantity for this tool: ";

			quantity = safeInput<int>("\n      WARNING: You have entered an invalid number!",
													              "\nEnter a valid number: ",-1,-4);
			if(quantity != -1)
			{
				arrayOfRecordData[record.recordNumber].quantity = quantity; 

				cout<<"You have changed the quantity from "<<record.quantity<<" to "<<quantity<<"."<<endl;

				record.quantity = quantity; 
			}

				

		
			break;
		case '4':
			//Edit tool cost

			break;
		case '5':
			//Edit all feilds.
			break;
		case '6':
			//The user wanted to exit the editing mode, so the loop control is set to false.
			loopControl = false; 
			break;

		default:
			cout<<endl<<"WARNING: CRITICAL ERROR!"<<endl;
		}
	}while(loopControl);

}
void recordInterface(ToolRecord record,ToolRecord *arrayOfRecordData)
{
	int menuChoice;
	cout<<"\n**************** Tool Record ****************"<<endl
		<<"* Tool id: "<<record.recordNumber<<endl
		<<"* Tool name: "<<record.toolName<<endl
		<<"*"<<endl
		<<"* 1.)Edit record information. "<<endl
		<<"* 2.)Delete record. "<<endl
		<<"* 3.)Exit menu. "<<endl
		<<"*"<<endl
		<<"* Please chose a number: ";	
	menuChoice = safeInput("*\n*   WARNING: Please enter a vaild number!\n*","* Enter(1,2, or 3): ",validChars);

	switch(menuChoice)
	{
	case '1':
		editRecord(record,arrayOfRecordData);
		break;
	case '2':
		//Delete record

		//Needed to add this block because cases do not have a scope. 
		//Deleting a record
		{
			char usersContinuationChoice; 
			ToolRecord blankRecord;
			cout<<"\n        WARNING: You are about to delete this record("<<record.recordNumber<<")!\n"<<endl;
			cout<<"Do you wish to proceed(Y/N): ";

			usersContinuationChoice = safeInput("\n    WARNING: You have entered an invalid choice",
																				 "Enter(Y/N): ",validCharsYN);
			if(usersContinuationChoice == 'Y')
			{
				arrayOfRecordData[record.recordNumber] = blankRecord; 
				cout<<"\n        NOTICE: You have deleted this record("<<record.recordNumber<<")!\n"<<endl;
			}
		}
		
		
		break;
	case '3':
		break;
	default:
		cout<<endl<<"WARNING: CRITICAL ERROR!"<<endl;
	}
	
}

//Lists the records that contain data.
void listRecords(ToolRecord *arrayOfRecordData)
{
	cout<<"\n******* RECORD LIST ******"<<endl<<endl;

	//Counts how many records--non-blank-- are in the array.
	int recordCounter = 0;

	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	cout.setf(ios::left);

	//Output table header
	cout<<setw(10)<<"Record #"
		<<setw(30)<<" Tool Name"
		<<setw(10)<<"  Quantity"
		<<setw(10)<<"   Cost"<<endl
		<<"*****************************************************************"<<endl;

	for(int i = 1; i < SIZE_OF_RECORD_ARRAY; i++)
	{
		if(recordExists(i,arrayOfRecordData))
		{
			cout<<setw(10)<<arrayOfRecordData[i].recordNumber<<" "
				<<setw(30)<<arrayOfRecordData[i].toolName<<" "
				<<setw(10)<<arrayOfRecordData[i].quantity<<" "
				<<setw(10)<<arrayOfRecordData[i].cost<<endl<<endl;
			recordCounter++;
		}
		else
		{
			continue;
		}
	}

	if(recordCounter == 0)
	{
		cout<<"\nNo records found!"<<endl;
	}

}
//Makes a new record, allows the user to enter data for the new record.
void makeNewRecord(ToolRecord *arrayOfRecordData)
{
	ToolRecord temp;
	int indexOfRecord = -1;

	for(int i = 1; i < SIZE_OF_RECORD_ARRAY; i++)
	{
		if(!recordExists(i,arrayOfRecordData))
		{
			//If the record does not exist at index i, i will be the location of the new record.
			indexOfRecord = i; 
			break;

		}
	}

	if(indexOfRecord > 0)
	{

		//Header
		cout<<"\n\n***************** NEW RECORD "<<indexOfRecord<<" ****************"<<endl;

		//Prompt and get tool name
		cout<<"* Tool name: ";
		string toolName;
		cin.clear();
		cin.ignore(80,'\n');
		getline(cin,toolName,'\n');

		temp.toolName = toolName;

		//Prompt and get quantity
		cout<<"* Quantity: "; 
		temp.quantity = safeInput<int>("*\n*     WARNING: You have entered an invalid number!",
															  "\n* Enter a valid number: ",0,-4);

		//Prompt and get cost.
		cout<<"* Cost: ";
		temp.cost = safeInput<float>("*\n*      WARNING: You have entered an invalid number!",
																  "\n*Enter a valid number: ",0,-4);

		//Footer
		cout<<"****************************************************************"<<endl<<endl;
		
		temp.recordNumber = indexOfRecord;
		
		arrayOfRecordData[indexOfRecord] = temp;
	}
		
	else
	{
		//The array is full.
		cout<<"\n       WARNING: Unable to create a new record, all spaces are full!\n"<<endl;
	}
}
//The main menu for the program. 
void mainMenu(ToolRecord *arrayOfRecordData)
{
	while(true)
	{
		char menuChoice;
		cout<<"\n************* Main Menu ****************"<<endl
			<<"* 1.) List all records. "<<endl
			<<"* 2.) Modify a record by ID. "<<endl
			<<"* 3.) Delete all records. "<<endl
			<<"* 4.) Save modifications. "<<endl
			<<"* 5.) Create a record. "<<endl
			<<"* 6.) Exit program."<<endl
			<<"*"<<endl
			<<"* Please chose a number: ";	
		menuChoice = safeInput("*\n*   WARNING: Please enter a vaild number!\n*",
													  "* Enter(1,2,3, or 4): ",validChoicesForMainMenu);

		
		
		ToolRecord blankArray[SIZE_OF_RECORD_ARRAY];
		int indexOfRecord = -1; 

		switch(menuChoice)
		{
		case '1':
			//List all records.

			listRecords(arrayOfRecordData);
			break;
		case '2':
			//Modify a record by the record number/ID

			while(true)
			{
				int userInput; 
				char usersContinuationChoice; 
				cout<<endl<<"Please enter the record number of the record that you wish to modify: ";

				userInput = safeInput("\n     WARNING: You have entered an invalid record number!",
															   "\nPlease enter a record number 0-99: ",0,99);

				if(recordExists(userInput,arrayOfRecordData))
				{
					recordInterface(arrayOfRecordData[userInput],arrayOfRecordData);
					break;
				}
				else
				{
					cout<<"\n    WARNING: Record does not exist "<<endl; 
					cout<<"Try again(Y/N)? ";
					usersContinuationChoice = safeInput("\n    WARNING: You have entered an invalid choice",
		                                                                              "Enter(Y/N): ",validCharsYN);
					if(usersContinuationChoice == 'N')
					{
						break;
					}

				}
			}
			break;
		case '3':
			//Delete all records 
			//This means overwrite all records and make them blank.
			char usersContinuationChoice; 

			cout<<"\n        WARNING: You are about to delete all records!\n"<<endl;
			cout<<"Do you wish to proceed(Y/N): ";

			usersContinuationChoice = safeInput("\n    WARNING: You have entered an invalid choice",
		                                                                         "Enter(Y/N): ",validCharsYN);
			if(usersContinuationChoice == 'Y')
			{
				arrayOfRecordData = blankArray;
				cout<<"\n        NOTICE: You have deleted all records!\n"<<endl;
			}

			

			break;
		case '4':
			//Saves the modifications.
			
			//Opens the file for writing.
			saveFile.open("hardware.dat", ios::in |ios::out| ios::binary);
			if (saveFile.bad())
			{
				cout<<endl<<"		WARNING: Cannot read file!\n"<<endl;
			}
			else
			{
				//Writes the arrayOfRecords to the file, which stores all the updated information.
				saveFile.seekg(0,ios::beg);
				//Here I am writing the address of the arrayOfRecords in the main part of the program.
				saveFile.write((char *)&*arrayOfRecordData, sizeof(ToolRecord)*101 );
				cout<<"\n     NOTICE: You have successfuly saved your modifications."<<endl<<endl;
			}

			saveFile.close();

			break;
		case '5':
			//Create a record
			//Note: the user is not creating a record... the user is giving properties to a blank one.
			makeNewRecord(arrayOfRecordData);
	
			break;
		case '6':
			//Exits the program
			cout<<endl<<"Exiting the program. ";
			exit(0);
			break;
		}
	}

}