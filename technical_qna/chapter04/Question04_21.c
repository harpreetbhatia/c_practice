#include <stdlib.h>
#include <stdio.h>

// 	If i > 1, i/2 is the parent
// 	If 2*i > n, then there is no left child, else 2*i is the left child.
// 	If (2*i + 1) > n, then there is no right child, else (2*i + 1) is the right child. Converting a tree to an array is very easy
// 	Suppose we have a tree like this A
// 	B	C
// 	D E	F G
// 	The array representation would be a[1] a[2] a[3] a[4] a[5] a[6] a[7] A	B	C	D	E	F	G
// 	That is, for every node at position i in the array, its left child will be stored at position (2*i) and right child at (2*i + 1). The root starts at position 1.
	 