import java.util.LinkedList;
import java.io.*;
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			int n=Integer.parseInt(br.readLine());
			LinkedList names=new LinkedList();
			for(int i=0;i<n;i++)
				names.add(br.readLine());
			String name=br.readLine();
			int i;
			for(i=0;i<n;i++)
			{
				if(names.get(i).toString().equals(name))
				{
					System.out.println("yes");
					break;
				}
			}
			if(i==n)
				System.out.println("no");
		}
	}
}
