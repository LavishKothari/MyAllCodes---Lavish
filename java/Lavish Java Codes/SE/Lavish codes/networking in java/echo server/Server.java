import java.io.*;
import java.net.*;

class Server
{
	public static void main(String[]args)throws IOException
	{
		ServerSocket ss=new ServerSocket(1234);
		
		while(true)
		{
			Socket client=ss.accept();
			
			DataInputStream in=new DataInputStream(client.getInputStream());
			DataOutputStream out=new DataOutputStream(client.getOutputStream());
		
			new ServerThread(in,out);
			
		}
	}
}

class ServerThread extends Thread
{
	DataInputStream in;
	DataOutputStream out;
	ServerThread(DataInputStream in,DataOutputStream out)
	{
		this.in=in;
		this.out=out;
		Thread th=new Thread(this);
		th.start();
	}
	public void run()
	{
		try
		{
			while(true)
				out.writeUTF(in.readUTF().toUpperCase());
		}
		catch(IOException ioe){}
	}
}