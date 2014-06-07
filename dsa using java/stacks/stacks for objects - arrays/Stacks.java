/*
	implementation of stacks using arrays 
	creating stack of Object - Integer
*/

import java.io.*;
class MyStackException extends Exception
{
	MyStackException(String str)
	{
		super("You Got an Exception : \n"+str);
	}
}

class MyStack
{
	private int top=-1,size;
	private Object arr[];
	MyStack(int size)
	{
		this.size=size;
		arr=new Object[size];
	}
		
	public void push(Object element)throws MyStackException
	{
		if(top+1==size)
			throw new MyStackException("OVERFLOW !!!");
		else
			arr[++top]=element;
	}
	
	public Object pop()throws MyStackException
	{
		if(top==-1)
			throw new MyStackException("UNDERFLOW !!!");
		else
			return arr[top--];
	}
	
	public Object peek()throws MyStackException
	{
		if(top==-1)
			throw new MyStackException("UNDERFLOW !!!");
		else
			return arr[top];
	}
	
	public boolean isEmpty()
	{
		if(top==-1)
			return true;
		return false;
	}
	
	public int getSize()
	{
		return size;
	}
	public int getTop()
	{
		return top;
	}
}

class Main
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the size of the array : ");
		int n=Integer.parseInt(br.readLine());
		MyStack stack=new MyStack(n);
		
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
					try
					{
						stack.push(new Integer(element));
						System.out.println("Element pushed successfully...");
					}
					catch(MyStackException e){System.out.println(e.getMessage());}
					break;
				case 2:
					try
					{
						System.out.println(stack.pop()+" popped successfully...");
					}
					catch(MyStackException e){System.out.println(e.getMessage());}
					break;
				case 3:
					try
					{
						System.out.println("the top of the stack is : "+stack.peek());
					}
					catch(MyStackException e){System.out.println(e.getMessage());}
					break;
				case 4:
					System.out.println("The Maximum size of your stack is : "+stack.getSize());
					System.out.println("The current size of your stack is : "+(stack.getTop()+1));
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