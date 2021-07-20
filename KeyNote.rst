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
