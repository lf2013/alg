#include <stdlib.h>
struct searchTree{
	struct searchTree *p, *l, *r;
	int k;
};

struct searchTree * 
initTree()
{
	return NULL;
}

void
treeWalk(struct searchTree * t)
{
	if(t != NULL){
		treeWalk(t -> l);
		printf("%d ", t -> k);
		treeWalk(t -> r);
	}
}

struct searchTree *
treeInsert(struct searchTree * t, int x)
{
	if(t == NULL){
		struct searchTree *root = (struct searchTree *)malloc(sizeof(struct searchTree));	
		root -> l = NULL;
		root -> r = NULL;
		root -> p = NULL;
		root -> k = x;
		t = root;
		return root;
	}else if(t -> k > x){
		if(t -> l == NULL){
			struct searchTree *leaf = (struct searchTree *)malloc(sizeof(struct searchTree));	
			t -> l = leaf;
			leaf -> p = t;
			leaf -> l = NULL;
			leaf -> r = NULL;
			leaf -> k = x;
			return leaf;
		}else{
			treeInsert(t -> l, x);
		}
	}else{
		if(t -> r == NULL){
			struct searchTree *leaf = (struct searchTree *)malloc(sizeof(struct searchTree));	
			t -> r = leaf;
			leaf -> p = t;
			leaf -> l = NULL;
			leaf -> r = NULL;
			leaf -> k = x;
			return leaf;	
		}else{
			treeInsert(t -> r, x);
		}
	}
}

int
treeMax(struct searchTree * t)
{
	if(t == NULL)
		return -1;
	else if(t -> r == NULL)
		return t -> k;
	else return treeMax(t -> r);
}

int
treeMin(struct searchTree *t)
{
	if(t == NULL)
		return -1;
	else if(t -> l == NULL)
		return t -> k;
	else return treeMin(t -> l);
}

struct searchTree * treeSearch(struct searchTree * t, int x)
{
	if(t == NULL)
		return NULL;
	else if(t -> k == x)
		return t;
	else if(t -> k > x)
		treeSearch(t -> l, x);
	else 
		treeSearch(t -> r, x);
}

struct searchTree * treeSuccessor(struct searchTree *t)
{
	if(t -> r != NULL)
		return treeMin(t -> r);	
	//else(
}
