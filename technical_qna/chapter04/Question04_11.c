#include <stdlib.h>
#include <stdio.h>

    int isThisABST ( struct node* mynode )
	{

	data )
	 
	if ( mynode == NULL )
	return ( true ) ;
	if ( node -> left != NULL && maxValue( mynode -> left ) > mynode -> data ) return ( false );
	if ( node -> right != NULL  && minValue ( mynode -> right )  <=  mynode ->

	return ( false );
	if ( !isThisABST ( node -> left ) || !isThisABST ( node -> right ) ) return ( false );
	 
	return ( true );
	}