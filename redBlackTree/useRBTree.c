#include "rbTree.h"
int
main()
{
	struct rbTree* t = treeInit();
   
	struct rbTree *root = t = rbTreeInsert(t , 3);
	rbTreeInsert(t , 8);
	struct rbTree * x = rbTreeInsert(t , 4);
	struct rbTree * y = rbTreeInsert(t , 14);
	rbTreeInsert(t , 9);
	rbTreeInsert(t , 2);
	rbTreeInsert(t , 0);
	treeWalk(t);

//	treeWalk(t);
//	treeDelete(x);
//	treeWalk(root);
//	treeDelete(y);
//	treeWalk(root);

//	printf("\nmax = %d min = %d \n", treeMax(t) -> k, treeMin(t) -> k);
	
//	if(treeSearch(t, 3) != NULL)
//		printf("found\n");
	
//	printf("%d\n",t  -> k); 
//	t = treeSuccessor(t);
//	printf("%d\n",t  -> k); 
//	t = treePredecessor(t);
//	printf("%d\n",t  -> k); 
}
