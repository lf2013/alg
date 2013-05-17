#define RED 0
#define BLACK 1
#include <stdlib.h>
#include <stdio.h>
struct rbTree{
	struct rbTree *p, *l, *r;
	int color;
	int k;
};

/*
struct rbTree * 
getNil()
{
	struct rbTree * nil = (struct rbTree *)malloc(sizeof(struct rbTree));
	nil -> r = NULL;
	nil -> l = NULL;
	nil -> p = NULL;
	nil -> k = 0;
	nil -> color = BLACK;
	return nil;
}

struct rbTree *  getNil() = getNil();
*/

/*
	struct rbTree * getNil() = (struct rbTree *)malloc(sizeof(struct rbTree));
	getNil() -> r = NULL;
	getNil() -> l = NULL;
	getNil() -> p = NULL;
	getNil() -> k = 0;
	getNil() -> color = BLACK;
*/
struct rbTree * 
getNil()
{
	struct rbTree * nil = (struct rbTree *)malloc(sizeof(struct rbTree));
	nil -> r = NULL;
	nil -> l = NULL;
	nil -> p = NULL;
	nil -> k = 0;
	nil -> color = BLACK;
	return nil;
}

struct rbTree *  Nil; //指针初始化为全局变量时不可以使用malloc赋值，因为malloc发生在运行时

struct rbTree *
treeInit()
{
	return Nil = getNil();
}

void
leftRotate(struct rbTree * x)
{
	struct rbTree * y = x -> r;
	struct rbTree * z = y -> l;
	x -> r = z;
	if(z != Nil)
		z -> p = x;
	
	y -> p = x -> p;
	if(x -> p != Nil)
		if(x -> p -> l == x)
			x -> p -> l = y;	
		else 
			x -> p -> r = y;
	
	y -> l = x;
	x -> p = y;
}

void
treeWalk(struct rbTree * r)
{
	if(r != Nil){
		treeWalk(r -> l);
		printf("%d ", r -> k);
		treeWalk(r -> r);
	}
}

void
rightRotate(struct rbTree * x)
{
	struct rbTree * y = x -> l;
	struct rbTree * z = y -> r;
	x -> l = z;
	if(z != Nil)
		z -> p = x;
	
	y -> p = x -> p;
	if(x -> p != Nil)
		if(x -> p -> l == x)
			x -> p -> l = y;	
		else 
			x -> p -> r = y;
	
	y -> r = x;
	x -> p = y;
}

struct rbTree *
rbTreeInsert(struct rbTree * t, int x)
{
	if(t == Nil){
		struct rbTree * root = (struct rbTree *)malloc(sizeof(struct rbTree));
		root -> p = Nil;
		root -> l = Nil;
		root -> r = Nil;
		root -> k = x;
		root -> color = BLACK;
	}else if(t -> k > x)
		if(t -> r == Nil){
			struct rbTree * leaf = (struct rbTree *)malloc(sizeof(struct rbTree));
			t -> r = leaf;
			leaf -> p = t;
			leaf -> k = x;
			leaf -> l = Nil;
			leaf -> r = Nil;
			leaf -> color = RED;
		}else
			rbTreeInsert(t -> r, x);
	else{
		if(t -> l == Nil){
			struct rbTree * leaf = (struct rbTree *)malloc(sizeof(struct rbTree));
			t -> l = leaf;
			leaf -> p = t;
			leaf -> k = x;
			leaf -> l = Nil;
			leaf -> r = Nil;
			leaf -> color = RED;
		}else
			rbTreeInsert(t -> l, x);
	}
}
void
rbTreeFixup(struct rbTree * t)
{

}
