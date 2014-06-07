import java.io.*;
import java.util.*;
import java.net.*;

class Server
{
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
			
			/*******************/
			
			/* if the file is not yet created then the next statement will create the file 
				with empty contents and 
				if the file already exists then it will open the file in appending mode. */
			FileWriter fw=new FileWriter("log.txt",true); 
			
			/* sending the contents of file on server side to the connected client. */
			FileReader fr=new FileReader("log.txt");
			BufferedReader br=new BufferedReader(fr);
			String msg="";
			String str;	 
			while((str=br.readLine())!=null)
			{
				msg=msg+str+"\n";
			}
			out.writeUTF(msg);
			/**********************/
			fr.close();
			//serverThreadList.add(new ServerThread(in,out,serverThreadList));
			new ServerThread(in,out,serverThreadList);
			
		}
	}
}

class ServerThread extends Thread
{
	
	DataInputStream in;
	DataOutputStream out;
	static LinkedList<ServerThread> serverThreadList;
	ServerThread(DataInputStream in,DataOutputStream out,LinkedList<ServerThread> serverThreadList)
	{
		this.serverThreadList=serverThreadList;
		this.serverThreadList.add(this);
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
			{
				String str=in.readUTF();
				//System.out.println(str); // this is the string received after pressing enter by user
				FileWriter fw=new FileWriter("log.txt",true);
				BufferedWriter bw=new BufferedWriter(fw);
				bw.write(str);
				bw.flush();
				/*****************/
				/* reading the whole contents of the file */
				FileReader fr=new FileReader("log.txt");
				BufferedReader br=new BufferedReader(fr);
				String msg="";
				 
				while((str=br.readLine())!=null)
				{
					msg=msg+str+"\n";
				}
				System.out.println(msg); // these are the whole contents of the file 
				sendToAllClients(msg);
				System.out.println(serverThreadList.size());
				fw.close();
				fr.close();
			}
				
		}
		catch(IOException ioe){}
	}
	
	public static void sendToAllClients(String msg)throws IOException
	{
		for(int i=0;i<serverThreadList.size();i++)
		{
			serverThreadList.get(i).out.writeUTF(msg);
		}
	}
}