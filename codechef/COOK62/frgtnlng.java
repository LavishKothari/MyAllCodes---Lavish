import java.io.*;
import java.util.StringTokenizer; 
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine()," ");
			int n=Integer.parseInt(stz.nextToken());
			int k=Integer.parseInt(stz.nextToken());
			stz=new StringTokenizer(br.readLine()," ");
			String[] strArray=new String[n];
			int counter=0;
			while(stz.hasMoreTokens())
				strArray[counter++]=new String(stz.nextToken()+"");
			String[] sub=new String[3000];
			counter=0;
			for(int j=0;j<k;j++)
			{
				stz=new StringTokenizer(br.readLine()," ");
				stz.nextToken();
				while(stz.hasMoreTokens())
					sub[counter++]=new String(stz.nextToken()+"");
			}
			// counter --> length of sub
			// n --> length of strArray
			for(int x=0;x<n;x++)
			{
				int flag=0;
				for(int y=0;y<counter;y++)
				{
					if(strArray[x].equals(sub[y]))
					{
						flag=1;
						System.out.print("YES ");
						break;
					}
				}
				if(flag==0)
					System.out.print("NO ");
			}
			System.out.println();
		}
	}
}