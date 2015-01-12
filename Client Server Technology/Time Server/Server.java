import java.io.DataOutputStream; 
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Date;


public class Server 
{
	private static ServerSocket serverSocket;

	public static void main(String[] args)throws IOException,UnknownHostException 
	{
		serverSocket = new ServerSocket(5678);
		Socket clientSocket;
		while(true)
		{
			clientSocket=serverSocket.accept();
			System.out.println("accepted a client.");
			DataOutputStream dos=new DataOutputStream(clientSocket.getOutputStream());
			dos.writeUTF(new Date()+"");
		}
	}
}
