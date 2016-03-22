#include <iostream>
using namespace std;

int main()
{

	int numberOfLines;
	cout<<"Enter in the number of lines(1-15): ";
	cin>>numberOfLines;
	for (int row = 1; row <= numberOfLines;row++)
	{
		
		//Prints out leading spaces.
	
		int num;
		num = (numberOfLines - row) + 3;
		
		for (int i = 1; i < num ;i++)
		{
			cout<<" ";
		}
		
		cout<<row;
		
		//Before one
		for (int i =1; i < row; i++)
		{
			cout<<row - i;
		
		}

	
		for (int i = 2; i < row; i++)
		{
			cout<<i;
			
		}

		
		if (row != 1)
		{
			
			cout<<row<<endl;
		}
		else
		{
			cout<<endl;
		}

		

	}


	system("pause");
	return 0;
}
