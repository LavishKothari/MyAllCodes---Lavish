import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

class MyFrame extends JFrame implements ActionListener,FocusListener
{
 JTextField tTrn,tAcn,tNam,tAmt;
 JButton bSubmit,bClear,bExit;
 JRadioButton bCR,bDR;
 
 boolean doSubmit;
 
 int tId,acn;
 int balance;
 
 MyFrame()
 {
  super("My Bank - Transaction");
  setSize(400,500);
  setLocation(200,100);

  try
  {
   String str="jdbc:mysql://localhost:3306/banking";
   Connection cn=DriverManager.getConnection(str,"root","lavikothari");  

   Statement st=cn.createStatement();
   ResultSet rs=st.executeQuery("select max(transid) as m from trans");

   rs.next();
   if(rs.getInt("m")==0)
    tId=101;  
   else
    tId=rs.getInt("m")+1;
   
   st.close();
   cn.close();
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(null,e.getMessage());
   System.exit(2);
  }

  tTrn=new JTextField(tId+"");
  tTrn.setFont(new Font("lucida console",Font.PLAIN,18));
  tTrn.setEditable(false);

  tAcn=new JTextField();
  tAcn.setFont(new Font("lucida console",Font.PLAIN,18));

  tNam=new JTextField();
  tNam.setFont(new Font("lucida console",Font.PLAIN,18));

  tAmt=new JTextField();
  tAmt.setFont(new Font("lucida console",Font.PLAIN,18));

  bSubmit=new JButton("Submit");
  bSubmit.setFont(new Font("lucida console",Font.PLAIN,18));

  bClear=new JButton("Clear");
  bClear.setFont(new Font("lucida console",Font.PLAIN,18));

  bExit=new JButton("Exit");
  bExit.setFont(new Font("lucida console",Font.PLAIN,18));

  bCR=new JRadioButton("CR");
  bCR.setFont(new Font("lucida console",Font.PLAIN,18));

  bDR=new JRadioButton("DR");
  bDR.setFont(new Font("lucida console",Font.PLAIN,18));

  ButtonGroup bg=new ButtonGroup();
  bg.add(bCR);
  bg.add(bDR);

  JLabel l1=new JLabel("Trans Id");
  l1.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l2=new JLabel("Acct. No");
  l2.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l3=new JLabel("Name");
  l3.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l4=new JLabel("Amount");
  l4.setFont(new Font("lucida console",Font.PLAIN,18));

  MainPanel mp=new MainPanel(20,10,10,10);
  add(mp);

  mp.setLayout(new GridLayout(7,1,1,1));
  
  MainPanel p1=new MainPanel(12,1,12,1);
  p1.setLayout(new BorderLayout(5,5));
   JPanel p11=new JPanel();
   p11.setLayout(new GridLayout(1,3,5,5));
   p11.add(tTrn);
   p11.add(new JLabel());
   p11.add(new JLabel());
  p1.add(l1,BorderLayout.WEST);
  p1.add(p11,BorderLayout.CENTER);

  MainPanel p2=new MainPanel(12,1,12,1);
  p2.setLayout(new BorderLayout(5,5));
   JPanel p21=new JPanel();
   p21.setLayout(new GridLayout(1,3,5,5));
   p21.add(tAcn);
   p21.add(new JLabel());
   p21.add(new JLabel());
  p2.add(l2,BorderLayout.WEST);
  p2.add(p21,BorderLayout.CENTER);

  MainPanel p3=new MainPanel(12,1,12,1);
  p3.setLayout(new BorderLayout(45,5));
  p3.add(l3,BorderLayout.WEST);
  p3.add(tNam,BorderLayout.CENTER);
         
  JPanel p4=new JPanel();
  p4.setLayout(new GridLayout(1,3,5,5));
  p4.add(bCR);
  p4.add(bDR);


  p4.add(new JLabel());
  p4.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black,2),"Transaction Type")); 

  MainPanel p5=new MainPanel(12,1,12,1);
  p5.setLayout(new BorderLayout(40,5));
   JPanel p51=new JPanel();
   p51.setLayout(new GridLayout(1,2,5,5));
   p51.add(tAmt);
   p51.add(new JLabel());
  p5.add(l4,BorderLayout.WEST);
  p5.add(p51,BorderLayout.CENTER);



  MainPanel p6=new MainPanel(12,1,12,1);
  p6.setLayout(new GridLayout(1,3,10,10));
  p6.add(bSubmit);
  p6.add(bClear);

  p6.add(bExit);

  mp.add(p1);
  mp.add(p2);
  mp.add(p3);
  mp.add(p4);
  mp.add(p5);
  mp.add(new JLabel());
  mp.add(p6);

  bSubmit.addActionListener(this);
  bClear.addActionListener(this);
  bExit.addActionListener(this);

  bCR.addFocusListener(this);  
  bDR.addFocusListener(this); 
  tAmt.addFocusListener(this); 
  bSubmit.addFocusListener(this);    
  tNam.addFocusListener(this);
 }
 
 public void focusGained(FocusEvent fe)
 {
  doSubmit=false;
  if(fe.getSource()==bCR||fe.getSource()==bDR||fe.getSource()==tAmt||fe.getSource()==bSubmit||fe.getSource()==tNam)
  {
   try
   {
    acn=Integer.parseInt(tAcn.getText());
   
    String str="jdbc:mysql://localhost:3306/banking";
    Connection cn=DriverManager.getConnection(str,"root","lavikothari");  
    PreparedStatement pst=cn.prepareStatement("select * from cust where custid = ?");
    pst.setInt(1,acn);
    ResultSet rs=pst.executeQuery();
    if(rs.next())
    {
	 doSubmit=true;
     tNam.setText(rs.getString("cname"));
  	 balance=rs.getInt("bal");
    }
    else
    { 
     tAcn.select(0,tAcn.getText().length());
     tAcn.requestFocus();  
     JOptionPane.showMessageDialog(this,"Account No. Not Found");
     return;
    }
   }
   catch(NumberFormatException e)
   {
    tAcn.select(0,tAcn.getText().length());
    tAcn.requestFocus();  
    JOptionPane.showMessageDialog(this,"account no cannot be blank or non numeric");
    return;
   }
   catch(SQLException e)
   {
    tAcn.select(0,tAcn.getText().length());
    tAcn.requestFocus();  
    JOptionPane.showMessageDialog(this,e.getMessage());
   }
  }
 }
 
 public void focusLost(FocusEvent fe){}

 public void actionPerformed(ActionEvent ae)
 {
  if(ae.getSource()==bExit)
  {
   dispose();
   System.exit(0);
  }

  if(ae.getSource()==bClear)
  {
   tAcn.setText("");
   tNam.setText("");
   tAmt.setText("");
   tAcn.requestFocus();
  }
  else
  if(ae.getSource()==bSubmit)
  {  
   if(!doSubmit)
    return;
	
   String trn;
   int amt;
   try
   {
    if(bCR.isSelected())
	 trn="CR";
	else
	if(bDR.isSelected())
	 trn="DR";
	else
	{
     JOptionPane.showMessageDialog(this,"Transaction Type ?");
	 bCR.requestFocus();
     return;
	}
    
	amt=Integer.parseInt(tAmt.getText());
	    
	String status="Success";	
	if(trn=="DR")
    {
     if(amt>balance)
	 {
	  status="Failed";
      JOptionPane.showMessageDialog(this,"Insufficient Fund.. Transaction Failed !");
	 }
     else
      balance=balance-amt;
    }	
	else
     balance=balance+amt;

    String str="jdbc:mysql://localhost:3306/banking";
    Connection cn=DriverManager.getConnection(str,"root","lavikothari");  
	PreparedStatement pst;
	
    if(status=="Success")
	{
     pst=cn.prepareStatement("update cust set bal = ? where custid = ?");
     pst.setInt(1,balance);
     pst.setInt(2,acn);     
     pst.executeUpdate();
     pst.close();
     cn.close();
    }
	
	java.util.Date dt=new java.util.Date();
	java.sql.Date sdt=new java.sql.Date(dt.getTime());
	
    cn=DriverManager.getConnection(str,"root","lavikothari");  
    pst=cn.prepareStatement("insert into trans values (?,?,?,?,?,?)");
	pst.setInt(1,tId++);
	pst.setInt(2,acn);
	pst.setDate(3,sdt);
	pst.setString(4,trn);
	pst.setInt(5,amt);
	pst.setString(6,status);
    pst.executeUpdate();
    pst.close();
    cn.close();

	tAcn.setText("");
    tNam.setText("");
    tAmt.setText("");
    tTrn.setText(tId+"");
	
	JOptionPane.showMessageDialog(this,"Record(s) Updated Successfully");
	
	tAcn.requestFocus();
   }
   catch(NumberFormatException e)
   {
    JOptionPane.showMessageDialog(this,"Amount cannot be Blank or Non-Numeric");
    tAmt.select(0,tAmt.getText().length());
	tAmt.requestFocus();
   }
   catch(SQLException e)
   {
    JOptionPane.showMessageDialog(this,e.getMessage());
   }   
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

class trans
{
 public static void main(String arg[])
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
  mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }
}