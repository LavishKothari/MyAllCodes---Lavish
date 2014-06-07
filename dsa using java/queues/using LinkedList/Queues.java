/*
	implementation of queues using LinkedList 
	creating queue of Object - Integer
*/

import java.io.*;

class MyQueue
{
	MyLinkedList lst=new MyLinkedList();
	private MyListNode head,tail;
	MyQueue()
	{
		head=tail=null;
	}
	public int getSize()
	{
		return lst.getSize();
	}
	
	public void enqueue(Object element)
	{
		lst.addLast(element);
	}
	
	public Object dequeue()throws MyListEmptyException
	{
		return lst.deleteFirst();
	}
	
	public Object peek()
	{
		return lst.getIthElement(lst.getSize());
	}
	
	public boolean isEmpty()
	{
		if(lst.getSize()==0)
			return true;
		return false;
	}
}

class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		MyQueue queue=new MyQueue();
		
		while(true)
		{
			System.out.println("___________________________________\n");
			System.out.println("You have the following choices : \n");
			System.out.println("1. INSERT");
			System.out.println("2. DELETE");
			System.out.println("3. PEEK");
			System.out.println("4. get size of Queue");
			System.out.println("5. Check whether the Queue is empty or not...");
			System.out.println("6. EXIT\n");
			System.out.print("Enter your choice : ");
			int ch=Integer.parseInt(br.readLine());
			
			switch(ch)
			{
				case 1:
					System.out.print("Enter the number that you want to insert : ");
					int element=Integer.parseInt(br.readLine());
					queue.enqueue(new Integer(element));
					System.out.println("Element inserted successfully...");
					break;
				case 2:
					try
					{
						System.out.println(((Integer)(((MyListNode)(queue.dequeue())).getData())).intValue()+" deleted successfully...");
					}
					catch(MyListEmptyException e)
					{
						System.out.println(e.getMessage());
					}
					break;
				case 3:
					System.out.println("the head of the queue is : "+((Integer)(((MyListNode)(queue.peek())).getData())).intValue());
					break;
				case 4:
					System.out.println("The Maximum size of your queue is : "+queue.getSize());
					break;
				case 5:
					System.out.println("Is your queue Empty ? "+queue.isEmpty());
					break;
				case 6:
					System.exit(0);
				default:
					System.out.println("wrong choice entered...\nPlease enter a valid choice...");
			}
		}
	}
}