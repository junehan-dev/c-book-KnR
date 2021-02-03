01_Character_IO
===============

1.5.1-File_Copying
------------------

EOF is an integer defined in ``<stdio.h>``.
If the assignment of  charater to ``c`` is put inside the part of a ``while`` loop,
the copy program can be written whis way::

   .. code-block:: c

      while ((c = getchar()) != EOF)
          putchar(c);

This version centralizes the input, there is only one reference to ``getchar`` , and shrinks the program.

1.7-Functions
-------------

With properly designed functions,
it is possible to **ignore how a job is done.**
Only **knowing what is done is sufficient.**

*program dependancies loading by os*
   If source program appears in several files,
   you may have to say more to compile and load it than if it all appears in one, but *that is operating system matter, not a language attribute.*

.. note::

   The biggest change between ANSI C and earlier versions is **how functions are declared and defined.**

1.8-Arguments-Call by Value
---------------------------

In C, the called function cannot directly alter a variable in the calling function::

   It Can only alter its private(local), temporary copy.

**Call by value**
   It is an asset not a liability.
   It usually lead to more compact programs with fewer extraneous variables,
   Because parameters can be treated as conveniently initialized local variables in the called routine.

Example:

.. code-block:: c

   int power(int base, int n)
   {
       int p;

       for (p = 1; n > 0; --n)
           p = p * base;
       return (p);
   }

The parameter ``n`` is used as temporary variable.

**Passing Pointer value**
   When necessary, it's possible to arrange for a function to modify a variable in caller routine.
   The caller must provide the *address* of the variable to be set (technically a *pointer* to a variable).
   The callee function must declare a parameter to be a *pointer* and access the variable indirectly through it.

1.9-Character_Arrays
--------------------

get_line_SOURCE_CODE_
.. _get_line_SOURCE_CODE: src/1.9_char_arr.c

1. ``char  line[MAXLINE]``

   Purpose of supplying the size of an array in declaration is to set aside storage.(not to decide.)

#. ``int   get_line(char dest[], int lim)``

   - The length of the array ``dest[]`` is not necessary in the get_line parameter.
   - Since, its size is set in main.

#. ``void  copy(char dest[], char src[])``

  return type ``void``, which states explicitly that no value is returned.

