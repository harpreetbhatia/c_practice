#include <stdlib.h>
#include <stdio.h>

	 
// 	For Inorder And Preorder traversals inorder  = g d h b e i a f j c preorder = a b d g h e i c f j
// 	Scan the preorder left to right using the inorder sequence to separate left and right subtrees. For example, "a" is the root of the tree; "gdhbei" are in the left subtree; "fjc" are in the right subtree. "b" is the next root; "gdh" are in the left subtree; "ei" are in the right subtree. "d" is the next root; "g" is in the left subtree; "h" is in the right subtree.
// 	For Inorder and Postorder traversals
// 	Scan postorder from right to left using inorder to separate left and right subtrees. inorder   = g d h b e i a f j c
// 	post order = g h d i e b j f c a
// 	Tree root is "a"; "gdhbei" are in left subtree; "fjc" are in right subtree. For Inorder and Levelorder traversals
// 	Scan level order from left to right using inorder to separate left and right subtrees. inorder	= g d h b e i a f j c
// 	level order = a b c d e f g h i j
// 	Tree root is "a"; "gdhbei" are in left subtree; "fjc" are in right subtree.
// 	Here is some working code which creates a tree out of the Inorder and Postorder
// 	traversals. Note that here the tree has been represented as an array. This really simplifies the whole implementation.
// 	Converting a tree to an array is very easy Suppose we have a tree like this
// 	A
// 	B	C
// 	D E	F G
// 	The array representation would be a[1] a[2] a[3] a[4] a[5] a[6] a[7] A	B	C	D	E	F	G
	 
// 	That is, for every node at position j in the array, its left child will be stored at position (2*j) and right child at (2*j + 1). The root starts at position 1.
// 	// CONSTRUCTING A TREE GIVEN THE INORDER AND PREORDER SEQUENCE
	#include<stdio.h>
	#include<string.h>
	#include<ctype.h>
	/*-------------------------------------------------------------
	*	Algorithm
	*
	*	Inorder And Preorder
	*	inorder = g d h b e i a f j c
	*	preorder = a b d g h e i c f j
	*	Scan the preorder left to right using the inorder to separate left
	*	and right subtrees. a is the root of the tree; gdhbei are in the
	*	left subtree; fjc are in the right subtree.
	*------------------------------------------------------------*/
	static char io[]="gdhbeiafjc"; static char po[]="abdgheicfj";
	static char t[100][100]={'\0'}; //This is where the final tree will be stored static int hpos=0;
	void copy_str( char dest[], char src[], int pos, int start, int end ); void print_t( );
	int main(int argc, char* argv[])
	{

	int i,j,k; char *pos; int posn;
	// Start the tree with the root and its
	 
	// left and right elements to start off for( i = 0 ; i < strlen ( io ) ; i++ )
	{

	if ( io[i] == po[0] )
	{

	copy_str(t[1],io,1,i,i);	// We have the root here copy_str(t[2],io,2,0,i-1);		// Its left subtree copy_str(t[3],io,3,i+1,strlen(io)); // Its right subtree print_t();
	}
	}

	// Now construct the remaining tree for( i = 1 ; i < strlen ( po ) ; i++ )
	{

	for ( j = 1 ; j <= hpos ; j++ )
	{

	 

	strlen ( t[j] ) != 1 )
	 
	if ( ( pos = strchr ( ( const char * ) t[j] , po[i] ) )  != ( char * )0 &&

	{
	for ( k = 0 ; k < strlen ( t[j] ) ; k++ )
	{
	 

	if ( t[j][k] == po[i] )
	{

	posn=k; break;
	}
	}

	printf("\nSplitting [%s] for po[%d]=[%c] at %d..\n", t[j],
	 
	i,po[i],posn);









	}
	}
	 


	copy_str(t[2*j],t[j],2*j,0,posn-1); copy_str(t[2*j+1],t[j],2*j+1,posn+1,strlen(t[j])); copy_str(t[j],t[j],j,posn,posn);
	print_t();
	}
	 

	}
	// This function is used to split a string into three seperate strings
	// This is used to create a root, its left subtree and its right subtree void copy_str( char dest[] , char src[] , int pos , int start , int end )
	{

	char mysrc[100] ; strcpy(mysrc,src); dest[0]='\0';
	strncat( dest , mysrc + start , end - start + 1 ); if ( pos > hpos ) hpos = pos
	}

	void print_t(
	{

	nt i;
	for ( i = 1 ; i <= hpos ; i++ )
	{

	printf("\nt[%d] = [%s]", i, t[i]);
	}

	printf("\n");
	 
	}