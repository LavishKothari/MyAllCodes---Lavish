import java.io.*;
import javax.swing.*;
import java.util.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

class Client extends WindowAdapter implements ActionListener,KeyListener
{
	static Hashtable<String,String> passwordHash=new Hashtable<String,String>();
	JLabel lName,lPassword;
	JTextField tName,tPassword,chatField;
	JButton bSubmit,bCancel;
	
	JTextArea chatArea;
	
	Frame f;
	Frame loginFrame;
	Panel centerPanel;
	
	Socket server;
	DataInputStream in;
	DataOutputStream out;
	
	Client()
	{
		try
		{
			server=new Socket("localhost",1234);
		}
		catch(UnknownHostException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
		
		try
		{
			in=new DataInputStream(server.getInputStream());
			out=new DataOutputStream(server.getOutputStream());
		}
		catch(IOException e){System.out.println(e);}
		catch(Exception e){System.out.println(e);}
			
		chatField=new JTextField();
		chatArea=new JTextArea();
		chatArea.setEditable(false);
		
		f=new Frame();
		f.setSize(500,500);
		f.setLocation(100,100);
		
		centerPanel=new Panel();
		centerPanel.setLayout(new BorderLayout(10,10));
		centerPanel.add(chatArea,BorderLayout.CENTER);
		centerPanel.add(chatField,BorderLayout.SOUTH);
		
		f.setLayout(new BorderLayout(10,10));
		
		f.add(centerPanel,BorderLayout.CENTER);
		
		loginFrame=new Frame();
		loginFrame.setTitle("Login");
		loginFrame.setResizable(false);
		loginFrame.setSize(450,180);
		loginFrame.setLocation(100,100);
		loginFrame.setVisible(true);
		loginFrame.setBackground(new Color(255,255,230));
		loginFrame.setLayout(new GridLayout(4,1,5,5));
		
		lName=new JLabel("User-Name");
		lName.setFont(new Font("lucida console",Font.PLAIN,20));
		
		lPassword=new JLabel("Password ");
		lPassword.setFont(new Font("lucida console",Font.PLAIN,20));
		
		tName=new JTextField();
		tName.setFont(new Font("lucida console",Font.PLAIN,20));
		
		tPassword=new JTextField();
		tPassword.setFont(new Font("lucida console",Font.PLAIN,20));
		
		bSubmit=new JButton("Submit");
		bSubmit.setFont(new Font("lucida console",Font.PLAIN,16));
		bSubmit.setBackground(new Color(230,230,255));
		
		bCancel=new JButton("Cancel");
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
		p3.add(new JLabel(""));
		p3.add(bSubmit);
		p3.add(bCancel);
		p3.add(new JLabel(""));
		
		loginFrame.add(p1);
		loginFrame.add(p2);
		loginFrame.add(new JLabel(""));
		loginFrame.add(p3);
		
		loginFrame.addWindowListener(this);
		f.addWindowListener(this);
		
		bSubmit.addActionListener(this);
		bCancel.addActionListener(this);
		chatField.addKeyListener(this);
	}
	public void keyTyped(KeyEvent ke)
	{	
		if(ke.getKeyChar()=='\n')
		{	
			try
			{	
				out.writeUTF("[ "+tName.getText()+" ] : "+chatField.getText()+"\n");
				chatField.setText("");
			}
			catch(FileNotFoundException e){}
			catch(IOException ioe){}
			new ChatThread(in,chatArea);
		}
	}
	public void keyReleased(KeyEvent ke)
	{
	}
	public void keyPressed(KeyEvent ke)
	{
	}
	
	public static void main(String []args)throws UnknownHostException,IOException
	{
		passwordHash.put("Lavish","Lavi");
		passwordHash.put("Rakshit","Rakshi");
		passwordHash.put("Manoj","Manu");
		
		new Client();
	}
	
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bSubmit)
		{
			while(true)
			{
				if(!passwordHash.containsKey(tName.getText()))
					JOptionPane.showMessageDialog(loginFrame,"No such user exist","Login-Error",JOptionPane.ERROR_MESSAGE);
				else if((passwordHash.get(tName.getText())).equals(tPassword.getText()))
				{
					JOptionPane.showMessageDialog(loginFrame,"Login Successful","Login-Successful",JOptionPane.INFORMATION_MESSAGE);	
					break;
				}
				else
					JOptionPane.showMessageDialog(loginFrame,"Wrong Password","Login-Error",JOptionPane.ERROR_MESSAGE);
				tName.setText("");
				tPassword.setText("");
				return ;
			}
			loginFrame.dispose();
			f.setVisible(true);
			f.setTitle(tName.getText());
			try
			{
				chatArea.setText(in.readUTF());
			}
			catch(IOException ioe){System.out.println(ioe);}
			catch(Exception e){System.out.println(e);}
		}
		else if(ae.getSource()==bCancel)
		{
			System.exit(0);
		}
	}
}

class ChatThread extends Thread
{
	JTextArea chatArea;
	DataInputStream in;
	ChatThread(DataInputStream in,JTextArea chatArea)
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
				String str=in.readUTF();
				System.out.println(str);
				chatArea.setText(str);
			} 	
			catch(IOException ioe){System.out.println(ioe);}
			catch(Exception e){System.out.println(e);}
		}
	}
}