//PROBLEM2.CPP
//Andrew Ribeiro
//This program demonstrates the usage of the function i created: max()

#include <iostream>
#include <string>
#include <cstdarg> 

//The max function exists in the std namespace, therefore the specific using statements are used.
using std::cout;
using std::endl;


double max(double numberOfArguments...);

int main()
{
	cout<<"*********************************************************"<<endl
		<<"*This program demonstrates the usage of my max function.*"<<endl
		<<"*********************************************************"<<endl<<endl
	    <<"max(5,-100.0,-5.5,5.0,0,-3.4) = "<<max(5,-100.0,-5.5,5.0,0.0,-3.4)<<endl
		<<"max(7,49.4,100.0,499.0,499.5,0,0.39,499.60) = "<<max(7,49.4,100.0,499.0,499.5,0.0,0.39,499.69)<<endl;

	//Testing the function for a diferent values.
	for(double i = 0.0; i< 15; i++)
	{
		cout<<"max(5,"<<i+1.3<<","<<i+4.3<<","<<i +45.4<<","<<i -95.4<<","<<i -3<<") = "
			<<max(5,(i+1.3),(i+4.3),(i +45.4),(i -95.4),(i -3))<<endl;
	}
	cout<<endl;
	
	return 0;
}


double max(double numberOfArguments...)
{
	va_list arg_ptr; //Argument list of pointers
	va_start(arg_ptr,numberOfArguments); 

	double largest = va_arg(arg_ptr,double),currentValue = largest; // stores the first arg, and largest value.

	for(int i = 0; i < numberOfArguments; i++)
	{
		if(largest < currentValue)
		{
			//If the largest value is less than the current value, make the largest value the currentValue. 
			largest = currentValue;
		}

		currentValue = va_arg(arg_ptr,double);
	}

	va_end(arg_ptr); //reset the function. 

	return largest;
}