class TwoDArray
{
	public static void main(String args[])
	{
		int arr[][]={{1,2},{4,66,76},{89,9,8},{3,54,90,8},{7,2},{22,6,8}};
		
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
				System.out.print(arr[i][j]+"\t");
			System.out.println();
		}
	}
}