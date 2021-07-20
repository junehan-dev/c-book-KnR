Core Concept of Programming
===========================

Declaration and Definition
--------------------------

Declaration
^^^^^^^^^^^
   

Definition
^^^^^^^^^^

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
   
CH02-Types, Operators, and Expressions
=======================================

2.4-Declarations
----------------

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

2.8-Increment and Decrement Operators
-------------------------------------

2.10-Assigment operators and expressions
----------------------------------------

03 Control Flow
===============

04 Function and Program Structure
=================================

1. **C is designed for Program consists of many small functions.**
#. **A Program may reside in one or more source files.**

Basic of funcitions
-------------------

**Exercise 4-1**
   Write a function strrindex(s, t), which returns the position od the right most occurrence of t in s, or -1 if there is no one.

Function Returning Non-Integers
-------------------------------
**Exercise 4-2**
   Write a function atof to handle scientific notation of the form *123.45e-6*
