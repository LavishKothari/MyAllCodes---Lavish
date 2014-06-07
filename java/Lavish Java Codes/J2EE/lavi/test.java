import javax.swing.*;
import java.awt.*;
//import java.awt.event.*;

class MyFrame extends JFrame
{
	JLabel ladmission,lname,lage,lmarks,lfathersname,laddress,lgender;
	JTextField tname,tage,tmarks,tfathersname,taddress;
	JButton bsubmit,bcancel,bclear;
	JRadioButton male,female;
	MyFrame()
	{
		setLayout(new FlowLayout());
		setSize(1100,570);
		setLocation(100,50);
			
		ladmission=new JLabel("ADMISSION FORM");	
		ladmission.setFont(new Font("lucida console",Font.PLAIN,40));
		
		lname=new JLabel("NAME");
		lname.setFont(new Font("lucida console",Font.PLAIN,24));
		
		lage=new JLabel("AGE");	
		lage.setFont(new Font("lucida console",Font.PLAIN,24));
		
		lmarks=new JLabel("PREV. MARKS");	
		lmarks.setFont(new Font("lucida console",Font.PLAIN,24));
		
		lfathersname=new JLabel("FATHER'S NAME");	
		lfathersname.setFont(new Font("lucida console",Font.PLAIN,24));
		
		laddress=new JLabel("ADDRESS");	
		laddress.setFont(new Font("lucida console",Font.PLAIN,24));
		
		lgender=new JLabel("GENDER");	
		lgender.setFont(new Font("lucida console",Font.PLAIN,24));
		
		tname=new JTextField();
		tname.setFont(new Font("lucida console",Font.PLAIN,24));
		
		tage=new JTextField(3);
		tage.setFont(new Font("lucida console",Font.PLAIN,24));
		
		tmarks=new JTextField(3);
		tmarks.setFont(new Font("lucida console",Font.PLAIN,24));
		
		tfathersname=new JTextField();
		tfathersname.setFont(new Font("lucida console",Font.PLAIN,24));
		
		taddress=new JTextField();
		taddress.setFont(new Font("lucida console",Font.PLAIN,24));
		
		bsubmit=new JButton("SUBMIT");
		bsubmit.setFont(new Font("lucida console",Font.PLAIN,24));
		
		bcancel=new JButton("CANCEL");
		bcancel.setFont(new Font("lucida console",Font.PLAIN,24));
		
		bclear=new JButton("CLEAR");
		bclear.setFont(new Font("lucida console",Font.PLAIN,24));
		
		male=new JRadioButton("MALE");
		male.setFont(new Font("lucida console",Font.PLAIN,24));
		
		female=new JRadioButton("FEMALE");
		female.setFont(new Font("lucida console",Font.PLAIN,24));
		
		ButtonGroup bg=new ButtonGroup();
		bg.add(male);
		bg.add(female);
		
		MainPanel mp=new MainPanel(25,10,10,10);
		mp.setLayout(new GridLayout(9,1,10,10));
		add(mp);
		
		JPanel p1=new JPanel();
		p1.setLayout(new GridLayout(1,3,5,5));
		p1.add(new JLabel());
		p1.add(ladmission);
		p1.add(new JLabel());
		
		JPanel p2=new JPanel();
		p2.setLayout(new BorderLayout(150,5));
		p2.add(lname,BorderLayout.WEST);
		p2.add(tname,BorderLayout.CENTER);
		
		JPanel p3=new JPanel();
		p3.setLayout(new GridLayout(1,2,250,10));
		
		JPanel p31=new JPanel();
		p31.setLayout(new BorderLayout(165,5));
		p31.add(lage,BorderLayout.WEST);
		p31.add(tage,BorderLayout.CENTER);
		
		JPanel p32=new JPanel();
		p32.setLayout(new BorderLayout(60,5));
		p32.add(lmarks,BorderLayout.WEST);
		p32.add(tmarks,BorderLayout.CENTER);
		
		JPanel p4=new JPanel();
		p4.setLayout(new BorderLayout(25,5));
		p4.add(lfathersname,BorderLayout.WEST);
		p4.add(tfathersname,BorderLayout.CENTER);
		
		JPanel p5=new JPanel();
		p5.setLayout(new BorderLayout(110,5));
		p5.add(laddress,BorderLayout.WEST);
		p5.add(taddress,BorderLayout.CENTER);
		
		JLabel p6=new JLabel();
		p6.setLayout(new GridLayout(1,5,10,10));
		p6.add(lgender);
		p6.add(male);
		p6.add(female);
		p6.add(new JLabel());
		p6.add(new JLabel());
		
		JPanel p7=new JPanel();
		p7.setLayout(new GridLayout(1,3,20,10));
		p7.add(bsubmit);
		p7.add(bcancel);
		p7.add(bclear);
		
		mp.add(p1);
		mp.add(new JPanel());
		mp.add(p2);
		p3.add(p31);
		p3.add(p32);
		mp.add(p3);
		mp.add(p4);
		mp.add(p6);
		mp.add(p5);
		mp.add(new JPanel());
		mp.add(p7);
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
class test
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		//mf.setSize(400,400);
		//mf.setLocation(400,300);
		mf.setVisible(true);
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}