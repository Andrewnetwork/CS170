
namespace version1
{
	int encode(int number)
	{
		int encodedNumber; 

		encodedNumber = (number + 7) * 10;
		return encodedNumber; 
	}

	int decode(int number)
	{
		int decodedNumber; 

		decodedNumber = (number /10)- 7; 
		return decodedNumber; 
	}
}

