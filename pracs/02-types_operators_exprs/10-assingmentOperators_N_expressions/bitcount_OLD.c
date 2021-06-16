int	bitcount(unsigned int x)
{
	int	b;

	b = 0;
	while (x) {
		if (x & 0b01)
			b++

		x >>= 1;
	}

	return (b);
}
