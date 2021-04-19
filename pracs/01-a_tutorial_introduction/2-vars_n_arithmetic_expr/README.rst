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


Excercise 1-1
-------------

Result
^^^^^^

Excercise 1-2
-------------

Result
^^^^^^
