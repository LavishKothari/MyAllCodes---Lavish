

public class TreeNode 
{
	long frequency;
	char character;
	TreeNode left,right,parent;

	public TreeNode(long frequency,char character,TreeNode left,TreeNode right,TreeNode parent) 
	{
		this.frequency=frequency;
		this.character=character;
		this.left=left;
		this.right=right;
		this.parent=parent;
	}

	public TreeNode() 
	{
		this.frequency=0;
		this.character='\0';
		this.left=null;
		this.right=null;
		this.parent=null;
	}
}
