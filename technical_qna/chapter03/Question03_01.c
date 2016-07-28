#include <stdlib.h>
#include <stdio.h>

	// This questions is asked almost always in every interview.
	// The best way to swap two variables is to use a temporary variable. 
	int a,b,t;
	t = a; a = b; b = t;
	// There is no way better than this as you will find out soon. There are a few slick expressions that do swap variables without using temporary storage. But they come with their own set of problems.
	 
	// Method1 (The XOR trick) a ^= b ^= a ^= b;
	// Although the code above works fine for most of the cases, it tries to modify variable 'a' two times between sequence points, so the behavior is undefined. What this means is it wont work in all the cases. This will also not work for floating-point values. Also, think of a scenario where you have written your code like this
	swap(int *a, int *b)
	{

	*a ^= *b ^= *a ^= *b;
	}

	// Now, if suppose, by mistake, your code passes the pointer to the same variable to this function. Guess what happens? Since Xor'ing an element with itself sets the variable to zero, this routine will end up setting the variable to zero (ideally it should have swapped the variable with itself). This scenario is quite possible in sorting algorithms which sometimes try to swap a variable with itself (maybe due to some small, but not so fatal coding error). One solution to this problem is to check if the numbers to be swapped are already equal to each other.
	swap(int *a, int *b)
	{

	if(*a!=*b)
	{
	*a ^= *b ^= *a ^= *b;
	}
	}

	// Method2
	// This method is also quite popular a=a+b;
	// b=a-b;
	// a=a-b;
	// But, note that here also, if a and b are big and their addition is bigger than the size of an int, even this might end up giving you wrong results.
	 
	// Method3
	// One can also swap two variables using a macro. However, it would be required to pass the type of the variable to the macro. Also, there is an interesting problem using macros. Suppose you have a swap macro which looks something like this
	#define swap(type,a,b) type temp;temp=a;a=b;b=temp;
	
	// Now, think what happens if you pass in something like this
	
	swap(int,temp,a) //You have a variable called "temp" (which is quite possible).
	
	// This is how it gets replaced by the macro int temp;
	temp=temp; temp=b;
	=temp;
	// Which means it sets the value of "b" to both the variables!. It never swapped them! Scary, isn't it?
	// So the moral of the story is, dont try to be smart when writing code to swap variables. Use a temporary variable. Its not only fool proof, but also easier to understand and maintain.