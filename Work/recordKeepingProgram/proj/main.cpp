//main.cpp
/*#############################################################
  #|||||||||||||||||\\      // |||||||||   ||||||||||=====    #
  #||  ||  ||     || \\    //  ||     ||   ||      ||    //   #
  #||  }{  ||{}{}{||  \\  //   ||{}{}{|||||||{}{}{}||   //    #
  #||      ||     ||   \\//    ||     ||   ||      ||  //=====#
  #############################################################*/
//This program is a simple record keeping program.


#include <iostream>
#include "structs.h"
#include <vector>
#include <cmath>
using namespace std; 

	//Define global variables 

	vector<record> arrayOfRecords; 

	//End defining globals
	
	//Function Prototypes
	void newRecord(double age,double employee,double gpa,double married,
							double weight, double gender,double id);
	void addRecordToGlobalArray(double id, record *recordPointer);
	void viewRecords();
	
	//End function Prototypes


int main()
{

//### Start menu #######################

	unsigned int usersChoice;
	bool breakConditionMenuLoop = false,menuLoopBreakConditon = false;
	
	do
	{
		cout<<"   Welcome to the record keeping program  "<<endl<<endl
			<<"What would you like to do:"<<endl
			<<"1)Veiw Records"<<endl
			<<"2)Create a new record"<<endl 
			<<"3)Exit"<<endl
			<<"Enter your choice: ";
		cin>>usersChoice; 

		do
		{
			switch(usersChoice)
			{
			case 1:

				cout<<"###  View Records Mode  ###"<<endl<<endl<<endl;

				if (arrayOfRecords.size() == 0)
				{
					cout<<"There are no records on file."<<endl<<endl;
				}

				viewRecords();

				breakConditionMenuLoop = true;
				break;
			case 2:
				//newRecord function call.
				//(age,employee,gpa,married,weight,gender,id)

				double weight,gpa,employee,married,gender,age,id;

				cout<<endl<<endl<<"   New record entry mode   "<<endl<<endl
					<<"Is this individual an employee(1 = yes,0 = no): ";
				cin>>employee; 
				cout<<endl<<"What is the individuals age: ";
				cin>>age;
				cout<<endl<<"What is the individuals gpa: ";
				cin>>gpa;
				cout<<endl<<"Is the individual married(1 = yes,0 = no): ";
				cin>>married;
				cout<<endl<<"What is the individuals weight: ";
				cin>>weight;
				cout<<endl<<"What is the individuals genter(1= M,0=F): ";
				cin>>gender;
				if (employee == true)
				{
					cout<<endl<<"What is the individuals id: ";
					cin>>id;
				}
				else
				{
					id = 0;
				}
				
				if( (age > 0 && age <= 120) && (employee == true || employee == false)  
						&& (married == true || married == false) && (gpa >= 0 || gpa <=4) 
							&& (id == false || id >= 0 && id <= pow(2.0,31))
								&& (gender == 1 || gender == 0))
				{
					newRecord(age,employee,gpa,married,weight,gender,id);
					cout<<"\nRecord succesfuly added!"<<endl<<endl;
				}
				else
				{
					cout<<"Invalid entry"<<endl;
				}

				//Returns user to the menu

				breakConditionMenuLoop = true;
				break;

			case 3:
				//Exit

				breakConditionMenuLoop = true;
				menuLoopBreakConditon = true;
				break;

			default:
				cout<<"Please enter a correct choice: ";
				cin>>usersChoice;
			}
			

		}while(!breakConditionMenuLoop);
	}while(!menuLoopBreakConditon);

//### End menu #####################################################
	
	return 0; 
}


void newRecord(double age,double employee,double gpa,double married,
						double weight, double gender,double id)
{

	record *recordPointer; //Create a record class pointer. 

	recordPointer = new record(age,employee,gpa,married,weight,gender,id); //point to a new record

	addRecordToGlobalArray(id,recordPointer);//add the record to the global record array

}

void addRecordToGlobalArray(double id, record *recordPointer)
{
	//This adds the record to the array.
	arrayOfRecords.push_back(*recordPointer);
}

void viewRecords(int condition)
{
	for(unsigned i = 0; i < arrayOfRecords.size(); i++)
	{
		arrayOfRecords[i].printRecordData();
	}
}

