ft_itoa_recursive
-----------------
   Adapt the idea of ``printd`` to write a recursive version of itoa;
   that is, convert an interger into a string by calling a recursive routine.

   Signature
      ``size_t ft_itoa(int n, char *dest);``

``printd``
----------
.. code-block:: c

   void	printd(int n)
   {
       if (n < 0) {
           putchar('-');
           n = -n;
       };
       if (n / 10)
           printd(n / 10);

       putchar(n % 10 + '0');
   }


