import java.io.*;
import java.net.*;
class Sender
{
	Sender(int port,String msg)
	{
		try
		{
		    /*
		        Sender sends the message received in the constructor 
		        to the local host on the specified port.
		    */
			Socket server=new Socket("localhost",port);
			DataOutputStream dos=new DataOutputStream(server.getOutputStream());
			dos.writeUTF(msg);
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
	    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    System.out.print("Enter the port on which you want to send the message : ");
	    int port=Integer.parseInt(br.readLine());
	    System.out.print("Enter the message : ");
	    String msg=br.readLine();
	    new Sender(port,msg);
    }
}
/*
class Main
{
    public static boolean portIsOpen(String ip, int port, int timeout) 
    {
        try {
            Socket socket = new Socket();
            //socket.connect(new InetSocketAddress(ip, port), timeout);
            socket.connect(new InetSocketAddress(ip, port));
            socket.close();
            return true;
        } catch (Exception ex) {
            return false;
        }
    }
    public static void main(String args[]) throws IOException
	{
	    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    int port=0;
	    for(int i=1024;i<65535;i++)
	    {
	        if(portIsOpen("localhost",i,200))
	        {
	            port=i;
	            break;
	        }
	    }
	    System.out.println("Found port : "+port);
	    if(port!=0)
	    {
	        System.out.print("Enter the message : ");
	        String msg=br.readLine();
	        new Sender(port,msg);
	    }
	    else
	    {
	        System.out.println("No port found.");
	    }
    }
}
*/
