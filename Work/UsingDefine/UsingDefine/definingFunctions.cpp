#include <iostream>
using namespace std;

#define addValues( x,y ) ( ((x)+(y)) ? (x+y))
#define whichValueIsBigger(x,y) (    (x > y) ? (0) :  (  (y > x) ? (1)  :  (y == x) ? (2) : (3) ) )



int main()
{
	int yValue,xValue,caseVal;

	cout<<"Enter in the first value: ";
	cin>>xValue;
	cout<<"Enter in the second value: ";
	cin>>yValue;
	
	caseVal = whichValueIsBigger(xValue,yValue);

	switch (caseVal)
	{
		case 1:
			cout<<"\nThe first value is smaller than the second value."<<endl;
			break;
		case 0:
			cout<<"\nThe first value is larger than the second value."<<endl;
			break;
		case 2:
			cout<<"\nBoth values are equal"<<endl;
			break;
		default:
			cout<<"\nInvlaid value!"<<endl;
			break;
	}

	system("pause");
	return 0;
}