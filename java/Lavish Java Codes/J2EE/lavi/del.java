import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

class MyFrame extends JFrame implements ActionListener,FocusListener,ListSelectionListener
{
	JList myList;
	JScrollPane jsp1,jsp2;
	String []data;
	JLabel lName,lBalance;
	JTextField tName,tBalance;
	MyFrame()
	{
		try
		{
			String str="jdbc:mysql://localhost:3306/banking";
			Connection cn=DriverManager.getConnection(str,"root","lavikothari");  
			PreparedStatement pst=cn.prepareStatement("select count(*) as cnt from cust");
			ResultSet rs=pst.executeQuery();
			rs.next();
			int count=rs.getInt("cnt");
			pst.close();
			//System.out.println("total number of rows in customer table : "+count);
			pst=cn.prepareStatement("select custid from cust");
			rs=pst.executeQuery();
			data=new String[count];
			int i=0;
			while(rs.next())
			{
				data[i++]=""+rs.getInt("custid");
			}
			
			lName=new JLabel("Name");
			lBalance=new JLabel("Balance");
			tName=new JTextField();
			tBalance=new JTextField();
			myList = new JList(data);
			
			MainPanel mp=new MainPanel(10,10,10,10);
			
			JPanel p=new JPanel(new GridLayout(1,2,10,10));
			
			JPanel p1=new JPanel(new GridLayout(2,1,10,10));
			JPanel p11=new JPanel(new BorderLayout(10,10));
			JPanel p12=new JPanel(new BorderLayout(10,10));
				
			p11.add(lName,BorderLayout.WEST);
			p11.add(tName,BorderLayout.CENTER);
			
			p12.add(lBalance,BorderLayout.WEST);
			p12.add(tBalance,BorderLayout.CENTER);
			
			p1.add(p11);
			p1.add(p12);
			JPanel rightPanel=new JPanel(new BorderLayout(10,10));
			
			JPanel p2=new JPanel(new GridLayout(1,1,10,10));
			
			rightPanel.add(p1,BorderLayout.NORTH);
			rightPanel.add(p2,BorderLayout.CENTER);
			
			jsp1=new JScrollPane(myList);
			
			p.add(jsp1);
			p.add(rightPanel);
			
			mp.add(p);
			add(mp);
			
			myList.addListSelectionListener(this);
		}
		catch(SQLException e)
		{
			JOptionPane.showMessageDialog(null,e.getMessage());
			System.exit(2);
		}	
	}
	public void valueChanged(ListSelectionEvent e)
	{
			try
		{
			if(e.getSource()==myList)
			{
				tName.requestFocus();
			
				String str="jdbc:mysql://localhost:3306/banking";
				Connection cn=DriverManager.getConnection(str,"root","lavikothari");
				
				int cid;
				cid=Integer.parseInt(""+myList.getSelectedValue());
				//System.out.println(""+myList.getSelectedValue());
				PreparedStatement pst=cn.prepareStatement("select count(*) as c from trans where custid=?");
				pst.setInt(1,cid);
				ResultSet rs=pst.executeQuery();
				rs.next();
				JOptionPane.showMessageDialog(this,"total number of transanction = "+rs.getInt("c")+"");
			}
		}
		catch(SQLException se)
		{
			JOptionPane.showMessageDialog(null,se.getMessage());
			System.exit(3);
		}
		catch(NumberFormatException ne)
		{
			JOptionPane.showMessageDialog(null,ne.getMessage());
			System.exit(3);
		}
	}
	
	public void focusGained(FocusEvent e)
	{
		/*
		try
		{
			if(e.getSource()==myList)
			{
				tName.requestFocus();
			
				String str="jdbc:mysql://localhost:3306/banking";
				Connection cn=DriverManager.getConnection(str,"root","lavikothari");
				
				int cid;
				cid=Integer.parseInt(""+myList.getSelectedValue());
				//System.out.println(""+myList.getSelectedValue());
				PreparedStatement pst=cn.prepareStatement("select count(*) as c from trans where custid=?");
				pst.setInt(1,cid);
				ResultSet rs=pst.executeQuery();
				rs.next();
				JOptionPane.showMessageDialog(this,"total number of transanction = "+rs.getInt("c")+"");
			}
		}
		catch(SQLException se)
		{
			JOptionPane.showMessageDialog(null,se.getMessage());
			System.exit(3);
		}
		catch(NumberFormatException ne)
		{
			JOptionPane.showMessageDialog(null,ne.getMessage());
			System.exit(3);
		}
		*/
	}
	
	public void focusLost(FocusEvent ae){}
	
	public void actionPerformed(ActionEvent e){}
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

class Main extends JFrame
{
	public static void main(String args[])
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
		}
		catch(ClassNotFoundException e)
		{
			JOptionPane.showMessageDialog(null,"Driver Not Found.. aborting...");
			System.exit(1);
		}

		MyFrame mf=new MyFrame();
		mf.setVisible(true);
		mf.setSize(400,400);
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}