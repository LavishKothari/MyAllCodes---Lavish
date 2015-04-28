import java.io.*;
import java.net.*;
class Server
{
	Server()
	{
	    try
	    {
	        /*
	            If 0 is passed as the port number to the constructor of ServerSocket, 
	            a free port will be allcated automatically.
	        */
		    ServerSocket s=new ServerSocket(0);
		    System.out.println("Server Listining on port number : "+s.getLocalPort());
		    Socket client=s.accept();
		    DataInputStream dis=new DataInputStream(client.getInputStream());
		    String str = dis.readUTF();
		    System.out.println("Sender sent : "+str);
		}
		catch(IOException e)
		{
		    e.printStackTrace();
		}
	}
}

class Main
{
	public static void main(String args[]) throws IOException
	{
	    new Server();
    }    
}

