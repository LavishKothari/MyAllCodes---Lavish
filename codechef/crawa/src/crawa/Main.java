package crawa;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int ystart,yend;
	
	public static void findy(int x)
	{
		if(x>0)
		{
			int n=(x+1)/2;
			ystart=x*(-1)+1;
			yend=2*n;
		}
		else
		{
			ystart=x;
			yend=-x;
		}
	}
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			int x=Integer.parseInt(stz.nextToken());
			int y=Integer.parseInt(stz.nextToken());
			
			if(x==0 && y==0)
				System.out.println("YES");
			else if(x==0 || x==-1)
			{
				if(y%2==0 && y!=0)
					System.out.println("YES");
				else
					System.out.println("NO");
			}
			else
			{
				if((x>0))
				{
					if((x)%2!=0)
					{
						findy(x);
						if((y>=ystart && y<=yend) || (y<ystart && y%2==0) || (y>yend && y%2==0))
							System.out.println("YES");
						else
							System.out.println("NO");
					}
					else
					{
						findy(x+1);
						if((y%2==0 && y>=yend) || (y%2==0 && y<=ystart))
							System.out.println("YES");
						else
							System.out.println("NO");
					}
				}
				else
				{
					if(x%2==0)
					{
						findy(x);
						if((y>=ystart && y<=yend) || (y<ystart && y%2==0) || (y>yend && y%2==0))
							System.out.println("YES");
						else
							System.out.println("NO");
					}
					else
					{
						findy(x-1);
						if((y%2==0 && y>=yend) || (y%2==0 && y<=ystart))
							System.out.println("YES");
						else
							System.out.println("NO");
					}
				}
			}
		}
	}
}
