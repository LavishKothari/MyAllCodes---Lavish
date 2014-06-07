/*
	implementation of stacks using arrays 
	creating stack of Object - Integer
*/

import java.io.*;
class MyStack
{
	private MyListNode top=null;
	MyLinkedList lst=new MyLinkedList();	
	public void push(Object element)
	{
		lst.addLast(element);
	}
	
	public Object pop()throws MyListEmptyException
	{
		return lst.deleteLast();
	}
	
	public Object peek()throws MyListEmptyException
	{
		return lst.getIthElement(lst.getSize());
	}
	
	public boolean isEmpty()
	{
		if(lst.getSize()==0)
			return true;
		return false;
	}
	public int getSize()
	{
		return lst.getSize();
	}
	public Object getTop()
	{
		return lst.getIthElement(lst.getSize());
	}
}

class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		MyStack stack=new MyStack();
		
		while(true)
		{
			System.out.println("___________________________________\n");
			System.out.println("You have the following choices : \n");
			System.out.println("1. PUSH");
			System.out.println("2. POP");
			System.out.println("3. PEEK");
			System.out.println("4. get size of Stack");
			System.out.println("5. Check whether the stack is empty or not...");
			System.out.println("6. EXIT\n");
			System.out.print("Enter your choice : ");
			int ch=Integer.parseInt(br.readLine());
			
			switch(ch)
			{
				case 1:
					System.out.print("Enter the number that you want to push : ");
					int element=Integer.parseInt(br.readLine());
					stack.push(new Integer(element));
					System.out.println("Element pushed successfully...");
					break;
				case 2:
					try
					{
						System.out.println(((Integer)(((MyListNode)(stack.pop())).getData())).intValue()+" popped successfully...");
					}
					catch(MyListEmptyException e){System.out.println(e.getMessage());}
					break;
				case 3:
					try
					{
						System.out.println("the top of the stack is : "+((Integer)(((MyListNode)(stack.peek())).getData())).intValue());
					}
					catch(MyListEmptyException e){System.out.println(e.getMessage());}
					break;
				case 4:
					System.out.println("The Maximum size of your stack is : "+stack.getSize());
					break;
				case 5:
					System.out.println("Is your stack Empty ? "+stack.isEmpty());
					break;
				case 6:
					System.exit(0);
				default:
					System.out.println("wrong choice entered...\nPlease enter a valid choice...");
			}
		}
	}
}