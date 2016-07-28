#include <stdlib.h>
#include <stdio.h>

	The AND operator Truth Table
	-----------
	0 AND 0 = 0
	0 AND 1 = 0
	1 AND 0 = 0
	1 AND 1 = 1
	x AND 0 = 0 x AND 1 = x
	We use bitwise "and" to test if certain bit(s) are one or not. And'ing a value against a
	 
	pattern with ones only in the bit positions you are interested in will give zero if none of them are on, nonzero if one or more is on. We can also use bitwise "and" to turn off (set to zero) any desired bit(s). If you "and" a pattern against a variable, bit positions in the pattern that are ones will leave the target bit unchanged, and bit positions in the pattern that are zeros will set the target bit to zero.
	The OR operator Truth Table
	-----------
	0 OR 0 = 0
	0 OR 1 = 1
	1 OR 0 = 1
	1 OR 1 = 1
	x OR 0 = x x OR 1 = 1
	Use bitwise "or" to turn on (set to one) desired bit(s). The XOR operator
	0 XOR 0 = 0
	0 XOR 1 = 1
	1 XOR 0 = 1
	1 XOR 1 = 0 x XOR 0 = x
	x XOR 1 = ~x
	Use bitwise "exclusive or" to flip or reverse the setting of desired bit(s) (make it a one if it was zero or make it zero if it was one).
	The >>, <<, >>=, <<= operators
	Operators >> and << can be used to shift the bits of an operand to the right or left a desired number of positions. The number of positions to be shifted can be specified as a constant, in a variable or as an expression. Bits shifted out are lost. For left shifts, bit positions vacated by shifting always filled with zeros. For right shifts, bit positions vacated by shifting filled with zeros for unsigned data type and with copy of the highest (sign) bit for signed data type. The right shift operator can be used to achieve quick multiplication by a power of 2. Similarly the right shift operator can be used to do a quick
	 
	division by power of 2 (unsigned types only). The operators >> and <<, dont change the operand at all. However, the operators >>= and <=< also change the operand after doing the shift operations.
	x << y - Gives value x shifted left y bits (Bits positions vacated by shift are filled with zeros).
	x <<= y - Shifts variable x left y bits (Bits positions vacated by shift are filled with zeros). A left shift of n bits multiplies by 2 raise to n.
	x >> y - Gives value x shifted right y bits. x >>= y - Shifts variable x right y bits.
	For the right shift, All bits of operand participate in the shift. For unsigned data type, bits positions vacated by shift are filled with zeros. For signed data type, bits positions vacated by shift are filled with the original highest bit (sign bit). Right shifting n bits
	divides by 2 raise to n. Shifting signed values may fail because for negative values the result never
	gets past -1:
	-5 >> 3 is -1 and not 0 like -5/8. Good interview question
	A simple C command line utility takes a series of command line options. The options are given to the utility like this : <utility_name> options=[no]option1,[no]options2,[no] option3?... Write C code using bitwise operators to use these flags in the code.
	//Each option will have a bit reserved in the global_options_bits integer. The global_options_bits
	// integer will have a bit set or not set depending on how the option was specified by the user.
	// For example, if the user said nooption1, the bit for OPTION1 in global_options_bits
	// will be 0. Likewise, if the user specified option3, the bit for OPTION3 in global_options_bits
	// will be set to 1.
	#define OPTION1 "option1" // For strcmp() with the passed arguments.
	#define OPTION1_BITPOS (0x00000001) // Bit reserved for this option.
	#define OPTION2 "option2"
	 
	#define OPTION2_BITPOS (0x00000002)
	#define OPTION3 "option3"
	#define OPTION3_BITPOS (0x00000004)


	//Required to do the bit operations.
	#define ALL_BITPOS (0x0001ffff)


	// Assume you have already parsed the command line option and that
	// parsed_argument_without_no has option1 or option2 or option3 (depending on what has
	// been provided at the command line) and the variable negate_argument says if the
	// option was negated or not (i.e, if it was option1 or nooption1)


	if (strcmp((char *) parsed_argument_without_no, (char *) OPTION1) == 0)
	{

	// Copy the global_options_bits to a temporary variable. tmp_action= global_options_bits;
	if (negate_argument)
	{

	 







	}
	else
	{
	 
	// Setting the bit for this particular option to 0 as the option has
	// been negated.
	action_mask= ~(OPTION1_BITPOS) & ALL_BITPOS; tmp_action= tmp_action & action_mask;





	//Setting the bit for this particular option to 1. action_mask= (OPTION1_BITPOS);
	 
	tmp_action= tmp_action | action_mask;
	}

	// Copy back the final bits to the global_options_bits variable global_options_bits= tmp_action;
	}

	else if (strcmp((char *) parsed_argument_without_no, (char *) OPTION2) == 0)
	{

	//Similar code for OPTION2
	}

	else if (strcmp((char *) parsed_argument_without_no, (char *) OPTION3) == 0)
	{

	//Similar code for OPTION3
	}

	//Now someone who wishes to check if a particular option was set or not can use the
	// following type of code anywhere else in the code. if(((global_options_bits & OPTION1_BITPOS) == OPTION1_BITPOS)
	{

	 


	}
	else
	{


	}
	 
	//Do processing for the case where OPTION1 was active.






	//Do processing for the case where OPTION1 was NOT active.
	 
