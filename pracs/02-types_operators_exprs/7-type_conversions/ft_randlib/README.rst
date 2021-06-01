ft_randlib
==========
   Defined in ``stdlib.h,`` functions return promised values differently on call by call.
   Start from seed value(1) computation.
   So to be real random-like, it need timevalue as a seed.

ft_rand
-------
   Signature
      ``int rand(void);``

   Description
      A Function returns a pseudo-random integer in the range 0 to ``RAND_MAX`` inclusive.
      Default seeded with a value of 1.

RAND_MAX
--------
   Constant for 2147483647, Equal to ``INT_MAX`` .

ft_srand
--------
   Signature
      ``void srand(unsigned int useed);``

   Description
      Defined in ``stdlib.h,`` A Function sets its arguments as the seed for a new sequence of pseudo-random integers to be returned by ``rand()`` .
  
