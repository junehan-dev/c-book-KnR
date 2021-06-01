ft_randlib
==========
   Defined in ``stdlib.h,`` functions return promised values differently on call by call.
   Start from seed value(1) computation.
   So to be real random-like, it need timevalue as a seed.

   ``RAND_MAX``
      Constant for 2147483647, Equal to ``INT_MAX`` .

make_random
-----------
   Signature
      ``./make_program [max_value] [seed];``

   Description
      prints out random number with max_value depend on the seed.

ft_ranlib.a
-----------
ft_rand
^^^^^^^
   Signature
      ``int	rand(void);``

   Description
      A Function returns a pseudo-random integer in the range 0 to ``RAND_MAX`` inclusive.
      Default seeded with a value of 1.

ft_srand
^^^^^^^^
   Signature
      ``void	srand(unsigned int useed);``

   Description
      Defined in ``stdlib.h,`` A Function sets its arguments as the seed for a new sequence of pseudo-random integers to be returned by ``rand()`` .

ft_atoi
^^^^^^^
   Signature
      ``int	ft_atoi(const char *src);``

   Description
      Same as atoi

