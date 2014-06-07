import java.awt.*;
import java.io.*;
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
}

class Graph
{
	int numberOfVertices;
	MyLinkedList lst[];
	GraphNode vertices[];
	Graph(int numberOfVertices)
	{
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
}

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
				g.lst[i].addLast(new Integer(br.readLine()));
			}
		}
		g.printGraph();
		
	}
}