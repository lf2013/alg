#include <stdlib.h>
#include <stdio.h>
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

struct searchTree * 
treeMax(struct searchTree * t)
{
	if(t == NULL)
		return NULL; 
	else if(t -> r == NULL)
		return t;
	else return treeMax(t -> r);
}

struct searchTree * 
treeMin(struct searchTree *t)
{
	if(t == NULL)
		return NULL;
	else if(t -> l == NULL)
		return t;
	else return treeMin(t -> l);
}

struct searchTree * 
treeSearch(struct searchTree * t, int x)
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

struct searchTree *
treeSuccessor(struct searchTree *t)
{
	if(t -> r != NULL)
		return treeMin(t -> r);	
	else{
		struct searchTree *y = t -> p; 
		struct searchTree *x = t;
		while(y != NULL && y -> l != x){
			x = y;
			y = x -> p;
		}	
		return y;
	}
}

struct searchTree *
treePredecessor(struct searchTree *t)
{
	if(t -> l != NULL)
		return treeMax(t -> r);	
	else{
		struct searchTree *y = t -> p; 
		struct searchTree *x = t;
		while(y != NULL && y -> r != x){
			x = y;
			y = x -> p;
		}	
		return y;
	}
}

struct searchTree *
treeDelete(struct searchTree * t)
{
	if(t == NULL)
		return NULL;

	if(t -> l == NULL && t -> r == NULL)
		if(t -> p -> l == t)
			t -> p -> l = NULL;
		else 
			t -> p -> r = NULL;

	else if(t -> l == NULL && t -> r != NULL)
		if(t -> p -> l == t){
			t -> r -> p = t -> p;
			t -> p -> l = t -> r;
		}
		else{
			t -> r -> p = t -> p;
			t -> p -> r = t -> r;
		}
	else if(t -> l != NULL && t -> r == NULL)
		if(t -> p -> l == t){
			t -> l -> p = t -> p;
			t -> p -> l = t -> l;
		}
		else{
			t -> l -> p = t -> p;
			t -> p -> r = t -> l;
		}
	else{
		struct searchTree * y = treeSuccessor(t);
		t -> k = y -> k;
		treeDelete(y);
	}
}
