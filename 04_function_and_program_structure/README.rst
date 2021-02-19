04_Functions_and_Program_Structure
==================================

Intro
-----

Functions break large computing tasks into smaller ones.
And enable people to build on what others have done instead of starting over from scratch.

.. note::

   Appropriate functions hide details of operation from parts of the program that,
   don't need to know about them,
   thus clarifying the whole, and easing the pain of making changes.

**C Programs generally consist of many small functions rather than a few big ones.**

Examples
--------

- ft_atof_ : ``double atof(const char *src)``
- main_exec_witout_headerfile_ : from external object file.

.. _ft_atof: src/ft_atof.c
.. _main_exec_witout_headerfile: src/main_nonheader.c

4.2-Functions Returning Non-integers
------------------------------------

Manu numerical funcitons like ``sqrt, sin, cos`` retrun ``double`` .
To illustrate how to deal with this, let us write and use the function ``atof(str),`` which converts string to double-precision floating point equivalent.

``atof`` is an extension of ``atoi,`` which we showed.

declare in calling routine
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: c

   int	main()
   {
       char line[32];
       double atof(char []);
       int getline (char [], int);
       /*
        * codes
       */
       return (0);
   }

``double atof(char []);``
   The function ``atof`` must be declared and defined consistently.
 
4.3-External Variables
----------------------

The adjective "external" is used in contrast to "internal".

External variables (analoguous Fortran ``COMMON`` , *outermost block* in Pascal)
   Defined outside of any functions, and are potentially available to many functions.
   By default, **External variables and functions have the property that all references to them by the same name, even from functions compiled separately, are references to the same thing.**

.. note::

   Functions themselves are always external, because C does not allow functions to be defined inside other functions.


- Pros::

   - Greater scope
   - Life time
   - Permanent
      - useful in shareing kept data between many other functions called.

4.4-Scope Rules
---------------

.. code-block:: c

   extern int sp;
   extern double val[];

This line declare fore the rest of the source file that sp and val do not create variables or reserve storage for their block.

Function ``push`` and ``pop`` could be defined in the one file, and the variable ``val`` and ``sp`` could be defined in another file.
Then these  definitions and declarations would be nesccessary to tie them togehter:

In file1::

   .. code-block:: c

      extern int	sp;
      extern double val[];

      void		push(double f) {};
      double	pop(void) {};

In file2::

   .. code-block:: c

      int	sp = 0;
      double val[MAXVAL];

Because the ``extern`` declaration in file1 ahead of.
And outside the function definitions, they apply to all functions.
*One set of declaration suffices for all of file1.*

4.5-Header files
----------------


