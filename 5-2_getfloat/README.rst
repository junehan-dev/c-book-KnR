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
