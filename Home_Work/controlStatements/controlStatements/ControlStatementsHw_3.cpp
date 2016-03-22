//ControlStatementsHw_3.cpp
//Andrew Ribeiro
//September 30, 2008
//From the control statements lecture powerpoint. 

/*
Write a program that will encrypt four-digit integers by replacing each digit by (the sum of that digit plus 7)
modulus 10(Hint: use the integer division and modulus operations to separate the number into its individual digits)
*/

#include <iostream>
using namespace std;
int encrypt(int inNum);


int main()
{

	int userIn;

	cout<<"Enter a 4-digit integer to encode: ";
	cin>>userIn;
	
	while(!cin.good())
	{
		cout<<"Try again: ";
		cin.clear();
		cin.ignore(80,'\n');
		cin>>userIn;
	}
	cout<<encrypt(userIn)<<endl;
	


	system("pause");
	return 0;
}

int encrypt(int inNum)
{
	int num = inNum,outNum = 0;
	
	//Replace each digit with the sum of that digit plus 7.
	//Each value is multiplied by a factor of 1000 in order to provide the correct possitions. 

	outNum += ((num % 10) + 7 * 1);

	num /= 10;
	outNum +=  ((num % 10) + 7 * 10);
	
	num /= 10;
	outNum +=  ((num % 10) + 7 * 100);

	num /= 10;
	outNum +=  ((num % 10) + 7 * 1000);
	

	return outNum;

}


