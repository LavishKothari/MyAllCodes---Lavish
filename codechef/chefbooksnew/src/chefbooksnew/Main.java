package chefbooksnew;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) 
	{
		
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(br.readLine());
			for(int i=0;i<t;i++)
			{
				long totalSum=0;
				StringTokenizer stz=new StringTokenizer(br.readLine());
				int n=Integer.parseInt(stz.nextToken());
				int m=Integer.parseInt(stz.nextToken());
				stz=new StringTokenizer(br.readLine());
				
				int arr[]=new int[1000001];
				for(int j=0;j<n;j++)
				{
					int temp=Integer.parseInt(stz.nextToken());
					arr[temp]++;
					totalSum+=temp;
				}
				long answer=0;
				int counter=1;
				int items=0;
				outer:while(true)
				{
					while(arr[counter]!=0)
					{
						answer+=counter;
						items++;
						arr[counter]--;
						if(items==m)
							break outer;
					}
					counter++;
				}
				
				answer=totalSum-2*answer;
				System.out.println(Math.abs(answer));
			}
		}catch(Exception e)
		{
			System.out.println("Exception caught");
			e.printStackTrace();
		}
	}

}
