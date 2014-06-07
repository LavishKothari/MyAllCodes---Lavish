/*
	Creates the directory named by this abstract pathname, including any necessary but non-existent parent directories. 
	Note that if this operation fails it may have succeeded in creating some of the necessary parent directories.
	
	Suppose you want to create a directory named “Directory2 and all its sub-directories “Sub2? and “Sub-Sub2? together
	new File("C:\\Directory2\\Sub2\\Sub-Sub2").mkdirs()
*/	
import java.io.*;

class Main
{
	public static void main(String args[])
	{
		
		if(args.length==1)
		{			
			File f=new File(args[0]);
			System.out.println(f.mkdirs());
			// if the directory already exists then f.mkdirs() returns false
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");
		
	}
}