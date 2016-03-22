//versionExample.cpp
/*#############################################################
  #|||||||||||||||||\\      // |||||||||   ||||||||||=====    #
  #||  ||  ||     || \\    //  ||     ||   ||      ||    //   #
  #||  }{  ||{}{}{||  \\  //   ||{}{}{|||||||{}{}{}||   //    #
  #||      ||     ||   \\//    ||     ||   ||      ||  //=====#
  #############################################################*/
//September 13, 2008
/*Discription: This program exemplifies how namespaces are used to make programs portable. 
In this example namespaces will allow the testing of two diferent verions of this simple 
number encryption program.

Senerio: A client orders software that will encode a simple integer. The first version of the
program was not strong enough, so the client called for the making of a second version. In 
order to save time and money, the namespace feature will be utilised to change between versions.

*/

#include "includes.h"
using namespace version2;   // Specifies which version the program is running.
using namespace std; 

int main()
{
	int userNumber;
 

	cout<<"Enter in an integer to be encoded: ";
	cin>>userNumber; 

	encode(userNumber);

	cout<<"\n"<<"Enter an integer you would like to decode: ";
	cin>>userNumber; 
	decode(userNumber); 

	//cout<<"\n"<<"Decoded number: "<<decode(userNumber)<<endl;
	
	

	system("pause");
	return 0;
}