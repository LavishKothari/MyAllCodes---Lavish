import javax.swing.*;
import java.sql.*;
import java.awt.*;
import java.sql.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.*;

class MyFrame extends JFrame implements ActionListener,ListSelectionListener,ItemListener
{
	int cur_custid[],cur_bal[],index,trans_count,newBalance;
	JLabel mainHeading,lname,lbalance;
	JTextField tname,tbalance,trn[];
	JList jl1;
	JCheckBox chk[];
	JScrollPane jsp1,jsp2;
	String data[],cur_cname[];
	JButton bexit,bdelete;
	
	MyFrame()
	{
		super("Banking-Transaction");
		trn=new JTextField[100];
		chk=new JCheckBox[100];
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
			}
		}
		catch(SQLException e)
		{
			JOptionPane.showMessageDialog(null," hello lavish kothari...there was a problem in connecting with database");
		}
		
		mainHeading=new JLabel("      DELETE   TRANSACTIONS");
		mainHeading.setFont(new Font("rosewood std regular",Font.PLAIN,50));
		
		jl1=new JList(data);
		
		jsp1=new JScrollPane(jl1);
		
		lname=new JLabel("Name     ");
		lname.setFont(new Font("lucida console",Font.PLAIN,20));
		lbalance=new JLabel("Balance   ");
		lbalance.setFont(new Font("lucida console",Font.PLAIN,20));
		
		tname=new JTextField();
		tname.setEditable(false);
		tbalance=new JTextField();
		tbalance.setEditable(false);
		
		bexit=new JButton("Exit");
		bdelete=new JButton("Delete");
		
		MainPanel mp=new MainPanel(10,10,10,10);
		mp.setLayout(new BorderLayout(10,10));
		
		JPanel p1=new JPanel(new BorderLayout(5,5));
		
		JPanel p11=new JPanel(new GridLayout(2,1)); // panel for name and balance
		
		JPanel p111=new JPanel(new BorderLayout(18,5)); // for name		
		JPanel p112=new JPanel(new BorderLayout(5,5)); // for balance
		
		JPanel p12=new JPanel(new BorderLayout(5,5));
		
		jsp2=new JScrollPane(p12);
		
		p1.add(p11,BorderLayout.NORTH);
		p11.add(p111);
		p11.add(p112);
		p111.add(lname,BorderLayout.WEST);
		p111.add(tname,BorderLayout.CENTER);
		p112.add(lbalance,BorderLayout.WEST);
		p112.add(tbalance,BorderLayout.CENTER);
		
		
		
		p1.add(jsp2,BorderLayout.CENTER);
		
		JPanel p13=new JPanel(new GridLayout(1,4,5,5));
		
		
		jl1.addListSelectionListener(this);
		
		JPanel p121=new JPanel(new GridLayout(100,1,1,1));	//for checkboxes
		JPanel p122=new JPanel(new GridLayout(100,1,1,1));	//for textfields
			
		
		for(int i=0;i<100;i++)
		{
			
			chk[i]=new JCheckBox();
			trn[i]=new JTextField();
			p121.add(chk[i]);
			
			p122.add(trn[i]);
			trn[i].setVisible(false);
			chk[i].setVisible(false);
			chk[i].addItemListener(this);
		}
			
		p13.add(new JLabel(""));
		p13.add(bdelete);
		p13.add(bexit);		
		p13.add(new JLabel(""));
		
		p1.add(p13,BorderLayout.SOUTH);
		
		p12.add(p121,BorderLayout.WEST);
		p12.add(p122,BorderLayout.CENTER);
		
		
		mp.add(p1,BorderLayout.CENTER);
		mp.add(mainHeading,BorderLayout.NORTH);
		mp.add(jsp1,BorderLayout.WEST);
		add(mp);
		
		bexit.addActionListener(this);
		bdelete.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==bexit)
		{
			System.exit(1);
		}
		
		if(e.getSource()==bdelete)
		{
			try
			{
				/* first of all updating new balance in cust table.*/
				
				String str="jdbc:mysql://localhost:3306/banking";
				Connection cn=DriverManager.getConnection(str,"root","lavikothari");
				PreparedStatement pst=cn.prepareStatement("update cust set bal=? where custid=?");
				pst.setInt(1,Integer.parseInt(tbalance.getText()));
				pst.setInt(2,cur_custid[index]);
				pst.executeUpdate();
				/* update in cust for new balance is successful */
				
				int limit=trans_count;
				for(int i=1;i<limit+1;i++)
					if(chk[i].isSelected())
					{
						StringTokenizer stz=new StringTokenizer(trn[i].getText());
						int abc=Integer.parseInt(stz.nextToken());
						pst=cn.prepareStatement("delete from trans where transid=?");
						pst.setInt(1,abc);
						pst.executeUpdate();
						
						index=jl1.getSelectedIndex();
						
						cn=DriverManager.getConnection(str,"root","lavikothari");
						pst=cn.prepareStatement("select count(*) as cnt from trans where custid=?");
						pst.setInt(1,cur_custid[index]);
						ResultSet rs=pst.executeQuery();
						rs.next();	
						trans_count=rs.getInt("cnt");
						
						pst=cn.prepareStatement("select*from trans where custid=?");
						pst.setInt(1,cur_custid[index]);
						rs=pst.executeQuery();
								
						for(int j=0;j<100;j++)
						{
							if(j>trans_count)
							{
								trn[j].setVisible(false);
								chk[j].setVisible(false);
							}
							else
							{
								if(j==0)
								{
								
									trn[j].setVisible(true);
									trn[j].setEditable(false);
									trn[j].setFont(new Font("lucida console",Font.PLAIN,20));
									trn[j].setText("TransId\tDate_of_trans\tCR/DR\tAmount\tStatus");
									continue;
								}
								trn[j].setVisible(true);
								trn[j].setEditable(false);
								chk[j].setVisible(true);
								
								/*write code here to unselect the checkbox IMPORTANT*/
								chk[j].setSelected(false);
								rs.next();
								java.sql.Date dt=rs.getDate("dot");
								int d=dt.getDate();
								int m=dt.getMonth()+1;
								int y=dt.getYear()+1900;
				
								trn[j].setText(String.format("%-30d %-1d-%-1d-%-50d %-20s %-28d %-40s",rs.getInt("transid"),d,m,y,rs.getString("transtype"),rs.getInt("amt"),rs.getString("Status")));
							}
						}
					}				
			}
			catch(NumberFormatException ex)
			{
				JOptionPane.showMessageDialog(null,"enter a valid number");
			}
			catch(SQLException ex)
			{
				JOptionPane.showMessageDialog(null,"there was some error in connection");
			}
			
		}				
	}
	
	public void itemStateChanged(ItemEvent ie)
	{ 
		newBalance=cur_bal[index];
		StringTokenizer stz;
		for(int i=1;i<trans_count+1;i++)
		{
			try
			{
				stz=new StringTokenizer(trn[i].getText());
				
				int tid = Integer.parseInt(stz.nextToken());
				stz.nextElement();
				String ttype=stz.nextToken();
				int a=Integer.parseInt(stz.nextToken());
				String st=stz.nextToken();
				if(chk[i].isSelected() && st.equals("Success"))
				{
					if(ttype.equals("CR"))
						newBalance-=a;
					else
						newBalance+=a;
					
					tbalance.setText(newBalance+"");
				}
			
			}
			catch(NumberFormatException e)
			{
				JOptionPane.showMessageDialog(null,"enter a valid number");
			}
		}
	}
	
	public void valueChanged(ListSelectionEvent lse)
	{
		
		index=jl1.getSelectedIndex();
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
			
			pst=cn.prepareStatement("select*from trans where custid=?");
			pst.setInt(1,cur_custid[index]);
			rs=pst.executeQuery();
					
			for(int i=0;i<100;i++)
			{
				if(i>trans_count)
				{
					trn[i].setVisible(false);
					chk[i].setVisible(false);
				}
				else
				{
					if(i==0)
					{
						trn[i].setVisible(true);
						trn[i].setEditable(false);
						trn[i].setFont(new Font("lucida console",Font.PLAIN,20));
						trn[i].setText("TransId\tDate_of_trans\tCR/DR\tAmount\tStatus");
						continue;
					}
					trn[i].setVisible(true);
					trn[i].setEditable(false);
					chk[i].setVisible(true);
					rs.next();
					java.sql.Date dt=rs.getDate("dot");
					int d=dt.getDate();
					int m=dt.getMonth()+1;
					int y=dt.getYear()+1900;
	
					trn[i].setText(String.format("%-30d %-1d-%-1d-%-50d %-20s %-28d %-40s",rs.getInt("transid"),d,m,y,rs.getString("transtype"),rs.getInt("amt"),rs.getString("Status")));
				}
			}
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
		mf.setSize(700,400);
		mf.setLocation(100,100);
	}
}