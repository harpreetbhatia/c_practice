#include <stdlib.h>
#include <stdio.h>

	This is also one of the most frequently asked interview questions.
	Its asked almost 99% of the times. Here are a few C programs to implement your own strstr() function.

	There are a number of ways to find a string inside another string. Its important to be aware of these algorithms than to memorize them. Some of the fastest algorithms are quite tough to understand!.

	Method1
	The first method is the classic Brute force method. The Brute Force algorithm checks, at all positions in the text between 0 and (n-m), if an occurrence of the pattern starts at that position or not. Then, after each successfull or unsuccessful attempt, it shifts the pattern exactly one position to the right. The time complexity of this searching phase is O(mn). The expected number of text character comparisons is 2n.
	Here 'n' is the size of the string in which the substring of size 'm' is being searched
	for.

	Here is some code (which works!)

	#include<stdio.h>

	void BruteForce(char *x /* pattern */, int m /* length of the pattern */, char *y /* actual
	 
	string being searched */, int n /* length of this string */)
	{
	int i, j;
	printf("\nstring :[%s]""\nlength :[%d]" "\npattern :[%s]""\nlength :[%d]\n\n", y,n,x,m);

	/* Searching */
	for (j = 0; j <= (n - m); ++j)
	{
	for (i = 0; i < m && x[i] == y[i + j]; ++i);
	if (i >= m) {printf("\nMatch found at\n\n->[%d]\n->[%s]\n",j,y+j);}
	}
	}

	int main()
	{
	char *string = "hereroheroero"; char *pattern = "hero";

	BF(pattern,strlen(pattern),string,strlen(string)); printf("\n\n");
	return(0);
	}

	This is how the comparison happens visually

	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	|||| ----> Match! hero
	 
	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero
	Method2
	The second method is called the Rabin-Karp method.

	Instead of checking at each position of the text if the pattern occurs or not, it is better to check first if the contents of the current string "window" looks like the pattern or not. In order to check the resemblance between these two patterns, a hashing function is used. Hashing a string involves computing a numerical value from the value of its characters using a hash function.

	The Rabin-Karp method uses the rule that if two strings are equal, their hash values must also be equal. Note that the converse of this statement is not always true, but a good hash function tries to reduce the number of such hash collisions. Rabin-Karp computes hash value of the pattern, and then goes through the string computing hash values of all of its substrings and checking if the pattern's hash value is equal to the substring hash value, and advancing by 1 character every time. If the two hash values are the same, then the algorithm verifies if the two string really are equal, rather than this being a fluke of the hashing scheme. It uses regular string comparison for this final check. Rabin-Karp is an algorithm of choice for multiple pattern search. If we want to find any of a large number, say k, fixed length patterns in a text, a variant Rabin-Karp that uses a hash table to check whether the hash of a given string belongs to a set of hash values of patterns we are looking for. Other algorithms can search for a single pattern in time order O(n), hence they will search for k patterns in time order O(n*k). The variant Rabin-Karp will still work in time order O(n) in the best and average case because a hash table allows to check whether or not substring hash equals any of the pattern hashes in time order of O(1).

	Here is some code (not working though!)
	#include<stdio.h> hashing_function()
	{
	// A hashing function to compute the hash values of the strings.
	....
	}

	void KarpRabinR(char *x, int m, char *y, int n)
	{
	 
	int hx, hy, i, j;
	printf("\nstring :[%s]""\nlength :[%d]""\npattern :[%s]""\nlength :[%d]\n\n", y,n,x,m);

	/* Preprocessing phase */ Do preprocessing here..
	/* Searching */ j = 0;
	while (j <= n-m)
	{
	if (hx == hy && memcmp(x, y + j, m) == 0)
	{
	// Hashes match and so do the actual strings! printf("\nMatch found at : [%d]\n",j);
	}

	hy = hashing_function(y[j], y[j + m], hy);
	++j;
	}
	}

	int main()
	{

	char *string="hereroheroero"; char *pattern="hero";

	KarpRabin(pattern,strlen(pattern),string,strlen(string));

	printf("\n\n"); return(0);
	}

	This is how the comparison happens visually

	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero
	 
	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	|||| ----> Hash values match, so do the strings! hero
	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero

	Method3

	The Knuth-Morris-Pratt or the Morris-Pratt algorithms are extensions of the basic Brute Force algorithm. They use precomputed data to skip forward not by 1 character, but by as many as possible for the search to succeed.

	Here is some code

	void preComputeData( char *x, int m, int Next[] )
	{
	int i, j; i = 0;
	j = Next[0] = -1;

	while ( i < m )
	{
	while ( j > -1 && x[i] != x[j] ) j = Next[j];
	Next[++i] = ++j;

	}
	}

	void MorrisPrat(char *x, int m, char *y, int n)
	{
	int i, j, Next[1000];

	/* Preprocessing */
	 
	preComputeData( x, m, Next );

	/* Searching */ i = j = 0;
	while (j < n)
	{
	while (i > -1 && x[i] != y[j]) i = Next[i];
	i++; j++;
	if (i >= m)
	{
	printf("\nMatch found at : [%d]\n",j - i); i = Next[i];
	}
	}
	}

	int main()
	{
	char *string="hereroheroero"; char *pattern="hero";

	MorrisPrat(pattern,strlen(pattern),string,strlen(string));

	printf("\n\n"); return(0);
	}

	This is how the comparison happens visually

	hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	!
	hero hereroheroero
	|||| ----> Match found! hero
	hereroheroero
	 
	!
	hero

	Method4

	The Boyer Moore algorithm is the fastest string searching algorithm. Most editors use this algorithm.

	It compares the pattern with the actual string from right to left. Most other algorithms compare from left to right. If the character that is compared with the rightmost pattern symbol does not occur in the pattern at all, then the pattern can be shifted by m positions behind this text symbol.

	The following example illustrates this situation. Example:
	0 1 2 3 4 5 6 7 8 9 ...
	a b b a d a b a c b a
	| |
	b a b a c |
	<------ |
	|
	b a b a c

	The comparison of "d" with "c" at position 4 does not match. "d" does not occur in the pattern. Therefore, the pattern cannot match at any of the positions 0,1,2,3,4, since all corresponding windows contain a "d". The pattern can be shifted to position 5. The best case for the Boyer-Moore algorithm happens if, at each search attempt the first compared character does not occur in the pattern. Then the algorithm requires only O(n/m) comparisons .

	Bad character heuristics

	This method is called bad character heuristics. It can also be applied if the bad character (the character that causes a mismatch), occurs somewhere else in the pattern. Then the pattern can be shifted so that it is aligned to this text symbol. The next example illustrates this situation.

	Example:

	0 1 2 3 4 5 6 7 8 9 ...
	a b b a b a b a c b a
	|
	b a b a c
	<----
	|
	 
	b a b a c

	Comparison between "b" and "c" causes a mismatch. The character "b" occurs in the pattern at positions 0 and 2. The pattern can be shifted so that the rightmost "b" in the pattern is aligned to "b".

	Good suffix heuristics

	Sometimes the bad character heuristics fails. In the following situation the comparison between "a" and "b" causes a mismatch. An alignment of the rightmost occurence of the pattern symbol a with the text symbol a would produce a negative shift. Instead, a shift by 1 would be possible. However, in this case it is better to derive the maximum possible shift distance from the structure of the pattern. This method is called good suffix heuristics.

	Example:

	0 1 2 3 4 5 6 7 8 9 ...
	a b a a b a b a c b a
	| | |
	c a b a b
	<----
	| | |
	c a b a b


	The suffix "ab" has matched. The pattern can be shifted until the next occurence of ab in the pattern is aligned to the text symbols ab, i.e. to position 2.

	In the following situation the suffix "ab" has matched. There is no other occurence of "ab" in the pattern.Therefore, the pattern can be shifted behind "ab", i.e. to position 5.

	Example:

	0 1 2 3 4 5 6 7 8 9 ...
	a b c a b a b a c b a
	| | |
	c b a a b c b a a b

	In the following situation the suffix "bab" has matched. There is no other occurence of "bab" in the pattern. But in this case the pattern cannot be shifted to position 5 as before, but only to position 3, since a prefix of the pattern "ab" matches the end of "bab". We refer to this situation as case 2 of the good suffix heuristics.

	Example:
	 

	0 1 2 3 4 5 6 7 8 9 ...
	a a b a b a b a c b a
	| | | |
	a b b a b a b b a b

	The pattern is shifted by the longest of the two distances that are given by the bad character and the good suffix heuristics.

	The Boyer-Moore algorithm uses two different heuristics for determining the maximum possible shift distance in case of a mismatch: the "bad character" and the "good suffix" heuristics. Both heuristics can lead to a shift distance of m. For the bad character heuristics this is the case, if the first comparison causes a mismatch and the corresponding text symbol does not occur in the pattern at all. For the good suffix heuristics this is the case, if only the first comparison was a match, but that symbol does not occur elsewhere in the pattern.

	A lot of these algorithms have been explained here <http://www-igm.univ- mlv.fr/~lecroq/string/node1.html> with good visualizations. Remember, again that its sufficient to know the basic Brute force algorithm and be aware of the other methods. No one expects you to know every possible algorithm on earth.
