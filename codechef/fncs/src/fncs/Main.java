package fncs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main 
{

	static long []makeT(long arr[],int n) // n is the length of the array.
	{
		/* This function make the BIT */
		int i,j;
		long answer[]=new long[n+1];
		for(i=0;i<=n;i++)
			answer[i]=0;

		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;) // dont increment j in the for loop due to carelessness
			{
				answer[j]=answer[j]+arr[i];
				j=j+(j&(-j));
			}
		}
		return answer;
	}

	static long GET(long T[],int i)
	{
		/* GET (index) sums up A[1]  A[index]. */
		long s=0;
		while(i>0)
		{
			s+=T[i];
			i=i-(i&(-i));
		}
		return s;
	}

	static void SET(long T[],int i,long v,int n)
	{
		int j;
		/* n is the size of array T */
		/*The value at T[i] is increased by v*/
		/* SET (index,value) adds value units to A[index] */
		for(j=i;j<=n;)// dont increment j in the for loop due to carelessness
		{
			T[j]+=v;
			j=j+(j&(-j));
		}
	}


	public static void main(String[] args) throws IOException
	{
		LinkedList list[];
		int i,temp;
		int n,funarg1[],funarg2[],q,a,b,c;
		long fun[],answer,change,arrT[],funT[],arr[];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		list=new LinkedList[n+1];
		for(i=0;i<=n;i++)
			list[i]=new LinkedList();
		arr=new long[n+1];
		fun=new long[n+1];
		funarg1=new int[n+1];
		funarg2=new int[n+1];

		/* Taking the input of the original array */
		arr[0]=0; // for making the indexing start with 1
		StringTokenizer stz=new StringTokenizer(br.readLine());
		i=1;
		while(stz.hasMoreElements())
			arr[i++]=Integer.parseInt(stz.nextToken());


		arrT=makeT(arr,n);

		funarg1[0]=funarg2[1]=0;
		for(i=1;i<=n;i++)
		{
			stz=new StringTokenizer(br.readLine());
			funarg1[i]=Integer.parseInt(stz.nextToken());
			funarg2[i]=Integer.parseInt(stz.nextToken());

			if(funarg1[i] > funarg2[i])
			{
				temp=funarg1[i];
				funarg1[i]=funarg2[i];
				funarg2[i]=temp;
			}
			fun[i]=GET(arrT,funarg2[i])-GET(arrT,funarg1[i])+arr[funarg1[i]];
			for(int j=funarg1[i];j<=funarg2[i];j++)
				list[j].add(""+i);
		}

		funT=makeT(fun,n);


		q=Integer.parseInt(br.readLine());
		for(int z=0;z<q;z++)
		{
			stz=new StringTokenizer(br.readLine());
			a=Integer.parseInt(stz.nextToken());
			b=Integer.parseInt(stz.nextToken());
			c=Integer.parseInt(stz.nextToken());

			if(a==1)
			{
				change=c-arr[b];
				arr[b]=c;

				// updating the fun array
				for(i=0;i<list[b].size();i++)
				{
					int index=Integer.parseInt(list[b].get(i)+"");
					fun[index]+=change;
					SET(funT,index,change,n);
				}
				/*
				   for(i=1;i<=n;i++)
				   {
				   if(b>=funarg1[i] && b<=funarg2[i])
				   {
				   fun[i]+=change;
				   SET(funT,i,change,n);
				   }
				   }
				 */
			}
			else if(a==2)
			{
				if(b>c)
				{
					temp=b;
					b=c;
					c=temp;
				}
				answer=GET(funT,c)-GET(funT,b)+fun[b];
				System.out.println(answer);
			}
		}
	}
}
