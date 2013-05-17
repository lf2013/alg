struct rbTree{
	struct rbTree *p, *l, *r;
	int color;
	int k;
};

void
leftRotate(struct rbTree * x)
{
	struct rbTree * y = x -> r;
	struct rbTree * z = y -> l;
	x -> r = z;
	if(z != NULL)
		z -> p = x;
	
	y -> p = x -> p;
	if(x -> p != NULL)
		if(x -> p -> l == x)
			x -> p -> l = y;	
		else 
			x -> p -> r = y;
	
	y -> l = x;
	x -> p = y;
}

void
rightRotate(struct rbTree * x)
{
	struct rbTree * y = x -> l;
	struct rbTree * z = y -> r;
	x -> l = z;
	if(z != NULL)
		z -> p = x;
	
	y -> p = x -> p;
	if(x -> p != NULL)
		if(x -> p -> l == x)
			x -> p -> l = y;	
		else 
			x -> p -> r = y;
	
	y -> r = x;
	x -> p = y;
}
