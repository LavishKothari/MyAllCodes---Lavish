import java.util.LinkedList;

public class HuffmanTree
{
	int treeHeight;
	String codeString[]=new String[256];
	int numberOfNodes; // this represents the number of leaf nodes
	LinkedList<TreeNode> nodeList;
	
	HuffmanTree()
	{
		numberOfNodes=0;
		nodeList=new LinkedList<TreeNode>();
		treeHeight=0;
		for(int i=0;i<256;i++)
			codeString[i]=new String("");
	}
	
	public TreeNode makeHuffmanTree(char charArray[],long frequencyArray[])
	{
		Queue q=new Queue();
		for(int i=0;i<charArray.length;i++)
		{
			TreeNode node=new TreeNode(frequencyArray[i], charArray[i], null,null,null);
			numberOfNodes++;
			nodeList.add(node);
			q.enQueue(node);
		}
		
		for(int i=0;i<charArray.length-1;i++)
		{
			TreeNode z=new TreeNode();
			TreeNode x=q.extractMin();
			TreeNode y=q.extractMin();
			z.frequency=x.frequency+y.frequency;
			z.left=x;
			z.right=y;
			x.parent=z;
			y.parent=z;
			q.enQueue(z);
		}
		
		return q.extractMin();
	}
	public void inorder(TreeNode root)
	{
		if(root==null)
			return ;
		else
		{
			inorder(root.left);
			System.out.println(root.frequency);
			inorder(root.right);
		}
	}
	public void makeCodes()
	{
		for(int i=0;i<numberOfNodes;i++)
		{
			TreeNode x=nodeList.get(i);
			char ch=x.character;
			while(x.parent!=null)
			{
				if(x.parent.left==x)
					codeString[ch]+="0";
				else
					codeString[ch]+="1";
				x=x.parent;
			}
		}
		treeHeight=0;
		/* reversing each string code*/
		for(int i=0;i<256;i++)
		{
			String str=codeString[i];
			char c[]=str.toCharArray();
			for(int j=0,k=c.length-1;j<k;j++,k--)
			{
				char temp=c[j];
				c[j]=c[k];
				c[k]=temp;
			}
			codeString[i]=new String(c);
			if(treeHeight<codeString[i].length())
				treeHeight=codeString[i].length();
		}
	}
	
}
