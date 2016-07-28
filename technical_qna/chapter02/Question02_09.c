#include <stdlib.h>
#include <stdio.h>

	toUpper()
	int toUpper(int ch)
	{

	if(ch>='a' && c<='z')
	return('A' + ch - 'a');

	 
	else


	}
	 


	return(ch);
	 

	isUpper()
	int isUpper(int ch)
	{

	if(ch>='A' && ch <='Z')
	return(1); //Yes, its upper!

	 
	else


	}
	 


	return(0); // No, its lower!
	 

	Its important to know that the upper and lower case alphabets have corresponding integer values.
	A-Z - 65-90
	a-z - 97-122
	Another way to do this conversion is to maintain a correspondance between the upper and lower case alphabets. The program below does that. This frees us from the fact that these alphabets have a corresponding integer values. I dont know what one should do for non- english alphabets. Do other languages have upper and lower case letters in the first
	place :) !
	#include <string.h>
	#define UPPER  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	#define LOWER  "abcdefghijklmnopqrstuvwxyz"
	 
	int toUpper(int c)
	{

	const char *upper;
	const char *const lower = LOWER;
	// Get the position of the lower case alphabet in the LOWER string using the strchr() function ..
	upper = ( ((CHAR_MAX >= c)&&(c > '\0')) ? strchr(lower, c) : NULL);
	// Now return the corresponding alphabet at that position in the UPPER string .. return((upper != NULL)?UPPER[upper - lower] : c);
	}
	Note that these routines dont have much error handling incorporated in them. Its really easy to add error handling to these routines or just leave it out (as I like it). This site consciously leaves out error handling for most of the programs to prevent unwanted clutter and present the core logic first.
