#include <iostream>
using namespace std;

/*
int a ()
{
	char str[] ="- This, a sample string:.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-!:");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-!:");
  }
  return 0;
}


void b()
{
	char practiceString[] = "Hello there, my name is andrew. ";
	
	char *ph;
	ph = strtok(practiceString," ,.-!:");
	
	while(ph != NULL )
	{
		cout<<ph<<endl;
		ph = strtok(NULL," ,.-!:");

	}

}

*/


void main()
{
	char f[] = "Hello there";
	int lengthOfArray; 
	cout<<storeTokens(f,lengthOfArray)[1]<<endl;
	
}

