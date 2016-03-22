//PROBLEM3_FUNCTIONS.cpp
//Andrew Ribeiro 
//October 6, 2008
//Used in: PROBLEM3.cpp
/*File Discription & Contents.
>This file contains the functions for the main source file: PROBLEM3.cpp

####### Functions located in this file #########

1.)int reverseNumber(int num)
	This function reveses the integer number-num. This function returns num reversed. 
	Ex: reverseNumber(45) == 54 is true. 
2.)bool isPrime(int num)
	This function tests if the integer number-num- is prime. The function then returns 
	false(0) if the number is not prime or if the number is prime, the function 
	returns true(1). 
*/

#include <iostream>
using namespace std;

//Reverses the number 
int reverseNumber(int num)
{
	int reversedNum = 0;
	
	if(num >= 10)
	{
		while(num > 0)
		{
			reversedNum = reversedNum * 10 + (num % 10) ;
			num /= 10;
		}
		
		return reversedNum;
	}
	else
	{
		return num;
	}
}


bool isPrime(int num)
{
	/*Tests num to determine if it is prime or not. If num is prime, then the function returns true.
	if the number is not prime, then the function returns false.*/
	
	//Zero is not prime; therefore, make shure isPrime returns false if num == 0.
	if(num != 0) 
	{
		for(int i = 2; i < num; i++)
		{
			if(num % i == 0)
			{
				return false; //Num was divisible by a number other than itself and one. 
			}
		}

		return true; //If the number was not divisible other than itself and one, it is true that it is prime. 
	}
	else
	{
		return false;
	}

}


