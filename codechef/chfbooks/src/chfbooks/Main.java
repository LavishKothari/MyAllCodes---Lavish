package chfbooks;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	public static int heapLength;
	public static int getParentIndex(int n)

    {

          return (n/2);

    }

    public static int getLeftChildIndex(int n)

    {

          return n*2;

    }

    public static int getRightChildIndex(int n)

    {

          return n*2+1;

    }

    

    public static void maxHeapify(int []arr,int i)

    {

          int l=getLeftChildIndex(i+1)-1; // our array is zero indexed array...

          int r=getRightChildIndex(i+1)-1;

          int largest,tmp;

          if(l<=heapLength-1 && arr[l]>arr[i])

               largest=l;

          else

               largest=i;

               

          if(r<=heapLength-1 && arr[r]>arr[largest])

               largest=r;

          

          // exchange arr[i] and arr[largest]

          if(largest!=i)

          {

               tmp=arr[i];

               arr[i]=arr[largest];

               arr[largest]=tmp;

               

               maxHeapify(arr,largest);

          }

    }

    

    public static void buildMaxHeap(int []arr)

    {

          for(int i=getParentIndex(arr.length)-1;i>=0;i--)

               maxHeapify(arr,i);

    }

    

    public static void heapSort(int[]arr)

    {

          buildMaxHeap(arr);

          int tmp;

          for(int i=arr.length-1;i>=1;i--)

          {

               tmp=arr[0];

               arr[0]=arr[i];

               arr[i]=tmp;

               

               heapLength--;

               maxHeapify(arr,0);

          }

    }    

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
				int p[]=new int[n];
				stz=new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++)
				{
					p[j]=Integer.parseInt(stz.nextToken());
					totalSum+=p[j];
				}heapLength=n;
				heapSort(p);
				long answer=0;
				for(int j=0;j<m;j++)
					answer+=p[j];
				answer=totalSum-2*answer;
				System.out.println(answer);
			}
		}catch(Exception e)
		{
			System.out.println("Exception caught");
			e.printStackTrace();
		}
	}

}
