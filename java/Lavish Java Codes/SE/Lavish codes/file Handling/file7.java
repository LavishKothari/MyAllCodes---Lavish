import java.io.*;
class Main
{
	public static void main(String args[])
	{
		try
		{
			File f=new File("f://a.txt");
			
			ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(f));
			int i=90;
			oos.write(i);
			oos.close();
		}
		catch(IOException ioe){}
	}
}