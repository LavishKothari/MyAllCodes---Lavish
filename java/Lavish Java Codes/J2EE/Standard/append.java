import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

class MyFrame extends JFrame implements ActionListener
{
 JTextField tAcn,tNam,tDob,tDoj,tBal;
 JButton bSubmit,bClear,bExit;
 java.util.Date dt;
 
 int actno;
 
 MyFrame()
 {
  super("My Bank - Account Opening");
  setSize(400,400);
  setLocation(200,100);

  try
  {
   String str="jdbc:mysql://localhost:3306/bank";
   Connection cn=DriverManager.getConnection(str,"root","lavikothari");  

   Statement st=cn.createStatement();
   ResultSet rs=st.executeQuery("select max(acctno) as m from cust");

   rs.next();
   if(rs.getInt("m")==0)
    actno=101;  
   else
    actno=rs.getInt("m")+1;
   
   st.close();
   cn.close();
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(null,e.getMessage());
   System.exit(2);
  }

  tAcn=new JTextField(actno+"");
  tAcn.setFont(new Font("lucida console",Font.PLAIN,18));
  tAcn.setEditable(false);

  tNam=new JTextField();
  tNam.setFont(new Font("lucida console",Font.PLAIN,18));

  tDob=new JTextField();
  tDob.setFont(new Font("lucida console",Font.PLAIN,18));

  dt=new java.util.Date();
  String s=String.format("%d/%02d/%02d",dt.getYear()+1900,dt.getMonth()+1,dt.getDate());
 
  tDoj=new JTextField(s);
  tDoj.setFont(new Font("lucida console",Font.PLAIN,18));
  tDoj.setEditable(false);

  tBal=new JTextField();
  tBal.setFont(new Font("lucida console",Font.PLAIN,18));

  bSubmit=new JButton("Submit");
  bSubmit.setFont(new Font("lucida console",Font.PLAIN,18));

  bClear=new JButton("Clear");
  bClear.setFont(new Font("lucida console",Font.PLAIN,18));

  bExit=new JButton("Exit");
  bExit.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l1=new JLabel("Acct. No.");
  l1.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l2=new JLabel("Name");
  l2.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l3=new JLabel("D-O-B");
  l3.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l4=new JLabel("D-O-J");
  l4.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l5=new JLabel("Balance");
  l5.setFont(new Font("lucida console",Font.PLAIN,18));

  MainPanel mp=new MainPanel(20,10,10,10);
  add(mp);

  mp.setLayout(new GridLayout(7,1,10,10));
  
  JPanel p1=new JPanel();
  p1.setLayout(new BorderLayout(5,5));
   JPanel p11=new JPanel();
   p11.setLayout(new GridLayout(1,3,5,5));
   p11.add(tAcn);
   p11.add(new JLabel());
   p11.add(new JLabel());
  p1.add(l1,BorderLayout.WEST);
  p1.add(p11,BorderLayout.CENTER);

  JPanel p2=new JPanel();
  p2.setLayout(new BorderLayout(60,5));
  p2.add(l2,BorderLayout.WEST);
  p2.add(tNam,BorderLayout.CENTER);
         
  JPanel p3=new JPanel();
  p3.setLayout(new BorderLayout(50,5));
   JPanel p31=new JPanel();
   p31.setLayout(new GridLayout(1,2,5,5));
   p31.add(tDob);
   p31.add(new JLabel());
  p3.add(l3,BorderLayout.WEST);
  p3.add(p31,BorderLayout.CENTER);


 
  JPanel p4=new JPanel();
  p4.setLayout(new BorderLayout(50,5));
   JPanel p41=new JPanel();
   p41.setLayout(new GridLayout(1,2,5,5));
   p41.add(tDoj);
   p41.add(new JLabel());
  p4.add(l4,BorderLayout.WEST);
  p4.add(p41,BorderLayout.CENTER);



  JPanel p5=new JPanel();
  p5.setLayout(new BorderLayout(30,5));
   JPanel p51=new JPanel();
   p51.setLayout(new GridLayout(1,2,5,5));
   p51.add(tBal);
   p51.add(new JLabel());
  p5.add(l5,BorderLayout.WEST);
  p5.add(p51,BorderLayout.CENTER);



  JPanel p6=new JPanel();
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

 }

 public void actionPerformed(ActionEvent ae)
 {
  if(ae.getSource()==bExit)
  {
   dispose();
   System.exit(0);
  }

  if(ae.getSource()==bClear)
  {
   tNam.setText("");
   tDob.setText("");
   tDoj.setText("");
   tBal.setText("");
  }
  else
  if(ae.getSource()==bSubmit)
  {
   try
   {
    String str="jdbc:mysql://localhost:3306/bank";
    Connection cn=DriverManager.getConnection(str,"root","lavikothari");  

    /*
    Statement st=cn.createStatement();
    str="insert into cust(acctno,cname,dob,doj,balance) values('"+
        tAcn.getText()+"','"+
        tNam.getText()+"','"+
        tDob.getText()+"','"+
        tDoj.getText()+"','"+
        tBal.getText()+"')";


    st.executeUpdate(str);    
    st.close();
    */

    PreparedStatement pst=cn.prepareStatement("insert into cust values(?,?,?,?,?)");
    pst.setInt(1,actno);
    pst.setString(2,tNam.getText());
    
    java.util.Date dtu=new java.util.Date(tDob.getText());
    java.sql.Date dts=new java.sql.Date(dtu.getTime());  
    pst.setDate(3,dts);

    dts=new java.sql.Date(dt.getTime());
    pst.setDate(4,dts);

    int bal=0;
    try
    {
     bal=Integer.parseInt(tBal.getText());
    }
    catch(NumberFormatException e)
    {
     JOptionPane.showMessageDialog(this,"invalid balance");
     tBal.select(0,tBal.getText().length());
     tBal.requestFocus();
     return;
    }   

    pst.setInt(5,bal);

    pst.executeUpdate();

    pst.close();
    cn.close();
    JOptionPane.showMessageDialog(this,"Record added successfully..");
    actno++;
    tAcn.setText(actno+"");    
    tNam.setText("");
    tDob.setText("");
    tDoj.setText("");
    tBal.setText("");
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

class append
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