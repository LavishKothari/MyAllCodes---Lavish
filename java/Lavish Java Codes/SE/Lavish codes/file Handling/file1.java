import java.io.*;

class Main
{
	public static void main(String args[])
	{
		if(args.length==1)
		{			
			File f=new File(args[0]);
			System.out.println("The file Properties are : ");
			
			System.out.println("File exists ?                : "+f.exists());
			System.out.println("is File ?                    : "+f.isFile());
			System.out.println("is Directory ?               : "+f.isDirectory());
			System.out.println("can Read ?                   : "+f.canRead());
			System.out.println("can Write ?                  : "+f.canWrite());
			System.out.println("length in bytes              : "+f.length());
			System.out.println("Name                         : "+f.getName());
			System.out.println("Parent                       : "+f.getParent());
			System.out.println("Path                         : "+f.getPath());
			System.out.println("Absolute Path                : "+f.getAbsolutePath());
			System.out.println("last date of modification    : "+new java.util.Date(f.lastModified()));
		}
		else
			System.out.println("you have given wrong number of arguments at the command line !!!");
	}
}