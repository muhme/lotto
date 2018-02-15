/*
 * get 6 unique numbers out of the range from 1 to 49
 *
 * hlu, Aug 1 1998 - Aug 8 1998
 */

# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>

# define NUMBERS 6
# define MAX 49

int compare();

int main(void)
{
    int n[NUMBERS];		/* the 6 numbers */
    int i;			/* run over n[] */
    int j;			/* run over filled n[] */

    srandom ((unsigned int)time(NULL) + getpid());

    for (i=0; i < NUMBERS; ++i) {
	n[i] = 1 + (int)(((double)MAX * random())/ (RAND_MAX + 1.0));
	for (j=0; j < i; ++j) {
	    if (n[i] == n[j]) {
		/* sorry, I have this number already */
		--i;
		break;
	    }
	}
    }

    qsort ((void *)n, NUMBERS, sizeof (n[0]), compare);

    for (i=0; i < NUMBERS; ++i) {
	printf ("%2d%c", n[i], i == (NUMBERS - 1) ? '\n' : ' ');
    }

} /* main */


/*
 * Compare two integers and return -1, 0 or 1 if the first
 * integer less  than,  equal  to, or greater than the second. 
 */
int compare (a, b)
    int *a, *b;
{

    if (*a < *b)
	return (-1);
    else if (*a > *b)
	return (1);
    else
	return (0);

} /* compare */
