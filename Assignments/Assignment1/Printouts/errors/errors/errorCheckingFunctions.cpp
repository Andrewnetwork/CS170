#include <iostream>
#include <string>
#include <cmath>
using namespace std; 


int convertStringToNumber(string userInputString);
string removeCharictersFromString(string userInputString);


int safeInput(string errorMessage,string prompt,int minValue,int maxValue)
{
	int userIn;

	string userInputString;
	cin>>userInputString;

	userIn = convertStringToNumber(removeCharictersFromString(userInputString));
	

	
	if(maxValue <= minValue)
	{
		//Loop if there is errors. Be aware of the side effects. 
		while(!cin.good() || userIn < minValue)
		{
			cout<<errorMessage<<endl
				<<prompt;

			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
			userIn = convertStringToNumber(removeCharictersFromString(userInputString));
		}
	}
	else if( maxValue == minValue) // Ignore both min and max
	{
		while(!cin.good() )
		{
			cout<<endl<<errorMessage<<endl
				<<prompt;

			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
			userIn = convertStringToNumber(removeCharictersFromString(userInputString));
		}
	}

	else
	{
		while(!cin.good() || userIn < minValue || userIn > maxValue )
		{
			cout<<errorMessage<<endl
				<<prompt;

			cin.clear();
			cin.ignore(80,'\n');
			cin>>userIn;
			userIn = convertStringToNumber(removeCharictersFromString(userInputString));
		}
	}
	
	return userIn; 
}






double convertStringToDouble(string userInputString)
{
	double  convertedStringNumber = 0; 
	


	return convertedStringNumber;
}
int convertStringToNumber(string userInputString)
{
	int  convertedStringNumber = 0,charicter = 0,skipCharicter = 0;
	bool isNegative = false; 
	
	while (userInputString[charicter] != '\0')
	{
		if (userInputString[charicter] == 'F' || userInputString[charicter] == '-')
		{
			skipCharicter++;
		}

		charicter++;
	}

	charicter = 0; //Reset counter
	

	//Get the base of the number.
	int powerBase = (pow(10.0,static_cast<double>((userInputString.length()- skipCharicter)))/10);
																			
	
	while (userInputString[charicter] != '\0')
	{
		//If the negitive sign is infront of a number, we assume the numbers following it are negitive aswell.
		if(userInputString[charicter+1] != 'F' && userInputString[charicter] == '-') 
		{
			
			isNegative = true;
			cout<<"IIIS"<<endl;
		}
		else
		{
			if(userInputString[charicter] != 'F' &&  userInputString[charicter] != '-')
			{
				switch(userInputString[charicter]) //Transform into a number
				{
				case '0':
					convertedStringNumber += powerBase * 0;
					break;
				case '1':
					convertedStringNumber += powerBase * 1;
					break;
				case '2':
					convertedStringNumber += powerBase * 2;
					break;
				case '3':
					convertedStringNumber += powerBase * 3;
					break;
				case '4':
					convertedStringNumber += powerBase * 4;
					break;
				case '5':
					convertedStringNumber += powerBase * 5;
					break;
				case '6':
					convertedStringNumber += powerBase * 6;
					break;
				case '7':
					convertedStringNumber += powerBase * 7;
					break;
				case '8':
					convertedStringNumber += powerBase * 8;
					break;
				case '9':
					convertedStringNumber += powerBase * 9;
					break;
				}
				powerBase /= 10; //Decrease by one digit. 
			}
			

		}

		charicter++;
	}

	if(isNegative)
	{
		convertedStringNumber = (convertedStringNumber - (convertedStringNumber * 2));
	}

	return convertedStringNumber;
}
string removeCharictersFromString(string userInputString)
{
	int charicter = 0;


		while (userInputString[charicter] != '\0')
		{
			//If the charicter is not equal to a number. Remove it from the string. 
			if (userInputString[charicter] != '0'&& userInputString[charicter] != '1'&&\
				userInputString[charicter] != '2'&& userInputString[charicter] != '3'&&\
				userInputString[charicter] != '4'&& userInputString[charicter] != '5'&&\
				userInputString[charicter] != '6'&& userInputString[charicter] != '7'&&\
				userInputString[charicter] != '8'&& userInputString[charicter] != '9'&& \
				userInputString[charicter] != '-'&& userInputString[charicter] != '\0')
			{
				userInputString[charicter] = 'F'; //Replace charicters with F.
			}

			charicter++;
		}

		return userInputString;
}