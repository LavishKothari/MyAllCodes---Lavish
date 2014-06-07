/*
	illustration of java.util.LinkedList class
	the LinkedList Class implements the List interface
*/
import java.io.*;
import java.util.*;

class Main
{
	public static void main(String args[])
	{
	
		try
		{
			BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
			LinkedList ll=new LinkedList();
			while(true)
			{
				System.out.println("__________________choices_____________________________");
				System.out.println("\nYour option are : ");
				
				System.out.println("1. Insert a new element in the linked list at last");
				System.out.println("2. Insert a new element in the linked list at first");
				System.out.println("3. Get the first element of the linked list");
				System.out.println("4. Get the last element of the linked list");
				System.out.println("5. Remove the first element from the linked list");
				System.out.println("6. Remove the last element from the linked list");
				System.out.println("7. Print the size of the linked list");
				System.out.println("8. Exit");
				
				
				System.out.println("");
				System.out.print("Enter your choice : ");
				int choice=Integer.parseInt(br.readLine());
				
				switch(choice)
				{
					case 1:
						System.out.print("Enter the Number that you want to Insert at the end : ");
						int num=Integer.parseInt(br.readLine());
				
						ll.addLast(new Integer(num));
						break;
					case 2:
						System.out.print("Enter the Number that you want to Insert at the start : ");
						num=Integer.parseInt(br.readLine());
				
						ll.addFirst(new Integer(num));
						break;
					case 3:
						System.out.println(ll.getFirst());
						break;
					case 4:
						System.out.println(ll.getLast());
						break;
					case 5:
						try
						{
							ll.removeFirst();
						}
						catch(NoSuchElementException e)
						{
							System.err.println("Your Linked list is empty !!!\nDeletion not possible");
						}
						break;
					case 6:
						try
						{
							ll.removeLast();
						}
						catch(NoSuchElementException e)
						{
							System.err.println("Your Linked list is empty !!!\nDeletion not possiblez");
						}
						break;
					case 7:
						System.out.println("The size of the linked list is : "+ll.size());
						break;
					case 8:
						System.exit(0);
					default:
						System.out.println("You entered a wrong choice !! \nEnter a correct choice again...");
						break;
				}
				
				System.out.println("\nYour Linked list is : \n"+ll);
			}
		}
		catch(IOException e){}
	}
}