/*
	ArrayList implementation
	Creating ArrayList of String
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
		
		a.add("Hello");
		a.add("Lavish");
		a.add("Kothari");
		a.add("How");
		a.add("are");
		a.add("You!!!");
		
		System.out.println();
		System.out.println("The contents of Collection - a are :\n"+a);
		System.out.println();
		
		/* removing element from ArrayList by specifing the Object*/
		a.remove("Kothari"); // from the Collection Interface
		System.out.println("The contents of Collection - a after deleting \"Kothari\" are :\n"+a);
		System.out.println();
		
		/* removing element from ArrayList by specifing the index*/
		a.remove(0); // from the List Interface
		System.out.println("The contents of Collection - a after deleting 0th index are :\n"+a);

		System.out.println();
		System.out.println("the size of your collection a is : "+a.size());
		
		System.out.println();
		/* obtaining an array from the ArrayList */
		Object str[]=a.toArray();
		
		System.out.println("Your array elements are :");
		for(Object s:str)
			System.out.println(s.toString());
		
	}
}