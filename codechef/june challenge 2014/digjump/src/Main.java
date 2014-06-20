import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main 
{
	static int []intarr;
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		char[]arr=(br.readLine()).toCharArray();
		intarr=new int[arr.length];
		for(int i=0;i<arr.length;i++)
			intarr[i]=(int)arr[i]-48;
		
		LinkedList mainList=new LinkedList();
		
	}
}
