import java.io.*;
import java.util.*;
import java.net.*;

class Server
{
	static LinkedList<String> loggedInUsers=new LinkedList<String>();
	static LinkedList<ServerThread> serverThreadList=new LinkedList<ServerThread>();
	//static LinkedList<Socket> clientList=new LinkedList<Socket>();
	public static void main(String args[])throws IOException
	{
		ServerSocket ss=new ServerSocket(1234);
		while(true)
		{
			Socket client=ss.accept();
			//clientList.add(client);
			
			DataInputStream in=new DataInputStream(client.getInputStream());
			DataOutputStream out=new DataOutputStream(client.getOutputStream());
			
			serverThreadList.add(new ServerThread(in,out,loggedInUsers,serverThreadList));
			
		}
	}
}

class ServerThread extends Thread
{
	LinkedList<String> loggedInUsers;
	
	DataInputStream in;
	DataOutputStream out;
	static LinkedList<ServerThread> serverThreadList;
	ServerThread(DataInputStream in,DataOutputStream out,LinkedList<String> loggedInUsers,LinkedList<ServerThread> serverThreadList)
	{
		this.serverThreadList=serverThreadList;
		this.loggedInUsers=loggedInUsers;
		this.in=in;
		this.out=out;
		Thread th=new Thread(this);
		th.start();
	}
	public void run()
	{
		//while(true)
		{
			try
			{
				/*
				String user=in.readUTF(); // receiving the User Name
				loggedInUsers.add(user);
				//out.writeUTF(loggedInUsers.getLast());
				for(int i=0;i<loggedInUsers.size()-1;i++)
					serverThreadList.getLast().out.writeUTF(loggedInUsers.get(i));
				sendToAllClients(user);
				*/
				while(true)
				{
					String str=in.readUTF();
					//System.out.println(str);
					sendToAllClients(str);
				}
				
			}
			catch(IOException ioe){}
		}
	}
	public static void sendToAllClients(String msg)throws IOException
	{
		for(int i=0;i<serverThreadList.size();i++)
		{
			serverThreadList.get(i).out.writeUTF(msg);
		}
	}
}