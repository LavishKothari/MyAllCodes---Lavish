class GraphNode<E>
{
	GraphNode<E> parent;
	int parentDistance;
	String color;
	private E data;
	
	GraphNode(E data)
	{
		this.data=data;
	}
	GraphNode()
	{
	}
	public E getData()
	{
		GraphNode<E> obj=new GraphNode<E>();
		return data;
	}
}
class Main
{
	public static void main(String args[])
	{
		Integer i=25;
		GraphNode<Integer> gn=new GraphNode(new Integer("5"));
		System.out.println(gn.getData().getClass());
	}
}