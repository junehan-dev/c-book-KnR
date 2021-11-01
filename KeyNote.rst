Core Concept of Programming
===========================

Variable
--------

Automatic variable
^^^^^^^^^^^^^^^^^^
   They are initialized each time the function or block it is in is entered.
   *The initializer may be any expression.*

Non Automatic variable
^^^^^^^^^^^^^^^^^^^^^^
   If variabls is not automatic, initialization is done once only,
   Conceptually before the program starts executing,
   *And their initializer must be a constant expression.*

External and static variable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   By default, they are initialized to zero.
   while automatic variable has undefined(garbage) values.

Const
^^^^^
   The qualifier ``const`` can be applied to declaration of any variable to sepdictry that,
   It's value will not be changed.

Statement and Expression
------------------------

Statement(JMP)
^^^^^^^^^^^^^^
   Unit of execution and doesn't return anything.
   Statement is targeted to control the program.
   Purpose of a statement is to have side-effects.
   Breaks up cooperations between main-routine and sub-routines.

Expression(SET, CALL)
^^^^^^^^^^^^^^^^^^^^^
   Combined with *Value, Operator, Function.*
   Expect to produce(Return) value.

Functional, combination of expressions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   Expressions are safer and more compact.
 
KeyNote from Chapters 
=====================

CH02-Types, Operators, and Expressions
======================================

2.4-Declarations
----------------
   Automatic variable
      They are initialized each time the function or block it is in is entered.
      *The initializer may be any expression.*

   Non Automatic variable
      If variabls is not automatic, initialization is done once only,
      Conceptually before the program starts executing,
      *And their initializer must be a constant expression.*

   External and static variable
      By default, they are initialized to zero.
      while automatic variable has undefined(garbage) values.

   ``const``
      The qualifier ``const`` can be applied to declaration of any variable to sepdictry that,
      It's value will not be changed.

2.7-Type Conversions
--------------------
   When an operator has operands of different types, they are converted to a common type according to a *small number of rules.*

   *small number of rules*
      convert a "narrower" operand into a "wider" one without losing information.

CH04-Function and Program Structure
===================================
   1. **C is designed for Program consists of many small functions.**
   #. **A Program may reside in one or more source files.**

4.4-Scope Rules
---------------
   - How are Definitions written so that variables are properly declared during compilation?
   - How are declarations arranged so that all the pieces will be properly connected when the program is loaded?
   - How are declarations organized so there is only one copy?
   - How are external variables initialized?

   .. note::
 
      It is important to distinguish between the
         - declaration of an external variable and
         - definition of that of external variable.

4.5-Header Files
----------------
   There is a tradeoff between that,
      1. *each file have access only to the information it needs for its jobs and,*
      2. *the practical reality that it is harder to maintain more header files.*

4.6-Static variables
--------------------
``static`` keyword applies to...
   1. External(global) variable:
      That of ``static`` declaration **Limits the scope of that object to the rest of the source file being compiled.**
   #. Internal variable:
      That of ``static`` declaration are local to a perticular function like normal.
      but, unlike automatics, **they remain in existence rather take life cycle with function execution.**
      this means, they provide **private, permanent storage within a single function.**
   #. Function:
      A function declared with static, **it's name is invisible outside of the file in which it is declared.**

4.7-Register variables
----------------------
   ``register`` declaration **just advice the compiler that variable need to be placed in machine registers.** 
   *(it can be ignored.)*

   .. important::

      IMPOSIBLE to take address of register variable! even if variable is not in the register.

4.8-Block structure
-------------------
   **C is not a block-structured language.**
      it just can have fashion of block-structure within loop while re-initializes the automatic variable.

4.9-initialization
------------------
   - ``extern`` and ``static`` variable are garanteed to be initialized to zero.
      1. initializer must be a constant expression.
      #. initialization is done once. *(before program begins execution)*

   - *automatic* and ``register`` variable have garbage initial values.
      1. initializer is not restricted to being a constant.
      #. initialization is done each time the function or block is entered.
      #. inittilization for automatic variable is **just shorthand for assignment statements.**

   - *array may be initialized,* by following its declaration with a list of initializers.
      1. when size of the *array* is omitted, compiler will compute the length.
      #. if fewer initialzed than specified length, **missing will be zero** for ``extern,`` ``static`` and *automatic* variables.
      #. it will be error to have more than specified length.

4.10-Recursion
--------------
   - C functions may be used recursively;
      A function may call itself either directly or indrectly.

   - Good example of recursion, *quicksort*
      - Given an array, one element is chosen and the others are **partitioned into two subsets.**
         1. those less than the partition element
         #. those greater than or equalt to it
      - The same process is then applied recusively to the two subsets.
      - When a subset has fewer than 2-elements, it doesn't need any sorting.
      - Our version of `quicksort`_ is not fastest possible, but it's one of the simplest.
         It uses middle element of each sub-array for partitioning.

