//main.cpp
//Andrew Ribeiro 
//September 17, 2008.
/* Chapter 10: Pointers and Dynamic Arrays
>Dynamically allocated arrays: Array size is determined while the program is running. 
>Pointer: Memory adress of a variable. 
-declare example: double *p; 
-If pointer is typed double, then the variable it is pointing to shoudld be a double. 
-* is the dereferencing opperator when used as a pointer.
-& refers the the memory location of the variable. Called the 'adress of opperator'.
>the 'new' command is used to create nameless variables and allow them to 
be accesed by pointers. This type of variable is called dynamically allocated variables. Or
just dynamic variables. 

Ex: p1 = new int; //Can be refered to as *p1

>Special part of memory called freestore or heap is reserved for dynamically allocated variables.
>The 'delete' command is used to delete dynamic variables and make room for more. 
>Dangling pointers: when one deletes a dynamic variable, it does not delete the pointer to that
variable. Thus, the pointer becomes undefined. Are then equal to NULL.
>Automatic variables: variables inside functions are created and distroyed while the program 
is running. Therefore, they have a dynamic charicteristc; however, they are set up 
automaticaly. 
>typedef: used to create types. Ex: typeDef int* pointers; // would make it so one could 
declare integer pointers like this: pointers p1;
>int* p1,p2; //would be a legal way to declare pointers

###10.2##
>Arrays are a type of pointer value. Therefore, a pointer can be assigned an array. 
- ex:
int *p1, a[10];
p1 = a;
Then you could access a by using the pointer
-ex:
p1[1] = 4;



end chapter notes */

#include <iostream>
#include <cmath>
#include "simpleArithmeticClass.h"
using namespace std;

void test1();
void changeByReference();
void changePointingLocation();
void namelessVariables();
void testingClassPointers();
void recycling();
void testingTypeDef();
void dynamicArray1();

int main()
{

	//test1();
	//changeByReference();
	//changePointingLocation();
	//namelessVariables();
	//testingClassPointers();
	//recycling();
	//testingTypeDef(); 
	dynamicArray1();
	
	
	
	system("pause");
	return 0; 


}

void test1()
{
	int *p1,*p2,v1 = 5,v2 = 10;
	//Set pointer to point to the variables v1 and v2.
	p1 = &v1;
	p2 = &v2;


	//Shows the casted integer memory location of the pointer.
	cout<<"Adress of pointer 1: "<<(int)&p1<<endl;
	cout<<"Adress of pointer 2: "<<(int)&p2<<endl;

	//Shows the value of the variable that the pointer is pointing to.Dereferencing is uccuring.
	cout<<"Contents of p1: "<<*p1<<endl; 
	cout<<"Contents of p2: "<<*p2<<endl; 

}

void changeByReference()
{
	int var1 = 1, var2 = 5,*p1 = &var1,*p2 = &var2;

	*p2 += *p1;

	cout<<"The result of *p2 += *p1 is: "<<*p2<<endl;
}

void changePointingLocation()
{
	int var1 = 3, var2 = 4, *p1 = &var1,*p2 = &var2; 

	p1 = p2; // This will make p1 point to variable two aswell. 

	cout<<"p1 points to: "<<*p1<<endl<<"p2 points to: "<<*p2<<endl<<endl;

}
void namelessVariables()
{
	int *p1,var1 = 5;

	//Creating a dynamically allocated variable.
	p1 = new int; 

	cout<<"Please insert an integer value to test nameless variables: ";
	cin>>*p1; // Read in a value for the nameless variable

	*p1 = *p1 + var1; // Take the dereference value of p1 and add var1 = 5 to it. 

	cout<<"The resulting value of the nameless variable + "<<var1<<" is: "<<*p1<<endl<<endl;
}

void testingClassPointers()
{
	/*simpleArithmetic is the class used here. It is located in the header 
	file 'simpleArithmeticClass'*/

	simpleArithmetic *classPtr; //Points to the simpleArithmetic class
	classPtr = new simpleArithmetic(3); //Creates a nameless instance of the class 
	

}
void recycling()
{
	int *p1,*p2;
	p1 = new int(3); // Initilizes p1 = int 3
	p2 = new int(4);
	
	cout<<*p1<<"   "<<*p2<<endl<<endl;
	delete p1,p2;

}
void testingTypeDef()
{
	typedef int* pointer; 
	typedef int variable; 

	
	variable var1 = 3, var2 = 4, var3 = 5;
	pointer p1 = &var1,p2 = &var2,p3 = &var3;

	//Dereference the values and print them out. 
	cout<<"Var1 = "<<*p1<<endl
		<<"Var2 = "<<*p2<<endl
		<<"Var3 = "<<*p3<<endl;




}
void dynamicArray1()
{
	int userIn;
	cout<<"This program will print out all the even values up to the value you enter in."
		<<endl<<endl
		<<"Please enter in the max value: ";
	cin>>userIn;

	typedef int* intPtr; 
	
	intPtr a;
	/*Dynamically sizes the array. The absolute value of the users input is 
	included in case of an integer overload causing a negative to set of an infinate loop*/

	a = new int[abs(userIn)];

	for(int i = 0; i <= userIn; i++)
	{
		a[i] = i; //Fills the array: 0 to userIn.
	}
	
	for(int i = 0; i<=userIn;i++)
	{
		if (i % 2 == 0 && i !=0){cout<<a[i]<<" ";} //Prints out all the values in the array
	}
	
	cout<<endl;




}