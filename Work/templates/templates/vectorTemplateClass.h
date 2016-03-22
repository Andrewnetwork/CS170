/* vectorTemplateClass.h
#############################################################
#|||||||||||||||||\\      // |||||||||   ||||||||||=====    #
#||  ||  ||     || \\    //  ||     ||   ||      ||    //   #
#||  }{  ||{}{}{||  \\  //   ||{}{}{|||||||{}{}{}||   //    #
#||      ||     ||   \\//    ||     ||   ||      ||  //=====#
#############################################################


>>Description of Code: The class vectors is placed within the namespace mavahaz and uses the
template class F.The default constructor is used in the class; However, there is a defined 
constructor which takes three string args- The name of the vector, A discription of the
data in the vector, and an access password that is used to acces the data.
############################################################################################
++Member variables: 
-Public
{
	--string vectorName: This variable stores the name of the vector. 
	--string vectorType: Stores the discription of the data in the vector. 
}
-Private
{
	--vector<F> classVector: Is the vector that will contain all the data. 
	--sring accessPassword: Contains the password to manipulate the existing vector data.
}
############################################################################################
++Member functions:
-Public
{




>>

#include <iostream>
#include <fstream>
using namespace std;


}



}

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



namespace mavahaz
{
	template<class F> 
	class vectors
	{
	public:
		//Constructor: vectorName,vectorType,password to access data
		vectors(string vectorName,string vectorType,string accessPassword); 

		/*Loops through the array and prints out the data stored in the vector when given the 
		proper password */
		void printVectorData(string password); 
		
		//Discriptive data about the vector.
		string vectorName,
			   vectorType; 

		//Adds a value to the vector by way of push_back.
		void enterValueIntoVector(F element);
		
		//Returns a copy of the vector when given the proper password.
		vector<F> returnCopyVector(string password);

		//Saves the vector data to a file when given the proper password. 
		void saveVectorDataToFile(string Password,string nameOfOutputFile);
		




	private:
		//The vector for the class, which is the main component of the class.
		vector<F> classVector;
		
		//Stores the user defined password; which is used to access the data. 
		string accessPassword;
		
	};

	//Constructor: Initilises values.
	template<class F>
	vectors<F>::vectors(string vectorName,string vectorType,string accessPassword)
	{
		vectors::vectorName = vectorName;
		vectors::vectorType = vectorType;
		vectors::accessPassword = accessPassword;
	}

	//Enters value into the vector.
	template<class F>
	void vectors<F>::enterValueIntoVector(F element)
	{
		vectors::classVector.push_back(element);
	}

	template<class F>
	vector<F> vectors<F>::returnCopyVector(string password)
	{
		if (password == vectors::accessPassword)
		{
			vector<F> copyOfVector;
			copyOfVector = vectors::classVector;
			return copyOfVector;
		}
		else
		{
			cout<<"Invalid password!"<<endl;
		}

	}

	template<class F>
	void vectors<F>::printVectorData(string password)
	{
		if (vectors::accessPassword == password)
		{
			for(unsigned int i = 0; i < vectors::returnCopyVector().size(); i++)
			{
				cout<<i + 1<<".) "<<vectors::classVector[i]<<endl;
			}
		}
		else
		{
			cout<<"Password is invalid."<<endl<<endl;
		}

	}

	template<class F>
	void vectors<F>::saveVectorDataToFile(string Password,string nameOfOutputFile)
	{
		if (Password == vectors::accessPassword)
		{ 
			/*Convert the file name string into a charicter array; so that it can be used in the arg-
			for fileOut.open().*/
			char *charArrayPointer;
			charArrayPointer = new char[nameOfOutputFile.size()];
			for(int i = 0; i <= nameOfOutputFile.size();i++)
			{
				charArrayPointer[i]= nameOfOutputFile[i];
			}
			cout<<charArrayPointer<<endl;

			ofstream fileOut;
			fileOut.open((charArrayPointer));
			fileOut << "### "<<vectors::vectorName<<" ###\n"<<endl;

			for(unsigned int i = 0; i < vectors::returnCopyVector(vectors::accessPassword).size();i++)
			{
				fileOut<<i + 1<<".) "<<returnCopyVector(vectors::accessPassword)[i]<<endl;
			}

			fileOut.close();
		}
		else
		{
			cout<<"\nPassword is incorrect!"<<endl;

		}
	}
}
