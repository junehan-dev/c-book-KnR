do while
========

ft_itoa
-------
   Write a function ``itoa(n, src)`` that handle minimum negative number.
   itoa in knr version cannot handle minimum negative, because it re-define value to positive integer.

   Signature
      ``ft_itoa(int n, char *src);``

   Description
      unlike original, it doesn't changes the value it self, but converts left-mod div by 10 to positive integer and adds '0' at the end.


ft_itob
-------
   Write a function ``ft_itob(n, s, b)`` converts integer *n* into base *b* character representation in the string *s.*

   Signature
      ``ft_itob(int n, char *dest, int b);``
