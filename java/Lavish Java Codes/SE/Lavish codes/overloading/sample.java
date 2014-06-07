/*

The ellipsis (...) is specified between the <type> and the <formal parameter name>.
The <type> can be a primitive type, a reference type, or a type parameter.
Whitespace can be specified on both sides of the ellipsis. Such a parameter is usually
called a varargs parameter.
Apart from the varargs parameter, a variable arity method is identical to a fixed
arity method. The method publish() below is a variable arity method:
public static void publish(int n, String... data) 
{
 // (int, String[])
System.out.println("n: " + n + ", data size: " + data.length);
}

*/
class Main
{
	public static void main(String args[])
	{
		System.out.println(add(15,3));
		System.out.println(add(5,3,6));

		System.out.println(add());
		/*
		System.out.println(add(5,3));
		System.out.println(add(5,3));
		System.out.println(add(5,3));
		*/
	}

	public static int add(int a,int b)
	{
		System.out.println("for 2 arguments");
		return a+b;
	}

	public static int add(int a,int b,int c)
	{
		System.out.println("for 3 arguments");
		return a+b+c;
	}

	public static int add(int ... arr)
	{
		System.out.println("cases other than 2 or 3 arguments");
		int sum=0;
		for(int i=0;i<arr.length;i++)
			sum+=arr[i];
		return sum;
	}			
}