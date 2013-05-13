int quicksort(int A[], int l, int r)
{
	if(l < r){
		int q = quickdiv(A, l, r);
		quicksort(A, l, q - 1);
		quicksort(A, q + 1, r);
	}
}
int quickdiv(int A[], int l, int r)
{
	int i = l + 1, x = A[l], j = r;
	while(i <= j){
		while(A[i] < x)
			i++;	
		while(A[j] >= x)
			j--;
		if(j > i){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	A[l] = A[j];
	A[j] = x;
	return j;
}
