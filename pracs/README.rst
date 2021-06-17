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
   
