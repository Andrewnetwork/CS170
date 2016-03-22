//PROBLEM1.cpp
//Andrew Ribeiro
//November 5, 2008
//Files used: PROBLEM1_FUNCTIONS.CPP
//This is a multiplication practice problem for children. 

#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string randomResponce(bool answerIsCorrect);
int safeInput(string errorMessage,string prompt,int minValue,int maxValue);
char safeInput(string errorMessage,string prompt,const char validChars[]);
void sub_rangedMode();
void sub_normalMode();


//Stores the valid charicter input for the menu
const char validChars[] = {'N',  //Normal entry mode. 
						   'R',  //Range mode. 
					       'Q'}; //Quit

int main()
{

	//Make it so the random numbers produced will be random according to the system clock.
	srand((unsigned)time(0));
	char menuChoice;

	cout<<"\t\t **********************************************"<<endl
		<<"\t\t * Welcome to the times table learning system *"<<endl
		<<"\t\t **********************************************"<<endl<<endl
		<<"\t\t***************** INSTRUCTIONS *****************"<<endl
		<<"\t\t* 1.)Chose an option and follow the directions *"<<endl
		<<"\t\t* 2.) Once you are done solving problems, pre- *"<<endl
		<<"\t\t*     ss ^Z(CTRL + Z) to exit the program      *"<<endl
		<<"\t\t************************************************"<<endl<<endl;

	//The main menu loop will be repeated untill the user quits the program or presses ^Z.
	do{
		cout<<"\n\n\t****************************************************************"<<endl
			<<"\t*************************** MAIN MENU **************************"<<endl
			<<"\t*"<<endl
			<<"\t* Please select an option:"<<endl
			<<"\t*          Normal mode: N"<<endl
			<<"\t*          Ranged mode: R"<<endl
			<<"\t*          Quit: Q"<<endl
			<<"\t*"<<endl
			<<"\t* Enter(N,R,or Q): ";
		menuChoice = safeInput("\t*\n\t* WARNING: INVALID CHOICE","\t* Please enter a valid choice: ",validChars);

		if(menuChoice == 'N')
		{
			sub_normalMode();
		}
		if(menuChoice == 'R')
		{
			sub_rangedMode();
		}
		else if(menuChoice == 'Q')
		{
			cout<<endl<<"Thank you for using the program."<<endl<<"Now exiting the program. ";
			exit(0);
		}

	}while(true);

	return 0;
}