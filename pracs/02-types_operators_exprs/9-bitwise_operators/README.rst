Bitwise operators
=================

ft_setbits
----------
   ``ft_setbits(x, p, n, y)``
      A function returns ``x``
      that, begin at position ``p`` rightmost ``n`` bits set to ``y``

   Signature 
      ``unsigned int	ft_setbits(unsigned int src, size_t offset, size_t len, int mask);``

   ENHENCED
      - after ``ft_invert``
         - ``offet`` 0 handled.
         - automatic variable names become clear
         - left + right + mid

ft_invert
---------
   ``ft_invert(x, p, n)``
      A funciton returns ``x``
      that, begin at position ``p`` for ``n`` bits inverted.
      leaving other bits unchanged.

   Signature
      ``unsigned int ft_invert(unsigned int src, size_t offset, size_t len, size_t maxlen)``

   ENHENCED
      - various bit length can be handled by parameter ``maxlen``
      - ``offset`` 0 and with ``len`` handled without if-statement.
      - not mid + mid
