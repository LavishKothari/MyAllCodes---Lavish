class ArraySum
{	
	public static void main(String args[])
	{
		int sum=0;
		int arr[]={2,52,6,23,42,51,9,78};
		for(int i=0;i<arr.length;i++)
			sum+=arr[i];
		System.out.println("sum = "+sum);
	}
}