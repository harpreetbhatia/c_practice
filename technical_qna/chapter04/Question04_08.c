#include <stdlib.h>
#include <stdio.h>

	Here is a C program. Study it carefully, it has some Gotchas! typedef struct node
	{

	int value;
	struct node *left; struct node *right;
	}mynode; mynode *root; static ctr;
	void nthnode( mynode *root ,  int n , mynode **nthnode /* POINTER TO A POINTER!
	*/ ) ;
	 
	int main( )
	{

	mynode *temp; root = NULL;
	// Construct the tree add(19);
	add(20);
	...
	add(11);
	// Plain Old Inorder traversal
	// Just to see if the next function is really returning the nth node? inorder(root);
	// Get the pointer to the nth Inorder node nthinorder( root , 6 , &temp ); printf("\n[%d]\n,  temp -> value ) ; return ( 0 );
	}

	// Get the pointer to the nth inorder node in "nthnode"
	void nthinorder( mynode *root ,  int n ,  mynode **nthnode )
	{

	static whichnode; static found;
	if( !found )
	{

	if ( root )
	{

	nthinorder ( root -> left ,  n , nthnode ) ;
	 
	if ( ++whichnode  ==  n )
	{

	printf("\nFound %dth node\n", n); found = 1;
	*nthnode  =  root ; // Store the pointer to the nth node.
	}

	nthinorder( root -> right ,  n , nthnode ) ;
	}
	}
	}

	inorder( mynode *root )
	{

	// Plain old inorder traversal
	}

	// Function to add a new value to a Binary Search Tree add(int value)
	{

	mynode *temp , *prev , *cur ;
	temp = malloc ( sizeof ( mynode ) ) ; temp -> value  =  value ;
	temp -> left = NULL; temp -> right = NULL; if ( root  ==  NULL )
	{

	root  =  temp ;
	}
	else
	 
	{
	prev = NULL ; cur = root ; while ( cur )
	{

	prev = cur;
	cur  = ( value  <  cur -> value ) ?  cur -> left : cur -> right ;
	}

	if ( value > prev -> value ) prev -> right = temp;
	 
	else


	}
	}
	 

	prev->left  = temp;
	 

// 	There seems to be an easier way to do this, or so they say. Suppose each node also has a weight associated with it. This weight is the number of nodes below it and including itself. So, the root will have the highest weight (weight of its left subtree + weight of its right subtree + 1). Using this data, we can easily find the nth inorder node.
// 	Note that for any node, the (weight of the leftsubtree of a node + 1) is its inorder rankin the tree!. Thats simply because of how the inorder traversal works (left->root->right). So calculate the rank of each node and you can get to the nth inorder node easily. But frankly speaking, I really dont know how this method is any simpler than the one I have presented above. I see more work to be done here (calculate thw weights, then calculate the ranks and then get to the nth node!).
	Also, if (n > weight(root)), we can error out saying that this tree does not have the nth node you are looking for.