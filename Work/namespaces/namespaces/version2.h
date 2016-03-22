/*Senerio: Since the client who funded the project did not think the encryption was strong enough
they called for a second version to be made.*/

//This encoding system outputs numbers in a list. Ex: 342432432,24234234,24324324,2323423423.
//To decode all of the numbers must be entered in the same sequence. 

#include <cmath>
#include <iostream>
using namespace std;

namespace version2
{
	void encode(long int number)
	{
		long int encodedNumber; 

		int sizeOfArray = 0; 
		
		//Finds out the size of the number. 
		for(int counter = 1;(number/counter != 0);counter *= 10)
		{
			sizeOfArray++;
		}
		
		//TestV

		
		const int sizeOfArrayConst = sizeOfArray;
		
		//Array that will store the encoded digits. 
		
		long int arrayOfEncodedNumbers[100];

		short int digitArray[100];
		long int divisor = pow(10,(double)sizeOfArray-1);
		long int remNum = number;

		//Test code: cout<<divisor<<"     "<<remNum<<endl;

		for(int counter = 0; counter <= sizeOfArray-1;counter++)
		{
			//Test code: cout<<counter<<":"<<remNum<<"      "<<divisor<<endl;

			digitArray[counter] = remNum / divisor;
			remNum = number % divisor;
			divisor = divisor/10;
		}
		
		for(int counter = 0;counter <= sizeOfArray;counter++)
		{
			
			encodedNumber = ((pow(static_cast<double>((digitArray[counter] + 7) * 10),4) - 100000000));
			arrayOfEncodedNumbers[counter] = encodedNumber;
		}

		cout<<"\nEncoded digit array: ";

		for(int counter = 0;counter <= sizeOfArray-1; counter++)
		{
			cout<<arrayOfEncodedNumbers[counter]<<",";
		}

		cout<<endl<<"\n";
	} 

	
	void decode(long int number)
	{
		long int decodedNumber;
		
		decodedNumber = ((sqrt( ((double)(sqrt(  (double)number + 100000000  ))))/10) - 7); 
		cout<<"The decoded number is: "<<decodedNumber<<endl; 

	}
	

}
