1.10 External variables and scope
----------------------------------

Exercise 1-20
^^^^^^^^^^^^^
Question
   Write a Program ``detab``
      Replaces tabs in the input with the proper number of blanks to space to the next tab stop.

Procedure
   1. ``get_line``, gets single line and store it to global extern ``line[]``
   #. ``main``, keep search the array of char, and find a tab key.
      - if '\t' key found in it, ``detab(line, i)`` to exchange it with spaces.
   #. detab uses ``copy`` function, it copies array after '\t' occurence to it's own stack array ``buf[MAXLINE]``.
   #. convert tab to 4 spaces, and ``copy`` buf to after last space, ``nth + 4``
   #. with ``assert(*(src + nth + i) == ' ')`` i starts from 3 to 0, it asserts data is fine.
   #. return ``(nth + 4)`` to specify it points the character after tab was placed.

Exercise 1-21
^^^^^^^^^^^^^
Question
   Write a Program ``entab``
      Replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.

Procedure
   1. ``get_line``
   #. while.traverse char in ``extern char *line``
      - if space found? call is_entab to check 4spaces.
   #. based on if, do entab or pass character. (with counting spaces and tabs)

Exercise 1-22
^^^^^^^^^^^^^
Question
   Write a prgram to ``fold`` long input lines into two or more shorter lines.
      Fold after the last non-blank character that occurs before the n-th column of input.
      Make program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

Scenario
   1. ``const char* get_column(const char *str, size_t nth)`` to get column
      - column verified by dot(.) mark.
   #. check dot+1 character
      - if dot+1 == BLANK_TYPE: insert NL and remove all blanks. 
      - else(char or EOF or Nullterminate): alloc new line from there.
   #. May be not allocate, but split. and no manipulates but pointer array with NULL-Termination.

Exercise 1-23
^^^^^^^^^^^^^

Exercise 1-24
^^^^^^^^^^^^^
