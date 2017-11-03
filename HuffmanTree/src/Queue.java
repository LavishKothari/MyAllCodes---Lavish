import java.util.LinkedList;

public class Queue 
{
	private LinkedList<TreeNode> queueList;
	Queue()
	{
		this.queueList=new LinkedList<TreeNode>();
	}

	public void enQueue(TreeNode node)
	{
		queueList.add(node);
	}

	public TreeNode dQueue()
	{
		return queueList.removeFirst();
	}

	public boolean isQueueEmpty()
	{
		return queueList.isEmpty();
	}

	public TreeNode extractMin()
	{
		long min=Long.MAX_VALUE;
		TreeNode returnNode=null;

		for(int i=0;i<queueList.size();i++)
		{
			if(queueList.get(i).frequency<min)
			{
				min=queueList.get(i).frequency;
				returnNode=queueList.get(i);
			}			
		}
		queueList.remove(returnNode);
		return returnNode;
	}
}
