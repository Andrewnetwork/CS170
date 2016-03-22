//ControlStatementsHw_2.cpp
//Andrew Ribeiro
//September 30, 2008
//From Home work .doc from the control statements lectures. 

/*
2.	Write a program to calculate the number of days between two given dates within the same year.
	For simplicity you may ignore leap years. How would your program change if the dates can be in different years? 
	How would it change if you want to include leap year calculations?
*/
#include <iostream>
using namespace std;
int safeGetInt(int yMin, int yMax);

int main()
{
	int mm1,dd1,mm2,dd2,totalDays = 0;
	int monthDays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; //Ex: 1 = january,2 = febuary,........,12= december
	cout<<"Enter in the first month: ";
	mm1 = safeGetInt(1,12);
	cout<<"Enter in the day of that month: ";
	dd1 = safeGetInt(1,31);
	cout<<"Enter in the second month: ";
	mm2 = safeGetInt(1,12);
	cout<<"Enter in the of the day of that month: ";
	dd2 = safeGetInt(1,31);

	//Since distance is measured in abs terms. The largest month will be determined 

	if(mm1 > mm2)
	{
		totalDays +=  monthDays[mm1] - dd1; //How many days are left in the last month
		totalDays += monthDays[mm2] - dd2; //How many days are left in the first month 
		
		

		//Loop through the days in between the two months.
		for(int m = (mm2 + 1); m < mm1; m++)
		{
			totalDays += monthDays[m];
		}
	
	}
	if(mm1 == mm2)
	{
		if (dd2 > dd1)
		{
			totalDays += dd2 - dd1;
		}
		else if( dd2 == dd1)
		{
			totalDays += 0;
		}
		else
		{
			totalDays += dd1 - dd2;
		}
	}
		
	else
	{
		totalDays +=  monthDays[mm2] - dd2; //How many days are left in the first month
		totalDays +=  monthDays[mm1] - dd1; //How many days are left in the last month 
		
		

		//Loop through the days in between the two months.
		for(int m = (mm1 + 1); m < mm2; m++)
		{
			totalDays += monthDays[m];
		}
	}

	cout<<"The amount of days between these two dates is: "<<totalDays<<endl;
	system("pause");
	return 0;
}

int safeGetInt(int yMin, int yMax)
{
	//Used to check errors in input.  

	int userIn;
	cin>>userIn; 

	while(!cin.good() || ( userIn < yMin || userIn > yMax))
	{
		cout<<"Enter a valid value: ";
		cin.clear();
		cin.ignore();
		cin>>userIn;
	}

	return userIn;
}
