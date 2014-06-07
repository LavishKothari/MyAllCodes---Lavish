// important concept of pre-increment and post-increment
// this concept is different from that of these operators in C

class Main
{	
	public static void main(String []args)
	{
		int a=10;
		int c=a++ + a++ + ++a;	// this is a very good example to illlustrate the difference b/w java and c
		System.out.println("c = "+c+"\na = "+a);
	}
}