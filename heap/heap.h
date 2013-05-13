#include <stdio.h>
int heapMax(int A[], int i)
{
	int headSize = A[0], l = 2*i, r = 2*i+1;
	int max;

	if(l <= headSize && A[i] < A[l]){
		max = l;
	}else
		max = i;
	if(r <= headSize && A[max] < A[r])
		max = r;
	if(max != i){
		int temp = A[max];
		A[max] = A[i];
		A[i] = temp;
		heapMax(A, max);
	}
}
int creatheap(int A[])
{
	int headSize = A[0], i;
	for(i = headSize / 2; i > 0;i--)
		heapMax(A, i);
}
int heapsort(int A[])
{
	int i, heapSize = A[0];
	for(i = heapSize; i > 1; i--){
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		A[0] -= 1;
		heapMax(A, 1);
	}
}
