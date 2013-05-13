int
insertSort(int A[], int len)
{
	int i = 1;
	for( ; i < len; i++){
/*		To see process	
		int i1;
		for(i1 = 0; i1 < 11; i1++)
			printf("%d ", A[i1]);
		printf("\n");
*/

		int x = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > x){
			A[j+1] = A[j];
			j -= 1;
		}
		A[j+1] = x;
	}
}
