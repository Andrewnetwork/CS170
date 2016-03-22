//functions.h
//Andrew Ribeiro
/* File discription

>This file containes the functions neccesary to manipulate the data from main.cpp
>Functions include:
-newRecord.



end file diescription*/

/*record varname(double age,double employee,double gpa,double married,
						double weight, double gender)*/
/*
#include "structs.h"
using namespace std;

void addRecordToGlobalArray(double id, record *recordPointer);

void newRecord(double age,double employee,double gpa,double married,
						double weight, double gender,double id)
{
	record *recordPointer;

	recordPointer = new record(age,employee,gpa,married,weight,gender,id);

	addRecordToGlobalArray(id,recordPointer);


}

void addRecordToGlobalArray(double id, record *recordPointer)
{
	//arrayOfMemoryLocationsOfRecordArrays
					 
	int sizeOfArray = arrayOfMemoryLocationsOfRecordArrays.size();
	arrayOfMemoryLocationsOfRecordArrays.resize(sizeOfArray + 1);  
    arrayOfMemoryLocationsOfRecordArrays[sizeOfArray].resize(sizeOfArray + 1);
	arrayOfMemoryLocationsOfRecordArrays[sizeOfArray][sizeOfArray] = id ;
	arrayOfMemoryLocationsOfRecordArrays[sizeOfArray + 1][sizeOfArray + 1] = recordPointer;
}

*/