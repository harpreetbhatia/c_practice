#include <stdlib.h>
#include <stdio.h>

	The following preprocessor directives are used for conditional compilation. Conditional compilation allows statements to be included or omitted based on conditions at compile time.
	#if
	#else
	#elif
	#endif
	#ifdef
	#ifndef
	In the following example, the printf statements are compiled when the symbol DEBUG is defined, but not compiled otherwise
	/* remove to suppress debug printf's*/
	#define DEBUG
	...
	x = ....
	 
	#ifdef DEBUG
	printf( "x=%d\n" );
	#endif... y = ....;
	#ifdef DEBUG
	printf( "y=%d\n" );
	#endif...
	#if, #else, #elif statements
	#if directive
	*	#if is followed by a intger constant expression.
	*	If the expression is not zero, the statement(s) following the #if are compiled, otherwise they are ignored.
	*	#if statements are bounded by a matching #endif, #else or #elif
	*	Macros, if any, are expanded, and any undefined tokens are replaced with 0 before the constant expression is evaluated
	*	Relational operators and integer operators may be used Expression examples
	#if 1
	#if 0
	#if ABE == 3
	#if ZOO < 12
	#if ZIP == 'g'
	#if (ABE + 2 - 3 * ZIP) > (ZIP - 2)
	In most uses, expression is simple relational, often equality test
	#if SPARKY == '7'
	#else directive
	*	#else marks the beginning of statement(s) to be compiled if the preceding #if or #elif expression is zero (false)
	*	Statements following #else are bounded by matching #endif
	 
	Examples
	#if OS = 'A'
	system( "clear" );

	 
	#else


	#endif
	 


	system( "cls" );
	 

	#elif directive
	*	#elif adds an else-if branch to a previous #if
	*	A series of #elif's provides a case-select type of structure
	*	Statement(s) following the #elif are compiled if the expression is not zero, ignored otherwise
	*	Expression is evaluated just like for #if Examples
	#if TST == 1
	z = fn1( y );
	#elif TST == 2
	z = fn2( y, x );
	#elif TST == 3
	z = fn3( y, z, w );

	#endif
	...
	#if ZIP == 'g'
	rc = gzip( fn );
	#elif ZIP == 'q'
	rc = qzip( fn );

	 
	#else


	#endif
	 


	rc = zip( fn );
	 
	#ifdef and #ifndef directives
	Testing for defined macros with #ifdef, #ifndef, and defined()
	*	#ifdef is used to include or omit statements from compilation depending of whether a macro name is defined or not.
	*	Often used to allow the same source module to be compiled in different environments (UNIX/ DOS/MVS), or with different options (development/production).
	*	#ifndef similar, but includes code when macro name is not defined.
	Examples
	#ifdef TESTENV
	printf( "%d ", i );

	#endif
	#ifndef DOS
	#define LOGFL "/tmp/loga.b";
	#else
	#define LOGFL "c:\\tmp\\log.b";
	#endif
	defined() operator
	*	defined(mac), operator is used with #if and #elif and gives 1 (true) if macro name mac is defined, 0 (false) otherwise.
	*	Equivalent to using #ifdef and #ifndef, but many shops prefer #if with defined(mac) or !defined(mac)
	Examples
	#if defined(TESTENV)
	printf( "%d ", i );

	#endif
	#if !defined(DOS)
	#define LOGFL "/tmp/loga.b";
	#else
	#define LOGFL "c:\\tmp\\log.b";
	 
	#endif
	Nesting conditional statements
	Conditional compilation structures may be nested:
	#if defined(UNIX)
	#if LOGGING == 'y'
	#define LOGFL "/tmp/err.log"
	#else
	#define LOGFL "/dev/null"
	#endif
	#elif defined( MVS )
	#if LOGGING == 'y'
	#define LOGFL "TAP.AVS.LOG"
	#else
	#define LOGFL "NULLFILE"
	#endif
	#elif defined( DOS )
	#if LOGGING == 'y'
	#define LOGFL "C:\\tmp\\err.log"
	#else
	#define LOGFL "nul"
	#endif
	#endif