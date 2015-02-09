import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			int n=Integer.parseInt(br.readLine());
			char c[]=new char[n];
			char p[]=new char[n];
			
			for(int j=0;j<n;j++)
			{
				StringTokenizer stz=new StringTokenizer(br.readLine());
				c[j]=(((String)(stz.nextElement())).toCharArray())[0];
				p[j]=(((String)(stz.nextElement())).toCharArray())[0];
			}
			char S[]=(br.readLine()).toCharArray();
			for(int j=0;j<S.length;j++)
			{
				int searchValue=search(S[j],c);
				if(searchValue!=-1)
					S[j]=p[searchValue];
			}
			String answer=new String(S);
			answer=toShortestNotation(answer);
			if(answer.equals(""))
				System.out.println(0);
			else
				System.out.println(answer);
		}
	}
	
	public static int search(char ch,char arr[])
	{
		for(int i=0;i<arr.length;i++)
			if(ch==arr[i])
				return i;
		return -1;
	}
	
	public static String toShortestNotation(String str)
	{
		char arr[]=str.toCharArray();
		int start,end=arr.length-1,flag=0;
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]=='.')
				flag=1;
		}
		
		for(start=0;start<arr.length;start++)
		{
			if(arr[start]!='0')
				break;
		}
		if(flag==1)
		{
			for(end=arr.length-1;end>=0;end--)
			{
				if(arr[end]!='0')
					break;
			}
			if(arr[end]=='.')
				end--;
		}
		//System.out.println(end);
		
		return new String(arr,start,end-start+1);
	}
}