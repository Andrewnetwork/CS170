/* qsort example */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;



int compare(const void *first, const void *second)
{
    const char **firstStr = (const char **)first;
    const char **secondStr = (const char **)second;
	//The compare function returns values suited for qsort
    return strcmp(*firstStr, *secondStr); 

}
 


int main ()
{
   char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter" };
    size_t strings_len = sizeof(strings) / sizeof(char *);
 
	cout<<strings[0];
    /** STRING */
    //puts("*** String sorting...");

    /* sort array using qsort functions */
    qsort(strings, strings_len, sizeof(char *), cstring_cmp);
	cout<<strings[0];
 
    /* print sorted string array */


}