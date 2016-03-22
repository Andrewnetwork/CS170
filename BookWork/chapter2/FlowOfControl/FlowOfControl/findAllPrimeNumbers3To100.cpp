//findAllPrimeNumbers3To100.cpp
//Andrew Ribeiro 
//September 12, 2008 
//This program finds all the prime numbers between 3 and 100.
//Prime number: a number that can only be divided by itself equaly. 

#include <iostream>
using namespace std;

int main()
{
	int number = 3;
	cout<<"Prime numbers: ";

	do
	{
		bool isPrime = true; 
		int testNumber; 

		for(int i = 2; i < number; i++)
		{
			testNumber = number % i;

			if (testNumber == 0)
			{
				isPrime = false;
			}
		}
		
		if(isPrime)
		{
			cout<<number<<",";
		}

		number++;
		
	}while(number <= 100);



	

	system("pause");

	cout<<" end."<<endl;


	return 0;

}