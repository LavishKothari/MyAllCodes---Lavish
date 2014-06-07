import java.io.*;
import java.net.*;

class Server
{
	public static void main(String[]args)throws IOException
	{
		ServerSocket ss=new ServerSocket(1235);
		while(true)
		{
			System.out.println("Waiting for client...");
			Socket client=ss.accept();
			System.out.println("Client successfully Connected !!!");
			DataOutputStream out=new DataOutputStream(client.getOutputStream());
			out.writeUTF("Hello Lavish kothari...How are you?");
		}
	}
}