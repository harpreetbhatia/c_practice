#include <stdlib.h>
#include <stdio.h>

	Hashing is the process of mapping strings to integers, in a relatively small range.
	A hash function maps a string (or some other data structure) to a bounded number (called the hash bucket) which can more easily be used as an index in an array, or for performing repeated comparisons.
	A mapping from a potentially huge set of strings to a small set of integers will not be unique. Any algorithm using hashing therefore has to deal with the possibility of collisions.
	Here are some common methods used to create hashing functions Direct method
	Subtraction method Modulo-Division method Digit-Extraction method Mid-Square method Folding method
	Pseudo-random method
	 
	Here is a simple implementation of a hashing scheme in C
	#include <stdio.h>
	#define HASHSIZE 197 typedef struct node
	{

	int value;
	struct node *next;
	}mynode;
	typedef struct hashtable
	{

	mynode *llist;
	}HT;

	HT myHashTable[HASHSIZE]; int main()
	{

	initialize(); add(2); add(2500); add(199); display_hash(); getch(); return(0);
	}

	int initialize()
	{

	int i; for(i=0;i<HASHSIZE;i++)
	 
	myHashTable[i].llist=NULL; return(1);
	}

	int add(int value)
	{

	int hashkey; int i;
	mynode *tempnode1, *tempnode2, *tempnode3; hashkey=value%HASHSIZE;
	printf("\nHashkey : [%d]\n", hashkey); if(myHashTable[hashkey].llist==NULL)
	{

	 









	}
	else
	{
	 
	//This hash bucket is empty, add the first element! tempnode1 = malloc(sizeof(mynode));
	tempnode1->value=value; tempnode1->next=NULL;
	myHashTable[hashkey].llist=tempnode1;






	//This hash bucket already has some items. Add to it at the end.
	//Check if this element is already there? for(tempnode1=myHashTable[hashkey].llist; tempnode1!=NULL; tempnode3=tmpnode1,tempnode1=tempnode1->next)
	{
	 

	if(tempnode1->value==value)
	 



	value);
	 
	{
	printf("\nThis value [%d] already exists in the Hash!\n",

	return(1);
	}
	}
	 

	tempnode2 = malloc(sizeof(mynode)); tempnode2->value = value; tempnode2->next=NULL;
	tempnode3->next=tempnode2;
	}

	return(1);
	}

	int display_hash()
	{

	int i;
	mynode *tempnode; for(i=0;i<HASHSIZE;i++)
	{

	if(myHashTable[i].llist==NULL)
	{

	 


	}
	else
	{
	 
	printf("\nmyHashTable[%d].llist -> (empty)\n",i);





	printf("\nmyHashTable[%d].llist -> ",i); for(tempnode=myHashTable[i].
	 
	llist;tempnode!=NULL;tempnode=tempnode->next)
	 
	{
	printf("[%d] -> ",tempnode->value);
	}

	printf("(end)\n");
	}

	if(i%20==0)
	getch();
	}

	return(0);
	}

	And here is the output Hashkey : [2]
	Hashkey : [136]
	Hashkey : [2]
	Hashkey : [2]
	This value [2] already exists in the Hash! myHashTable[0].llist -> (empty) myHashTable[1].llist -> (empty) myHashTable[2].llist -> [2] -> [199] -> (end) myHashTable[3].llist -> (empty) myHashTable[4].llist -> (empty) myHashTable[5].llist -> (empty) myHashTable[6].llist -> (empty) myHashTable[7].llist -> (empty) myHashTable[8].llist -> (empty) myHashTable[9].llist -> (empty) myHashTable[10].llist -> (empty)
	 
	myHashTable[11].llist -> (empty) myHashTable[12].llist -> (empty) myHashTable[13].llist -> (empty) myHashTable[14].llist -> (empty) myHashTable[15].llist -> (empty) myHashTable[16].llist -> (empty) myHashTable[17].llist -> (empty) myHashTable[18].llist -> (empty) myHashTable[19].llist -> (empty) myHashTable[20].llist -> (empty) myHashTable[133].llist -> (empty) myHashTable[134].llist -> (empty) myHashTable[135].llist -> (empty) myHashTable[136].llist -> [2500] -> (end) myHashTable[137].llist -> (empty) myHashTable[196].llist -> (empty) 
