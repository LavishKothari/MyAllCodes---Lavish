/* program to find the average of 
all the numbers at command line.*/
class demoCla
{
	public static void main(String[]args)
	{
		double sum=0.0;
		for(int i=0;i<args.length;i++)
			sum+=Double.parseDouble(args[i]);
		double avg=sum/args.length;
		System.out.println("Average = "+avg);
	}
}