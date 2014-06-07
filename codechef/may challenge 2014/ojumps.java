import java.io.*;

class Main
{
	public static void main(String[]args)throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		long n=Long.parseLong(br.readLine());
		if(n==0 || n%3==0 || ((n+2)%3==0 && ((n+2)/3)%2==1))
			System.out.print("yes");
		else 
			System.out.print("no");
	}
}