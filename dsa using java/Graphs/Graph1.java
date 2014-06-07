import java.io.*;
import java.awt.*;
class Main
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the number of vertices of your Graph : ");
		Graph g=new Graph(new Integer(br.readLine()));
		
		for(int i=0;i<g.numberOfVertices;i++)
		{
			System.out.println("__________________________________________________\n");
			System.out.print("Enter the data part of vertex # "+(i+1)+" : ");
			g.vertices[i]=new GraphNode(new Integer(br.readLine()));
			
			System.out.print("Enter the number of vertices joined to this current vertex : ");
			int n=Integer.parseInt(br.readLine());
			
			for(int j=0;j<n;j++)
			{
				System.out.print("Enter the data part of joined vertex : ");
				g.lst[i].addLast(new GraphNode(new Integer(br.readLine())));
			}
		}
		g.printGraph();
		
		System.out.println("Enter the Node Number of the starting Node : ");
		g.BFS(g.getIthNode(Integer.parseInt(br.readLine())));
		g.printDistanceAfterBFS();
	}
}

class GraphNode
{
	GraphNode pi;
	int parentDistance;
	Color color;
	private Object data;
	GraphNode(Object data)
	{
		pi=null;
		parentDistance=Integer.MAX_VALUE;
		color=Color.white;
		this.data=data;
	}
	public Object getData()
	{
		return data;
	}
	public String toString()
	{
		return data.toString();
	}
}

class Graph
{
	MyQueue queue;
	int numberOfVertices;
	MyLinkedList lst[];
	GraphNode vertices[];
	Graph(int numberOfVertices)
	{
		queue=new MyQueue();
		this.numberOfVertices=numberOfVertices;
		lst=new MyLinkedList[this.numberOfVertices];
		for(int i=0;i<this.numberOfVertices;i++)
			lst[i]=new MyLinkedList();
		vertices=new GraphNode[this.numberOfVertices];
	}
	
	public void printGraph()
	{	
		System.out.println("/--------------------------------/");
		for(int i=0;i<numberOfVertices;i++)
		{
			System.out.print(vertices[i].getData()+" ---> ");
			lst[i].printList();
			System.out.println("__________________________________________");
		}
	}
	public GraphNode getIthNode(int i)
	{
		return vertices[i-1];
	}
	
	public int searchNode(GraphNode obj)
	{
		for(int i=0;i<numberOfVertices;i++)
			if(obj.getData().equals(vertices[i].getData()))
				return i+1;
		return 0;
	}
	
	// get the adjacency LinkedList of the corresponding vertex of graph
	public MyLinkedList getLinkedList(GraphNode node) 
	{
		return lst[searchNode(node)-1];
	}
	
	public void BFS(GraphNode node)
	{
		queue.enqueue(node);
		node.parentDistance=0;
		node.color=Color.gray;
		while(!queue.isEmpty())
		{
			try
			{
				node=(GraphNode)((queue.dequeue()).getData());
			}
			catch(MyListEmptyException e)
			{
				System.out.println(e.getMessage());
			}
			MyLinkedList linkedList=getLinkedList(node);
			for(int i=0;i<linkedList.getSize();i++)
			{
				GraphNode currentNode=(GraphNode)((linkedList.getIthElement(i+1)).getData());
				if((currentNode.color)==(Color.white))
				{
					currentNode.color=Color.gray;
					currentNode.pi=node;
					currentNode.parentDistance=node.parentDistance+1;
					System.out.println("hello lavish kothari : "+currentNode.parentDistance);
					queue.enqueue(currentNode);
				}
			}
			node.color=Color.black;
		}
	}
	
	public void printDistanceAfterBFS()
	{
		for(int i=0;i<numberOfVertices;i++)
		{
			System.out.println(getIthNode(i+1).getData()+"  "+getIthNode(i+1).parentDistance);
		}
	}
}

/****************/
/****************/
/****************/
/****************/
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
	
	public MyListNode dequeue()throws MyListEmptyException
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
/****************/
/****************/
/****************/
/****************/
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

	public MyListNode getIthElement(int i)
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
	
	public MyListNode deleteFirst() throws MyListEmptyException
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
	
	public MyListNode deleteLast()throws MyListEmptyException
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
	
	public MyListNode deleteNode(Object obj) throws NoSuchNodeException,MyListEmptyException
	{
		if(size==0)
			throw new MyListEmptyException("Your List is now empty...You can't delete any node");
		int position=search(obj);
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
/****************/
/****************/
/****************/
/****************/