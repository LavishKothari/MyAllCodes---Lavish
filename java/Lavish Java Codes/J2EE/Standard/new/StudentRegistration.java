/*
	this program illustrates type4
	creating a connection with the database and then 
	executing an SQL query
	printing the corresponding result
	
	here the sql query is regarding filling 
	in the values asked by the user 
	as a new row in the database;
*/
import java.io.*;
import java.sql.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class MyFrame extends JFrame implements ActionListener
{
	JTextField tname,taddress,tage;
	JButton submit;
	JLabel name,address,age;
	MyFrame()
	{
		super("ABC School - Registration form");
		setSize(500,500);
		setLocation(100,100);
		
		name=new JLabel("Name");
		age=new JLabel("Age");
		address=new JLabel("Address");
		
		tname=new JTextField(10);
		taddress=new JTextField();
		tage=new JTextField();
		
		submit=new JButton("Add");
		
		JPanel p1=new JPanel();
		JPanel p11=new JPanel();
		JPanel p12=new JPanel();
		JPanel p2=new JPanel();
		JPanel p21=new JPanel();
		JPanel p22=new JPanel();
		JPanel p3=new JPanel();
		JPanel p31=new JPanel();
		JPanel p32=new JPanel();
		JPanel p4=new JPanel();
		
		JPanel p=new JPanel();
		
		p1.setLayout(new GridLayout(1,2,5,5));
		p11.setLayout(new GridLayout(1,1,5,5));
		p12.setLayout(new GridLayout(1,1,5,5));
		
		p2.setLayout(new GridLayout(1,2,5,5));
		p21.setLayout(new GridLayout(1,1,5,5));
		p22.setLayout(new GridLayout(1,1,5,5));
		
		p3.setLayout(new GridLayout(1,2,5,5));
		p31.setLayout(new GridLayout(1,1,5,5));
		p32.setLayout(new GridLayout(1,1,5,5));
		
		p4.setLayout(new FlowLayout(FlowLayout.CENTER));
		
		p.setLayout(new GridLayout(4,1,5,5));
		
		p11.add(name);
		p12.add(tname);
		
		p21.add(address);
		p22.add(taddress);
		
		p31.add(age);
		p32.add(tage);
		
		p1.add(p11);
		p1.add(p12);
		
		p2.add(p21);
		p2.add(p22);
		
		p3.add(p31);
		p3.add(p32);
		
		p4.add(submit);

		p.add(p1);
		p.add(p2);
		p.add(p3);
		p.add(p4);
		
		MainPanel mp=new MainPanel(10,5,5,5);
		
		mp.add(p);
		add(mp);
		submit.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		try
		{
			Connection cn=DriverManager.getConnection("jdbc:mysql://localhost:3360/registration","root","lavikothari");
			PreparedStatement pst=cn.prepareStatement("insert into stud values(?,?,?)");
			pst.setString(1,tname.getText());
			pst.setString(2,taddress.getText());
			pst.setInt(3,Integer.parseInt(tage.getText()));
			pst.executeUpdate();
			pst.close();
			cn.close();
		}
		catch(SQLException se)
		{
			System.out.println("you got an exception Lavish : "+se.getMessage());
		}
		catch(NumberFormatException ne){}
	}
}

class MainPanel extends JPanel
{
	int top,left,bottom,right;
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	}
	public MainPanel(int top,int left,int bottom,int right)
	{
		this.top=top;
		this.left=left;
		this.bottom=bottom;
		this.right=right;
	}
	
	public Insets getInsets()
	{
		return new Insets(top,left,bottom,right);
	}
}

class StudentRegistration
{
	public static void main(String []args)
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
		}
		catch(ClassNotFoundException e)
		{
			System.err.println("you have an exception dear : " + e);
		}
		
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
		
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}