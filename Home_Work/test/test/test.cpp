#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) 
{
  char* cLength = getenv("R");
  cout<<*cLength; 
  return 0;
}
