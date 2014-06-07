import java.io.*;
import java.net.*;

class Client
{
	public static void main(String args[])throws UnknownHostException, IOException
	{
		Socket server=new Socket("localhost",1234);
		System.out.println("Connected!");
		InputStream in=server.getInputStream();
		byte[]b=new byte[1000];
		in.read(b);
		System.out.println("Server said : "+new String(b));
	}
}