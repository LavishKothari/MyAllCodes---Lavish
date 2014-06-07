/*
	illustration of f.listFiles() method and
					f.list() method
*/	
import java.io.*;

class Main
{
	public static void main(String args[])
	{
		
		if(args.length==1)
		{			
			File f=new File(args[0]);
			if(f.exists())
			{
				String[]str=f.list();
				File farr[]=f.listFiles();
				for(int i=0;i<str.length;i++)
				{
					System.out.println(farr[i].getName()); // statement A
 					System.out.println(str[i]);				// statement B
					
					//Statement A and Statement B will print the same thing
					//System.out.println(farr[i].isFile());
				}
			}
			else
				System.out.println("the directory you specified does not exists !!!");
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");
	}
}