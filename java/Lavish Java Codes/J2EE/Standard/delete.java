import javax.swing.*;
import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.*;

class MyFrame extends JFrame implements ListSelectionListener,ItemListener,ActionListener
{
 JList jl;
 JTextField tNam,tBal;
 JButton bDel;
 JLabel msg;

 JTextField trn[]=new JTextField[20];
 JCheckBox  chk[]=new JCheckBox[20];  
 int tId[]=new int[20];
 int sel;
 
 String name[],actno[];
 int bal[];
 int index;
 int tot;
 
 MyFrame()
 {
  super("Transaction Management");
  setSize(600,400);
  setLocation(200,100);

  try
  {
   String str="jdbc:mysql://localhost:3307/banking";
   Connection cn=DriverManager.getConnection(str,"root","depan");
   PreparedStatement pst=cn.prepareStatement("select count(*) as cnt from cust");
   ResultSet rs=pst.executeQuery();
   rs.next();
   int n=rs.getInt("cnt");
   if(n==0)
   {
    JOptionPane.showMessageDialog(this,"No Customer in the Database..");   
    System.exit(2);
   }
   actno=new String[n];
   bal=new int[n];
   name=new String[n];

   pst.close();
   
   pst=cn.prepareStatement("select * from cust");
   rs=pst.executeQuery();
   for(int i=0;rs.next();i++)
   {
    actno[i]=String.valueOf(rs.getInt("actno"));
    name[i]=rs.getString("cname");
    bal[i]=rs.getInt("bal");
   }
 
   pst.close();
   cn.close();   
   
   JLabel l1=new JLabel("Act Nos");
   l1.setFont(new Font("arial",Font.PLAIN,18));
   
   JLabel l2=new JLabel("Name");
   l2.setFont(new Font("arial",Font.PLAIN,18));

   JLabel l3=new JLabel("Balance");
   l3.setFont(new Font("arial",Font.PLAIN,18));
   
   tNam=new JTextField();
   tNam.setFont(new Font("arial",Font.PLAIN,18));
   tNam.setEditable(false);

   tBal=new JTextField();
   tBal.setFont(new Font("arial",Font.PLAIN,18));
   tBal.setEditable(false);
     
   jl=new JList(actno); 	 
   jl.setFont(new Font("arial",Font.PLAIN,18));
 	 
   JScrollPane jsp1=new JScrollPane(jl);
   	 
   MyPanel mp=new MyPanel(10,10,10,10);
   add(mp);
   
   mp.setLayout(new BorderLayout(5,5));

    JPanel p1=new JPanel();
    p1.setLayout(new BorderLayout(5,5));
    p1.add(l1,BorderLayout.NORTH);
    p1.add(jsp1,BorderLayout.CENTER);

    JPanel p2=new JPanel();
    p2.setLayout(new BorderLayout(5,10));
   
     MyPanel p21=new MyPanel(5,5,5,5);
     p21.setLayout(new GridLayout(2,1,3,3));
     p21.setBorder(BorderFactory.createLineBorder(Color.black,1));

      JPanel p211=new JPanel();
      p211.setLayout(new BorderLayout(23,3));
      p211.add(l2,BorderLayout.WEST);
      p211.add(tNam,BorderLayout.CENTER);

      JPanel p212=new JPanel();
      p212.setLayout(new BorderLayout(5,3));
      p212.add(l3,BorderLayout.WEST);
      p212.add(tBal,BorderLayout.CENTER);

     p21.add(p211);
     p21.add(p212);
     
     JPanel p22=new JPanel();
     p22.setLayout(new GridLayout(20,1,1,1));
     for(int i=0;i<20;i++)
     {
      JPanel p=new JPanel();
      p.setLayout(new BorderLayout(1,1));

      trn[i]=new JTextField();
      trn[i].setFont(new Font("lucida console",Font.PLAIN,18));
      trn[i].setVisible(false);
      trn[i].setEditable(false);

      chk[i]=new JCheckBox();
      chk[i].setVisible(false);
      chk[i].addItemListener(this);
   
      p.add(chk[i],BorderLayout.WEST);
      p.add(trn[i],BorderLayout.CENTER);
      
      p22.add(p);
     }

     JScrollPane jsp2=new JScrollPane(p22);
    
     JPanel p23=new JPanel();
     p23.setLayout(new BorderLayout(3,3));

     JPanel p231=new JPanel();
     p231.setLayout(new BorderLayout(1,1));
       
      bDel=new JButton("Delete");
      bDel.setFont(new Font("lucida console",Font.PLAIN,18));

      msg=new JLabel();
      msg.setFont(new Font("lucida console",Font.PLAIN,18));
     
     p231.add(bDel,BorderLayout.EAST);
     p231.add(msg,BorderLayout.CENTER);
   
     p23.add(jsp2,BorderLayout.CENTER);
     p23.add(p231,BorderLayout.SOUTH); 
 
    p2.add(p21,BorderLayout.NORTH);
    p2.add(p23,BorderLayout.CENTER);
   
   mp.add(p1,BorderLayout.WEST);
   mp.add(p2,BorderLayout.CENTER);
   
   jl.setSelectedIndex(0);
   tNam.setText(name[0]);
   tBal.setText(bal[0]+"");
   
   cn=DriverManager.getConnection(str,"root","depan");
   pst=cn.prepareStatement("select * from trans where actno=?");
   
   try
   {
    n=Integer.parseInt(actno[index]);
   }
   catch(NumberFormatException e)
   {
    n=0;
   }

   pst.setInt(1,n);

   rs=pst.executeQuery();

   tot=0;
   while(rs.next())
   {
    int tid,d,m,y,amt;
    String tt,st;

    tid=rs.getInt("transid");
    java.sql.Date dt=rs.getDate("dot");
    d=dt.getDate();
    m=dt.getMonth()+1;
    y=dt.getYear()+1900;
    amt=rs.getInt("amt");
    tt=rs.getString("transtype");
    st=rs.getString("status");

    String s=String.format("%3d  %02d/%02d/%d  %s  %5d  %s",tid,d,m,y,tt,amt,st);
  
    trn[tot].setText(s);
    trn[tot].setVisible(true);
    chk[tot].setVisible(true);
    tot++;
   }   
   if(tot>0)
    msg.setText("0 Record(s) Selected");
   else
    msg.setText("No Transactions for this Account");
   
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(this,e.getMessage());
  }   

  jl.addListSelectionListener(this);
  bDel.addActionListener(this);
  
 } 

