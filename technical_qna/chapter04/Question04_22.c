#include <stdlib.h>
#include <stdio.h>

	AVL trees are self-adjusting, height-balanced binary search trees and are named after the inventors: Adelson-Velskii and Landis. A balanced binary search tree has O(log n) height and hence O(log n) worst case search and insertion times. However, ordinary binary search trees have a bad worst case. When sorted data is inserted, the binary search tree is very unbalanced, essentially more of a linear list, with O(n) height and thus O(n) worst case insertion and lookup times. AVL trees overcome this problem.
	An AVL tree is a binary search tree in which every node is height balanced, that is, the difference in the heights of its two subtrees is at most 1. The balance factor of a node is the height of its right subtree minus the height of its left subtree (right minus left!). An equivalent definition, then, for an AVL tree is that it is a binary search tree in which each node has a balance factor of -1, 0, or +1. Note that a balance factor of -1 means that the subtree is left-heavy, and a balance factor of +1 means that the subtree is right-heavy.
	Each node is associated with a Balancing factor.
	Balance factor of each node = height of right subtree at that node - height of left subtree at that node.
	Please be aware that we are talking about the height of the subtrees and not the weigths of the subtrees. This is a very important point. We are talking about the height!.
	Here is some recursive, working! C code that sets the Balance factor for all nodes starting from the root....
	#include <stdio.h> typedef struct node
	{

	int value; int visited; int bf;
	struct node *right; struct node *left;
	}mynode;


	mynode *root;
	mynode *add_node(int value);
	void levelOrderTraversal(mynode *root);
	 
	int setbf(mynode *p);
	// The main function
	int main(int argc, char* argv[])
	{

	root = NULL;
	// Construct the tree.. add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67); add_node(13);
	// Set the balance factors setbf(root);
	printf("\n\n\nLEVEL ORDER TRAVERSAL\n\n"); levelOrderTraversal(root);
	getch();
	}

	// Function to add a new node to the tree... mynode *add_node(int value)
	{

	mynode *prev, *cur, *temp;
	temp = (mynode *) malloc(sizeof(mynode)); temp->value = value;
	temp->visited = 0;
	temp->bf = 0;
	 
	temp->right = NULL; temp->left = NULL; if(root==NULL)
	{

	//printf("\nCreating the root..\n"); root = temp;
	return;
	}

	prev=NULL; cur=root; while(cur!=NULL)
	{

	prev=cur;
	cur=(value<cur->value)?cur->left:cur->right;
	}

	if(value < prev->value)
	prev->left=temp;

	else
	prev->right=temp;

	return(temp);
	}

	// Recursive function to set the balancing factor
	// of each node starting from the root! int setbf(mynode *p)
	{

	int templ, tempr; int count;
	 
	count = 1;
	if(p == NULL)
	{

	 


	}
	else
	{
	 
	return(0);






	templ = setbf(p->left); tempr = setbf(p->right); if(templ < tempr)
	count = count + tempr;
	 

	 
	else


	}
	 


	count = count + templ;
	 

	// Set the nodes balancing factor.
	printf("\nNode = [%3d], Left sub-tree height = [%1d], Right sub-tree height = [% 1d], BF = [%1d]\n",
	p->value, templ, tempr, (tempr - templ)); p->bf = tempr - templ;
	return(count);

	}
	// Level order traversal..
	void levelOrderTraversal(mynode *root)
	{

	mynode *queue[100] = {(mynode *)0}; int size = 0;
	int queue_pointer = 0; while(root)
	 
	{
	printf("\n[%3d] (BF : %3d) ", root->value, root->bf); if(root->left)
	{

	queue[size++] = root->left;
	}

	if(root->right)
	{

	queue[size++] = root->right;
	}

	root = queue[queue_pointer++];
	}
	}

	And here is the output...
	Node = [-20], Left sub-tree height = [0], Right sub-tree height = [0], BF = [0] Node = [ 1], Left sub-tree height = [1], Right sub-tree height = [0], BF = [-1] Node = [ 13], Left sub-tree height = [0], Right sub-tree height = [0], BF = [0] Node = [ 67], Left sub-tree height = [0], Right sub-tree height = [0], BF = [0] Node = [ 23], Left sub-tree height = [1], Right sub-tree height = [1], BF = [0] Node = [100], Left sub-tree height = [2], Right sub-tree height = [0], BF = [-2] Node = [ 5], Left sub-tree height = [2], Right sub-tree height = [3], BF = [1] LEVEL ORDER TRAVERSAL
	[  5] (BF :  1)
	[  1] (BF : -1)
	[100] (BF : -2)
	[-20] (BF :  0)
	[ 23] (BF :  0)
	 
	[ 13] (BF :  0)
	[ 67] (BF :  0)
	Here is the tree which we were dealing with above 5
	1	100
	-20	23
	13	67
	After insertion, the tree might have to be readjusted as needed in order to maintain it as an AVL tree. A node with balance factor -2 or 2 is considered unbalanced and requires rebalancing the tree. The balance factor is either stored directly at each node or computed from the heights of the subtrees, possibly stored at nodes. If, due to an instertion or deletion, the tree becomes unbalanced, a corresponding left rotation or a right rotation is performed on that tree at a particular node. A balance factor > 1 requires a left rotation (i.e. the right subtree is heavier than the left subtree) and a balance factor < -1 requires a right rotation (i.e. the left subtree is heavier than the right subtree).
	Here is some pseudo code to demonstrate the two types of rotations... Left rotation
	BEFORE
	0 (par)
	0	0 (p)
	0	0 (tmp)
	0   0	0   0
	(a)	(b)
	Here we left rotate the tree around node p tmp	= p->right;
	p->right	= tmp->left; tmp->left   = p;
	if(par)
	{

	if(p is the left child of par)
	 












	}
	else
	{
	 
	{


	}
	else
	{


	}
	 


	par->left=tmp;






	par->right=tmp;
	 

	root=tmp;
	}

	// Reclaculate the balance factors setbf(root);
	AFTER
	0 (par)
	0	0
	(tmp)
	0	0
	(p)		(b) 0	0
	(a)
	0	0
	Right rotation BEFORE
	0 (par)
	0	0 (p)
	 
	0 (tmp)	0
	0	0	0	0
	(a) (b)
	Here we right rotate the tree around node p tmp	= p->left;
	p->left	= tmp->right; tmp->right  = p;
	if(par)
	{

	if(p is the left child of par)
	{

	 










	}
	else
	{
	 


	}
	else
	{


	}
	 
	par->left=tmp;






	par->right=tmp;
	 

	root=tmp;
	}

	// Recalculate the balancing factors... setbf(root);
// 	AFTER
// 	0 (par)
// 	0	0 (tmp)
	 
// 	0	0
// 	(a)	(p) 0		0
// 	(b)	

	0	0