06-Structures
=============

Structure
   A collection of one or more variables(Possibly of different types),
   grouped together under a single name for convenient handling.
   (Structures are called "records" in some languages)

Intro
-----

They permit a group of related variables to be **treated as a unit** instead of a separate entities.

Traditional Example: ``Payroll record``::

   - name
   - address
   - social security number
   - salary

More Typical for C: ``grahpic``::

   - A point is pair of coordinates.
   - A Rectangle is a pair of points.

01-Basics of Structures
-----------------------

- A structure declaration that is not followed by a list of variables reserves no storage.
- If the declaration is tagged, tag can be used later in definitions of instances of the structure.

   ``struct point pt;`` 
      Defines a variable pt which is a structure of type struct point. A structure can be initialized by following.

.. code-block:: c

   struct point { /* Structure declaration */
       int x;
       int y;
   } pt_x, pt_y, pt_z; /* following varaibles, reserves storage */

   struct point pt = { 320, 200 };
   int diff = pt.x - pt.y;


Member Operator *.*
^^^^^^^^^^^^^^^^^^^

A member of particular structure is referred to in an expression by a construction of the form:
   ``structure-name.member``

Member operator "." connects the structure name and the member name.
To print the coordinates of the point ``pt`` for instance,:
   ``printf("%d, %d", pt.x, pt.y);``

Nested structure
^^^^^^^^^^^^^^^^

Structures can be nested.
One representation of a rectangle is a pair of points:

.. code-block:: c

   struct rect {
       struct point pt1;
       struct point pt2;
   };

   struct rect screen;

   return (screen.pt1.x);

02-Structures and Functions
---------------------------

Manipulate structures with Functions with 3-approaches::

   1. Pass components separately
   #. Pass an entire structure
   #. Pass a Pointer to it

Each has its good points and bad points.

makepoint: Pass components separately
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: c

   struct rect screen;
   struct point mid;
   struct point makepoint(int, int);

   /* makepoint: make a point from x and y components  */
   struct point makepoint(int x, int y)
   {
       struct point		temp;

       temp.x	= x;
       temp.y	= y;
       return (temp);
   }

   screen.pt1	= makepoint(0, 0);
   screen.pt2	= makepoint(XMAX, YMAX);
   mid			= makepoint((screen.pt1.x + screen.pt2.x) / 2,
                            (screen.pt1.y + screen.pt2.y) / 2);

addpoint: Pass an entire structure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: c

   /* addpoint: add two points */
   struct point addpoint(struct point p1, struct point p2)
   {
       p1.x += p2.x;
       p1.y += p2.y;

       return (p1);
   }

We incremented the component in p1 rather than using an explicit temporary variable to emphasize that structure parameters are passed by value like any others.

.. code-block:: c

   #define min(a, b) ((a) < (b) ? (a) : (b));
   #define max(a, b) ((a) > (b) ? (a) : (b));

   /* canonicalize coordinates of rectangle */
   struct rect canonrect(struct rect r)
   {
       struct rect temp;

       temp.pt1.x = min(r.pt1.x, r.pt2.x);
       temp.pt1.y = min(r.pt1.y, r.pt2.y);
       temp.pt2.x = max(r.pt1.x, r.pt2.x);
       temp.pt2.y = max(r.pt1.y, r.pt2.y);

       return (temp);
   }

Structure Pointer
^^^^^^^^^^^^^^^^^

.. note::

   If large structure is to be passed to a function,
   It is generally more efficient to pass a pointer than to copy the whole structure.

``struct point *pp;``
   If ``pp`` points to a point structure, ``*pp`` is the structure, an ``(*pp).x`` is a member.

.. code-block:: c

   struct point origin, *pp;

   pp = &origin;
   printf("origin is (%d, %d)\n", pp -> x, pp -> y);

   assert((r.pt1,x == rp.pt1.x && (r.pt1).x == (rp->pt1).x), "Equality test");

03-Arrays of Structures
-----------------------

