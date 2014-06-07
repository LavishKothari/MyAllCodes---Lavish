import java.util.Scanner;

//PROGRAM TO ILLUSTRATE THE USE OF CONTINUE KEYWORD
//PROGRAM TO FIND ALL THE EVEN NUMBERS BETWEEN A GIVEN RANGE.
public class continuekeyword {
	public static void main(String[] args)
	{
		Scanner s=new Scanner (System.in);
		
		System.out.println("ENTER THE LOWER LIMIT OF RANGE : ");
		int a=s.nextInt();
		
		System.out.println("ENTER THE UPPER LIMIT OF RANGE : ");
		int b=s.nextInt();
		for(int i=a;i<=b;i++)
		{
			if(i%2!=0)
				continue;
			System.out.println("i = "+i);
		
		}
	}
}
