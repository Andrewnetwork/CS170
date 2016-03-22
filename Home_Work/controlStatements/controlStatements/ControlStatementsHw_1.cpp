//ControlStatementsHw_1.cpp
//Andrew Ribeiro
//September 30, 2008
//From Home work .doc from the control statements lectures. 

/*
1.)Write a program which gives the insurance premium to be paid each year on a life insurance policy under these rules:
	a.	The rate in dollars per $1000 insured  changes with age:
		i.	Age < 40			$10 per $1000 insured
		ii.	Age between 40 and 59	$15 per $1000 insured 
		iii.	Age 60 and over		$20 per $1000 insured
	b.	If the policy holder is unfit multiply the premium by an extra 1.2
	c.	If the policy holder smokes multiply the premium by an extra 2.0
	d.	If unfit and smoker and age 60 or over display a message “Cannot insure”, otherwise display the final vale of the 
	    premium.

//Notes
>Since the program did not specify if an individual could be charged less 1000 or above I created a formula that would 
allow for the coverage of a value like 600, in relation to the original ratio. 
*/

#include <iostream>

using namespace std;

double calculatePremium(int age,char smokeIn,char unfitIn,double amountOfInsurance);

const double unfit = 1.2, smokes = 2; //Global variables.

int main()
{
	double premium,amountOfInsurance;
	int age;
	char smokeIn,unfitIn; 
	

	cout<<"Welcome to the life insurance cost calculator!"<<endl<<endl
		<<"Please enter how much insurance coverage you would like to have: ";
	cin>>amountOfInsurance; 

	while(!cin.good()) //Error checking.
	{
		cout<<"\nInvalid entry!"<<endl
			<<"Please enter how much insurance coverage you would like to have: ";
		cin.clear();
		cin.ignore();
		cin>>amountOfInsurance;
	}

	cout<<"\nEnter your age: ";
	cin>>age; 

	while(!cin.good() && age < 0) //Error checking.
	{
		cout<<"\nInvalid entry!"<<endl
			<<"Enter your age: ";
		cin.ignore();
		cin.clear();
		cin>>age;
	}

	cout<<"\nDo you smoke (y/n): ";
	cin>>smokeIn;

	while(!cin.good() && !(smokeIn == 'y' || smokeIn =='n')) //Error checking.
	{
		cout<<"\nInvalid entry!"<<endl
			<<"\nDo you smoke (y/n): ";
		cin.clear();
		cin.ignore();
		cin>>smokeIn;
	}

	cout<<"\nAre you fit (y/n): ";
	cin>>unfitIn;

	while(!cin.good() && !(unfitIn == 'y' || unfitIn =='n')) //Error checking.
	{
		cout<<"\nInvalid entry!"<<endl
			<<"\nAre you fit (y/n): ";
		cin.clear();
		cin.ignore();
		cin>>unfitIn;
	}

	//If the function does not return 0, or if the user is elgible.
	if(calculatePremium(age,smokeIn,unfitIn,amountOfInsurance)) 
	{
		cout<<"The cost to cover this individual per year is: $"<<calculatePremium(age,smokeIn,unfitIn,amountOfInsurance)<<endl;
	}
	else
	{
		cout<<"\nCannot insure!"<<endl;
	}

	system("pause");
	return 0;
	
}

double calculatePremium(int age,char smokeIn,char unfitIn,double amountOfInsurance)
{
	//Returns the preimium based on the diferent rules.
	//If client is unelgible, this function will return 0.

	//Calculate premium

	double premium,remainder,ratio = 0,leftOver,thousands; 

	thousands = static_cast<int>((amountOfInsurance / 1000)); // How many thousands are in the amount, and add them to thousands

	remainder = (int)amountOfInsurance % 1000;
	
	if(remainder != 0) // avoid division by zero!
	{
		ratio = (1000 / remainder); //Find the ratio.
	}
	

 

	if(age < 40)
	{
		//Calculate the initial premium.
		if(ratio != 0)
		{
			premium = ((10/ratio)+(thousands * 10));
		}
		else
		{
			premium = thousands * 10;
		}
		
		//Add on the stipulations
		if(unfitIn == 'y')
		{
			premium *= 1.2;
		}
		if(smokeIn == 'y')
		{
			premium *= 2.0;
		}

		return premium;
	}
	else if(age < 59)
	{
		//Calculate the initial premium.
		if(ratio != 0)
		{
			premium = ((15/ratio)+(thousands * 15));
		}
		else
		{
			premium = thousands * 15;
		}
		
		//Add on the stipulations
		if(unfitIn == 'y')
		{
			premium *= 1.2;
		}
		if(smokeIn == 'y')
		{
			premium *= 2.0;
		}

		return premium;
	}
	else 
	{
		
		//Calculate the initial premium.
		if(ratio != 0)
		{
			premium = ((20/ratio)+(thousands * 20));
		}
		else
		{
			premium = thousands * 20;
		}
		

		if(unfitIn == 'y' && smokeIn == 'n')
		{
			return 0;
		}
		//Add on the stipulations
		if(unfitIn == 'y')
		{
			premium *= 1.2;
		
		}
		if(smokeIn == 'y')
		{
			premium *= 2.0;
		}

		return premium;

		
	}

}