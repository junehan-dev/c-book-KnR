1.5.1 File Copying
------------------

Exercise 1-6
^^^^^^^^^^^^
   Write a program to print the value of EOF.

Exercise 1-7
^^^^^^^^^^^^
   Veryfy that the expression ``getchar() != EOF`` is 0 or 1.

Result
^^^^^^
   *srcs/get_eof.c*
      EOF returns -1.
      Integer larget than 0 will something meaning.
      0 means eol(End of line).
      So -1 is appropriate choice to promise File has ended.

1.5.3 Line Counting
-------------------

Exercise 1-8
^^^^^^^^^^^^
   Write a Program to count blanks, tabs, and newlines.

Exercise 1-9
^^^^^^^^^^^^
   1. Write a Program to copy its input to its output.
   2. Replace each string of one or more blanks by a single blank.

Exercise 1-10
^^^^^^^^^^^^^
   1. Write a program to copy its input to its output.
   2. Replace each tab by \t, each backspace by \b, each backslash by \\.
   3. This makes tabs and backspaces visible in an unambiguous way.
