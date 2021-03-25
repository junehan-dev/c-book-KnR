#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct	key {
	char	*word;
	int		count;
};
int		getword(char *, int);
int		binsearch(char *, struct key *, int);

int		main(int argc, const char *argv[])
{
	int		n;
	char	word[MAXWORD];
	struct	key keytab[] = {
		"auto", 0,
		"break", 0,
		"case", 0,
		"char", 0,
		"const", 0,
		"default", 0,
		"else", 0,
		"else if", 0,
		"size_t", 0,
		"ssize_t", 0,
		"int", 0, 
		"void", 0,
		"unsigned", 0,
		"while", 0,
		"if", 0,
		"volatile", 0,
	};

	while (getword(word, MAXWORD) != -1) {
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)))
				keytab[n].count++;
	}
}

int		quicksort(struct key *keytab)
{

}

int		binsearch(char *word, struct key *keytab, int n)
{
	int	cond;
	int	low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		return (mid);
	}

	return (-1);
}

