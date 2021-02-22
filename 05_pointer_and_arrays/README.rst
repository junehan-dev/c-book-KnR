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

Examples
--------

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

