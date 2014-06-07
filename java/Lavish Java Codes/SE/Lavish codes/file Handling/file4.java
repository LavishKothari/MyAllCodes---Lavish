/*
	making a directory using the File class
	mkdir() returns true if directory is successfully created
	it returns false if directory was not created successfully
	
	what if the directory name that you specified already exists??
	and you didnt checked this in the if statement as given below?
	
	if the directory specified already exists then the f.mkdir() method will return false;
*/	
import java.io.*;

class Main
{
	public static void main(String args[])
	{
		
		if(args.length==1)
		{			
			File f=new File(args[0]);
			//System.out.println(f.mkdir());
			
			if(!f.exists())
			{
				if(f.mkdir())
					System.out.println("Directory you specified was created successfully...");
				else
					System.out.println("Directory you specified was not created !!!")
			}
			else
				System.out.println("the directory you specified already exists !!!");
			
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");
	}
}