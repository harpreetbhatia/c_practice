#include <stdlib.h>
#include <stdio.h>



	// Doubly linked lists

	// This is really easy, just keep swapping the prev and next pointers and at the end swap the head and the tail:)

	#include<stdio.h>
	#include<ctype.h>

	typedef struct node
	{
	int value;
	struct node *next; struct node *prev;
	}mynode ;

	mynode *head, *tail; void add_node(int value); void print_list();
	void reverse();

	int main()
	{
	head=NULL; tail=NULL;

	add_node(1); add_node(2); add_node(3); add_node(4); add_node(5);

	print_list();
	 
	reverse(); print_list(); return(1);

	}

	void add_node(int value)
	{
	mynode *temp, *cur;

	temp = (mynode *)malloc(sizeof(mynode)); temp->next=NULL;
	temp->prev=NULL;

	if(head == NULL)
	{
	 




	}
	else
	{





	}
	}
	 
	printf("\nAdding a head pointer\n"); head=temp;
	tail=temp;
	temp->value=value;



	for(cur=head;cur->next!=NULL;cur=cur->next); cur->next=temp;
	temp->prev=cur; temp->value=value; tail=temp;
	 

	void print_list()
	{
	mynode *temp;

	printf("\n--------------------------------\n");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
	printf("\n[%d]\n",temp->value);
	}
	}

	void reverse()
	{
	mynode *cur, *temp, *save_next; if(head==tail)return; if(head==NULL || tail==NULL)
	 
	return; for(cur=head;cur!=NULL;)
	{
	printf("\ncur->value : [%d]\n",cur->value); temp=cur->next;
	save_next=cur->next; cur->next=cur->prev; cur->prev=temp; cur=save_next;
	}
	temp=head; head=tail; tail=temp;
	}