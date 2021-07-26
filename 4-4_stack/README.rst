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
      set ``data``  to ``*stack`` while ``*(stack + 1)`` is NULL value.

      Return cases::

         1. return -1	(Failure)
            ``*data`` it self is null, and ``*stack`` is not null

         2. return 1	(Failure)
            ``*data`` it self is not null, but ``stack`` is full or ``*stack`` already has data.

         3. return 0	(Success)
            ``*data`` it self not null, and ``*stack`` is not null

ft_stack_pop
^^^^^^^^^^^^
   Write function to pop data from stack.

   Signature
      ``void	*ft_stack_pop(void **stack)``

   Description
      Pop off last pushed data. (with set that space as null)
      returns pointer of poped element.
      if nothing in stack, returns NULL.
      
ft_stack_stat
^^^^^^^^^^^^^
   Signature
      ``void	ft_stack_stat(void **stack, size_t bytelen, char delimiter)``

   Description
	  Print out each stack element with ``delemiter`` character.
      speaking in honestly, it uses ``printf`` function for now,
      but need to be changed to use ``write`` some day.

ft_stack_len
^^^^^^^^^^^^
   Signature
      ``int		ft_stack_len(void **stack)``

   Description
	  returns current length of stack.
      Basically all pointer has null.
    
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
