#include "searchtree.h"
int
main()
{
	struct searchTree * t = initTree();

   
	struct searchTree *root = t = treeInsert(t , 3);
	treeInsert(t , 8);
	struct searchTree * x = treeInsert(t , 4);
	struct searchTree * y = treeInsert(t , 14);
	treeInsert(t , 9);
	treeInsert(t , 2);
	treeInsert(t , 0);

	treeWalk(t);
	treeDelete(x);
	treeWalk(root);
	treeDelete(y);
	treeWalk(root);

	printf("\nmax = %d min = %d \n", treeMax(t) -> k, treeMin(t) -> k);
	
	if(treeSearch(t, 3) != NULL)
		printf("found\n");
	
	printf("%d\n",t  -> k); 
	t = treeSuccessor(t);
	printf("%d\n",t  -> k); 
	t = treePredecessor(t);
	printf("%d\n",t  -> k); 
}
