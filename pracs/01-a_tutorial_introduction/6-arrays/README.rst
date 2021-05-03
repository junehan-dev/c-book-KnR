1.6 Arrays
----------

Exercise 1-13
^^^^^^^^^^^^^
   Write a program to print a histogram of the lengths of words in its inputs.
   It is easy to draw the histogram with the bars horizontal
   A vertical orientation is more challenging.

Result
^^^^^^

.. code-block:: c

   #define MAXLEN 32
   char	*render_horizontal_bar(int occurences);
   /*
    * get int from argument and return as mallocated string.
    * combined with '|' character meaning count of that.
    * return value is appended with "\n\0" charaters.
    */

   int	print_bar(const char *src, ssize_t len);
   /*
    * src is return form render_horizontal_bar and len is length word.
    * actually writes len of src + newline character.
    * and returns len itself, excludes the count of newline character.
    */

Exercise 1-14
^^^^^^^^^^^^^
   Write a program to print a histogram of the frequencies of different characters in its input.

Result
^^^^^^
   frequencies of different character doesn't understandable...
