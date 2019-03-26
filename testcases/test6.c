/* multiple functions */

void myfunc(int a)
{
	int i, f;

	while(i<=10)
	{
		f = i*a;
		printf("%d * %d = %d\n", a, i, f);
		i = i+1;
	}
	
	return;
}

int trial(int a)
{	
	int b, c;
	b=7;
	c=9;

	a=b*c;
	return a;

}



int main()
{
	struct num
	{
		int x;
		int y;
	};
	
	struct num mult;
	
	mult.x = 10;
	mult.y = 20;	
	
	myfunc(mult.x);	
	trial(mult.y);
	return 0;
}

