Ponters and Function Arguments
==============================

ft_getint
---------
   ``getint`` treats '+' or '-' not followed by a digit as a valid zero.
   Fix it to push such a character back on the input.

   Signature
      ``int	ft_getint(int *pn, FILE *fd)``

   Description
      returns 1 on Success, return zero if not-numerable character found. 
      Internally use ``getc`` and ``ungetc`` to manage stream.
      Set ``*pn`` value to 0 changed to set ``c - '0'`` if its numerable.
      (So Set ``*pn`` to 0 removed.)

      *If there is non space character and numerics, then move captured character back to stream and return 0.*
