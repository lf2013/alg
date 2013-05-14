#include "selectsort.h"
#include <stdio.h>
int
main()
{
	int A[] = {10, 4, 1, 3, 2, 16, 9,10, 14,8,7};
	selectSort(A, 11);

	int i;
	for(i = 0; i < 11; i++)
		printf("%d ", A[i]);
}
