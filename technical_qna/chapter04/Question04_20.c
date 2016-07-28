#include <stdlib.h>
#include <stdio.h>

 the expression and obtain a paranthesized form of the expression.
	The code below prints the paranthesized form of a tree. infix_exp(p)
	{

	 
	if(p)
	{
	 



	printf("("); infix_exp(p->left);
	 
	printf(p->data); infix_exp(p->right); printf(")");
	}
	}

	creating a binary tree for a postfix expression mynode *create_tree(char postfix[])
	{

	mynode *temp, *st[100]; int i,k;
	char symbol;
	for(i=k=0; (symbol = postfix[i])!='\0'; i++)
	{

	temp = (mynode *) malloc(sizeof(struct node)); temp->value = symbol;
	temp->left = temp->right = NULL; if( isalnum ( symbol ) )
	st[k++] = temp; else
	{

	temp->right = st[--k]; temp->left = st[--k]; st[k++]	= temp;
	}
	}

	return(st[--k]);
	}
	 
	Evaluate a tree
	float eval(mynode *root)
	{

	float num; switch(root->value)
	{

	case '+' :
	return(eval(root->left) + eval(root->right)); break;
	case '-' :
	return(eval(root->left) - eval(root->right)); break;
	case '/' :
	return(eval(root->left) / eval(root->right)); break;
	case '*' :
	return(eval(root->left) * eval(root->right)); break;
	case '$' :
	return(eval(root->left) $ eval(root->right)); break;
	default :
	if(isalpha(root->value))
	{

	printf("%c = ", root->value); scanf("%f", &num); return(num);
	 
	}
	else
	{


	}
	}
	}
	 





	return(root->value - '0');
	 

	// Level order traversal..
	void levelOrderTraversal(mynode *root)
	{

	mynode *queue[100] = {(mynode *)0}; int size = 0;
	int queue_pointer = 0; while(root)
	{

	printf("[%d] ", root->value); if(root->left)
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
	 
	// Function to find the closest ancestor...
	mynode *closestAncestor(mynode* root, mynode* p, mynode* q)
	{

	mynode *l, *r, *tmp; if(root == NULL)
	{

	return(NULL);
	}

	if(root->left==p || root->right==p || root->left==q || root->right==q)
	{

	 


	}
	else
	{
	 
	return(root);






	l = closestAncestor(root->left, p, q);
	r = closestAncestor(root->right, p, q); if(l!=NULL && r!=NULL)
	{
	 

	 


	}
	else
	{




	}
	}
	}
	 
	return(root);






	tmp = (l!=NULL) ? l : r; return(tmp);
	 
// 	Here is the tree for you to visualize...
// 	5 (node=0)
// 	1 (node=1)	100 (node=3)
// 	-20 (node=2)	23 (node=4)
// 	13 (node=5)	67 (node=6) Here is the output...
// 	LEVEL ORDER TRAVERSAL [5] [1] [100] [-20] [23] [13] [67]
// 	Closest ancestor of [67] and [13] is [23]
// 	Closest ancestor of [-20] and [13] is [5]
// 	Closest ancestor of [23] and [67] is [100]
// 	Closest ancestor of [1] and [100] is [5]
// 	Closest ancestor of [-20] and [13] is [5] 