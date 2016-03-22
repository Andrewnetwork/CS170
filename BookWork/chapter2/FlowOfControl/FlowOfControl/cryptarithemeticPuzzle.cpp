//cryptarithemeticPuzzle.cpp
//Andrew Ribeiro 
//This program solves cryptarithemetic puzzles.
/* A cryptarithmetic puzzle assigns the digits 0-9 to each letter, no two letters can have the same value. 

Solve: TOO + TOO + TOO + TOO = GOOD

*/



#include <iostream>
using namespace std;

int tooAddedTogether(int,int,int,int);
void solve();
int good(int,int,int);

int main()
{
	solve();
	system("pause");

	return 0;
}


void solve()
{
	//Solve: TOO + TOO + TOO + TOO = GOOD
	

	//Main loop raises the stationary numbers.

	int T,G,O,D;

	for(int i = 0; i <=  9;i++)
	{ 
		//bool exitVal = false;

		for(int x = 0; x <= 9; x++)
		{
			T = x;
			G = i;
			O = i;
			D = i;

		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = x;
			O = i;
			D = i; 

			

			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = i;
			O = x; 
			D = i; 

			//cout<<"3: "<<T<<G<<O<<D<<endl;

			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = i;
			O = i;
			D = x;

			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			} 
		}

		for(int x = 0; x <= 9; x++)
		{
			T = x;
			G = x;
			O = i;
			D = i;

		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			} 
		}
		for(int x = 0; x <= 9; x++)
		{
			T = x;
			G = i;
			O = x;
			D = i;

	
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 
		for(int x = 0; x <= 9; x++)
		{
			T = x;
			G = i;
			O = i;
			D = x;

		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = x;
			O = x;
			D = i;


			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = i;
			O = x;
			D = x;

			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 
		for(int x = 0; x <= 9; x++)
		{
			T = i;
			G = x;
			O = i;
			D = x;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = counter;
			G = i;
			O = i;
			D = x;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		} 

		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = counter;
			O = i;
			D = x;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}

		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = i;
			O = counter;
			D = x;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = i;
			O = x;
			D = counter;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = x;
			O = i;
			D = counter;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = x;
			G = i;
			O = i;
			D = counter;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = x;
			O = counter;
			D = i;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = i;
			G = x;
			O = counter;
			D = i;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = x;
			G = counter;
			O = x;
			D = counter;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}
		for(int x = 9; x >= 0; x--)
		{
			int counter = 0;
		
			T = counter;
			G = x;
			O = counter;
			D = x;

			counter++;


		
			
			if (tooAddedTogether(T,O,D,G) == good(O,D,G))
			{
				cout<<"The numbers that satisfy this equation are: T = "<<T<<",G = "<<G<<",O = "<<O<<",D = "<<D<<endl;
				//exitVal = true;
			}
		}

		

		//if (exitVal)
		//{
		//	i = 10;
		//}	
	}

}

int tooAddedTogether(int T,int O,int D,int G)
{
	
	int tooAddedTogether;
	tooAddedTogether = ((T * 100)+ (O * 10) + O )*3; 

	if( T != O && T != D && T != G && O != D && O != G && D != G)
	{
		return tooAddedTogether;
	}
	
	else
	{
		return 0;
	}
}

int good(int O,int D,int G)
{
	int GOOD;
	GOOD = ((G * 1000)+(O * 100)+(O * 10)+ D );

	if(G != O && G != D && D != O)
	{
		
		return GOOD;
	}
	
	else
	{
		return -1;
	}
}
