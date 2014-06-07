import java.util.*;
import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
class ServerFrame extends JFrame implements ActionListener
{
	JButton bStartServer,bDeleteLogFile;
	JLabel lStartServer,lDeleteLogFile;
	public Insets getInstes()
	{
		return new Insets(40,20,20,20);
	}
	
	ServerFrame()
	{
		setSize(450,100);
		setLocation(100,100);
		setResizable(false);
		setLayout(new GridLayout(2,2,10,10));
		
		lDeleteLogFile=new JLabel("Log File Deleted Successfully !!!");
		lStartServer=new JLabel("Server Running...");
		
		lStartServer.setVisible(false);
		bStartServer=new JButton("Start the Server");
		
		bDeleteLogFile=new JButton("Delete the Log File");
		lDeleteLogFile.setVisible(false);
		
		add(bStartServer);
		add(lStartServer);
		add(bDeleteLogFile);
		add(lDeleteLogFile);
		
		bStartServer.addActionListener(this);
		addWindowListener(new MyWindowAdapter());
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bStartServer)
		{
			System.out.println("hello lavish kothari");
			lStartServer.setVisible(true);
			new Server();
		}
		else if(ae.getSource()==bDeleteLogFile)
		{
			File f=new File("log.txt");
		}
	}
}

class MyWindowAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}
class Server
{
	Socket client;
	ServerSocket server;
	static LinkedList<Socket> clientList=new LinkedList<Socket>();
	public static void main(String args[])
	{
		//new ServerFrame().setVisible(true);
		new Server();
	}
	
	Server()
	{
		try
		{
			server=new ServerSocket(1234);
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
		
		while(true)
		{
			try
			{
				client=server.accept();
			}
			catch(IOException e){System.out.println("hello : "+e);}
			catch(Exception e){System.out.println("hey"+e);}

			clientList.add(client);
			new ServerThread(this);
		}
	}
}

class ServerThread extends Thread
{
	Server s;
	
	ServerThread(Server s)
	{
		this.s=s;
		
		Thread th=new Thread(this);
		th.start();
	}
	
	synchronized public void run()
	{
		DataOutputStream out=null;
		DataInputStream in=null;
		try
		{
			out=new DataOutputStream(s.client.getOutputStream());
			in=new DataInputStream(s.client.getInputStream());
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
		try
		{
			while(true)
			{
				String inputString=in.readUTF();
				
				FileWriter fw=new FileWriter("log.txt",true);
				BufferedWriter bw=new BufferedWriter(fw);
					
					
					
				if(inputString.equals("###@@@"))
				{
					FileReader fr=new FileReader("log.txt");
					BufferedReader br=new BufferedReader(fr);
					
					String str,msg="";
					while((str=br.readLine())!=null)
						msg=msg+str+"\n";
					out.writeUTF("###@@@");
					out.writeUTF(msg);
					//sendToAllClients(msg);
					
					fr.close();
				}
				else
				{
					bw.write(inputString);
					bw.flush();
				
					sendToAllClients(inputString);
				}
	 			fw.close();
			}
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
		s.clientList.remove(s.client);
		try
		{
			s.client.close();
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
		System.out.println("herer yyou handeled it");
	}
	
	synchronized void sendToAllClients(String msg)
	{
		for(int i=0;i<s.clientList.size();i++)
		{
			try
			{
				DataOutputStream out=new DataOutputStream(s.clientList.get(i).getOutputStream());
				out.writeUTF(msg);
			}
			catch(IOException e){System.out.println(e);}
			catch(Exception e){System.out.println(e);}
		}
	}	
}