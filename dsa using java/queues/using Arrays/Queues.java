/*
	implementation of queues using arrays 
	creating queue of Object - Integer
*/

import java.io.*;
class MyQueueException extends Exception
{
	MyQueueException(String str)
	{
		super("You Got an Exception : \n"+str);
	}
}

class MyQueue
{
	private int head,tail,size;
	private Object arr[];
	MyQueue(int size)
	{
		head=tail=-1;
		this.size=size;
		arr=new Object[size];
	}
		
	public void enqueue(Object element)throws MyQueueException
	{
		if(isFull())
			throw new MyQueueException("OVERFLOW !!!");
		else
		{
			if(tail==-1)
				head=tail=0;
			else
				tail++;
			if(tail==size)
				tail=0;
			arr[tail]=element;
		}
	}
	
	public Object dequeue()throws MyQueueException
	{
		if(isEmpty())
			throw new MyQueueException("UNDERFLOW !!!");
		else
		{
			if(head==tail) // if there is only a single element in the queue
			{
				int tmp=tail;
				head=tail=-1;
				return arr[tmp];
			}
			head++;
			if(head==size) // if the element to be deleted is the last element of the array
			{
				head=0;
				return arr[size-1];
			}
			return arr[head-1];
		}
	}
	
	public Object peek()throws MyQueueException
	{
		if(isEmpty())
			throw new MyQueueException("UNDERFLOW !!!");
		else
			return arr[head];
	}
	
	public boolean isEmpty()
	{
		if(head==-1&&tail==-1)
			return true;
		return false;
	}
	public boolean isFull()
	{
		if((head==0 && tail==size-1)||(tail+1==head))
			return true;
		return false;
		
	}
	public int getSize()
	{
		return size;
	}
	public int getCurrentSize()
	{
		return (getHead()<getTail()?getTail()-getHead()+1:getSize()-(getTail()-getHead()+1));
	}
	public int getHead()
	{
		return head;
	}
	public int getTail()
	{
		return tail;
	}
}

class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the size of the array : ");
		int n=Integer.parseInt(br.readLine());
		MyQueue queue=new MyQueue(n);
		
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
					try
					{
						queue.enqueue(new Integer(element));
						System.out.println("Element inserted successfully...");
					}
					catch(MyQueueException e){System.out.println(e.getMessage());}
					break;
				case 2:
					try
					{
						System.out.println(queue.dequeue()+" deleted successfully...");
					}
					catch(MyQueueException e){System.out.println(e.getMessage());}
					break;
				case 3:
					try
					{
						System.out.println("the head of the stack is : "+queue.peek());
					}
					catch(MyQueueException e){System.out.println(e.getMessage());}
					break;
				case 4:
					System.out.println("The Maximum size of your queue is : "+queue.getSize());
					System.out.println("The current size of your queue is : "+queue.getCurrentSize());
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