class GraphNode
{
	GraphNode parent;
	int parentDistance;
	String color;
	private Object data;
	
	GraphNode(Object data)
	{
		this.data=data;
	}
	public Object getData()
	{
		return data;
	}
}
class Main
{
	public static void main(String args[])
	{
		GraphNode gn=new GraphNode(new Integer("5"));
		System.out.println(gn.getData().getClass());
		
		
		if(gn.getData() instanceof Object)
			System.out.println("hello lavish kothari");
	}
}