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

get_line_program_

.. _get_line_program: src/1.9_char_arr.c

1. ``char  line[MAXLINE]``

   Purpose of supplying the size of an array in declaration is to set aside storage.(not to decide.)

#. ``int   get_line(char dest[], int lim)``

   - The length of the array ``dest[]`` is not necessary in the get_line parameter.
   - Since, its size is set in main.

#. ``void  copy(char dest[], char src[])``

  return type ``void``, which states explicitly that no value is returned.


1.10-External_variables_N_scope
-------------------------------

automatic heceforth
   The local variables, or automatic variables, exist only when the function is called.

External Variables
^^^^^^^^^^^^^^^^^^

extern_var_program_

.. _extern_var_program: src/1.10_externs.c

As an alternative to automatic variables, it's possible to define variables that are ``external`` to each functions.
That is variables that can be accessed by name by any function.::

   This mechanism is rather like Fortan COMMON or Pascal variables declared in the outermost block.

Because External variables are globally accessible,
they can be used instead of argument lists to communicate data between functions.
Furthermore, because ``external variables`` remain in existence  permanently, rather than normally does,
They retain their values even after the functions that set them have returned.

An external variable must be *defined*, exactly once, outside of any function.::

   this sets aside storage for it.

The variable must also be *declared* in each function that wants to access it.::

   This states the type of the variable.

The declaration may be an explicit ``extern`` statement or may be implicit from context.
To make the discussion concrete, let us rewrite the longest-line program with ``line, longest, max`` as an ``external`` variables.

Before a function can use an external variable,
**The name of the variable must be made to known to the function.**

Extern variables on several source files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

extern variable defined in ``file 1`` and, used in...

   - ``file 2``
   - ``file 3``

then, ``extern`` declarations are needed in ``file 2`` and ``file 3`` *to connect the occurrences of the variables.*

.. note::

   Usual Practice is to collect ``extern`` declarations and functions in a separate file.
   Historically called a *header.*
   That is included by ``#include`` at the front of each source file.

Definition
   Refers to the place where the variable is created or assigned storage.

Declaration
   Refers to the places where the nature of the variable is stated but no storage is allocated.

The second version of longest-line program is inferior to first,
because it destroys the fenerality of two useful functions by wiring into then the names of the variables they manipulate.

.. important:

   At this point we have coverd what might be called the conventional core of C.
   With this handful of building blocks,
   It's possible to write useful programs of considerable size, and probably be good idea,
   if you paused long enough to do so.

