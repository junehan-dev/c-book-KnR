External Variable
=================

ft_stack.a
----------
ft_stack_create
^^^^^^^^^^^^^^^
   Write function to create stack.

   Signature
      ``void	**ft_stack_create(int len)``

   Description
      returns NULL or valid pointer based on ``malloc`` results.


ft_stack_push
^^^^^^^^^^^^^
   Write function to push data to stack.

   Signature
      ``int		ft_stack_push(void **stack, void *data)``

   Description
      Return cases::

         1. return -1	(Failure)
            ``*data`` it self is null, and ``*stack`` is not null

         2. return 1	(Failure)
            ``*data`` it self is not null, but ``*stack`` is null, means lenth limit

         3. return 0	(Success)
            ``*data`` it self not null, and ``*stack`` is not null

ft_stack_pop
^^^^^^^^^^^^
   Write

   Signature
      ``void	*ft_stack_pop(void)``

   Description
	  Converts

ft_stack_stat
^^^^^^^^^^^^^
   Write

   Signature
      ``void	ft_stack_stat(int len)``

   Description
	  Converts

ft_stack_len
^^^^^^^^^^^^
   Write

   Signature
      ``int		ft_stack_len(void)``

   Description
	  Converts

ft_stack_copy
^^^^^^^^^^^^^
   Write

   Signature
      ``void	**ft_stack_copy(int len)``

   Description
	  Converts

ft_stack_swap
^^^^^^^^^^^^^
   Write

   Signature
      ``int		ft_stack_swap(int s1, int s2)``

   Description
	  Converts
