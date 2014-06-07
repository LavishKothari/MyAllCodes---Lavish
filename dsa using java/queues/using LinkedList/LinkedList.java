/*
	LinkedList of integers
*/
import java.io.*;
class NoSuchNodeException extends Exception
{
	NoSuchNodeException(String msg)
	{
		super(msg);
	}
}
class MyListEmptyException extends Exception
{
	MyListEmptyException(String msg)
	{
		super(msg);
	}
}

class MyListNode
{
	private Object data;
	MyListNode next;
	MyListNode(Object data)
	{
		this.data=data;
		next=null;
	}
	public Object getData()
	{	
		return data;
	}
}

class MyLinkedList
{
	private MyListNode start,last;
	private int size=0;
	public int getSize()
	{
		return size;
	}
	
	public void addLast(Object data)
	{
		MyListNode node=new MyListNode(data);
		if(size==0)
		{
			start=last=node;
			size++;
			return;
		}
		this.last.next=node;
		this.last=node;
		size++;
	}
	public void addStart(Object data)
	{
		MyListNode node=new MyListNode(data);
		if(size==0)
		{
			start=last=node;
			size++;
			return;
		}
		node.next=start;
		start=node;
		size++;
	}
	public void addAfter(Object data1,Object data2) throws NoSuchNodeException
	{
		int position=search(data1);
		MyListNode node=new MyListNode(data2);
		if(position==0)
			throw new NoSuchNodeException("The given node was not found in the Linked List");
		if(position==size)
			last=node;
		node.next=((MyListNode)getIthElement(position)).next;
		((MyListNode)getIthElement(position)).next=node;
		size++;
	}

	public Object getIthElement(int i)
	{
		MyListNode node=start;
		for(int j=1;j<=size;j++)
		{
			if(i==j)
				break;
			node=node.next;
		}
		return node;
	}
	
	public void printList()
	{
		for(int i=1;i<=size;i++)
			System.out.print(((MyListNode)getIthElement(i)).getData()+" , ");
		System.out.println();
	}
	
	public Object deleteFirst() throws MyListEmptyException
	{
		MyListNode returnNode;
		if(size==0)
			throw new MyListEmptyException("Your List is now empty...You can't delete any node");
		size--;
		returnNode=start;
		if(start==last)
		{
			start=last=null;
			return returnNode;
		}
		start=start.next;
		return returnNode;
	}
	
	public Object deleteLast()throws MyListEmptyException
	{
		MyListNode returnNode=last;
		if(size==0)
			throw new MyListEmptyException("Your List is now empty...You can't delete any node");
		size--;
		MyListNode prevNode=null;
		MyListNode node=start;
		if(start==last)
		{
			start=last=null;
			return returnNode;
		}
		while(node.next!=null)
		{
			prevNode=node;
			node=node.next;
		}
		last=prevNode;
		last.next=null;
		return returnNode;
	}
	
	public int search(Object obj)
	{
		MyListNode node=new MyListNode(obj);
		for(int i=1;i<=size;i++)
			if((((MyListNode)getIthElement(i)).getData()).equals(node.getData()))
				return i;
		return 0; // returns 0 if the element is not found in the list.
	}
	
	public Object deleteNode(Object obj) throws NoSuchNodeException,MyListEmptyException
	{
		if(size==0)
			throw new MyListEmptyException("Your List is now empty...You can't delete any node");
		int position=search(obj);
		//System.out.println("search result : "+position);
		if(position==0)
			throw new NoSuchNodeException("The given node was not found in the Linked List");
		
		if(position==1)
		{
			return deleteFirst();
		}
		if(position==size)
		{
			return deleteLast();
		}
		MyListNode returnNode=((MyListNode)getIthElement(position));
		((MyListNode)getIthElement(position-1)).next=((MyListNode)getIthElement(position)).next;
		size--;
		return returnNode;
	}
}

class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		MyLinkedList linkedList=new MyLinkedList();
		
		while(true)
		{
			System.out.println("___________________________________________");
			System.out.println("\nYou have the following choices : ");
			System.out.println("___________________________________________");
			
			System.out.println("1. Add a new Node at the end of the Linked List");
			System.out.println("2. Add a new Node at the starting of the Linked List");
			System.out.println("3. Add a new Node after a specific element");
			System.out.println("4. Delete the first node");
			System.out.println("5. Delete the last node");
			System.out.println("6. Delete a specific node");
			System.out.println("7. Search a specific node");
			System.out.println("11. Exit");
			
			System.out.print("Enter your choice : ");
			int ch=Integer.parseInt(br.readLine());
			switch(ch)
			{
				case 1:
					System.out.print("Enter the data that you wish to insert at the end of the list : ");
					linkedList.addLast(new Integer(br.readLine()));
					break;
				case 2:
					System.out.print("Enter the data that you wish to insert at the start of the list : ");
					linkedList.addStart(new Integer(br.readLine()));
					break;
				case 3:
					System.out.print("Enter the data after which you want to insert your new node : ");
					Integer data1=new Integer(br.readLine());
					
					System.out.print("Enter the data that you wish to insert after after this node in the list : ");
					Integer data2=new Integer(br.readLine());
					try
					{
						linkedList.addAfter(data1,data2);
					}
					catch(NoSuchNodeException e)
					{
						System.out.println(e.getMessage());
					}	
					break;
				case 4:
					try
					{
						System.out.println(((Integer)(((MyListNode)(linkedList.deleteFirst())).getData())).intValue()+" was deleted Successfully");
					}
					catch(MyListEmptyException e)
					{
						System.out.println(e.getMessage());
					}
					break;
				case 5:
					try
					{
						System.out.println(((Integer)(((MyListNode)(linkedList.deleteLast())).getData())).intValue()+" was deleted Successfully");
					}
					catch(MyListEmptyException e)
					{
						System.out.println(e.getMessage());
					}
					break;
				case 6:
					try
					{
						System.out.print("Enter the data part of the node that you want to delete : ");
						System.out.println(((Integer)(((MyListNode)(linkedList.deleteNode(new Integer(br.readLine())))).getData())).intValue()+" was deleted Successfully");
						//System.out.println(((Integer)(linkedList.deleteNode(new Integer(br.readLine())))).intValue()+" was deleted Successfully");
					}
					catch(NoSuchNodeException e)
					{
						System.out.println(e.getMessage());
					}
					catch(MyListEmptyException e)
					{
						System.out.println(e.getMessage());
					}
					break;
				case 7:
					System.out.print("Enter the data part of the node that you want to search : ");
					System.out.println("your element is at position # "+linkedList.search(new Integer(br.readLine())));
					break;
				case 11:
					System.exit(0);
				default:
					System.out.println("You entered a wrong choice!!!");
					System.out.println("Please again enter another choice...");
			}
			linkedList.printList();
		}
	}
}