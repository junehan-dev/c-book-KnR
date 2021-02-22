#define	MAXLEN	1024

int		readlines(char *lineptr[], int maxlines)
{
	int		len;
	int		nlines;
	char	*p;
	char	line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return (-1);
	}
	

}

