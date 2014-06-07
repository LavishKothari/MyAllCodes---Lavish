/*
	creating a new file using File class
	
	File.createNewFile() throws the IOException
*/	
import java.io.*;

class Main
{
	public static void main(String args[])
	{
		
		if(args.length==1)
		{			
			File f=new File(args[0]);
			if(!f.exists())
				try
				{
					if(f.createNewFile())
						System.out.println("File successfully created :)");
					else
						System.out.println("File can't be created ...");
				}catch(IOException e)
				{
					System.out.println("you got an exception  : "+e.getMessage());
				}
			else
				System.out.println("the file you requested for creating already exists !!!");
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");
	}
}