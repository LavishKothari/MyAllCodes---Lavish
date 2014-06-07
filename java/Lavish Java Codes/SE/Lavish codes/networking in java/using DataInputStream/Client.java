import java.io.*;
import java.net.*;

class Client
{
	public static void main(String []args)throws UnknownHostException,IOException
	{
		Socket server=new Socket("localhost",1235);
		DataInputStream in=new DataInputStream(server.getInputStream());
		
		System.out.println(in.readUTF());
	}
}