#include <stdlib.h>
#include <stdio.h>

	const char *p	-   This is a pointer to a constant char. One cannot change the value pointed at by p, but can change the pointer p itself.
	*p = 'A' is illegal.
	p  = "Hello" is legal.
	Note that even char const *p is the same!
	const * char p - This is a constant pointer to (non-const) char. One cannot change the pointer p, but can change the value pointed at by p.
	*p = 'A' is legal.
	p  = "Hello" is illegal.
	const char * const p - This is a constant pointer to constant char! One cannot change the value pointed to by p nor the pointer.
	*p = 'A' is illegal.
	p  = "Hello" is also illegal.
	To interpret these declarations, let us first consider the general form of declaration: [qualifier] [storage-class] type [*[*]..] [qualifier] ident ;
	or
	[storage-class] [qualifier] type [*[*]..] [qualifier] ident ;
	 
	where,	
	qualifier:		volatile	const		
	storage-class:		auto	extern	static	register
	type:	void	char	short	int	long	float
	double	signed	unsigned	enum-specifier typedef-name	struct-or-union-specifier
	Both the forms are equivalent. Keywords in the brackets are optional. The simplest tip here is to notice the relative position of the `const' keyword with respect to the asterisk (*).
	Note the following points:
	*	If the `const' keyword is to the left of the asterisk, and is the only such keyword in the declaration, then object pointed by the pointer is constant, however, the pointer itself is variable. For example:
	const char * pcc; char const * pcc;
	*	If the `const' keyword is to the right of the asterisk, and is the only such keyword in the declaration, then the object pointed by the pointer is variable, but the pointer is constant; i.e., the pointer, once initialized, will always point to the same object through out it's scope. For example:
	char * const cpc;
	*	If the `const' keyword is on both sides of the asterisk, the both the pointer and the pointed object are constant. For example:
	const char * const cpcc; char const * const cpcc2;
	One can also follow the "nearness" principle; i.e.,
	*	If the `const' keyword is nearest to the `type', then the object is constant. For example:
	char const * pcc;
	*	If the `const' keyword is nearest to the identifier, then the pointer is constant. For example:
	char * const cpc;
	 
	*	If the `const' keyword is nearest, both to the identifier and the type, then both the pointer and the object are constant. For example:
	const char * const cpcc; char const * const cpcc2;
	However, the first method seems more reliable...