#include <stdlib.h>
#include <stdio.h>

	Depth first search (DFS)
	Depth First Search (DFS) is a generalization of the preorder traversal. Starting at some arbitrarily chosen vertex v, we mark v so that we know we've visited it, process v, and then recursively traverse all unmarked vertices adjacent to v (v will be a different vertex with every new method call). When we visit a vertex in which all of its neighbors have been visited, we return to its calling vertex, and visit one of its unvisited neighbors, repeating the recursion in the same manner. We continue until we have visited all of the
	 
	starting vertex's neighbors, which means that we're done. The recursion (stack) guides us through the graph.
	public void depthFirstSearch(Vertex v)
	{

	v.visited = true;
	// print the node
	for(each vertex w adjacent to v)
	{

	if(!w.visited)
	{

	depthFirstSearch(w);
	}
	}
	}

	Here is some working C code for a DFS on a BST..
	#include <stdio.h> typedef struct node
	{

	int value; int visited;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	mynode *add_node(int value); void treeDFS(mynode *root); int main(int argc, char* argv[])
	{
	 
	root = NULL;
	// Construct the tree.. add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67); add_node(13);
	// Do a DFS.. printf("\n\nDFS : "); treeDFS(root); getch();
	}

	// Function to add a new node to the tree... mynode *add_node(int value)
	{

	mynode *prev, *cur, *temp;
	temp = (mynode *) malloc(sizeof(mynode)); temp->value = value;
	temp->visited = 0; temp->right = NULL; temp->left = NULL; if(root==NULL)
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
	prev->right=temp;

	return(temp);
	}

	// DFS..
	void treeDFS(mynode *root)
	{

	printf("[%d] ", root->value); root->visited = 1;
	if (root->left)
	{

	if(root->left->visited==0)
	{

	treeDFS(root->left);
	}
	}
	 
	if (root->right)
	{

	if(root->right->visited==0)
	{

	treeDFS(root->right);
	}
	}
	}

	Breadth First Search
	Breadth First Search (BFS) searches the graph one level (one edge away from the starting vertex) at a time. In this respect, it is very similar to the level order traversal that we discussed for trees. Starting at some arbitrarily chosen vertex v, we mark v so that we know we've visited it, process v, and then visit and process all of v's neighbors. Now that we've visited and processed all of v's neighbors, we need to visit and process all of v's neighbors neighbors. So we go to the first neighbor we visited and visit all of its neighbors, then the second neighbor we visited, and so on. We continue this process until we've visited all vertices in the graph. We don't use recursion in a BFS because we don't want to traverse recursively. We want to traverse one level at a time. So imagine that you visit a vertex v, and then you visit all of v's neighbors w. Now you need to visit each w's neighbors. How are you going to remember all of your w's so that you can go back and visit their neighbors? You're already marked and processed all of the w's. How are you going to find each w's neighbors if you don't remember where the w's are? After all, you're not using recursion, so there's no stack to keep track of them. To perform a BFS, we use a queue. Every time we visit vertex w's neighbors, we dequeue w and enqueue w's neighbors. In this way, we can keep track of which neighbors belong to which vertex.
	This is the same technique that we saw for the level-order traversal of a tree. The only new trick is that we need to makr the verticies, so we don't visit them more than once -- and this isn't even new, since this technique was used for the blobs problem during our discussion of recursion.
	public void breadthFirstSearch(vertex v)
	{

	Queue q = new Queue(); v.visited = true; q.enQueue(v);
	while( !q.isEmpty() )
	 
	{
	Vertex w = (Vertex)q.deQueue();
	// Print the node.
	for(each vertex x adjacent to w)
	{

	if( !x.visited )
	{

	x.visited = true; q.enQueue(x);
	}
	}
	}
	}

	BFS traversal can be used to produce a tree from a graph.
	Here is some C code which does a BFS (level order traversal) on a BST...
	#include <stdio.h> typedef struct node
	{

	int value;
	struct node *right; struct node *left;
	}mynode; mynode *root;
	add_node(int value);
	void levelOrderTraversal(mynode *root); int main(int argc, char* argv[])
	{
	 
	root = NULL; add_node(5); add_node(1); add_node(-20); add_node(100); add_node(23); add_node(67); add_node(13);
	printf("\n\n\nLEVEL ORDER TRAVERSAL\n\n"); levelOrderTraversal(root);
	getch();
	}

	// Function to add a new node... add_node(int value)
	{

	mynode *prev, *cur, *temp;
	temp	= (mynode *) malloc(sizeof(mynode)); temp->value = value;
	temp->right = NULL; temp->left = NULL; if(root==NULL)
	{

	printf("\nCreating the root..\n"); root = temp;
	return;
	}

	prev=NULL;
	 
	cur=root; while(cur!=NULL)
	{

	prev=cur;
	cur = (value<cur->value)?cur->left : cur->right;
	}

	if(value < prev->value)
	prev->left=temp;

	 
	else


	}
	 


	prev->right=temp;
	 

	// Level order traversal..
	void levelOrderTraversal(mynode *root)
	{

	mynode *queue[100] = {(mynode *)0}; // Important to initialize! int size = 0;
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