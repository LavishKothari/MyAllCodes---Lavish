import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

class MyFrame extends JFrame implements ActionListener,KeyListener
{
 JTextField tRol,tNam,tDob,tBrn,tMrk,tGoto;
 JButton bFrst,bLast,bPrev,bNext;

 int tot,cur;
 ResultSet rs;

 MyFrame()
 {
  setSize(500,270);
  setLocation(200,100);

  tRol=new JTextField();
  tRol.setFont(new Font("lucida console",Font.PLAIN,18));

  tBrn=new JTextField();
  tBrn.setFont(new Font("lucida console",Font.PLAIN,18));

  tNam=new JTextField();
  tNam.setFont(new Font("lucida console",Font.PLAIN,18));

  tDob=new JTextField();
  tDob.setFont(new Font("lucida console",Font.PLAIN,18));

  tMrk=new JTextField();
  tMrk.setFont(new Font("lucida console",Font.PLAIN,18));

  bFrst=new JButton("|<<");
  bFrst.setFont(new Font("lucida console",Font.PLAIN,18));

  bLast=new JButton(">>|");
  bLast.setFont(new Font("lucida console",Font.PLAIN,18));

  bPrev=new JButton("<<");
  bPrev.setFont(new Font("lucida console",Font.PLAIN,18));

  bNext=new JButton(">>");
  bNext.setFont(new Font("lucida console",Font.PLAIN,18));

  tGoto=new JTextField();
  tGoto.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l1=new JLabel("Roll #");
  l1.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l2=new JLabel("Branch");
  l2.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l3=new JLabel("Name");
  l3.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l4=new JLabel("DOB");
  l4.setFont(new Font("lucida console",Font.PLAIN,18));

  JLabel l5=new JLabel("Marks");
  l5.setFont(new Font("lucida console",Font.PLAIN,18));

  MyPanel mp=new MyPanel(25,10,10,10);  
  add(mp);
  mp.setLayout(new GridLayout(5,1,10,10));

  JPanel p1=new JPanel();
  p1.setLayout(new GridLayout(1,2,50,5));
  
   JPanel p11=new JPanel();
   p11.setLayout(new BorderLayout(2,2));
   p11.add(l1,BorderLayout.WEST);
   p11.add(tRol,BorderLayout.CENTER);
  
   JPanel p12=new JPanel();
   p12.setLayout(new BorderLayout(2,2));
   p12.add(l2,BorderLayout.WEST);
   p12.add(tBrn,BorderLayout.CENTER);

  p1.add(p11);
  p1.add(p12);
  
  JPanel p2=new JPanel();
  p2.setLayout(new BorderLayout(23,5));
  p2.add(l3,BorderLayout.WEST);
  p2.add(tNam,BorderLayout.CENTER);

  JPanel p3=new JPanel();
  p3.setLayout(new GridLayout(1,2,50,5));
  
   JPanel p31=new JPanel();
   p31.setLayout(new BorderLayout(35,2));
   p31.add(l4,BorderLayout.WEST);
   p31.add(tDob,BorderLayout.CENTER);

   JPanel p32=new JPanel();
   p32.setLayout(new BorderLayout(15,2));
   p32.add(l5,BorderLayout.WEST);
   p32.add(tMrk,BorderLayout.CENTER);

  p3.add(p31);
  p3.add(p32); 

  JPanel p4=new JPanel();
  p4.setLayout(new GridLayout(1,5,5,5));
  p4.add(bFrst);
  p4.add(bPrev);
  p4.add(bNext);
  p4.add(bLast);
  p4.add(tGoto);

  mp.add(p1);
  mp.add(p2);
  mp.add(p3);
  mp.add(new JLabel());
  mp.add(p4);

  try
  {
   Connection cn=DriverManager.getConnection("jdbc:odbc:dmatics",null,null); 
   Statement st=cn.createStatement();
   rs=st.executeQuery("select count(*) as cnt from studs");
   rs.next();
   tot=rs.getInt("cnt");
   
   if(tot==0)
   {
    JOptionPane.showMessageDialog(this,"No Records in the Database... aborting..");
    System.exit(2);
   }
  
   st.close();

   st=cn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
   rs=st.executeQuery("select * from studs");
   rs.next();
   cur=1;
   dispRec();
   
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(this,e.getMessage());
  }

  bFrst.addActionListener(this);
  bPrev.addActionListener(this);
  bNext.addActionListener(this);
  bLast.addActionListener(this);
  tGoto.addKeyListener(this); 
 }

 public void keyPressed(KeyEvent ke){}

 public void keyTyped(KeyEvent ke){}

 public void keyReleased(KeyEvent ke)
 {
  int n=0;
  try
  {
   n=Integer.parseInt(tGoto.getText());
  }
  catch(NumberFormatException e)
  {
   JOptionPane.showMessageDialog(this,"Invalid Record #");
  }
  
  if(n==0 || n>tot)
   JOptionPane.showMessageDialog(this,"Invalid Record #");
  else
  {
   try
   {
    rs.absolute(n);
    cur=n;
    dispRec();  
   }
   catch(SQLException e){}
  } 
 }
 
 public void actionPerformed(ActionEvent ae)
 {
  try
  { 
   if(ae.getSource()==bFrst)
   {
    rs.first();
    cur=1;   
   } 
   else
   if(ae.getSource()==bPrev)
   {
    if(!rs.isFirst())
    {
     rs.previous();
     cur--;
    } 
   } 
   else
   if(ae.getSource()==bNext)
   {
    if(!rs.isLast())
    {
     rs.next();
     cur++;
    }   
   } 
   else
   if(ae.getSource()==bLast)
   {
    rs.last();
    cur=tot;   
   } 
   dispRec();
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(this,e.getMessage());
  }
 }

 void dispRec()
 {
  try
  {
   setTitle("Record "+cur+" of "+tot);  
   tRol.setText(rs.getInt("rollno")+"");
   tNam.setText(rs.getString(2));  
   tDob.setText(rs.getString("lname"));
   tBrn.setText(rs.getString("branch"));
   tMrk.setText(rs.getInt("marks")+"");
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(this,e.getMessage());
  }
 } 
}

class MyPanel extends JPanel
{
 int top,left,bottom,right; 
 
 MyPanel(int top,int left,int bottom,int right)
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

class browse
{
 public static void main(String arg[])
 {
  try
  {
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
  }
  catch(ClassNotFoundException e)
  {
   JOptionPane.showMessageDialog(null,"Driver Not Found... aborting...");
   System.exit(1);
  }
 
  MyFrame mf=new MyFrame();
  mf.setVisible(true);
  mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }
}