//A constructor is called when a class object is constructed. 
//A deconstructor is called when a class object is deleted or when the program ends.
#include "includes.h"
using namespace std;

class Computer
{
	public:
		//function prototypes
		void monitor();
		void videoCard();
		void soundCard();
		void ram();
		void hdd();
		void processor();
		Computer(); //constructor
		~Computer(); //deconstructor

};

//Constructor
Computer::Computer()
{
	//Can take args
	cout<<"You have constructed a Computer object"<<endl;
}

Computer::~Computer()
{
	//Can not take args
	cout<<"End program"<<endl;
}

void Computer::monitor()
{
	cout<<"The monitor displays data and other graphical features to the user."<<endl;
}

void Computer::videoCard()
{
	cout<<"A video card converts binary graphical data to a form which can be displayed on a monitor."<<endl;
}

void Computer::ram()
{
	cout<<"Random access memory allows the computer to temporarialy store program runtime data."<<endl;
}

void Computer::hdd()
{
	cout<<"A hard disk drive allows the user to store data over a long period of time-which includes programs."<<endl;
}

void Computer::processor()
{
	cout<<"A processor connects all the digital signals of all devices together so they can logicaly function."<<endl;
}

void Computer::soundCard()
{
	cout<<"A sound card takes digital data and transforms it into analog data."<<endl;
}
