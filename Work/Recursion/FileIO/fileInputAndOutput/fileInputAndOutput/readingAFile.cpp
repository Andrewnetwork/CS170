#include <iostream>
using namespace std; 

/*
>Must at +b or b+ with one of these to opperate in binary mode. 
r  - open for reading
w  - open for writing (file need not exist)
a  - open for appending (file need not exist)
r+ - open for reading and writing, start at beginning
w+ - open for reading and writing (overwrite file)
a+ - open for reading and writing (append if file exists)

*/

int main()
{
	

	FILE *testFile;
	
	testFile=fopen("c:\\Users\\Andrew\\Documents\\test.txt", "r");
	for(int i = 0;i <= 20;i++)
	{
		cout<<(char)fgetc(testFile);
	}

	system("pause");

	return 0; 
}