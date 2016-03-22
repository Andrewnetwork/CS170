//Record.h
//Andrew Ribeiro 
//December 2, 2008 
/**** Notes ****
 * >I would have used a class with an Accessor and modifier pattern, but we did not cover
 * >I could of used an array of charicters instead of a string, but, since we do not have
 *  a method to reduce the size of the char array to each tools individual name... I felt
 *	the strings class was a nice substitute. 
 * >Would have used a constructor w/ args instead, but we did not cover this in class.
 */
#ifndef TOOLRECORD_H
#define TOOLRECORD_H

#include <string>
using namespace std;

struct ToolRecord
{
	//********************Member variables*******************

	//recordNumber: stores the number of the record object.
	int recordNumber; 
	//toolName: stores a c++-type string containing the tools name.
	string toolName; 
	//quantity: stores information on how many tools of this type are in stock.
	int quantity;
	//cost: contains the cost of each tool of this type. 
	float cost; 


};



#endif 