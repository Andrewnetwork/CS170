//mixedDataList.h
//Andrew Ribeiro 
/*Purpose of class: This class will allow for the creation of mixed data lists. The data
types supported here will be: double and int.

To test and see if the returned value was the returned value of the array, check the tempPassKey, that is the value that was
passed.
*/


#ifndef MIXEDDATALIST_H
#define MIXEDDATALIST_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;



class MixedList
{
public:
	void inputValue(double inVal);
	void inputValue(int inVal);
	double returnDouble(int setElement);
	int returnInteger(int element); 
	int setVal(int element);
	MixedList();

	
	
	
	double tempGetDoubleVal; //These values are used to return the values 
	int tempGetIntegerVal; 
	


private:
	vector<int> intValues;
	vector<double> dblValues; 
	vector<int> orderOfIntVals;
	vector<int> orderOfDoubleVals;
	double elementsInVector;
	bool checkVectorForNumber(double checkDoubleVectorForDigit); //Returns 0 if not found, Returns 1 if found. 
	bool checkVectorForNumber(int checkIntegerVectorForDigit);

	double tempPassKey; 

	int tempElementChoice; 

};

//Begin Overloaded input functions. 
void MixedList::inputValue(int inVal)
{
	intValues.push_back(inVal);
	orderOfIntVals.push_back(elementsInVector);
	orderOfDoubleVals.push_back(-1);//Sets the location to -1 to denote that there is not
	//a value at this location.
	elementsInVector++;
}

void MixedList::inputValue(double inVal)
{

	dblValues.push_back(inVal);
	orderOfDoubleVals.push_back(elementsInVector);
	orderOfIntVals.push_back(-1); //Sets the location to -1 to denote that there is not
	//a value at this location.
	elementsInVector++;
}
//End Overloaded input functions. 

//Sets the the temporary element choice value to the element selected, and 
//then returns if the element is in the int array or double array. 
int MixedList::setVal(int element)
{
	MixedList::tempElementChoice = element; 
	
	for (unsigned int i = 0; i < orderOfIntVals.size();i++)
	{
		if (orderOfIntVals[i] == element)
		{
			return 1;

		}
	}

	for (unsigned int i = 0; i < orderOfDoubleVals.size();i++)
	{
		if (orderOfDoubleVals[i] == element)
		{
			return 2;

		}
	}

}

int MixedList::returnInteger(int element)
{

	for(unsigned int i = 0; i < MixedList::orderOfIntVals.size();i++)
	{
		//If the element is the element picked by the user
		if (MixedList::orderOfIntVals[i] == element)
		{
			//Return the int value that corresponds to the element location
			//Ex: the 1 element is at [0] of the oder of int vals vector
			//therefore the element [0] located in the intValues vector will correspond
			//to the element inputed by the user.
			return MixedList::intValues[i] ;
		}
	}
	
	MixedList::tempPassKey = 0;

	for(;;)
	{
		if (MixedList::checkVectorForNumber(static_cast<int>(MixedList::tempPassKey)) == 1)
		{
			MixedList::tempPassKey++;
			
		}
		else
		{
			return MixedList::tempPassKey;
		}

	}

		
	

}

double MixedList::returnDouble(int setElement)
{
	for(unsigned int i = 0; i < MixedList::orderOfDoubleVals.size();i++)
		{
			//If the element is the element picked by the user
			if (MixedList::orderOfDoubleVals[i] == MixedList::tempElementChoice)
			{
				//Return the double value that corresponds to the element location
				return MixedList::dblValues[MixedList::orderOfDoubleVals[i]] ;
		
			}
		}
	
	MixedList::tempPassKey = 0.0;
	
	for(unsigned int i = 0; i < MixedList::dblValues.size();i++)
	{
		
		if (MixedList::checkVectorForNumber(MixedList::tempPassKey) == 1)
		{
			MixedList::tempPassKey++;
		}
		else
		{
			return MixedList::tempPassKey;
		}
	}

}



bool MixedList::checkVectorForNumber(double checkDoubleVectorForDigit)
{
	
		for(unsigned int i = 0; i < MixedList::dblValues.size();i++)
		{
			
			if (MixedList::dblValues.size() == checkDoubleVectorForDigit)
			{
				return 1;
		
			}
	
			else
			{
				return 0;
			}
		}
	
}

bool MixedList::checkVectorForNumber(int checkIntegerVectorForDigit)
{
	
		for(unsigned int i = 0; i < MixedList::dblValues.size();i++)
		{
			
			if (MixedList::dblValues.size() == checkIntegerVectorForDigit)
			{
				return 1;
		
			}
		
			else
			{
			return 0;
			}
		}
	
}


MixedList::MixedList()
{
	MixedList::elementsInVector = 0;
	MixedList::tempGetDoubleVal = 0;  
	MixedList::tempGetIntegerVal = 0; 
}



#endif //MIXEDDATALIST_H