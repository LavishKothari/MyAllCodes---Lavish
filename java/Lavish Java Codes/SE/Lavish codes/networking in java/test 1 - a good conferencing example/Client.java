import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.net.*;

class LoginFrame extends Frame implements ActionListener
{
	static Hashtable<String,String> passwordHash=new Hashtable<String,String>();
	MainFrame mainFrame;
	Label lName,lPassword;
	TextField tName,tPassword;
	Button bSubmit,bCancel;
	
	LoginFrame(MainFrame mainFrame)
	{
		this.mainFrame=mainFrame;
		
		passwordHash.put("Lavish","Lavi");
		passwordHash.put("Kavleen","Kavi");
		passwordHash.put("Priya","Priya");
		
		setTitle("Login");
		setResizable(false);
		setSize(450,220);
		setLocation(100,100);
		setVisible(true);
		setBackground(new Color(255,255,230));
		setLayout(new GridLayout(4,1,5,5));
		
		lName=new Label("User-Name");
		lName.setFont(new Font("lucida console",Font.PLAIN,20));
		
		lPassword=new Label("Password  ");
		lPassword.setFont(new Font("lucida console",Font.PLAIN,20));
		
		tName=new TextField();
		tName.setFont(new Font("lucida console",Font.PLAIN,20));
		
		tPassword=new TextField();
		tPassword.setFont(new Font("lucida console",Font.PLAIN,20));
		tPassword.setEchoChar('*');
		
		bSubmit=new Button("Submit");
		bSubmit.setFont(new Font("lucida console",Font.PLAIN,16));
		bSubmit.setBackground(new Color(230,230,255));
		
		bCancel=new Button("Cancel");
		bCancel.setFont(new Font("lucida console",Font.PLAIN,16));
		bCancel.setBackground(new Color(255,230,230));
		
		Panel p1=new Panel();
		p1.setLayout(new BorderLayout(10,10));
		p1.add(lName,BorderLayout.WEST);
		p1.add(tName,BorderLayout.CENTER);
		
		Panel p2=new Panel();
		p2.setLayout(new BorderLayout(10,10));
		p2.add(lPassword,BorderLayout.WEST);
		p2.add(tPassword,BorderLayout.CENTER);
		
		Panel p3=new Panel();
		p3.setLayout(new GridLayout(1,4,10,10));
		p3.add(new Label(""));
		p3.add(bSubmit);
		p3.add(bCancel);
		p3.add(new Label(""));
		
		add(p1);
		add(p2);
		add(new Label(""));
		add(p3);
		
		addWindowListener(new MyWindowAdapter());
		bSubmit.addActionListener(this);
		bCancel.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bCancel)
			System.exit(0);
		else if(ae.getSource()==bSubmit)
		{
			while(true)
			{
				if(!passwordHash.containsKey(tName.getText()))
					JOptionPane.showMessageDialog(this,"No such user exist","Login-Error",JOptionPane.ERROR_MESSAGE);
				else if((passwordHash.get(tName.getText())).equals(tPassword.getText()))
				{
					JOptionPane.showMessageDialog(this,"Login Successful","Login-Successful",JOptionPane.INFORMATION_MESSAGE);	
					break;
				}
				else
					JOptionPane.showMessageDialog(this,"Wrong Password","Login-Error",JOptionPane.ERROR_MESSAGE);
				/*
				tName.setText(null);
				tPassword.setText(null);
				*/
				return ;
			}
			this.dispose();
			mainFrame.setVisible(true);
			
			mainFrame.clientName=tName.getText();
			mainFrame.setTitle(tName.getText());
		}
	}
	public Insets getInsets()
	{
		return new Insets(40,20,20,20);
	}
}
class MainFrame extends Frame implements ActionListener,KeyListener
{
	TextArea chatArea;
	TextField chatField;
	String clientName;
	Button bClearChat,bLoadChat,bExitChat;
	Socket server;
	MainFrame(Socket server)
	{
		this.server=server;
		chatArea=new TextArea();
		
		try
		{
			DataOutputStream out=new DataOutputStream(server.getOutputStream());
			DataInputStream in=new DataInputStream(server.getInputStream());
			new ChatThread(in,chatArea);
			out.writeUTF("###@@@");
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
					
		
		setSize(500,500);
		setLocation(100,100);
		setLayout(new BorderLayout(10,10));
		
		chatField=new TextField();
		chatArea.setEditable(false);
		
		bClearChat=new Button("Clear Chat Area");
		bLoadChat=new Button("Load Previous Chat");
		bExitChat=new Button("Exit Chat");
		
		Panel centerPanel=new Panel();
		centerPanel.setLayout(new BorderLayout(10,10));
		centerPanel.add(chatArea,BorderLayout.CENTER);
		centerPanel.add(chatField,BorderLayout.SOUTH);
		
		Panel lowerPanel=new Panel();
		lowerPanel.setLayout(new GridLayout(1,3,30,10));
		lowerPanel.add(bClearChat);
		lowerPanel.add(bLoadChat);
		lowerPanel.add(bExitChat);
		
		add(centerPanel,BorderLayout.CENTER);
		add(lowerPanel,BorderLayout.SOUTH);
		
		addWindowListener(new MyWindowAdapter());
		
		chatField.addKeyListener(this);
		
		bClearChat.addActionListener(this);
		bLoadChat.addActionListener(this);
		bExitChat.addActionListener(this);
	}
	public Insets getInsets()
	{
		return new Insets(40,20,20,20);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bClearChat)
		{
			chatArea.setText("");
		}
		else if(ae.getSource()==bLoadChat)
		{
			try
			{
				DataOutputStream out=new DataOutputStream(server.getOutputStream());
				out.writeUTF("###@@@");
			}
			catch(IOException e){System.out.println(e);}
			catch(Exception e){System.out.println(e);}
		}
		else if(ae.getSource()==bExitChat)
		{
			System.exit(0);
		}
	}
	
