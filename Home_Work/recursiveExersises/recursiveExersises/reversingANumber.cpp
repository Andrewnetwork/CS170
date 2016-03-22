#include <iostream>
using namespace std;


int reverseNumber(int num,int base = 10,int reversedNumber = 0)
{
	if (num != 0)
	{
		reversedNumber *= 10;
		reversedNumber += num % base;
		num = num / base;

		reverseNumber(num,base,reversedNumber); 
	}
	else 
	{
		return reversedNumber; 
	}
}

void main()
{

	cout<<reverseNumber(45)<<endl;
	cout<<reverseNumber(67)<<endl;


}