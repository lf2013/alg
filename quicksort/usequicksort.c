#include <stdio.h>
#include <time.h>
#include "randomquicksort.h"
int
main()
{
	srand(time(NULL));
	int A[] = {10, 4, 1, 3, 2, 16, 9,10, 14,8,7};
	int i;
	quicksort(A, 0, 10);
	for(i = 0; i < 11; i++)
		printf("%d ", A[i]);
}
