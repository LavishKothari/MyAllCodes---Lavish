/*
	renaming and deleting the files
*/
/*
	the first command line argument should be the file name which you wish to rename
	the second command line argument should be the new file name
*/

/*
	use f.delete() method to delete the file
	if file couldnot be deleted f.delete() returns false
*/

import java.io.*;

class Main
{
	public static void main(String args[])
	{
		
		if(args.length==2)
		{			
			File f=new File(args[0]);
			if(f.renameTo(new File(args[1])))
				System.out.println("file renamed successfully...");
			else
				System.out.println("file could not be renamed...");
			// if the directory could not be renamed f.renameTo() returns false
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");		
	}
}