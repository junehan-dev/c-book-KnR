Ponters and Function Arguments
==============================

ft_getint
---------
   ``getint`` treats '+' or '-' not followed by a digit as a valid zero.
   Fix it to push such a character back on the input.

   Signature
      ``int	ft_getint(int *pn, FILE *fd)``

   Description
      returns 0 on Success, return zero if not-numerable character found. 
      Internally use ``getc`` and ``ungetc`` to manager stream.

