#include <iostream>
      
using namespace std;
int main()
{
  int arrayStructure[8];

  for(int x=0; x<8;x++)
  {
	cin>>arrayStructure[x];
  }

  for(int x = 0; x<8;x++)
  {
	  cout<<arrayStructure[x];
  }

  cout<<endl;

  system("pause");

  return 0;
}
