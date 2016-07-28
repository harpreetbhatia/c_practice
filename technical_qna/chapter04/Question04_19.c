#include <stdlib.h>
#include <stdio.h>

// 	Here is some working C code...
	#include <stdio.h> typedef struct node
	{

	int value;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	mynode *add_node(int value);
	void levelOrderTraversal(mynode *root);
	mynode *closestAncestor(mynode* root, mynode* p, mynode* q); int main(int argc, char* argv[])
	{

	mynode *node_pointers[7] , *temp ; root = NULL;
	// Create the BST.
	// Store the node pointers to use later... node_pointers[0] = add_node(5); node_pointers[1] = add_node(1); node_pointers[2] = add_node(-20); node_pointers[3] = add_node(100); node_pointers[4] = add_node(23); node_pointers[5] = add_node(67); node_pointers[6] = add_node(13);
	 
	printf("\n\n\nLEVEL ORDER TRAVERSAL\n\n"); levelOrderTraversal(root);
	// Calculate the closest ancestors of a few nodes..
	temp = closestAncestor(root, node_pointers[5], node_pointers[6]); printf("\nClosest ancestor of [%d] and [%d] is [%d]\n\n",node_pointers[5]-
	>value,node_pointers[6]->value , temp->value);
	temp = closestAncestor ( root, node_pointers[2], node_pointers[6]); printf("\n\nClosest ancestor of [%d] and [%d] is [%d]\n\n", node_pointers[2]-
	>value,node_pointers[6]->value, temp->value);
	temp = closestAncestor(root, node_pointers[4], node_pointers[5]);
	printf("\n\nClosest ancestor of [%d] and [%d] is [%d]\n\n",node_pointers[4]-
	>value,node_pointers[5]->value,temp->value);
	temp = closestAncestor(root, node_pointers[1], node_pointers[3]); printf("\n\nClosest ancestor of [%d] and [%d] is [%d]\n\n",node_pointers[1]-
	>value,node_pointers[3]->value, temp->value);
	temp = closestAncestor(root, node_pointers[2], node_pointers[6]); printf("\n\nClosest ancestor of [%d] and [%d] is [%d]\n\n",node_pointers[2]-
	>value,node_pointers[6]->value, temp->value);
	}
	// Function to add a new node to the tree.. mynode *add_node ( int value )
	{

	mynode *prev, *cur, *temp;
	temp = ( mynode * ) malloc( sizeof ( mynode ) ); temp -> value = value;
	temp -> right = NULL; temp -> left  = NULL;
	 
	if( root == NULL )
	{

	printf("\nCreating the root..\n"); root = temp;
	return;
	}

	prev=NULL; cur=root;
	while( cur != NULL )
	{

	prev=cur;
	cur = ( value < cur -> value ) ? cur -> left : cur -> right ;
	}

	if ( value < prev -> value ) prev -> left = temp;
	else
	prev->right=temp;

	return(temp);
	}
