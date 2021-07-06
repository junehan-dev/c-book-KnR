do while
========

ft_itoa
-------
   Write a function ``itoa(n, src)`` that handle minimum negative number.
   itoa in knr version cannot handle minimum negative, because it re-define value to positive integer.

   Signature
      ``size_t ft_itoa(int n, char *src);``

   Description
      unlike original, it doesn't changes the value it self, but converts left-mod div by 10 to positive integer and adds '0' at the end.
      Returns Length of allocated string length.


ft_itob
-------
   Write a function ``ft_itob(n, s, b)`` converts integer *n* into base *b* character representation in the string *s.*

   Signature
      ``ft_itob(int n, char *dest, int b);``

   Description
      with using bit mask with width ``(b - 1),`` push mask to left side.(MSB most)
      masking iterate while mask get right most side.
      printf b-mode expression for value, *n.*
      Returns Length of allocated string length.

   Exception
      on case of octal expression, there is left 32-bit div in 3bits(8).
      so left shifting make value error.
      my program runs with left shifting, so it need to be set for twice.

ft_itoa_format
--------------
   Write a Function ``ft_itoa_format(n, s, min)`` to assert s to length of min.
   If *s* is shorter than *min,*  pad blank on the left side.

   Signature
      ``size_t ft_itoa_format(int n, char *src, size_t min_len)``

   Description
      Return Length of allocated string length include *NULL-Termination.*
      So printing length would be better one decreased from return value.
      if ``min_len`` is lower than size of ``ft_itoa`` returns,
      Ignores that and returns orignal length.
      if pad lengh is bigger than 64, call function with 64.
