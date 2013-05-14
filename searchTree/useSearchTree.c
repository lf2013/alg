#include "searchtree.h"
int
main()
{
	struct searchTree * t = initTree();

	t = treeInsert(t , 3);
	treeInsert(t , 8);
	treeInsert(t , 4);
	treeInsert(t , 9);
	treeInsert(t , 2);
	treeInsert(t , 0);
	treeWalk(t);
	printf("\nmax = %d min = %d \n", treeMax(t), treeMin(t));
	
	if(treeSearch(t, 3) != NULL)
		printf("found\n");
	
}
