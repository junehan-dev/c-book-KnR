05_Pointer_and_Arrays
=====================

Intro
-----

Pointers are much used in C, partly beacuse,

   - They are sometimes the only way to express a computation,
   - They usually lead to mroe compact and efficient code than can be obtained in other ways.
   - Pointers and arrays are closely related.

Pointers have been lumped with ``goto`` statement as a marbelous way to create impossible-to-understand program.
However with dicipline, pointers can also be used to achieve clarity and simplicity.

05.3-Pointer and Array
----------------------

There is one difference between an array name and ponter:

   - A pointer is variable, so ``pa = a`` and ``pa++`` are legal.
   - But array name is not a varaible, so ``pa = a`` and ``pa++`` are iligal.

When an array name is passed to a function,
What is pass is the location of the initial element.
Within the called function, this argument is a local variable, and so an array name parameter is a pointer,
that is, a variable containing an address.

``char *strcat(char dest[], const char *src)``

   - ``char dest[]`` and ``char *dest`` are equivalent.
   - But ``char *dest`` is prefered because it says more explicitly that the parameter is a pointer.

05.4-Address Arithmetic
-----------------------

C-language's *integration of pointers, arrays, and address arithmetic* is one of the strengths of the language.

A Rudimentray storage allocator
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Routines:

   1. ``alloc(n)`` : Returns the pointer p to n-consecutive character positions, which can be used by caller of ``alloc`` for stroing characters.
   #. ``afree(p)`` : Realeases the storage thus acquired so it can be re-used later.

.. note::

   A storage managed by alloc and afree is a stack, or LIFO list.
   Standard library provide malloc and free, that have no such restrictions.

Implementation::

   alloc to handout pieces of a large character array that we weill call allocbuf.
   This array is pricate to alloc and afree.
   Since they deal in pointers, not array indices, no other routine need know the name of the array,
   which can be declared static in the source file contaning alloc and afree, and thus be invisible outside it.

Example
^^^^^^^

- alloc_ : ``char	*alloc(int n)``

.. _alloc: src/alloc.c

5.5-Character Pointers and Functions
------------------------------------

There is an important differecnce between these definitions:

.. code-block:: c

   char		amsg[] = "now is the time";
   char		*pmsg = "now is the time";

amsg-array
   amsg is an array, exact size to hold string and null termination.
   Individual characters within array may be changed.
   But will always refer to the same storage.

pmsg-pointer:
   Is a pointer, initialized to point to a string constat;
   The pointer may subsequently be modified to pointer elsewhere,
   but result is undefined if you try to modify the string content.

5.6-Pointer Arrays: Pointers to Pointers
----------------------------------------

Let us illustrate by writing a program that,
will sort a set of text lines into alphabetic order, a stripped-down version of the UNIX program ``sort.``

The sorting process has three steps:

   1. read all lines of input
   #. sort them
   #. print them in order

It's best to divide the program into functions that match this natural division,
with the main routine controlling the other functions.

Example
^^^^^^^

- sort_program_ : another repo in my *c-libs-file_program* repo.

.. _sort_program: https://github.com/junehan-dev/c-libs-file_program/sort/

5.7-Multi-dimensionmal Arrays
-----------------------------

.. code-block:: c

   static char daytab[2][13] = {
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
   };
   void month_day(int year, int yearday, int *pmonth, int *pday);
   int day_of_year(int year, int month, int day);

   int main(void)
   {
       int m, d;

       month_day(1988, 60, &m, &d); /* sets m to 2 and d to 29 */
   }

   void month_day(int year, int yearday, int *pmonth, int *pday)
   {
       int i, leap;

       leap = (year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0;
       for (i = 1; yearday > daytab[leap][i]; i++)
           yearday -= daytab[leap][i];
       *pmonth = i;
       *pday = yearday;
   }

   int day_of_year(int year, int month, int day)
   {
       int i, leap;

       leap = (year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0;
       for (i = 1; i < month; i++)
           day += daytab[leap][i];
       return (day);
   }

5.11-Pointers to Functions
--------------------------

function itself is not a variable, but,

.. note::

   It is possible to define pointers to functions, which can be, 
       - assigned
       - placed in arrays
       - passed to functions
       - returned by functions
       - and so on...

We will use sort program to use with option *-n* , to sort in numerical order instead of lexicographically.


Example-sort with numerical order
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Main three parts:
   1. A Comparison that determines the ordering of any pair of objects.
   #. An Exchange that reverses their order.
   #. A Sorting algorithm that makes comparisons and exchanges until that objects are in order.

- Lexicographic comparison of two lines were done by ``strcmp``
- We will also need a routine ``numcamp`` that compares two lines on the basis of numeric value and returns the same
kind of condition indication as ``strcmp`` does.


- sort_with_numerical_order_ : with *-n* option.

.. code-block:: c

   void qsort(void *lineptr[], int left, int right,
              int (*comp)(void *, void *));
   int numcmp(char *, char *);

   int main(int argc, char *argv[])
   {
       int nlines;
       int numeric = 0;

       /* check argv -v option */
       if (check_numeric_option(argv[2]) == 'n')
           numeric = 1;

       /* was there any line read? */
       if ((nlines = readlines(lineptr, MAXLINES) >= 0)) {
           qsort((void **)lineptr, 0, nlines-1,
                 (int (*)(void *, void *))(numeric ? numcmp : strcmp));
           writelines(lineptr, nlines);
           return (0);
       } else {
           printf("input too big to sort\n");
           return (1);
       }
   }

``qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));``
   in the call to ``qsort``,
   ``strcmp`` and ``numcmp`` are **address of functions.**
   Since  they are known to bo functions, the ``&`` operator is not necessray.

The generic pointer type ``void *`` is used for the pointer arguments.
Any pointer can be cast to ``(void *)some_pt;`` without loss of information.

   So we can call qsort by casting arguments to ``void *`` .

The use of comp in the line:
   ``if ((*comp)(v[i], v[left]) < 0)``
      : is Consistent with the declaration: comp is a pointer to a function, ``(*comp)`` is the function and, ``(v[i], v[left])`` is the call to it.
      Paranthesis are needed, so the components are correctly associated.

.. code-block:: c

   int numcmp(char *s1, char *s2)
   {
       double v1, v2;

       v1 = atof(s1);
       v2 = atof(s1);
       if (v1 < v2)
           return (-1);
       else if (v1 > v2)
           return (1);
       else
           return (0);
   }

5.12-Complicated Declarations
-----------------------------

C is somtimes Casticated (=kind of compliplicated) for syntax of its declarations, **particularly ones that involve pointers to functions.**


.. code-block:: c

   int *f();	/* f:	function returning pointer to int */
   int (*pf)();	/* pf:	pointer to function returning int */

.. note::

   - * is prefix operator and has lower precedence than (). so, parentheses are necessary to force the proper association.
   - typedef: is Good way to synthesize declarations in small steps with.

DCL_ONGOING...
^^^^^^^^^^^^^^
