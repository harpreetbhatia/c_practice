#include <stdlib.h>
#include <stdio.h>

	If this is the tree, 1
	2	3
	5   6	7   8
	its level order traversal would be 1 2 3 5 6 7 8
	You need to use a queue to do this kind of a traversal Let t be the tree root.
	while ( t != null )
	{

	visit t and put its children on a FIFO queue; remove a node from the FIFO queue and call it t;
	// Remove returns null when queue is empty
	}

	Pseduocode
	Level_order_traversal( p )
	{

	while(p)
	{

	Visit ( p ) ; If ( p -> left )
	Q.Add ( p -> left ) ; If ( p -> right )
	 
	Q.Add ( p -> right ); Delete ( p );
	}
	}

	Here is some C code (working :))..
	#include <stdio.h> typedef struct node
	{

	int value;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	add_node( int value );
	void levelOrderTraversal ( mynode *root ); int main ( int argc , char* argv[] )
	{

	root = NULL; add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67); add_node(13);
	printf("\n\n\nLEVEL ORDER TRAVERSAL\n\n"); levelOrderTraversal ( root ) ;
	 
	getch( );
	}

	// Function to add a new node... add_node ( int value )
	{

	mynode *prev, *cur, *temp;
	temp = ( mynode * ) malloc( sizeof ( mynode ) ); temp -> value = value;
	temp -> right = NULL; temp -> left  =  NULL; if ( root == NULL )
	{

	printf("\nCreating the root..\n"); root = temp;
	return;
	}

	prev = NULL ; cur = root ;
	while ( cur != NULL )
	{

	prev = cur ;
	cur = ( value < cur -> value ) ? cur -> left : cur -> right ;
	}

	if ( value < prev -> value ) prev -> left = temp;
	else
	prev -> right = temp;
	 
	}
	// Level order traversal..
	void levelOrderTraversal( mynode *root )
	{

	mynode *queue[100] = { (mynode *)0 } ; // Important to initialize! int size = 0;
	int queue_pointer = 0; while ( root )
	{

	printf("[%d] ", root -> value ) ; if ( root -> left )
	{

	queue[size++]  =  root -> left ;
	}

	if ( root -> right )
	{

	queue[size++]  =  root -> right ;
	}

	root  = queue[queue_pointer++];
	}
	}