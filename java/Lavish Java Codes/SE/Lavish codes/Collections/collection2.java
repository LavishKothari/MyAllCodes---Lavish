/*
	ArrayList implementation
	Creating ArrayList of integers
*/
/*
	ArrayList class implements the List interface
	The List interface extends the Collection Interface
*/

import java.util.*;

class Main
{
	public static void main(String args[])
	{
		ArrayList a=new ArrayList();
		
		a.add(new Integer(10));
		a.add(new Integer(18));
		a.add(new Integer(48));
		a.add(new Integer(13));
		a.add(new Integer(56));
		a.add(new Integer(89));
	
		System.out.println();
		System.out.println("The contents of Collection - a are :\n"+a);
		System.out.println();
		
		a.remove(new Integer(18)); // from the Collection Interface
		System.out.println("The contents of Collection - a after deleting \"18\" are :\n"+a);
		System.out.println();
		
		a.remove(3); // from the List Interface
		System.out.println("The contents of Collection - a after deleting 3rd index are :\n"+a);

		System.out.println();
		System.out.println("the size of your collection a is : "+a.size());
		
		
		/* now here finding the sum of all the elements of ArrayList*/
		
		Object arr[]=a.toArray();
		int sum=0;
		for(Object i:arr)
			sum+=(((Integer)i).intValue());
		System.out.println();	
		System.out.println("The sum of all the elements of your ArrayList is : "+sum);

	}
}