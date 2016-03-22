#include <iostream>
#include <string>
using namespace std; 

//Limit: 10^9 1,000,000,000  
int safeInput(string errorMessage,string prompt,int minValue,int maxValue);

int main(int c,char d[])
{
	for(;;)
	{
		int userNumber;
		cout<<"Hello, would you please enter in an integer number: ";
		userNumber = safeInput("Invalid number.","Please input another: ",-100,-10000);
		cout<<"You entered: "<<userNumber<<endl;
	}

	return 0;
}