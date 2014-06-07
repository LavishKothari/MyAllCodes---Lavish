import java.util.*;

class ListNode
{
	int item;
	ListNode next;

	ListNode(int item)
	{
		this.next=null;
		this.item=item;
	}
	
	public static ListNode insertEnd(int item, ListNode start)
	{
		ListNode l=new ListNode(item);
		if(start == null)
		{
			start=l;
			return l;
		}
		
		while(start.next!=null)
		{
			start=start.next;
		}
		
		start.next=l;
		return l;
	}
	
	static void print(ListNode start)
	{
		while(start!=null)
		{
			System.out.println(start.item);
			start=start.next;
		}
	}
	
	static int nth(int num, ListNode start)
	{
		int count=0;
		while(start!=null)
		{
			count++;
			if(num==count)
			{
				return start.item;
			}
			start=start.next;
		}
		return -1;
	}
	
	static ListNode deleteEnd(ListNode start)
	{
		ListNode cstart;
		cstart=start;
		if(start==null)
		{
			System.out.println("List empty!!! Deletion not possible");
			return start;
		}
		if(start.next==null)
		{
			start=null;
			System.out.println("Deletion Successful");
			return start;
		}
		while(start.next.next!=null)
		{
			start=start.next;
		}
		start.next=null;
		System.out.println("Deletion Successful");
		return cstart;
	}
	
	static ListNode insertAfter(int item1 ,int item2,ListNode start)
	{
		ListNode cstart;
		cstart=start;
		while(start!=null)
		{
			if(start.item==item1)
				break;
			start=start.next;
		}
		if(start==null)
		{
			System.out.println("Item not found");
			return cstart;
		}
		ListNode l2=new ListNode(item2);
		l2.next=start.next;
		start.next=l2;
		return cstart;
	}
	
	static ListNode insertBefore(int item1,int item2,ListNode start)
	{
		ListNode cstart;
		cstart=start;
		if(start==null)
		{
			System.out.println("List empty");
			return start;
		}
		
		while(start!=null)
		{
			if(start.next.item==item1)
			break;
			start=start.next;
		}
		if(start==null)
		{
			System.out.println("Item not Found");
			return cstart;
		}
		start=insertAfter(item1,item2,start);
	}
}

class Main
{
	public static void main(String args[])
	{
		ListNode start;
		int choice,item;
		Scanner sc=new Scanner(System.in);
		start=null;
		while(true)
		{
			System.out.println("-------Menu--------");
			System.out.println("1.\tInsert a new node at the end");
			System.out.println("2.\tPrint the list");
			System.out.println("3.\tPrint the nth item");
			System.out.println("4.\tDelete the last node");
			System.out.println("5.\tInsert after a given node");
			System.out.println("6.\tInsert before a given node");
			System.out.println("7.\tExit");
			System.out.println("Enter your choice");
			choice=sc.nextInt();
			switch(choice)
			{
				case 1:
						System.out.println("Enter the item you want to insert");
						item=sc.nextInt();
						if(start==null)
						{
							start=ListNode.insertEnd(item,start);
						}
						else
							ListNode.insertEnd(item,start);
						break;
						
				case 2:
						ListNode.print(start);
						break;
						
						
				case 3:
						System.out.println("Enter the item number you want to print");
						int num=sc.nextInt();
						System.out.println(ListNode.nth(num,start));
						break;
						
						
				case 4:
						start=ListNode.deleteEnd(start);
						break;
						
				case 5:
						System.out.println("Enter the  node item after which you want to insert");
						int item1=sc.nextInt();
						System.out.println("Enter the  node item which you want to insert");
						int item2=sc.nextInt();
						start=ListNode.insertAfter(item1,item2,start);
						break;
						
						
				case 6:
						System.out.println("Enter the  node item before which you want to insert");
						int item1=sc.nextInt();
						System.out.println("Enter the  node item which you want to insert");
						int item2=sc.nextInt();
						start=ListNode.insertBefore(item1,item2,start);
						break;
						

				case 7:
						System.exit(1);
						break;
						
						
				default:
						System.out.println("Wrong choice");
						
			}
		}
				
	}
}