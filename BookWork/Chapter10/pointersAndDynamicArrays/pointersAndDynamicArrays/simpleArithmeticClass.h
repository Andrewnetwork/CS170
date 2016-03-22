//This is a class with basic aritmetic functions. The purpose of this class is to 
//be used with the new command to create dynamic instances of the class. 

class simpleArithmetic
{
public:
	int addition(int a,int b);
	int subtraction(int a,int b);
	simpleArithmetic(int a);



};

int simpleArithmetic::addition(int a,int b)
{
	return a+b;
}
int simpleArithmetic::subtraction(int a,int b)
{
	return a-b;
}
simpleArithmetic::simpleArithmetic(int a) //constructor
{
}