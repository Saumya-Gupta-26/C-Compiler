/* if-else demonstrated via finding mimum of 3 numbers */
void main()
{
	int a, b, c;
	a=8;
	b=9;
	c=3;
	
	int m;

	if(a<b)
	{
		m=b;
	
		if(m<c)
		{
			m=c;
		}
	}	
	
	else
	{
		m=a;
	
		if(m<c)
		{
			m=c;
		}
	}

	printf("\nmimum of %d, %d, and, %d is %d\n", a, b, c, m);
}

