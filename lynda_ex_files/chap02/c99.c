// c99.c by Bill Weinman <http://bw.org/>
#include <stdio.h>

int main( int argc, char ** argv )
{
	puts("C99 Version:");
	for( int i = 0; argv[i]; i++ ) {
		printf("%d: %s\n", i, argv[i]);
	}
	return 0;
}
