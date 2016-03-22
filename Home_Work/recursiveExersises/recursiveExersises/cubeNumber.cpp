#include <iostream>
using namespace std;


int cubeNumber(int number,int counter = 0)
{
	if (counter < 2)
	{
		number *= cubeNumber(number,counter + 1);
	}
	else
	{
		return number;
	}

	return number; 
}

double cubeNumber(double number,int counter = 0)
{
	if (counter < 2)
	{
		number *= cubeNumber(number,counter + 1);
	}
	else
	{
		return number;
	}

	return number; 
}

int main()
{

	cout<<"Cubing numbers using recursion"<<endl
		<<"\tTwo cubed is: "<<cubeNumber(2)<<endl
		<<"\tFour cubed is: "<<cubeNumber(4)<<endl
		<<"\tSis cubed is: "<<cubeNumber(6)<<endl
		<<"\tEight cubed is: "<<cubeNumber(8)<<endl
		<<"\tTen cubed is: "<<cubeNumber(10)<<endl
		<<"\t24.4 cubed is: "<<cubeNumber(24.4)<<endl
		<<"\t50.4532 cubed is: "<<cubeNumber(50.4532)<<endl;

		

}

