#include <stdlib.h>
#include <stdio.h>

	Since traversing the three is the most frequent operation, a method must be devised to improve the speed. This is where Threaded tree comes into picture. If the right link of a node in a tree is NULL, it can be replaced by the address of its inorder successor. An extra field called the rthread is used. If rthread is equal to 1, then it means that the right link of the node points to the inorder success. If its equal to 0, then the right link represents an ordinary link connecting the right subtree.
	struct node
	{

	int value;
	struct node *left; struct node *right; int rthread;
	}

	Function to find the inorder successor mynode *inorder_successor(mynode *x)
	{

	mynode *temp; temp = x->right; if(x->rthread==1)
	return(temp);
	 
	while(temp->left!=NULL) temp = temp->left;
	return(temp);
	}

	Function to traverse the threaded tree in inorder void inorder(mynode *head)
	{

	mynode *temp; if(head->left==head)
	{

	printf("\nTree is empty!\n"); return;
	}

	temp = head; for(;;)
	{

	temp = inorder_successor(temp); if(temp==head)
	return;
	printf("%d ", temp->value);
	}
	}

	Inserting toward the left of a node in a threaded binary tree. void insert(int item, mynode *x)
	{

	mynode *temp; temp = getnode();
	 
	temp->value = item; x->left = temp; temp->left=NULL; temp->right=x; temp->rthread=1;
	}

	Function to insert towards the right of a node in a threaded binary tree. void insert_right(int item, mynode *x)
	{

	mynode *temp, r; temp=getnode(); temp->info=item; r=x->right;
	x->right=temp; x->rthread=0;
	temp->left=NULL; temp->right=r; temp->rthread=1;
	}

	Function to find the inorder predecessor (for a left threaded binary three) mynode *inorder_predecessor(mynode *x)
	{

	mynode *temp; temp = x->left; if(x->lthread==1)
	return(temp); while(temp->right!=NULL)
	 
	temp=temp->right; return(temp);
	}
