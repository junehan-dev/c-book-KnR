String pointers and Functions
=============================

ft_strcat
---------

   Write a pointer version of function ``strcat`` that showed in chapter 2, strcat_old_: ``strcat(s, t)``  copies the string t to the end of s.

.. _strcat_old: ./srcs/strcat_old.c

Usage
^^^^^

   1. Run ``make`` on current directory.
   #. Run ``./concat-strs.run`` generated from command above with positional argument which are the strings to concatnate in order.
   #. Run ``make clean`` to remove files generated.

About my code
^^^^^^^^^^^^^

   - early-return at 1st line if source string is empty.
   - Doesn't increment the pointer if source pointer has NULL terminate value.

      - because i don't like to increase the pointer to invalid address.

   - No handling for dest-address validity checking.

      - Length of dest array in 64 characters. user should take control of that.