.. _quicksort: ./studies/04_function_and_program_structure/src/sort.c

4.11-The C Preprocessor
-----------------------
   C Provide certain language facilities by means of a preprocessor, which is conceptually a separate first step in compilation.
   The two most frequently used features are ``#include`` to include the contents of a file during compilation, and ``#define`` to replace a token by an arbitary sequence of characters.
   Other features described in this section include conditional compliation and macros with arguments.

4.11.1-File Inclusion
^^^^^^^^^^^^^^^^^^^^^
   There are often several ``#include`` lines at the beginning of a source file, to include common ``#define`` statements an ``extern`` declarations, or to access the function prototype declaration for library functions from headers like ``<stdio.h>.``
      *(Strictly speaking, these need not be files. The details of how headers are accessed are implementation-dependent.)*

   ``#include`` is preferred way to tie the declarations together for a large program.
   It guarantees that all the source files will be supplied with the same definitions and varaible declarations, and thus eliminates a particularly nasty kind of bug.
   Naturally, when an included file is changed, all files that depend on it must be recomplied.

4.11.2-Macro Substitution
^^^^^^^^^^^^^^^^^^^^^^^^^
   A definition has the form:
      ``#define name	replacement text``

   It calls for a macro substitution of the simplest kind-(subsequent occurences of the token *name* will be replaced by the *replacement* text.)
   The name in a ``#define`` has the same form as a variable name;
      The replacement text is arbitary.

   Normally the replacement text is the rest of the line, but a long definition may be continued onto several lines by placing a ``\\`` at the end of each line to be continued.
   The scope of a name defined with ``#define`` is from its point of definition to the end of the source file being compiled.
   A definition may use previous definitions.

   Substitutions are made only for tokens, and do not take place within quoted strings.
   For example, if ``YES`` is a defined name, there would be no substitution in ``printf("YES")`` or in ``YESMAN``\.

   It is possible to define macros with arguments, so the replacement text can be different for different calls of the macro:
      ``#define max(A, B) ((A) > (B) ? (A) : (B))``

   Although it looks like a function call, a use of *max* expands into in-line code.

   **Pitfalls in Macro(with side effect)**
      If you examine expansion of *max*\, you will notice some pitfalls.
      The Expressions are evaluated twice;
      this is bad if they involve side effects like increment operators or input and output, For instance
         ``max(i++, j++) /* WRONG */``

      will increment the larger twice.
      Some care also has to be taken with parantheses to make sure the orfer of evaluation is preserved
         .. code-block:: c

            #define max(A, B) ((A) > (B) ? (A) : (B))
            max(i++, j++); 
            /*
            * (i = 4 and j = 5)
            * 1. 4 < 5 condition eval, and ++.
            * 2. (B) returns 6, and ++.
            * 3. j becomes 7.
            */
            
            #define square(x) x * x
            square(j + 1);
            /*
            * (j = 7)
            * 1. 7 + 1 set is x, expands to 7 + 1 * 7 + 1
            * 2. returns 15.
            */

   Nonetheless, macros are valuable,
   One practical example comes from ``<stdio.h>``\, in which ``getchar`` and ``putchar`` are oftendefined as macros,
   **to avoid the run-time overhead of a function call per character processed.**
   The functions in ``<ctype.h>`` are also usually implemented as macros.

   Names may be undefined with ``#undef``\, usually to ensure that a routine is really a function, not a macro.
      .. code-block:: c

         #undef getchar
         
         int	getchar(void) { ... }

   Formal parameters are not replaced within quoted strings.
   If, however, a parameter name is preceded by a ``#`` in replacement text, the combination will be expanded into a quoted stirng with the parameter replaced by the actual argument.
   This can be combined with string concatenation to make, for example. a debugging print macro.

      ``#define dprint(expr)	printf(#expr " = %g\n", expr)``

   When this is invoked with ``x/y`` arguments, macro is expanded into

      1. ``printf("x/y" " = &g\n", x/y);``
      #. And the strings are concatenated, so the effect is
      #. ``printf("x/y = &g\n", x/y);``

   The preprocessor operator ``##`` provides a way to concatenate actual arguments during macro expansion.
   If a parameter in the replacement text is adjacent to a ``##``\, the parameter is replaced by the actual argument, the ``##`` and surrounding white space are removed, and the result is rescanned. 

      ``#define	paste(front, back)	front ## back``

   So, ``paste(name, 1)`` creates the token ``name1``.
   The rules for nested uses of ``##`` are arcane.

