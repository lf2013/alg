#include "heap.h"
int insert(int A[], int x)
{
	A[0] += 1;
	int headSize = A[0];
	A[headSize] = x;
	while(headSize > 1 && A[headSize] > A[headSize / 2]){
		int temp = A[headSize];
		A[headSize] = A[headSize / 2];
		A[headSize / 2] = temp;
		headSize /= 2;
	}
}
int getMax(int A[])
{
	return A[1];
}
int pop(int A[])
{
	if(A[0] < 1)
		return -1;
		
	int heapSize = A[0];
	int max = A[1];
	A[0] -= 1;
	A[1] = A[heapSize];
	heapMax(A, 1);
	return max;
}
int improve(int A[], int i, int key)
{
	if(A[i] < key)
		A[i] = key;
	while(i > 1 && A[i] > A[i / 2]){
		int temp = A[i];
		A[i] = A[i / 2];
		A[i / 2] = temp;
		i /= 2;
	}
}

int
main()
{
	int A[10] = {0};
	insert(A, 1);
	insert(A, 5);
	insert(A, 4);
	insert(A, 7);
	insert(A, 9);
	insert(A, 9);
	improve(A, 3, 100);
	insert(A, 3);
	int i;
	
	while((i = pop(A)) != -1){
		printf("%d ", i);
	}
	
	return 0;	
}
