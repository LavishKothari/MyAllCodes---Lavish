// integers fields are initialized to 0
// float fields are initialized to    0.0
// double fields are initialized to   0.0
// boolean fields are initialized to  false
// object fields are initialized to   null
// char fields are initialized to   null-character '\0'


class Sample
{
	int i;
	float f;
	double d;
	String str;
	boolean b;
	char c;
}

class Main
{
	public static void main(String args[])
	{
		Sample s=new Sample();
		System.out.println("i   = "+s.i);
		System.out.println("f   = "+s.f);
		System.out.println("d   = "+s.d);
		System.out.println("str = "+s.str);
		System.out.println("b   = "+s.b);
		System.out.println("c   = "+s.c);
	}
}