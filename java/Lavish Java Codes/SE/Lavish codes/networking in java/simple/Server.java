import java.io.*;
import java.net.*;

class Server
{
	public static void main(String[]args)throws IOException
	{
		ServerSocket ss=new ServerSocket(1234);
		while(true)
		{
			System.out.println("Waiting for client ... ");
			Socket client=ss.accept();
			System.out.println("Client Connected !");
			OutputStream out=client.getOutputStream();
			byte b[]="hello lavish kothari".getBytes();
			out.write(b);
		}
	}
}		