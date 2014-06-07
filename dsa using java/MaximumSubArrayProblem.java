import java.io.*;
class Main
{
	static int lowIndex,highIndex,maxSum;
	static int leftLowIndex,leftHighIndex,leftMaxSum;
	static int rightLowIndex,rightHighIndex,rightMaxSum;
	static int crossLowIndex,crossHighIndex,crossMaxSum;
		
	public static void main(String args[])
	{
		
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter the number of elements of the array : ");
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int[n];
			System.out.println("Enter the elements of the array : ");
			for(int i=0;i<n;i++)
			{
				System.out.print("Enter the element # "+(i+1)+" : ");
				arr[i]=Integer.parseInt(br.readLine());
			}
			
			findMaximumSubArray(arr,0,arr.length-1);
			
			System.out.println("lowIndex  = "+(lowIndex+1));
			System.out.println("highIndex = "+(highIndex+1));
			System.out.println("maxSum    = "+(maxSum));
		}
		catch(IOException e){}
	}
	public static void findMaximumSubArray(int arr[],int low,int high)
	{
		if(low==high)
		{
			lowIndex=low;
			highIndex=high;
			maxSum=arr[low];
			return ;
		}
		int mid=(low+high)/2;
		
		findMaximumSubArray(arr,low,mid);
		leftLowIndex=lowIndex;
		leftHighIndex=highIndex;
		leftMaxSum=maxSum;
		
		findMaximumSubArray(arr,mid+1,high);
		rightLowIndex=lowIndex;
		rightHighIndex=highIndex;
		rightMaxSum=maxSum;
		
		findMaxCrossingSubArray(arr,low,mid,high);
		
		if(leftMaxSum>=rightMaxSum && leftMaxSum>=crossMaxSum)
		{
			lowIndex=leftLowIndex;
			highIndex=leftHighIndex;
			maxSum=leftMaxSum;
			return;
		}
		if(rightMaxSum>=leftMaxSum && rightMaxSum>=crossMaxSum)
		{
			lowIndex=rightLowIndex;
			highIndex=rightHighIndex;
			maxSum=rightMaxSum;
			return;
		}
		if(crossMaxSum>=rightMaxSum && crossMaxSum>=leftMaxSum)
		{
			lowIndex=crossLowIndex;
			highIndex=crossHighIndex;
			maxSum=crossMaxSum;
			return;
		}
	}
	public static void findMaxCrossingSubArray(int[]arr,int low,int mid,int high)
	{
		int leftIndex=mid,rightIndex=mid;
		int sum=0;
		int leftSum=Integer.MIN_VALUE;
		for(int i=mid;i>=low;i--)
		{
			sum+=arr[i];
			if(sum>leftSum)
			{	
				leftSum=sum;
				leftIndex=i;
			}
		}
		
		sum=0;
		int rightSum=Integer.MIN_VALUE;
		for(int i=mid+1;i<=high;i++)
		{
			sum+=arr[i];
			if(sum>rightSum)
			{	
				rightSum=sum;
				rightIndex=i;
			}
		}
		
		crossLowIndex=leftIndex;
		crossHighIndex=rightIndex;
		crossMaxSum=leftSum+rightSum;
	}
}