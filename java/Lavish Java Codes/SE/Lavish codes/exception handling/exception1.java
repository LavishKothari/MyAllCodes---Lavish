// automatic exception generation and mannual handling
class Main
{
	public static void main(String args[])
	{
		try
		{
	
			int arr[]=new int [10];
			for(int i=0;i<11;i++)
			{
				arr[i]=i+1;
				System.out.println(arr[i]+"  Hello Lavish Kothari");
			}
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("your Exception : "+e);	
			System.out.println("message        : "+e.getMessage());
			System.out.println("stack trace    : "+e.getStackTrace());
		}
	}	
}		