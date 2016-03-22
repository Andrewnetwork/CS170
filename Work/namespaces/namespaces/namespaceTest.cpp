#include <iostream>
using namespace std;

namespace andrew
{
	int andrewsAge = 18;
	double andrewsPhone = 2037918984;
	short int andrewsAppartmentNum = 34;
}

int main()
{
	int areaCode;
	int first;
	int second;
	int mainPart;
	
	areaCode= andrew::andrewsPhone/10000000;
	mainPart= (int)andrew::andrewsPhone%10000000;
	first = 7918984 / 10000;
	second = 7918984 % 10000;


	cout<<"Andrew's age: "<<andrew::andrewsAge<<endl;
	cout<<"Andrew's phone number: ("<<areaCode<<")"<<first<<"-"<<second<<endl;
	cout<<"Andrew's appartment number: "<<andrew::andrewsAppartmentNum<<endl;


	system("pause");
	return 0;
}