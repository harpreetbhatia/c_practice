#include <stdlib.h>
#include <stdio.h>

	This is what is Valid px<py
	px>=py px==py px!=py px==NULL
	px=px+n px=px-n px-py
	 
	Everything else is invalid (multiplication, division, addition of two pointers)!
	Something like j = j * 2;
	k = k / 2;
// 	where j and k are pointers will give this error Illegal use of pointer in function main 