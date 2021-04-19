Variables and arithmetic expressions
------------------------------------

Careful when calculate floating point numbers
   .. code-block:: c

      #include <float.h>
      #include <math.h>

      int i = 0;
      float ret = 0.0;

      while (i++ < 10)
         ret += 0.1;

      if (fabsf(ret - 1.0) <= FLT_EPSILON)
          printf("True");


Exercise 1-1
------------
   Modify the temperature conversion program to print a heading above the table.

Result
^^^^^^
   Pass this Exercise.

Exercise 1-2
------------
   Write a Program to print the corresponding Celsius to Fahrenheit table.

Result
^^^^^^
   make default-target to ``celtofhar.out``
   Run with cli params.
