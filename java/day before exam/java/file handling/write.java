//reading from console and writing to the file.

import java.io.*;

class Main
{
	public static void main(String args[])
	{	
		try
		{
			int i;
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			FileOutputStream fout=new FileOutputStream("d:/abcde.txt");
			do
			{
				i=br.read();
				if(i!='q')fout.write(i);
					
			}while(i!=(int)'q');
		}
		catch(Exception e)
		{
			System.out.println("you got an exception : "+e);
		}
	}
}