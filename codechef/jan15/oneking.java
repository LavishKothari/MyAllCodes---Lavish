
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Kingdom implements Comparable
{
	int start,end;
	@Override
	public int compareTo(Object c)
	{
		return this.end-((Kingdom)c).end; // sorting in ascending order.
	}
}
class Main
{
	public static void main(String[]args) throws IOException
	{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			while(t-->0)
			{
				int n=Integer.parseInt(br.readLine());
				Kingdom k[]=new Kingdom[n];
				for(int i=0;i<n;i++)
					k[i]=new Kingdom();
				for(int i=0;i<n;i++)
				{
					StringTokenizer stz=new StringTokenizer(br.readLine());
					k[i].start=Integer.parseInt(stz.nextToken());
					k[i].end=Integer.parseInt(stz.nextToken());
				}
				Arrays.sort(k);
				int answer=0;
				outer:for(int i=0;;)
				{
					answer++;
					int current=k[i].end;
					i++;
					if(i>=n)
						break outer;
					while(k[i].start<=current)
					{
						i++;
						if(i>=n)
							break outer;
					}
				}
				System.out.println(answer);
			}


	}
}
