// goto.c by Bill Weinman <http://bw.org/>
#include <stdio.h>

int main( int argc, char ** argv ) {
	printf("Before the goto.\n");
	goto target;
	printf("After the goto.\n");
	target:
	printf("After the target.\n");
	return 0;
}
