// server program accepting strings and capitalizing them.
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server 
{
	public static void main(String[] args) throws IOException 
	{
		ServerSocket serverSocket=new ServerSocket(1234);
		System.out.println("Server Started");
		while(true)
		{
			Socket client=serverSocket.accept();
			DataInputStream dis=new DataInputStream(client.getInputStream());
			DataOutputStream dos=new DataOutputStream(client.getOutputStream());
			while(true)
			{
				String str=dis.readUTF();
				if(str.equals("END"))
					break;
				dos.writeUTF(str.toUpperCase());
			}
		}
	}
}
