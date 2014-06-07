import java.util.*;
import java.io.*;
class Main
{
	public static void main(String[]args)throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int j=0;j<t;j++)
		{
			int flag=0;
			int length=0;
			Stack stack=new Stack();
			String str=br.readLine();
			char[]ch=str.toCharArray();
			for(int i=0;i<ch.length;i++)
			{
				if(stack.empty() && flag==1 && ch[i]!='<')
					break;
				if(stack.empty() && ch[i]=='>')
					break;
				if(stack.empty() && ch[i]=='<')
				{
					stack.push(new Character('<'));
					flag=1;
				}
				else if(stack.empty()&&ch[i]=='>')
				{}
				else
				{
					if(stack.peek().equals(new Character('<')) && ch[i]=='<')
						stack.push(new Character('<'));
					else if(stack.peek().equals(new Character('>')) && ch[i]=='>')
						stack.push(new Character('>'));
					else if(stack.peek().equals(new Character('<')) && ch[i]=='>')
					{
						stack.pop();
						length+=2;
					}
				}
			}
			System.out.println(length);
		}
	}
}
