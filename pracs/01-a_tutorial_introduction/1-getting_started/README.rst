Getting Started
---------------

1. Only way to learn a new programming language is by writting programs in it.
#. A C program, whatever its size, consists of functions and variables.
#. One method of communicating data between functions is for the calling function to provide a list of values, called *arguments*, to the function it calls.

Excercise 1-1
-------------
   Run the "hello, world" program on your system.
   Experment with leaving out parts of the program, to see what error messages you get.

Result
^^^^^^
   my cc is link to gcc only.
   It more modern and crowds are now familiar to c language.
   so error refered in book, no newline, is deprecated i guess.

Excercise 1-2
-------------
   Experiment to find out what happens when printf's argument string contains ``\c`` where c is some character not listed above.

Result
^^^^^^
   It just means not able to handle that escape sequnce.
   at: ``printf("\c");``

   Error:
      ``1-2_escape_c.c:5:13: error: unknown escape sequence: '\c' [-Werror]``

