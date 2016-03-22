#include<iostream>


using namespace std;

int main()

{
	int T,O,G,D;

for (T=0;T<=9;T++)

	{	
	for(O=0;O<=9;O++)
		{
			for(G=0;G<=9;G++)
				{
					for(D=0;D<=9;D++)
					{ 
						if( (T==O)+(T==G)+(T==D)+(O==G)+(O==D)+(D==G)==0)	
							if(4*(100*T+10*O+O)==1000*G+100*O+10*O+D){ cout<<"T: "<<T<<endl<<"O: "<<O<<endl<<"G: "<<G<<endl<<"D: "<<D<<endl;};
					}
				}
		}
	}

system("pause");


return 0;
}