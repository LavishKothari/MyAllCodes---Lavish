import java.io.*;
class Main
{
	static double goldenRatio=(1+Math.sqrt(5))/2;
		
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println(fibonacci(Integer.parseInt(br.readLine())));
	}
	public static int fibonacci(int n)
	{
		return (int)((Math.pow(goldenRatio,n)/Math.pow(5,0.5))+0.5);
	}
}