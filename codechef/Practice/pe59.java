import java.io.*;
import java.util.*;
class pe59
{
	public static void main(String []args)throws IOException
	{
		ArrayList al=new ArrayList();
		//Vector al=new Vector();
		File f=new File("pe59.txt");
		FileInputStream fis=new FileInputStream(f);
		int ch;
		int pro=0;
		while(true)
		{
			ch=fis.read();
			if(ch==-1)
				break;
			if(ch==',')
			{
				al.add(new Integer(pro));
				pro=0;
			}
			else 
				pro=pro*10+(ch-48);
		}
		al.add(new Integer(pro));
		//System.out.println(al);
		int arr[]=new int[al.size()];

lavish : for(int i='a';i<'z';i++)
		 {
			 for(int j='a';j<'z';j++)
			 {
				 for(int k='a';k<'z';k++)
				 {
					 for(int l=0;l<al.size();l++)
					 {
						 switch(l%3)
						 {
							 case 0:
								 arr[l]=i;
								 break;
							 case 1:
								 arr[l]=j;
								 break;
							 case 2:
								 arr[l]=k;
								 break;
						 }
					 }
					 int counter=0;
					 for(int l=0;l<al.size();l++)
					 {
						 int value=(((Integer)al.get(l)).intValue()^arr[l]);
						 if((value>='A'&&value<='Z')||(value>='a'&&value<='z'))
							 counter++;
						 else
							 break;
					 }

					 if(counter==al.size())
						 break lavish;
				 }
			 }
		 }
		 int sum=0;

		 for(int i=0;i<al.size();i++)
		 {
			 System.out.println(arr[i]);
			 sum+=(((Integer)al.get(i)).intValue()^arr[i]);
		 }	
		 System.out.println("your answer is : " +sum);
	}
}
