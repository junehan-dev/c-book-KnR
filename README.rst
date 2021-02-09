The C Programming language(2nd edition)
=======================================

**Book author by, Denis ritchie and Brian kernighan**

Intro
-----

C is general purpose programming language.
It has been closely associated with the UNIX system where it was developed.
*It has been called a "system programming language"*::

   Because it is useful for writing compilers and operating systems.

Many ideas of C stem from language BCPL.
Influence of BCPL on C proceeded indirectly through the language B.
BCPL and B are *"typeless"* languages.

A preprocessing step
   - Perform, macro subtitution on program text.
   - Perform, inclusion of other source files.
   - Perform, conditional compliation.

C provides no operations to deal directly with composite objects such as strings, sets, lists or arrays.
There are no operations that manipulate an entire array or stirng, although structures may be copied as a unit.

The language does not define *any storage allocation facility* other than::

   - **Stack definition**
   - **Stack discipline provided by the local variables of functions**

There is no *heap* or *garbage collection.*

Similary, C offers only straightforward **single-thread control flow.**

One of the goal of the standard
   Make sure that most existing programs would remain valid, or, failing that, that **compilers could produce warnings of new behavior.**

The data types and control structures provided by C are *supported directly by most computer.*

Book Chapters
-------------

- Chapter 1: **Tutorial on the central part of the C.**

   - Purpose is to Get the Reader Started as quickly as possible, since we believe strongly that the way to learn a new language is to write programs in it.

- Chapter 2: **Through 6 discusses various aspects of C in more detail, and rather more formally.**

   - Deals with the basic data types, operators and expressions.

- Chapter 3: **Treates control flow.**

   - ``if-else, switch, while, for,`` etc.

- Chapter 4: **Covers functions and program structure.**

   - External variables, scope rules, multiple source files, and so on.
   - Also youches on the *preprocessor.*

- Chapter 5: **Discusses pointers, and address arithmetic.**

- Chapter 6: **Covers Structures and unions.**

- Chapter 7: **Describes the Stanard library, provides a common interface to the operation system.**

   - This library is defined by the ANSI standard and is meant to be supported on all machines that support C.

- Chapter 8: **Describes an interface between C programs and UNIX operating system.**

   - Concentrates on input/output, file system, and storage allocation.

