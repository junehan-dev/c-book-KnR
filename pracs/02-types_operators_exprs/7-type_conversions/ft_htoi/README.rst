ft_htoi
=======

ft_tohex
--------
``int	to_hex(int c);``
   A function convert character *c* to interger in hex.
   Returns 0 ~ 15, case when ``[a-fA-F0-9]`` in *c.*
   On Non Hex convertable, returns ``-1`` to discriminate it.

ft_htoi
-------
``int	ft_htoi(const char *src);``
   A function convert string(hex string) to integer .
   Covers - or + mark prepended.
   Uses ``ft_tohex`` internally.
   Returns integer converted from string in hex.
   If nothing converted or *'0'* only in ``*src``
   then, returns 0.
