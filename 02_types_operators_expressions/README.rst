02_Types_Operators_N_Expressions
================================

Declarations
   List the variables to be used,
   and state what type they have,
   and perhaps what their initial values are.

Operators
   Specify what is to be done to them.

Expressions
   Combine variables and constants to produce new values.

Type of object
   Determines the set of values it can have,
   and what operations can be performed on it.

These building blocks are the topics of this chapter.

2.3-Constants
-------------

Octal and Hex, escape sequence
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cetain characters can be represented in character and string constants,
by escape sequences line ``\n`` (newline).

In addition, an arbitary byte-sized bit patterns can be specified by,

   - ``'\000'`` : Where 000 is one to three octal digits.
   - ``'\xhh'`` : Where hh is one or more hexadecimal digits.

.. code-block:: c

   /* OCTAL DIGITS */
   #define VTAB '\013'    /* ASCII Vertical tab */
   #define BELL '\013'    /* ASCII Bell character */

   /* HEX DIGITS */ 
   #define VTAB_H '\xb'
   #define BELL_H '\x7'

   #define M_MSG "hello," " world" /* equ to "hello, world" */
   /* String constants can be concatenated at compile time
    *
    * Useful for splitting long strings accross several source lines.
    */

String constant
^^^^^^^^^^^^^^^

Technically, a string constant is an array of characters.
The internal representation of a string *has a null character at the end.*

   - so, the physicasl storage required is one more than number of chars written between the quotes.

Enumeration constant
^^^^^^^^^^^^^^^^^^^^

**An Enumeration is a list of constant integer values.**

.. code-block:: c

   enum boolean { NO, YES };
   /* first has 0 next 1 unless, no explicit values are specified. */

   enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
                  NEWLINE = '\n', VTAB = '\t', RETURN = '\r' };
    
   enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
                 JUL, AUG, SEP, OCT, NOV, DEC };
   /* FEB is 2, MAR is 3, etc. */

Enumerations is an alternative to ``#define`` with the advantage that the values can be generated for you.

Enumeration variables offer the chance of checking and so are often better than ``#define`` .
In addition, a debugger maky be able to print values of enumeration variables in their symbolic form.

2.4-Declarations
----------------

.. note::

   - Automatic variables with no initializer have undefined garbage values.
   - ``extern`` and ``static`` variables are initialized to zero by default.
 
2.7-Type_Conversions
--------------------

There is one subtle point about characters to integers.
The language does not specify whether variables of type ``char`` are signed or unsigned quantities.
When a ``char`` is converted to an int, can it ever produce a negative integer?::

   - Answer varies from machine to machine, reflecting difference in architecture.
   - C guarantees that any character in the machine's standard print character set will never be negative.

Unsigned data conversion
^^^^^^^^^^^^^^^^^^^^^^^^

Conversion rules are more complicated when ``unsigned`` operands are involved.
Comparisons between signed and unsigned values are machine-depentant.

   **Because they depend on the sizes of various integer types**

For example, Suppose that::

   - ``int`` 16 bits
   - ``long`` 32 bits
   - ``-1L < 1U``   : 1U is promoted to a signed long.
   - ``-1L > 1UL``  : -1L promoted to unsgined long, U_L_MAX.

float to int
^^^^^^^^^^^^

floating point bit pattern
   1 bit(MSB) && 1 byte(exponent) && 31 bits(mentisa)

``float`` to ``int`` causes truncation of any fractional part.
When ``double`` to ``float``, whether the value is rounded or truncted is implementation dependant.

function argument with void value
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the absence of function prototype,

   - ``char`` ``short`` -> ``int``
   - ``float`` -> ``double``

