template <class T>
T* concatArrays(T *first,T *second,int sizeOfFirst,int sizeOfSecond)
{
	int positionCounter = 0; 
	sizeOfFirst = sizeOfFirst/sizeof(T);
	sizeOfSecond = sizeOfSecond/sizeof(T);
	int sizeOfArray = sizeOfFirst+ sizeOfSecond; 
	sizeOfArray++; //null char.
	T *newArray = new T[sizeOfArray];

	for(int i = 0; i < sizeOfFirst;i++)
	{
		newArray[i] = first[i];
	}

	for(int i = sizeOfFirst; i < sizeOfArray-1  ;i++)
	{
		newArray[i] = second[positionCounter];
		positionCounter++;
	}

	newArray[sizeOfArray-1] = '\0';
	return newArray;//pointer to the dynamicaly allocated array
}