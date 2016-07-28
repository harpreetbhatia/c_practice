#include <stdlib.h>
#include <stdio.h>

	Here is a complete C program which prints a BST using both recursion and iteration. The best way to understand these algorithms is to get a pen and a paper and trace out the traversals (with the stack or the queue) alongside. Dont even try to memorize these algorithms!
	#include <stdio.h> typedef struct node
	{

	int value;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	add_node ( int value ) ;
	void postorder ( mynode *root ); void inorder ( mynode *root ); void preorder ( mynode *root );
	void iterativePreorder ( mynode *root ); void iterativeInorder ( mynode *root );
	 
	void iterativePostorder ( mynode *root ); int main ( int argc , char* argv[] )
	{

	root = NULL ; add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67); add_node(13);
	printf("\nPreorder (R)		: "); preorder(root); printf("\nPreorder (I)	: "); iterativePreorder ( root ) ;

	printf("\n\nPostorder (R) : "); postorder(root); printf("\nPostorder (R) : "); iterativePostorder ( root ) ;


	printf("\n\nInorder (R)		: "); inorder(root); printf("\nInorder (I)	: "); iterativeInorder ( root ) ;
	}

	// Function to add a new node to the BST
	 
	add_node(int value)
	{

	mynode *prev, *cur, *temp;
	temp = ( mynode * ) malloc( sizeof ( mynode ) ) ; temp -> value = value;
	temp -> right = NULL ; temp -> left  = NULL; if ( root == NULL )
	{

	printf("\nCreating the root..\n"); root  = temp;
	return;
	}

	prev = NULL; cur = root;
	while ( cur != NULL )
	{

	prev = cur ;
	cur = ( value < cur -> value ) ? cur -> left : cur -> right ;
	}

	if ( value < prev -> value ) prev -> left = temp;
	 
	else


	}
	 

	prev -> right = temp;
	 


	// Recursive Preorder
	 
	void preorder ( mynode *root )
	{

	if ( root )
	{

	printf("[%d] ", root->value); preorder ( root -> left ); preorder ( root -> right );
	}
	}

	// Iterative Preorder
	void iterativePreorder(mynode *root)
	{

	mynode *save[100]; int top = 0;
	if ( root == NULL )
	{

	return;
	}

	save[top++] = root; while ( top != 0 )
	{

	root = save[--top]; printf("[%d] ", root->value); if ( root -> right != NULL )
	save[top++] = root -> right ; if ( root -> left != NULL )
	save[top++] = root->left;
	 
	}
	}

	// Recursive Postorder
	void postorder ( mynode *root )
	{

	if ( root )
	{

	postorder ( root -> left ); postorder ( root -> right ); printf("[%d] ", root -> value );
	}
	}

	// Iterative Postorder
	void iterativePostorder ( mynode *root )
	{

	 
	struct
	{
	 



	mynode *node;
	unsigned vleft :1; // Visited left? unsigned vright :1;  // Visited right?
	 
	}save[100]; int top = 0;
	save[top++].node = root ; while ( top != 0 )
	{

	/* Move to the left subtree if present and not visited */ if ( root -> left != NULL && !save[top].vleft )
	 
	{
	save[top].vleft = 1; save[top++].node = root; root = root -> left ; continue;
	}

	/* Move to the right subtree if present and not visited */ if( root -> right != NULL && !save[top].vright )
	{

	save[top].vright = 1; save[top++].node = root; root = root -> right ; continue;
	}

	printf("[%d] ", root->value);
	/* Clean up the stack */ save[top].vleft = 0;
	save[top].vright = 0;
	/* Move up */
	root = save[--top].node;
	}
	}

	// Recursive Inorder
	void inorder ( mynode *root )
	{

	if ( root )
	{
	 
	inorder ( root -> left ); printf("[%d] ", root->value); inorder ( root -> right );
	}
	}

	// Iterative Inorder..
	void iterativeInorder ( mynode *root )
	{

	mynode *save[100]; int top = 0;
	while( root != NULL )
	{

	while (root != NULL)
	{

	if (root->right != NULL)
	{

	save[top++] = root->right;
	}

	save[top++] = root; root = root->left;
	}

	root = save[--top];
	while(top != 0 && root->right == NULL)
	{

	printf("[%d] ", root->value); root = save[--top];
	}
	 
	printf("[%d] ", root->value);
	root = (top != 0) ? save[--top] : (mynode *) NULL;
	}
	}

	And here is the output... Creating the root..
	Preorder (R)	: [5] [1] [-20] [100] [23] [13] [67]
	Preorder (I)	: [5] [1] [-20] [100] [23] [13] [67]


	Postorder (R)   : [-20] [1] [13] [67] [23] [100] [5]
	Postorder (R)   : [-20] [1] [13] [67] [23] [100] [5]


	Inorder (R)	: [-20] [1] [5] [13] [23] [67] [100]
	Inorder (I)	: [-20] [1] [5] [13] [23] [67] [100]