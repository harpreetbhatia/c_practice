#include <stdlib.h>
#include <stdio.h>

// 	There are a number of ways one can reverse strings. Here are a few of them. These should be enough to impress the interviewer! The methods span from recursive to non-recursive (iterative).
// 	Also note that there is a similar question about reversing the words in a sentence, but still keeping the words in place. That is
// 	I am a good boy would become boy good a am I
// 	This is dealt with in another question. Here I only concentrate on reversing strings. That is
// 	I am a good boy would become yob doog a ma I
// 	Here are some sample C programs to do the same Method1 (Recursive)
	#include <stdio.h>
	static char str[]="STRING TO REVERSE"; int main(int argc, char *argv)
	{

	printf("\nOriginal string : [%s]", str);
	// Call the recursion function reverse(0);
	printf("\nReversed string : [%s]", str); return(0);
	}

	int reverse(int pos)
	{
	 
	// Here I am calculating strlen(str) everytime.
	// This can be avoided by doing this computation
	// earlier and storing it somewhere for later use. if(pos< (strlen(str)/2) )
	{

	char ch;
	// Swap str[pos] and str[strlen(str)-pos-1] ch = str[pos];
	str[pos]=str[strlen(str)-pos-1]; str[strlen(str)-pos-1]=ch;
	// Now recurse! reverse(pos+1);
	}
	}

	Method2
	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	void ReverseStr ( char *buff, int start, int end )
	{

	char tmp ;
	if ( start >= end )
	{

	printf ( "\n%s\n", buff ); return;
	}

	tmp = *(buff + start);
	 
	*(buff + start) = *(buff + end);
	*(buff + end) = tmp ;
	ReverseStr (buff, ++start, --end );
	}

	int main()
	{

	char buffer[]="This is Test"; ReverseStr(buffer,0,strlen(buffer)-1); return 0;
	}

	Method3
	public static String reverse(String s)
	{

	int N = s.length(); if (N <= 1)
	return s;
	String left = s.substring(0, N/2); String right = s.substring(N/2, N); return reverse(right) + reverse(left);
	}

	Method4
	for(int i = 0, j = reversed.Length - 1; i < j; i++, j--)
	{

	char temp = reversed[i]; reversed[i] = reversed[j]; reversed[j] = temp;
	}
	 
	return new String(reversed);
	Method5
	public static String reverse(String s)
	{

	int N = s.length(); String reverse = "";
	for (int i = 0; i < N; i++) reverse = s.charAt(i) + reverse; return reverse;
	}

	Method6
	public static String reverse(String s)
	{

	int N = s.length(); char[] a = new char[N]; for (int i = 0; i < N; i++)
	a[i] = s.charAt(N-i-1); String reverse = new String(a); return reverse;
	}

// 	Isn't that enough?