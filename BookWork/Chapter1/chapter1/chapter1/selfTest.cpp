//Andrew Ribeiro 
//September 7, 2008
//Self Test Exercises 
/* Chapter notes
>Variable declerations define and declare the variable. 
>A variable is not initilised until it is given a value.
>Automatic casting is caled type coercion. 
>Also, the way you cast variables is by static_cast<type>(expression/variable).
>The way you cast constants is const_cast<type>(expression)
>The old way to cast is type(var/expression). Ex: int(3.4) = 3 
>--n decreses then evaluates the variable.
>n-- evaluates the variable then decreases.
>same thing goes for n++/++n.

*/
//Preprossesor Directives
#include <iostream>
using namespace std;

//Function headers.
int three();
int four();
int seven();

int main()
{
	//Place the functions her to be ran. 
	//three();
	//four();
	//seven();
	return 0;
}
int one()
{
	int feet = 0,inches = 0;
	//Alternitive: int feet = (0), inches = (0)

	return 0;
}

int two()
{
	int count = 0;
	double distance = 1.5;
	/* Alternitive: 
	int count = (0);
	double distance = (1.5); */
	return 0;
}

/*
int three()
{
	//This program causes an error because the variables are uninitilised. 
	int a,b,c,d,e;
	cout<<a<<b<<c<<d<<e;
	return 0;
}
*/

int four()
{
	int x = 2,y = 4,z = 453;
	double answer;
	
	answer = 3 * x;

	answer = 3.0 *x + y;

	answer = (x+y)/7.0;
	
	answer = (3.0 * x + y)/z+2;

	cout<<answer; 
	cin>>x;

	return 0;

}

int seven()
{
	//Reads two whole numbers into two vars of type int and outputs both the whole number part and the remainder
	//when the first number is divided by the second. 

	int number1;
	int number2;
	int wholeNumber;
	int remainder;

	cout<<"Please enter two numbers to be divided!\n "
		<<"Enter the first number: ";
	cin>>number1;
	cout<<"Enter the second number: ";
	cin>>number2;

	remainder = number1 % number2;
	//Integer division
	wholeNumber = number1 / number2;

	cout<<number1<<" divided by "<<number2<<" is "<<wholeNumber<<" with a remainder of "<<remainder<<".";

	return 0;


}
