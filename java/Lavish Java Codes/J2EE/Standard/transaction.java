import java.util.*;
import javax.swing.*;
import java.awt.*;

class MyFrame extends JFrame
{
	JTextField taccount,tname,tbalance,tamount;
	JLabel laccount,lname,lbalance,lamount;
	JButton bupdate,bclear,bexit;
	JRadioButton bdebit,bcredit;
	MyFrame()
	{
		super("MY-BANK TRANSACTION");
		
		setLayout(new FlowLayout());
		setSize(400,400);
		setLocation(200,200);
		
		
		laccount=new JLabel("ACCOUNT ID");
		lname=new JLabel("ACCOUNT ID");
		lbalance=new JLabel("ACCOUNT ID");
		lamount=new JLabel("ACCOUNT ID");
		
		taccount=new JTextField();
		tname=new JTextField();
		tbalance=new JTextField();
		tamount=new JTextField();
		
		bupdate=new JButton("UPDATE");
		bclear=new JButton("CLEAR");
		bexit=new JButton("EXIT");
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



class transaction extends JFrame
{
	public static void main(String []args)
	{
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
		}
		catch(ClassNotFoundException e)
		{
			JOptionPane.showMessageDialog(null,"Drivers not found....aborting...");
			System.exit(1);
		}
		
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}