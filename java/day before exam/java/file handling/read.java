import java.io.*;

class Main
{
	public static void main(String args[])
	{	
		try
		{
			int i;
			FileInputStream fin=new FileInputStream("d:/abcde.txt");
			do
			{
				i=fin.read();
				if(i!=-1)System.out.print((char)i);			
			}while(i!=-1);
		}
		catch(IOException e)
		{
			System.out.println("you got an exception : "+e);
		}
		
	}
}