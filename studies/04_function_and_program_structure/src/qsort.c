void	swap(int v[], int i, int j)
{
	int	temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;

	return;
}

void	qsort(int v[], int left, int right)
{
	int	i;
	int	last;
	int	mid;

	mid = (left < right) ? ((left + right) / 2) : 0;

	if (mid) {
		swap(v, left, mid);
		last = left;
		i = last;
		while (i++ < right) {
			if (v[i] < v[left])
				swap(v, ++last, i);
			i++;
		}
		swap(v, left, last);
		qsort(v, left, last - 1);
		qsort(v, last + 1, right);
	}
	return;
}