4.11.3-Conditional Inclusion
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   It is possible to control preprocessing itself with conditional statements that are evaluated during preprocessing.
   This provides a way to include code selectively, depending on the value of conditions evaluated during compliation.

   - ``#if ~ #else ~ #endif``

   The ``#if`` line evaluates a constant integer expression(which may not include ``sizeof``\, casts or ``enum`` constants).
   If the expression is non-zero, subsequent lines until an ``#endif`` or ``#elif`` or ``#else`` are included.
      (The preprocessor statement ``#elif`` is line ``else-if``\.)
   The expression defined in a ``#if <name>`` is 1 if the *<name>* has been defined, and 0 otherwise.

   This sequence tests the name ``SYSTEM`` to decide which version of a header to include:

      .. code-block:: c

         #if SYSTEM == SYSV
         	#define HDR "sysv.h"
         #elif SYSTEM == BSD
         	#define HDR "bsd.h"
         #elif SYSTEM == MSDOS
         	#define HDR "msdos.h"
         #else
         	#define HDR "default.h"
         #endif
         #include HDR

   The ``#ifdef`` and ``#ifndef`` lines are specialized forms that test whether a name is defined.
   The first example of ``#if`` above could have been written

      .. code-block:: c

          #ifndef HDR
          #define HDR

          /* content of hdr.h go here */

          #endif

CH05-Pointers and Arrays
========================

   A pointer is a variable that contains the address of a variable.
   Pointers are much used in C, partly because,

      1. They are sometimes the only way to express a computation.
      #. They usually lead to more compact and efficient code than can be obtained in other ways.

   Pointers and arrays are closely related;
   (this chapter also explores this relation ship and shows how to exploit it.)

   Pointers have been lumped with the goto statement as a marvelous way to create *impossible-to-understand programs.*
   This is certainly true when they are used carelessly, and it is easy to create pointers that point somewhere unexpected.
   However, with discipline(well-trained way to use), Pointers can also be used to achieve clarity and simplicity.
   This is aspect that we will try to illustrate.

   The main change in *ANSI C* is to make explicit the rules about how pointers can be manipulated, in effect mandating what good programmer already practice and good compliers already enforce.
   In addition, the type ``void *``\*(pointer to void)* replaces ``char *`` as the proper type for a generic pointers.

5.1 Pointers and Addresses
--------------------------

   A typical machine has an array of consecutively numbered or addressed memory cells that may be manipulated individually or in contiguous groups.
   One common situation is that any byte can be a ``char``\, a pair of one-byte cells can be treated as a short integer, and foue adjacent bytes from a ``long``\.

   A pointer is a group of cells (often two or four) that can hold an address.
   So, if ``c`` is a ``char`` and ``p`` is a pointer that points to it, we could represent the situation this way::

      - ``c`` -> data ref 1byte character.
      - ``p`` -> c itself.

   The unary operator ``&`` gives the address of an object, so the statement:

      ``p = &c;``

   assigns the address of ``c`` to the variable ``p``\, and ``p`` is said to "point to" ``c``\.
   The ``&`` operator only applies to objects in memory:
      variables and array elements.
   It **cannot** be applied to expressions, constants, or ``register`` variables.

   The unary operator ``*`` is the *indirection* or *dereferencing* operator;
      When applied to a pointer, it accesses the object the pointer points to.
   Suppose that ``x`` and ``y`` are integers and ``ip`` is a pointer to ``int``\.
   This artificial sequence shows how to declare a pointer and how to use ``&`` and ``*``\:

      .. code-block:: c

         int	x = 1, y = 2, z[10];
         int	*ip;
         
         ip = &x;	// ip store ref to x.
         y = *ip;	// y store 1.
         *ip = 0;	// x store 0.
         ip = &z[0];	// ip -> z[0].

   The declaration of ``ip``\, is intended as mnemonic;
      it says that the expression ``*ip`` is an ``int``\.
   The syntax of the declaration for variable mimics the syntax of expression in which the variable might appear.
   This reasoning applies to function declarations as well.
   for example,

      ``double	*dp, atof(char *);``
         says that in an expression ``*dp`` and ``atof(s)`` have value of type double, and that argument of atof is pointer to ``char``\.

   .. note::

      The implication that a pointer is constrained to point to a particular kind of object:
         Every pointer points to a specific data type.

   .. note::

      There is one exception:
         a "pointer to ``void``\" is **used to hold any type of pointer but cannot be dereferenced itself.**

   Finally, since pointers are variables, they can be used without dereferencing.
   For example, if ``iq`` is another pointer to ``int``\.

      ``iq = ip``
         copies the contents of ``ip`` into ``iq``\, thus making ``iq`` point to whatever ``ip`` pointed to.


5.2 Pointers and Function Arguments
-----------------------------------
   Since C passes arguments to functions by value, there is no direct way for the called function to alter a variable in the calling fuction.
   For instance, a sorting routine might exchange two out-of-order arguments with a fuction called ``swap``\.
   It is not enough to write ``swap(a, b);`` where the ``swap`` function is defined as
      .. code-block:: c

         void swap(int x, int y) /*WRONG*/
         {
         	int	temp;

         	temp = x;
         	x = y;
         	y = temp;
         }

   Because of call by value, ``swap`` can't affect the arguments ``a`` and ``b`` in the routine that called it.
   The fuction above swaps **copies** of ``a`` and ``b``\.
   The way to obtain the desired effect is for the calling program to pass *pointers* to the values to be changed:

      - ``swap(a, b);`` -> ``swap(&a, &b);``
      - ``void swap(int, int);`` -> ``void swap(int *, int *);``

   Pointer arguments enable a function to access and change objects in the function that called it.

   As an example, consider a function ``getint`` that performs free-format input conversion by breaking a stream of characters into integer values, one integer per call.

      - ``getint`` has to return the value it found and also signal end of file when there is no more input.
      - These values have to be passed back by separate paths, for no matter what value is used for ``EOF``\, that could also be the value of an input integer.
      - One solution is to have ``getint`` return the end of file status as its function value, while using a pointer argument to store the converted integer back in the calling function.
      - This is the scheme used by ``scanf`` as well.

   Our version of ``getint`` returns ``EOF`` for end of file, zero if the next input is not a number, and a positive value if the input contains a valid number.

      .. code-block:: c

         int	getch(void);
         void	ungetch(int);

         /* getint: get next int from input into *pn */
         int	getint(int *pn)
         {
         	int	c, sign;
          
         	while (isspace(c = getch()));
         	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
         		ungetch(c);
         		return (0);
         	}

         	sign = (c == '-') ? -1 : 1;
         	for (*pn = 0; isdigit(c); c = getch())
         		*pn = 10 * *pn + (c - '0');

         	*pn *= sign;
         	if (c != EOF)
         		ungetch(c);

         	return (c);
         }
 
   Throughout ``getint``\, ``*pn`` is used as an ordinary ``int`` variable.
   We have also used ``getch`` and ``ungetch`` so the one extra character that must be read can be pushed back onto the input