 public void valueChanged(ListSelectionEvent lse)
 {
  index=jl.getSelectedIndex();
  tNam.setText(name[index]);
  tBal.setText(bal[index]+"");  

  for(int i=0;i<20;i++)
   trn[i].setVisible(false);

  try
  {
   String str="jdbc:mysql://localhost:3307/banking";
   Connection cn=DriverManager.getConnection(str,"root","depan");
   PreparedStatement pst=cn.prepareStatement("select * from trans where actno=?");
   
   int n;
   try
   {
    n=Integer.parseInt(actno[index]);
   }
   catch(NumberFormatException e)
   {
    n=0;
   }
 
   pst.setInt(1,n);
 
   ResultSet rs=pst.executeQuery();
   tot=0;
   while(rs.next())
   {
    int tid,d,m,y,amt;
    String tt,st;

    tid=rs.getInt("transid");

    java.sql.Date dt=rs.getDate("dot");

    d=dt.getDate();
    m=dt.getMonth()+1;
    y=dt.getYear()+1900;
    amt=rs.getInt("amt");
    tt=rs.getString("transtype");
    st=rs.getString("status");

    String s=String.format("%3d  %02d/%02d/%d  %s  %5d  %s",tid,d,m,y,tt,amt,st);
  
    trn[tot].setText(s);
    trn[tot].setVisible(true);
    chk[tot].setVisible(true);
    tot++;
   }

   if(tot>0)
    msg.setText("0 Record(s) Selected");
   else
    msg.setText("No Transactions for this Account");
          
  }
  catch(SQLException e)
  {
   JOptionPane.showMessageDialog(this,e.getMessage());
  } 
 }  

 public void itemStateChanged(ItemEvent ie)
 {
  int newBal=bal[index];
  sel=0;
  for(int i=0;i<tot;i++)
  {
   if(chk[i].isSelected())
   {
    String s=trn[i].getText();
    String tt,st;
    int amt;

    StringTokenizer stz=new StringTokenizer(s);
   
    try
    {
     tId[sel]=Integer.parseInt((String)stz.nextElement());
    }
    catch(NumberFormatException e)
    {
     tId[sel]=0;
    }

    stz.nextElement();

    tt=(String)stz.nextElement();
    
    try
    {
     amt=Integer.parseInt((String)stz.nextElement());
    }
    catch(NumberFormatException e)
    {
     amt=0;
    }
    st=(String)stz.nextElement();

    if(st.equals("Success"))
    {    
     if(tt.equals("CR"))
      newBal=newBal-amt;
     else
      newBal=newBal+amt;
    }
    sel++;
   }
  }
  msg.setText(sel+" Record(s) Selected");
  tBal.setText(newBal+"");
 }

 public void actionPerformed(ActionEvent ae)
 {
  try
  {
   String str="jdbc:mysql://localhost:3307/banking";
   Connection cn=DriverManager.getConnection(str,"root","depan");
   PreparedStatement pst=cn.prepareStatement("select count(*) as cnt from cust");
  }
    
 }
}

class MyPanel extends JPanel
{
  int top,left,right,bottom;
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
   return new Insets(top,left,right,bottom);
  }
}

class delete
{
 public static void main(String arg[])
 {
  try
  {
   Class.forName("com.mysql.jdbc.Driver");
  }
  catch(ClassNotFoundException e)
  {
   JOptionPane.showMessageDialog(null,"Driver Not Found");
   System.exit(1);
  }
  MyFrame mf=new MyFrame();
  mf.setVisible(true);
  mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }
} 