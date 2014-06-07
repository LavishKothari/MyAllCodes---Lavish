// passing arrays to a method

class Main
{
	public static void main(String args[])
	{
		int arr[]=new int[10];
		for(int i=0;i<10;i++)
			arr[i]=i+1;
		printArray(arr);
	}
	public static void printArray(int arr[])
	{
		for(int i=0;i<arr.length;i++)	
		 System.out.println(arr[i]);
	}
}