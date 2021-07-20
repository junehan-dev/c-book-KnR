for statement
=============

ft_expand
---------
   Write a function ``expand(s1, s2)`` that expands shorthand notations like a-z in the stirng s1 into equvalent complete list *abc...xyz* in s2.
   Allow for letters of either case and digits.
   And be prepared to handle cases like *a-b-c* and *a-z0-9* and *-a-z.*
   Arrange that a leading or trailing *-* is taken literally

   Signature
      ``size_t ft_expand(char *src, const char *dest)``

   Description
      A function converts '-' sign connected with digits, or same case alphabet characters into expanded char string.

	``int set_expand(char *dest, char start, char end)``
      set string into dest, from start to end.
      returns offset to after end character position.
 
   ``int is_expandable(const char *src)``
      check source is expandable or not.
      uses is_sametype and, returns 0 or 1.

   ``int is_sametype(const char s1, const char s2)``
      determine src's connected two character is same type.
      returns 0 or 1.


