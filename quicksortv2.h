int quicksort(int A[], int l, int r)
{
	if(l < r){
		int q = quickdiv(A, l, r);

//		int i;
//		printf("A[q] = %d\n", A[q]);
//		for(i = l; i <= r; i++)
//			printf("%d ", A[i]);
//		printf("\n");
//
		quicksort(A, l, q - 1);
		quicksort(A, q + 1, r);
	}
}
int quickdiv(int A[], int l, int r)
{
	int i = l, x = A[r], j = r - 1;
	while(i <= j){
		while(A[i] >= x && i < r)
			i++;	
		while(A[j] < x && j >= l)
			j--;
		if(j > i){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	A[r] = A[i];
	A[i] = x;
	return i;
}
