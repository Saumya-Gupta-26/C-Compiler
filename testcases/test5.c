/* errors in accessing struct */

int main()
{
	struct stud1
	{
		int roll;
		float n;
	}s1, s2;

	struct stud2
	{
		float x;
	};
	
	struct stud2 s5, s6;

	s1.roll = 6;
//	s1.xyz = 7;

//	s7.x = 9;

//	struct stud3 s10;
}