	public void keyTyped(KeyEvent ke)
	{	
		if(ke.getKeyChar()=='\n')
		{
			try
			{
				DataInputStream in=new DataInputStream(server.getInputStream());
				DataOutputStream out=new DataOutputStream(server.getOutputStream());
		
				out.writeUTF("[ "+clientName+" ] : "+chatField.getText()+"\n");
				chatField.setText("");
			}
			catch(IOException ioe){}
			
		}
	}
	public void keyReleased(KeyEvent ke)
	{
	}
	public void keyPressed(KeyEvent ke)
	{
	}
}


class ChatThread extends Thread
{
	TextArea chatArea;
	DataInputStream in;
	ChatThread(DataInputStream in,TextArea chatArea)
	{
		this.in=in;
		this.chatArea=chatArea;
		
		Thread th=new Thread(this);
		th.start();
	}
	public void run()
	{
		while(true)
		{
			try
			{
				String msg=in.readUTF();
				if(msg.equals("###@@@"))
					chatArea.setText(in.readUTF());
				else
				{
					String str=chatArea.getText()+msg;
					chatArea.setText(str);
				}
			} 	
			catch(IOException ioe){System.out.println(ioe);}
			catch(Exception e){System.out.println(e);}
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

class Client
{
	public static void main(String args[])throws UnknownHostException, IOException
	{
		new Client();
	}
	
	Client()throws UnknownHostException, IOException
	{
		Socket server=new Socket("localhost",1234);
		
		MainFrame mainFrame=new MainFrame(server);
		LoginFrame loginFrame=new LoginFrame(mainFrame);
		
		/*
		Socket server=new Socket("localhost",1234);
		DataInputStream in=new DataInputStream(server.getInputStream());
		DataOutputStream out=new DataOutputStream(server.getOutputStream());
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{
			out.writeUTF(br.readLine());
			System.out.println("Client Sent");
			System.out.println("Server sent : __________\n"+in.readUTF()+"\n _______this thing");
		}
		*/
	}
}