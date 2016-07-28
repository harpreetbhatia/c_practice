#include <stdlib.h>
#include <stdio.h>


	// Variables typedef struct node
	{
	int value;
	struct node *next;
	}mynode;

	// Globals (not required, though). mynode *head, *tail, *temp;

	// Functions
	void add(int value); void iterative_reverse(); void print_list();

	// The main() function 
	int main()
	{
	head=(mynode *)0;

	// Construct the linked list. add(1);
	add(2);
	add(3);

	//Print it print_list();

	// Reverse it. iterative_reverse();

	//Print it again print_list();

	return(0);
	}

	// The reverse function
	 
	void iterative_reverse()
	{
	mynode *p, *q, *r;

	if(head == (mynode *)0)
	{
	return;
	}

	p = head;
	q = p->next;
	p->next = (mynode *)0;

	while (q != (mynode *)0)
	{
	r = q->next; q->next = p; p = q;
	q = r;
	}

	head = p;
	}

	// Function to add new nodes to the linked list void add(int value)
	{
	temp = (mynode *) malloc(sizeof(struct node)); temp->next=(mynode *)0;
	temp->value=value;

	if(head==(mynode *)0)
	{
	 


	}
	else
	{


	}
	}
	 
	head=temp; tail=temp;



	tail->next=temp; tail=temp;
	 

	// Function to print the linked list. void print_list()
	{
	printf("\n\n");
	 
	for(temp=head; temp!=(mynode *)0; temp=temp->next)
	{
	printf("[%d]->",(temp->value));
	}
	printf("[NULL]\n\n");
	}

	Method2 (Recursive, without using any temporary variable)

	#include <stdio.h>
	// Variables typedef struct node
	{
	int value;
	struct node *next;
	}mynode;

	// Globals.
	mynode *head, *tail, *temp;

	// Functions
	void add(int value);
	mynode* reverse_recurse(mynode *root); void print_list();

	// The main() function int main()
	{
	head=(mynode *)0;

	// Construct the linked list. add(1);
	add(2);
	add(3);

	//Print it print_list();

	// Reverse it.
	if(head != (mynode *)0)
	{
	temp = reverse_recurse(head); temp->next = (mynode *)0;
	}

	//Print it again print_list();
	 

	return(0);
	}

	// Reverse the linked list recursively
	//
	// This function uses the power of the stack to make this
	// *magical* assignment
	//
	// node->next->next=node;
	//
	// :)

	mynode* reverse_recurse(mynode *root)
	{
	if(root->next!=(mynode *)0)
	{
	 



	}
	else
	{

	}
	}
	 
	reverse_recurse(root->next); root->next->next=root; return(root);



	head=root;
	 

	// Function to add new nodes to the linked list. void add(int value)
	{
	temp = (mynode *) malloc(sizeof(struct node)); temp->next=(mynode *)0;
	temp->value=value;

	if(head==(mynode *)0)
	{
	 


	}
	else
	{


	}
	}
	 
	head=temp; tail=temp;



	tail->next=temp; tail=temp;
	 

	// Function to print the linked list.
	 
	void print_list()
	{
	printf("\n\n");
	for(temp=head; temp!=(mynode *)0; temp=temp->next)
	{
	printf("[%d]->",(temp->value));
	}
	printf("[NULL]\n\n");
	}

	Method3 (Recursive, but without ANY global variables. Slightly messy!)

	#include <stdio.h>
	// Variables typedef struct node
	{
	int value;
	struct node *next;
	}mynode;

	// Functions
	void add(mynode **head, mynode **tail, int value); mynode* reverse_recurse(mynode *current, mynode *next); void print_list(mynode *);

	int main()
	{
	mynode *head, *tail; head=(mynode *)0;

	// Construct the linked list. add(&head, &tail, 1);
	add(&head, &tail, 2);
	add(&head, &tail, 3);

	//Print it print_list(head);

	// Reverse it.
	head = reverse_recurse(head, (mynode *)0);

	//Print it again print_list(head);

	getch(); return(0);
	}
	 

	// Reverse the linked list recursively
	mynode* reverse_recurse(mynode *current, mynode *next)
	{
	mynode *ret;

	if(current==(mynode *)0)
	{
	return((mynode *)0);
	}

	ret = (mynode *)0;
	if (current->next != (mynode *)0)
	{
	 

	}
	else
	{

	}
	 
	ret = reverse_recurse(current->next, current);



	ret = current;
	 

	current->next = next; return ret;
	}

	// Function to add new nodes to the linked list.
	// Takes pointers to pointers to maintain the
	// *actual* head and tail pointers (which are local to main()).

	void add(mynode **head, mynode **tail, int value)
	{
	mynode *temp1, *temp2;

	temp1 = (mynode *) malloc(sizeof(struct node)); temp1->next=(mynode *)0;
	temp1->value=value;

	if(*head==(mynode *)0)
	{
	 


	}
	else
	{
	 
	*head=temp1;
	*tail=temp1;



	for(temp2 = *head; temp2->next!= (mynode *)0; temp2=temp2->next); temp2->next = temp1;
	*tail=temp1;
	 
	}
	}

	// Function to print the linked list. void print_list(mynode *head)
	{
	mynode *temp; printf("\n\n");
	for(temp=head; temp!=(mynode *)0; temp=temp->next)
	{
	printf("[%d]->",(temp->value));
	}
	printf("[NULL]\n\n");
	}