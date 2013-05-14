int
bubbleSort(int A[], int n)
{
	int i, j;
	int swap = 0;
	for(i = 0; i < n; i++){
		swap = 0;
		for(j = 0; j < n - i - 1; j++){
			if(A[j] > A[j + 1]){
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				swap = 1;
			}		
		}
		if(!swap) break;
	}
}
