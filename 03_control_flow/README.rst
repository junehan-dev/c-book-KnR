03_Control_flow
===============

The control-flow statment of a language specify the order in which compuations are performed.

Statements
   Any expression becomes a statement when it is followed by a semicolon.

Semicolon
   In C, semicolons is a statement terminator,
   rather than a separator as it is in language like pascal.

Braces
   Group declarations and statements together into a **compound statement** , or **block.**
   Sytatically equal to single statement.

3.5-Loops_while_and_for
-----------------------

while
^^^^^

Whether to use while or for is largely a metter of a personal preference.
but ``while`` has no initialization or reinitialization,
**So the ``while`` is most natural.**

for
^^^

Because the components of the ``for`` are arbitary expressions,
for loops are not restricted to arithmetic progressions.

.. warning::

   Nonetheless, it is bad style to force unrelated computations into the initialization and increment of a for,
   which are better reserved for loop control operations.

- atoi_for_prog_
- shell_sort_prog_
- str_expand_ (not cleaned code)

.. _atoi_for_prog: src/3.5_for_atoi.c
.. _shell_sort_prog: src/3.5_shell_sort.c
.. _str_expand: src/ft_expand.c


