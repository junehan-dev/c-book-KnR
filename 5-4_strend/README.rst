String pointers and Functions
=============================

ft_strend
---------

   Write a function ``strend(s, t)``\, which returns 1 if the string ``t`` occurs at the end of the string ``s``\, and zero otherwise.

Usage
^^^^^

   1. Run ``make`` on current directory.
   #. Run ``./run_strend.out`` generated from command above with additional 2 of positional arguments like ``./run_strend.out mystr str`` which are the strings to check is first data with second input data.
   #. Run ``make clean`` to remove files generated.

About my code
^^^^^^^^^^^^^

   - Internally uses 2 more functions(``ft_strcmp``\, ``ft_strstr``\) by ``ft_strend``\.

      - user code doesn't need to know about those internals. only use ``ft_strend`` make sense.

