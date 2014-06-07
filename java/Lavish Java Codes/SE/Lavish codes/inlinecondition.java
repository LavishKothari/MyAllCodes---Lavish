import java.util.Scanner;
public class inlinecondition {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		System.out.println("ENTER VALUE OF a");
		int a=s.nextInt();
		
		System.out.println("ENTER VALUE OF b");
		int b=s.nextInt();
		
		int max1=(a>b)?a:b;
		System.out.println("ON USING INLINE CONDITION THE RESULT IS :");
		System.out.println("Max = "+max1);
		
		
		//using if else condition to perform the same task...
		int max2;
		System.out.println("ON USING THE IF ELSE BLOCK THE RESULT IS :");
		if(a>b)
			max2=a;
		else
			max2=b;
		
		System.out.println("Max = "+max2);
		
		
	}

}
