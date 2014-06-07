import javax.swing.*;
import java.awt.*;
import java.sql.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.*;

class MyFrame extends JFrame implements ListSelectionListener
{
	JLabel mainHeading,lname,lbalance;
	JTextField tname,tbalance,trn[];
	JList jl1;
	JCheckBox chk[];
	JScrollPane jsp1,jsp2;
	String data[];
	int cur_custid[];
	String cur_cname[];
	int cur_bal[];
	int index;
	int trans_count;
	JPanel p121,p122; 
	
	
	
	
	MyFrame()
	{
		super("Banking-Transaction");
		
		try
		{
			String str="jdbc:mysql://localhost:3306/banking";
			Connection cn=DriverManager.getConnection(str,"root","lavikothari");
			
			PreparedStatement pst=cn.prepareStatement("select count(*) as cnt from cust");
			ResultSet rs=pst.executeQuery();
			rs.next();	
			int count=rs.getInt("cnt");
			
			data=new String[count];
			cur_custid=new int[count];
			cur_cname=new String[count];
			cur_bal=new int[count];
			
			pst=cn.prepareStatement("select custid,cname,bal from cust");
			rs=pst.executeQuery();
			int i=0;
			
			while(rs.next())
			{
				data[i]=rs.getInt("custid")+"      ";
				cur_custid[i]=rs.getInt("custid");
				cur_cname[i]=rs.getString("cname");
				cur_bal[i++]=rs.getInt("bal");
				
				//JOptionPane.showMessageDialog(null,"Hello Rakshit Kothari");	
				
			}
		}
		catch(SQLException e)
		{
			JOptionPane.showMessageDialog(null," hello lavish kothari...there was a problem in connecting with database");
		}
		
		mainHeading=new JLabel("DELETE TRANSACTIONS");
		mainHeading.setFont(new Font("lucida console",Font.PLAIN,39));
		
		jl1=new JList(data);
		
		jsp1=new JScrollPane(jl1);
		
		lname=new JLabel("Name");
		lbalance=new JLabel("Balance");
		
		tname=new JTextField();
		tname.setEditable(false);
		tbalance=new JTextField();
		tbalance.setEditable(false);
		
		MainPanel mp=new MainPanel(10,10,10,10);
		mp.setLayout(new BorderLayout(10,10));
		
		JPanel p1=new JPanel(new BorderLayout(5,5));
		
		JPanel p11=new JPanel(new GridLayout(2,1)); // panel for name and balance
		
		JPanel p111=new JPanel(new BorderLayout(18,5)); // for name		
		JPanel p112=new JPanel(new BorderLayout(5,5)); // for balance
		
		JPanel p12=new JPanel(new BorderLayout(5,5));
		
		jsp2=new JScrollPane(p12);
		
		
		p121=new JPanel(new GridLayout(trans_count,1,5,5));	//for checkboxes
		p122=new JPanel(new GridLayout(trans_count,1,5,5));	//for textfields
		
		
		
		
		
		p1.add(p11,BorderLayout.NORTH);
		p11.add(p111);
		p11.add(p112);
		p111.add(lname,BorderLayout.WEST);
		p111.add(tname,BorderLayout.CENTER);
		p112.add(lbalance,BorderLayout.WEST);
		p112.add(tbalance,BorderLayout.CENTER);
		
		
		
		p1.add(jsp2,BorderLayout.CENTER);
		
		jl1.addListSelectionListener(this);
		
		while(true)
		{
		
		for(int i=0;i<trans_count;i++)
		{
			chk[i]=new JCheckBox();
			trn[i]=new JTextField();
			p121.add(chk[i]);
			p122.add(trn[i]);
		}
		
		p12.add(p121,BorderLayout.WEST);
		p12.add(p122,BorderLayout.CENTER);
		
		
		mp.add(p1,BorderLayout.CENTER);
		mp.add(mainHeading,BorderLayout.NORTH);
		mp.add(jsp1,BorderLayout.WEST);
		add(mp);
		jl1.addListSelectionListener(this);
		
		}
	}
	
	public void valueChanged(ListSelectionEvent lse)
	{
		index=jl1.getSelectedIndex();
		System.out.println("index = "+index);
		tname.setText(cur_cname[index]);
		tbalance.setText(cur_bal[index]+"");
	
		
		try
		{
			String str="jdbc:mysql://localhost:3306/banking";
			Connection cn=DriverManager.getConnection(str,"root","lavikothari");
			
			PreparedStatement pst=cn.prepareStatement("select count(*) as cnt from trans where custid=?");
			pst.setInt(1,cur_custid[index]);
			ResultSet rs=pst.executeQuery();
			rs.next();	
			trans_count=rs.getInt("cnt");
			System.out.println("hello=>trans_count"+trans_count);
			
			
			
			trn=new JTextField[trans_count];
			chk=new JCheckBox[trans_count];
		
		
			
			System.out.println("this program is interesting");
		}
		catch(SQLException e)
		{
			JOptionPane.showMessageDialog(null,"there was a problem in connecting with database");
		}
		
	
	}
}

class MainPanel extends JPanel
{
	int top,left,bottom,right;
	MainPanel(int top,int left,int bottom,int right)
	{
		this.top=top;
		this.left=left;
		this.bottom=bottom;
		this.right=right;
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	}
	
	public Insets getInsets()
	{
		return new Insets(top,left,bottom,right);
	}
}


class Main
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mf.setSize(500,500);
		mf.setLocation(100,100);
	}
}