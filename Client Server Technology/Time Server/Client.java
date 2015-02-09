import java.io.DataInputStream;
import java.io.IOException;
import java.net.*;

public class Client 
{
	public static void main(String[] args) throws UnknownHostException,IOException
	{
		Socket server=new Socket("localhost",5678);
		
		DataInputStream dis=new DataInputStream(server.getInputStream());
		System.out.println(dis.readUTF());
		server.close();
	}
}
