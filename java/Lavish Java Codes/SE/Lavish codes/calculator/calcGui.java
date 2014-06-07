import java.awt.*;
import java.awt.event.*;

class CalcFrame extends Frame implements ActionListener
{
 Button bNum[]=new Button[10];
 Button bAdd,bSub,bMul,bDiv,bEql,bClr,b00;
 TextField tScr;
 String opn="";

 int prv,cur;
 
 CalcFrame()
 {
  super("Calculator");
  setSize(250,350);
  setLocation(300,200);

  for(int i=0;i<10;i++)
  {
   bNum[i]=new Button(String.valueOf(i));
   bNum[i].setFont(new Font("lucida console",Font.PLAIN,18));
   bNum[i].setBackground(new Color(180,180,180));
  }   

  bAdd=new Button("+");
  bAdd.setFont(new Font("lucida console",Font.PLAIN,18));
  bAdd.setBackground(new Color(170,170,255));

  bSub=new Button("-");
  bSub.setFont(new Font("lucida console",Font.PLAIN,18));
  bSub.setBackground(new Color(170,170,255));

  bMul=new Button("*");
  bMul.setFont(new Font("lucida console",Font.PLAIN,18));
  bMul.setBackground(new Color(170,170,255));

  bDiv=new Button("/");
  bDiv.setFont(new Font("lucida console",Font.PLAIN,18));
  bDiv.setBackground(new Color(170,170,255));

  bEql=new Button("=");
  bEql.setFont(new Font("lucida console",Font.PLAIN,18));
  bEql.setBackground(new Color(255,255,170));

  bClr=new Button("Clr");
  bClr.setFont(new Font("lucida console",Font.PLAIN,18));
  bClr.setBackground(new Color(255,180,180));

  b00=new Button("00");
  b00.setFont(new Font("lucida console",Font.PLAIN,18));
  b00.setBackground(new Color(180,180,180));
  
  tScr=new TextField();
  tScr.setEditable(false);
  tScr.setFont(new Font("lucida console",Font.BOLD|Font.ITALIC,35));
  tScr.setBackground(Color.black);
  tScr.setForeground(Color.white);

  setLayout(new BorderLayout(5,5));
  
  add(tScr,BorderLayout.NORTH);
  
  Panel p=new Panel();
  p.setLayout(new GridLayout(5,4,5,5));

  p.add(new Label());
  p.add(new Label());
  p.add(new Label());
  p.add(bClr);
   
  p.add(bNum[7]);
  p.add(bNum[8]);
  p.add(bNum[9]);
  p.add(bAdd);
      
  p.add(bNum[4]);
  p.add(bNum[5]);
  p.add(bNum[6]);
  p.add(bSub);
  
  p.add(bNum[1]);
  p.add(bNum[2]);
  p.add(bNum[3]);
  p.add(bMul);

  p.add(bNum[0]);
  p.add(b00);
  p.add(bEql);
  p.add(bDiv);

  add(p,BorderLayout.CENTER);

  for(int i=0;i<10;i++)
   bNum[i].addActionListener(this);

  b00.addActionListener(this);
  bAdd.addActionListener(this);
  bSub.addActionListener(this);
  bMul.addActionListener(this);
  bDiv.addActionListener(this);
  bEql.addActionListener(this);
  bClr.addActionListener(this);

  addWindowListener(new CalcWndAdapter());
 }

 public Insets getInsets()
 {
  return new Insets(40,10,10,10);
 }

 public void actionPerformed(ActionEvent ae)
 {
 }
}

class CalcWndAdapter extends WindowAdapter
{
 public void windowClosing(WindowEvent we)
 {
  System.exit(0);
 }
}

class calc
{
 public static void main(String arg[])
 {
  CalcFrame cf=new CalcFrame();
  cf.setVisible(true);
 }
}
