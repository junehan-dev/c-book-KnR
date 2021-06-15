Assignment Operators and Expressions
====================================

ft_bitcount
-----------
   ``ft_bitcount(x)``
      A function counts bit-1 in faster way not compare by bit ``1``

   Question
      ``x &= (x - 1)`` deletes rightmost 1-bit in x.
      Use this observation to write a faster version of *bitcount_legacy.*

