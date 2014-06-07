import java.util.*;
import java.io.*;
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
				g.lst[i].add(new GraphNode(new Integer(br.readLine())));
			}
		}
		g.printGraph();
		
		System.out.println("Enter the Node Number of the starting Node : ");
		g.BFS(g.search(new GraphNode(new Integer(br.readLine()))));
		g.printDistanceAfterBFS();
	}
}

class GraphNode
{
	GraphNode parent;
	int parentDistance;
	String color;
	private Object data;
	GraphNode(Object data)
	{
		parent=null;
		parentDistance=Integer.MAX_VALUE;
		color="white";
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
	Queue queue;
	int numberOfVertices;
	LinkedList lst[];
	GraphNode vertices[];
	Graph(int numberOfVertices)
	{
		queue=new Queue();
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
			for(int j=0;j<lst[i].size();j++)
			{
				lst[i].get(j);
			}
			System.out.println("__________________________________________");
		}
	}
	
	public GraphNode getIthNode(int i)
	{
		return vertices[i-1];
	}
	
	public GraphNode search(GraphNode node)
	{
		for(int i=1;i<=numberOfVertices;i++)
		{
			if((getIthNode(i).getData()).equals(node.getData()))
				return getIthNode(i);
		}
		return null;
	}
	
	
	public int searchNode(GraphNode obj)
	{
		for(int i=0;i<numberOfVertices;i++)
			if(obj.getData().equals(vertices[i].getData()))
				return i+1;
		return 0;
	}
	
	// get the adjacency LinkedList of the corresponding vertex of graph
	public LinkedList getLinkedList(GraphNode node) 
	{
		return lst[searchNode(node)-1];
	}
	
	public void BFS(GraphNode node)
	{
		queue.enqueue(node);
		node.parentDistance=0;
		node.color="gray";
		while(!queue.isEmpty())
		{
			try
			{
				node=(GraphNode)(queue.dequeue());
			}
			catch(MyListEmptyException e)
			{
				System.out.println(e.getMessage());
			}
			MyLinkedList linkedList=getLinkedList(node);
			for(int i=0;i<linkedList.getSize();i++)
			{
				GraphNode currentNode=(GraphNode)((linkedList.getIthElement(i+1)).getData());
				if(currentNode.color=="white")
				{
					currentNode.color="gray";
					currentNode.pi=node;
					currentNode.parentDistance=node.parentDistance+1;
					System.out.println("hello lavish kothari : "+currentNode.parentDistance);
					queue.enqueue(currentNode);
				}
			}
			node.color="black";
		}
	}
	
	public void printDistanceAfterBFS()
	{
		System.out.println("_______________________________");
		for(int i=1;i<=numberOfVertices;i++)
		{
			System.out.println(getIthNode(i).getData()+" --> "+getIthNode(i).parentDistance);
		}
	}
}