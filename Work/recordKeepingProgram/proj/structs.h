//structs.h
//Andrew Ribeiro 
/* Notes

>The difference between classes and structs is that structs are purely public. 
>Each ID should be no more than 5 digits long.

end notes */

#ifndef MYHEADER_H
#define MYHEADER_H


#include <iostream>
#include <string>
using namespace std; 


struct record
{
	double age;
	double weight;
	double gpa; 
	double married; 
	double employee;
	double id; 
	double gender;

	double* accessRecordData();

	void printRecordData();

	record(double age,double employee,double gpa,
			double married,double weight, double gender, double id); 
};

//Returns an array that containes all the values of the struct.
double* record::accessRecordData()
{
	double *p1,age = record::age,employee = record::employee,
		gpa = record::gpa,married = record::married, weight = record::weight, 
		gender = record::gender, id = record::id;
	
	
	
	p1 = new double[6]; 
	p1[0] = age;
	p1[1] = employee;
	p1[2] = gpa;
	p1[3] = married;
	p1[4] = weight;
	p1[5] = gender; 
	p1[6] = id; 
	

	return p1; //Returns an array with all of the record data stored in it.

}

void record::printRecordData()
{
	double *recordData;
	recordData = record::accessRecordData(); //recordData is made to point to the returned array

	//Describes the printed out data. 
	string label[7] = {"Age: ","Is an employee: ","GPA: ","Married: ","Weight: ","Gender: ","Id: "};
	
	string one = "yes",two = "no",labelSub;

	for(int i = 0; i < 7;i++)
	{
		//Edit so 2 is read

		//Set up the output so the boolean values correspond to yes or no. 
		if ((i == 1 && recordData[i] == 1) ||  (i == 3 && recordData[i] == 1)||
				(i == 5 && recordData[i] == 1))
		{
			if (i == 5)
			{
				one = "M";
			}

			cout<<label[i]<<one<<endl;

			one = "yes"; 
		}
		else if ((i == 1 && recordData[1] == 1) || i == 3 && recordData[i] == 0 ||
					(i == 5 && recordData[i] == 0))
		{
			
			if (i == 5)
			{
				one = "F";
			}

			cout<<label[i]<<two<<endl;

			two = "no";
		}
		else
		{
			cout<<label[i]<<recordData[i]<<endl;
		}
	}

	cout<<endl;

}

record::record(double age,double employee,double gpa,double married,double weight,
			   double gender, double id)
{
	record::age = age;
	record::employee = employee;
	record::gpa = gpa;
	record::married = married;
	record::weight = weight; 
	record::gender = gender;
	record::id = id;
	
}
