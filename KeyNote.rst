Core Concept of Programming
===========================

Variable
--------

Automatic variable
^^^^^^^^^^^^^^^^^^
   They are initialized each time the function or block it is in is entered.
   *The initializer may be any expression.*

Non Automatic variable
^^^^^^^^^^^^^^^^^^^^^^
   If variabls is not automatic, initialization is done once only,
   Conceptually before the program starts executing,
   *And their initializer must be a constant expression.*

External and static variable
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   By default, they are initialized to zero.
   while automatic variable has undefined(garbage) values.

Const
^^^^^
   The qualifier ``const`` can be applied to declaration of any variable to sepdictry that,
   It's value will not be changed.

Statement and Expression
------------------------

Statement(JMP)
^^^^^^^^^^^^^^
   Unit of execution and doesn't return anything.
   Statement is targeted to control the program.
   Purpose of a statement is to have side-effects.
   Breaks up cooperations between main-routine and sub-routines.

Expression(SET, CALL)
^^^^^^^^^^^^^^^^^^^^^
   Combined with *Value, Operator, Function.*
   Expect to produce(Return) value.

Functional, combination of expressions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   Expressions are safer and more compact.
 
KeyNote from Chapters 
=====================

CH02-Types, Operators, and Expressions
--------------------------------------

2.4-Declarations
^^^^^^^^^^^^^^^^
   Automatic variable
      They are initialized each time the function or block it is in is entered.
      *The initializer may be any expression.*

   Non Automatic variable
      If variabls is not automatic, initialization is done once only,
      Conceptually before the program starts executing,
      *And their initializer must be a constant expression.*

   External and static variable
      By default, they are initialized to zero.
      while automatic variable has undefined(garbage) values.

   ``const``
      The qualifier ``const`` can be applied to declaration of any variable to sepdictry that,
      It's value will not be changed.

2.7-Type Conversions
--------------------
   When an operator has operands of different types, they are converted to a common type according to a *small number of rules.*

   *small number of rules*
      convert a "narrower" operand into a "wider" one without losing information.

CH04-Function and Program Structure
-----------------------------------
   1. **C is designed for Program consists of many small functions.**
   #. **A Program may reside in one or more source files.**

4.4-Scope Rules
^^^^^^^^^^^^^^^
   - How are Definitions written so that variables are properly declared during compilation?
   - How are declarations arranged so that all the pieces will be properly connected when the program is loaded?
   - How are declarations organized so there is only one copy?
   - How are external variables initialized?

   .. note::
 
      It is important to distinguish between the
         - declaration of an external variable and
         - definition of that of external variable.

4.5-Header Files
^^^^^^^^^^^^^^^^
   There is a tradeoff between that,
      1. *each file have access only to the information it needs for its jobs and,*
      2. *the practical reality that it is harder to maintain more header files.*

4.6-Static variables
^^^^^^^^^^^^^^^^^^^^
``static`` keyword applies to...
   1. External(global) variable:
      That of ``static`` declaration **Limits the scope of that object to the rest of the source file being compiled.**
   #. Internal variable:
      That of ``static`` declaration are local to a perticular function like normal.
      but, unlike automatics, **they remain in existence rather take life cycle with function execution.**
      this means, they provide **private, permanent storage within a single function.**
   #. Function:
      A function declared with static, **it's name is invisible outside of the file in which it is declared.**

4.7-Register variables
^^^^^^^^^^^^^^^^^^^^^^
   ``register`` declaration **just advice the compiler that variable need to be placed in machine registers.** 
   *(it can be ignored.)*

   .. important::

      IMPOSIBLE to take address of register variable! even if variable is not in the register.

4.8-Block structure
^^^^^^^^^^^^^^^^^^^
   **C is not a block-structured language.**
      it just can have fashion of block-structure within loop while re-initializes the automatic variable.

4.9-initialization
^^^^^^^^^^^^^^^^^^
   - ``extern`` and ``static`` variable are garanteed to be initialized to zero.
      1. initializer must be a constant expression.
      #. initialization is done once. *(before program begins execution)*

   - *automatic* and ``register`` variable have garbage initial values.
      1. initializer is not restricted to being a constant.
      #. initialization is done each time the function or block is entered.
      #. inittilization for automatic variable is **just shorthand for assignment statements.**

   - *array may be initialized,* by following its declaration with a list of initializers.
      1. when size of the *array* is omitted, compiler will compute the length.
      #. if fewer initialzed than specified length, **missing will be zero** for ``extern,`` ``static`` and *automatic* variables.
      #. it will be error to have more than specified length.

4.10-Recursion
^^^^^^^^^^^^^^
   - C functions may be used recursively;
      A function may call itself either directly or indrectly.

   - Good example of recursion, *quicksort*
      - Given an array, one element is chosen and the others are **partitioned into two subsets.**
         1. those less than the partition element
         #. those greater than or equalt to it
      - The same process is then applied recusively to the two subsets.
      - When a subset has fewer than 2-elements, it doesn't need any sorting.
      - Our version of `quicksort`_ is not fastest possible, but it's one of the simplest.
         It uses middle element of each sub-array for partitioning.

.. _quicksort: ./studies/04_function_and_program_structure/src/sort.c