5.3 Pointers and Arrays
-----------------------
   Any operation that can be achieved by array subscripting can also be done with pointers.
   The pointer version will in general be **faster** but, at least to the uninitiated, somewhat harder to understand.

   There is one difference between an array name and a pointer that must be kept in mind.

      - Pointer is a variable, so ``pa = a`` and ``pa++`` is legal.
      - But an array name is not a variable.
         constructions like ``a = pa`` and ``a++`` are illegal.

   When an array name is passed to a function, what is passed is the *location of the initial element*\.
   Within the the callee function, this argument is a local variable, and so an array name parameter is a pointer, that is, a variable containing address.

   As formal parameters in a function definition,

      - ``char s*``
      - ``char s[]`` *(PREFERED expression.)*
         *(because,* **it says more explicitly that the parameter is a pointer**\*.)*

   are equivalent.

5.4 Address Arithmetic
----------------------

   .. code-block:: c

      #define ALLOCIZE	100
      static char	allocbuf[ALLOCSIZE];
      static char	*allocp = allocbuf;

      char	*alloc(int n) {
      	allocp = (allocbuf + ALLOCSIZE - allocp) >= n ? allocp + n : allocp;
      	return (allocp);
      }

      void	afree(char *p) {
      	allocp = (p >= allocbuf && p (allocbuf + ALLOCSIZE)) ? p : allocp;
      }

- C guarantees that *zero* is never a valid address for data.
   - So return value of zero can be used to signal an abnormal event, in this case, **no space to allocate.**
- Pointers and integers are not interchangeable.
   - Zero is the sole exception
      - *the constant zero may be assigned to a pointer, and a pointer may be campared with the constant zero.*
   - The symbolic constant ``NULL`` is often used in place of zero, as mnemonic to indicate more clearly that, "This is a special value for a pointer."
- Pointers may be compared under certian circumstances: **if those are in same series of address**\, then they will work properly.
   - One exception for, address of the first element past the end of an array cna be used in pointer arithmetic.
- Pointer subtraction is also valid:

   .. code-block:: c

      int	strlen(char *s)
      {
      	char	*p = s;
      
      	while (*p != '\0')
      		p++;
      
      	return (p - s);
      }
   - the number of characters in string could be too large to store in int.

      - ``<stddef.h>`` defines a type ``ptrdiff_t`` that is large enough to handle singed diff of two pointers.
      - however, (if with very cautious), we would use ``size_t`` for the return type of ``strlen`` **to match the stdlib version.**

         - (``size_t`` is integer type return by ``sizeof`` operator.)
- All other pointer arithmatic is illegal.
  - except for ``void *`` to assign a pointer of one type to another type of pointer without cast.

