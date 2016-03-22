//vectors.cpp
//Andrew Ribeiro 
//This program demonstrates the usage of vectors.

#include <iostream>
#include <vector> //Includes the template for vectors. In std namespace.
using namespace std;

int main()
{
	/*vector<int> var1;
	
	var1.push_back(3);// Assigns 3 to the first element of the array. Command needed.
	var1.push_back(30);
	var1.push_back(499);
	
	cout<<"The contents of the var1 array are: ";
	for(unsigned int i = 0; i < var1.size(); i++)
	{
		cout<<var1[i]<<" ";
	}

	cout<<"\n Also, the size of var1 is: "<<var1.size()<<" elements"<<endl;
	*/

	/*Multidementianal vector array test.*/

	vector<vector<long int> > twoDimentionalArray;
	//Making space in location[0]
	twoDimentionalArray.resize(twoDimentionalArray.size() + 1);  
	//Making space in location[0]
    twoDimentionalArray[0].resize(twoDimentionalArray.size() + 1);
	twoDimentionalArray[0][0] = 1;

	twoDimentionalArray.resize(twoDimentionalArray.size() + 1);  
    twoDimentionalArray[0].resize(twoDimentionalArray.size() + 1);
	twoDimentionalArray[0][1] = 2;

	twoDimentionalArray.resize(twoDimentionalArray.size() + 1);  
    twoDimentionalArray[1].resize(twoDimentionalArray.size() + 1);
	twoDimentionalArray[1][0] = 3;

	//[columbs][rows]


	cout<<twoDimentionalArray[0][0]<<" "<<twoDimentionalArray[0][1]<<endl
		<<"Size of array: "<<twoDimentionalArray.size()<<endl;
	

	







	system("pause");
	return 0;
}