Ponters and Function Arguments
==============================

ft_getfloat
-----------
   ``getfloat``\, the floating-point analog of ``getint``\.
   What type does ``getfloat`` return as its function value?

   Signature
      ``int	ft_getfloat(float *pn, FILE *fd)``

   Description
      Basically uses ``ft_getint`` for capturing integer values, at the end of digit character, if that is equal to '.' charater it processes additionals for floating point value.

   BUGFIX
      1. Floating point accuracy improved
         div which store 0.1 was float data type, and when it become double data type to make 0.001 values to be accurate(not result value), result became accurate also.
