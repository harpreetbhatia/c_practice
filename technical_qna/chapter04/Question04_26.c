#include <stdlib.h>
#include <stdio.h>

	Here is a C code to construct a BST right from scratch...
	#include <stdio.h> typedef struct node
	{

	int value;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	add_node(int value);
	void postorder(mynode *root); void inorder(mynode *root); void preorder(mynode *root); int main(int argc, char* argv[])
	{

	root = NULL; add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67);
	 
	add_node(13); printf("\nPreorder	: "); preorder(root); printf("\n\nPostorder : "); postorder(root); printf("\n\nInorder : "); inorder(root);
	return(0);
	}

	// Function to add a new node... add_node(int value)
	{

	mynode *prev, *cur, *temp;
	temp = (mynode *) malloc(sizeof(mynode)); temp->value = value;
	temp->right = NULL; temp->left = NULL; if(root==NULL)
	{

	printf("\nCreating the root..\n"); root = temp;
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


	}
	 


	prev->right=temp;
	 

	void preorder(mynode *root)
	{

	 
	if(root)
	{






	}
	}
	 



	printf("[%d] ", root->value); preorder(root->left); preorder(root->right);
	 

	void postorder(mynode *root)
	{

	 
	if(root)
	{






	}
	}
	 



	postorder(root->left); postorder(root->right); printf("[%d] ", root->value);
	 

	void inorder(mynode *root)
	 
	{
	if(root)
	{






	}
	}
	 





	inorder(root->left); printf("[%d] ", root->value); inorder(root->right);
	 
