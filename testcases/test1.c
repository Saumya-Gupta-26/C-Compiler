/* while loop demonstration by multiplication table */

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

int main()
{
	struct num
	{
		int x;
		int y;
	};
	
	struct num mult;
	
	mult.x = 10;	
	
	myfunc(mult.x);	

	return 0;
}

