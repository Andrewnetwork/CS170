#include <iostream>
using namespace std;

/*Begin Notes

>A recursive function is one that calls itself in its function definition. 
>When the function is called in the function definition, it suspends calculations after the call untill the function is 
-proccesed again.

End Notes*/


void printVirtical(int n);


int main()
{
	
	printVirtical(54321);

	system("pause");
	return 0;

}

void printVirtical(int n)
{
	if(n < 10)
	{
		cout<<n<<endl;
	}
	else
	{
		printVirtical(n/10);
		cout<<(n%10)<<endl;
	}
}