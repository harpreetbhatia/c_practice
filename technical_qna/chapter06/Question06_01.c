#include <stdlib.h>
#include <stdio.h>

	A Heap is an almost complete binary tree.In this tree, if the maximum level is i, then, upto the (i-1)th level should be complete. At level i, the number of nodes can be less than or equal to 2^i. If the number of nodes is less than 2^i, then the nodes in that level should be completely filled, only from left to right.
	The property of an ascending heap is that, the root is the lowest and given any other node i, that node should be less than its left child and its right child. In a descending heap, the root should be the highest and given any other node i, that node should be greater than its left child and right child.
	To sort the elements, one should create the heap first. Once the heap is created, the root has the highest value. Now we need to sort the elements in ascending order. The root can not be exchanged with the nth element so that the item in the nth position is sorted. Now, sort the remaining (n-1) elements. This can be achieved by reconstructing the heap for (n-
	1) elements.
	A highly simplified pseudocode is given below heapsort()
	{

	n = array(); // Convert the tree into an array. makeheap(n); // Construct the initial heap. for(i=n; i>=2; i--)
	{

	swap(s[1],s[i]); heapsize--; keepheap(i);
	 
	}
	}

	makeheap(n)
	{

	heapsize=n; for(i=n/2; i>=1; i--) keepheap(i);
	}

	keepheap(i)
	{

	l = 2*i;
	r = 2*i + 1; p = s[l];
	q = s[r];
	t = s[i];
	if(l<=heapsize && p->value > t->value) largest = l;
	else
	largest = i;

	m = s[largest];
	if(r<=heapsize && q->value > m->value) largest = r;
	if(largest != i)
	{

	swap(s[i], s[largest]); keepheap(largest);
	}
	 
	}