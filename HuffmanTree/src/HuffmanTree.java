import java.util.LinkedList;

public class HuffmanTree
{
	int treeHeight;
	/*
	   codeString is the array of string - binary String
	   codeString[i] stores the huffman code of character whose ascii value is i
	   the huffman code will consists of either 0 or 1
	 */
	String codeString[]=new String[256];
	int numberOfNodes; // this represents the number of leaf nodes in the huffman tree.
	LinkedList<TreeNode> nodeList;

	/*
	   this constructor will initialize the linked list
	   and this constructor will also initialize each of the codeString to empty string
	 */
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

		/*
		   this loop enqueue each TreeNode into queue
		 */
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

		return q.extractMin(); // this will return the root of the Huffman tree.
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
		/*
		   this method will generate huffman code of each distinct character first in reverse order
		   and then reverse each huffman code again to get correct code.
		 */
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
