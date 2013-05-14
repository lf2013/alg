int
selectSort(int A[], int n)
{
	int i, j;
	for(i = 0; i < n; i++){
		int k = i;
		for(j = i + 1; j < n; j++){
			if(A[j] < A[k]){
				k = j;
			}
		}
		if(A[k] != A[i]){
			int temp = A[k];
			A[k] = A[i];
			A[i] = temp;
		}
	}
}
