translation phases
------------------

1. Characters are read from the source file and **converted into characters of the source character set.**
#. Whenever a backslash is followed immediately by a newline character, the **preporcessor deletes both.**
   - Since a **line end character ends a preprocessor directive,** this processing step lets you place a backslash at the end of a line in order to continue a directive, such as a macro definition, on the next line.

#. The source file is broken down into:
   - *preprocessor tokens*
   - *sequences of whitespace characters*

#. Each comment is treated as one space.
#. The Preprocessor directives are carried out and macro calls are expanded.

   .. note::

      Step 1 to 5 are also applied to any files inserted by ``#include`` directive.
      Once compiler has carried out the preprocessor directives, it removes them from its working copy of the source code.

#. The **characters and escape sequences in character constants** and string literals are converted into the corresponding
characters in the execution character set.
#. Adjacent string literals are concatenated into a single string.
#. The actual compiling tak place::

   The compiler analyzes the sequence of tokens and generates the corresponding machine code.

#. The linker resolves refereces to external objects and functions, and generates the executable file.
   - if a module refers to external objects or functions *that are not defined in any of the traslation units,*
      - the linker takes them from the standard library or another specified library.
   - External objects and functions must not be defined more than once in a program.

For most compilers, either the preprocessor is a separate program, or the compiler provide options to perform only the
preprocessing(step 1 through 5 in above).

This setup allows you to **verify that your preprocessor directives have the intended effects.**

