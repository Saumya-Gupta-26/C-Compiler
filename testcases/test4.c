/* nesting */
void main()
{
	int a, b, c;
	a=8;
	b=9;
	c=3;

	while(a<b+c)
	{
		a=a+1;
		b=a+c;
		while(b<10)
		{
			b=b+2;
		}
	}	

}

