#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quicksort(int A[], int l, int r)
{
	srand(time(NULL));
	if(l < r){
		int q = quickdiv(A, l, r);
		quicksort(A, l, q - 1);
		quicksort(A, q + 1, r);
	}
}
int quickdiv(int A[], int l, int r)
{
	int rrandom = rand() % (r - l + 1) + l;	 //random part
	int x = A[rrandom];
	A[rrandom] = A[r];
	A[r] = x;	
	
	int i = l - 1, j = l;
	for( ; j < r; j++)
		if(A[j] < x){
			i += 1;
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	A[r] = A[i + 1];
	A[i + 1]  = x; 
	return 1 + i;	
}
