#include <stdlib.h>
#include <stdio.h>

	While working under DOS only 1 mb of memory is accessible. Any of these memory locations are accessed using CPU registers. Under DOS, the CPU registers are only 16 bits long. Therefore, the minimum value present in a CPU register could be 0, and maximum 65,535. Then how do we access memory locations beyond 65535th byte? By using two registers (segment and offset) in conjunction. For this the total memory (1 mb) is divided into a number of units each comprising 65,536 (64 kb) locations. Each such unit is called a segment. Each segment always begins at a location number which is exactly divisible by 16. The segment register contains the address where a segment begins, whereas the offset register contains the offset of the data/code from where the segment begins. For example, let us consider the first byte in B block of video memory. The segment address of video memory is B0000h (20-bit address), whereas the offset value of the first byte in the upper 32K block of this segment is 8000h. Since 8000h is a 16-bit address it can be easily placed in the offset register, but how do we store the 20-bit address B0000h in a 16-bit segment register? For this out of B0000h only first four hex digits (16 bits) are stored in segment register. We can afford to do this because a segment address is always a multiple of 16 and hence always contains a 0 as the last digit.
	Therefore, the first byte in the upper 32K chunk of B block of video memory is referred using segment:offset format as B000h:8000h. Thus, the offset register works relative to segment register. Using both these, we can point to a specific location anywhere in the 1 mb address space.
	Suppose we want to write a character `A' at location B000:8000. We must convert this address into a form which C understands. This is done by simply writing the segment and offset addresses side by side to obtain a 32 bit address. In our example this address would be 0xB0008000. Now whether C would support this 32 bit address or not depends upon the memory model in use. For example, if we are using a large data model (compact, large, huge) the above address is acceptable. This is because in these models all pointers to data are 32 bits long. As against this, if we are using a small data model (tiny, small, medium) the above address won't work since in these models each pointer is 16 bits long.
	What if we are working in small data model and still want to access the first byte of the upper 32K chunk of B block of video memory? In such cases both Microsoft C and Turbo C provide a keyword called far, which is used as shown below,
	char far *s = 0XB0008000;
	 
	A far pointer is always treated as 32 bit pointer and contains both a segment address and an offset.
	A huge pointer is also 32 bits long, again containing a segment address and an offset. However, there are a few differences between a far pointer and a huge pointer.
	A near pointer is only 16 bits long, it uses the contents of CS register (if the pointer is pointing to code) or contents of DS register (if the pointer is pointing to data) for the segment part, whereas the offset part is stored in the 16-bit near pointer. Using near pointer limits your data/code to current 64 kb segment.
	A far pointer (32 bit) contains the segment as well as the offset. By using far pointers we can have multiple code segments, which in turn allow you to have programs longer than 64 kb. Likewise, with far data pointers we can address more than 64 kb worth of data. However, while using far pointers some problems may crop up as is illustrated by the following program.
	main( )
	{

	char far *a = OX00000120; char far *b = OX00100020; char far *c = OX00120000; if ( a == b )
	printf ( "Hello" ) ; if ( a == c )
	printf ( "Hi" ) ; if ( b == c )
	printf ( "Hello Hi" ) ; if ( a > b && a > c && b > c )
	printf ( "Bye" ) ;
	}

	Note that all the 32 bit addresses stored in variables a, b, and c refer to the same memory location. This deduces from the method of obtaining the 20-bit physical address from the segment:offset pair. This is shown below.
	00000 segment address left shifted by 4 bits 0120   offset address
	 
	--------
	00120 resultant 20 bit address
	00100 segment address left shifted by 4 bits 0020   offset address
	--------
	00120 resultant 20 bit address
	00120 segment address left shifted by 4 bits 0000   offset address
	--------
	00120 resultant 20 bit address
	Now if a, b and c refer to same location in memory we expect the first three ifs to be satisfied. However this doesn't happen. This is because while comparing the far pointers using == (and !=) the full 32-bit value is used and since the 32-bit values are different the ifs fail. The last if however gets satisfied, because while comparing using > (and >=, <,
	<= ) only the offset value is used for comparison. And the offset values of a, b and c are such that the last condition is satisfied.
	These limitations are overcome if we use huge pointer instead of far pointers. Unlike far pointers huge pointers are `normalized' to avoid these problems. What is a normalized pointer? It is a 32- bit pointer which has as much of its value in the segment address as possible. Since a segment can start every 16 bytes, this means that the offset will only have a value from 0 to F.
	How do we normalize a pointer? Simple. Convert it to its 20-bit address then use the the left 16 bits for the segment address and the right 4 bits for the offset address. For example, given the pointer 500D:9407, we convert it to the absolute address 594D7, which we then normalize to 594D:0007.
	Huge pointers are always kept normalized. As a result, for any given memory address there is only one possible huge address - segment:offset pair for it. Run the above program using huge instead of far and now you would find that the first three ifs are satisfied, whereas the fourth fails. This is more logical than the result obtained while using far. But then there is a price to be paid for using huge pointers. Huge pointer arithmetic is done with calls to special subroutines. Because of this, huge pointer arithmetic is significantly slower than that of far or near pointers. The information presented is specific to DOS operating system only.
