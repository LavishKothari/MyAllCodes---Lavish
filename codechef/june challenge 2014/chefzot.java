import java.io.*;
import java.util.*;	
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		StringTokenizer stz=new StringTokenizer(br.readLine());
		int arr[]=new int[n];
		int counter=0,answer=0;
		
		for(int i=0;i<n;i++)
		{
			arr[i]=Integer.parseInt((String)stz.nextElement());
			counter++;
			if(arr[i]==0)
				counter=0;
			if(counter>answer)
				answer=counter;
		}
		System.out.println(answer);
	}
}
