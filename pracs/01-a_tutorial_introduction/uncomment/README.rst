Excercise 1-23
==============

uncomment
---------
   Remove all comments from C program.

   - Don't forget to handle quoted strings and character consts properly.
   - C comments do not nest.

Procedure
^^^^^^^^^
   1. read and split per line.
   #. remember the double quote ``"`` start and end.
   #. if ``/*`` mark start and no quote started?
   #. mark there and remove it.
   #. else? dont do anything.


.. code-block:: c

   const char	*strcomment(const char *haystack, const char *needle);
   size_t		del_content(char *start, char *end);

``const char *strcomment``::

   DESCRIPTION
      A function find needle start without DQ(doublequote) occurence.

   RETURN
      A pointer start on needle, NULL on not found.

``size_t	del_conent``::

   DESCRIPTION
      A function works like bzero, but work with 2 pointers.

   RETURN
      byte counts set zeroed from start to end.
