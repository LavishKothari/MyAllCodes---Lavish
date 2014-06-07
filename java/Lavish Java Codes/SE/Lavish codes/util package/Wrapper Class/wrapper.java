/*
Simple java program illustrating
Float class 
*/
class Main
{
	public static void main(String []args)
	{
		System.out.println("TYPE              : "+Float.TYPE);
		System.out.println("POSITIVE_INFINITY : "+Float.POSITIVE_INFINITY);
		System.out.println("NEGATIVE_INFINITY : "+Float.NEGATIVE_INFINITY);
		System.out.println("NaN               : "+Float.NaN);
		System.out.println("MIN_VALUE         : "+Float.MIN_VALUE);
		System.out.println("MAX_VALUE         : "+Float.MAX_VALUE);

		Float f=new Float(1.5/0);
		if(f==Float.POSITIVE_INFINITY)
			System.out.println("f is infinite"); // will be executed
		else
			System.out.println("f is finite"); // will not be executed
		
		/* you can also do this */
		
		float a=5.2f,b;
		b=a/0;
		/* you might be thinking here that an ArithmeticException must be thrown here..
			but this is not the case..because 
			arithmetic exceptions are thrown only when integers are divided by zero not floats or doubles
		*/
		System.out.println(b);
		
		System.out.println("No Exception Generated");
		
		Float x=new Float(f);
		x=f/f;
		System.out.println("infinite/infinite = "+x);

		Float z=new Float(0.0/0);
		System.out.println("0.0 / 0 = "+x);
	}
}