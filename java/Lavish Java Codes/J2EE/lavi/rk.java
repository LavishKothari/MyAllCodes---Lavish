import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame
{
	JLabel l;
	JTextField t;
	JButton b;
	
	MyFrame()
	{
		setLayout(new FlowLayout());
		l=new JLabel("HELLO RAKSHIT KOTHARI");
		t=new JTextField(10);
		b=new JButton("SUBMIT");
		for(int i=0;i<10;i++)
		{
			add(l);
			add(t);
			add(b);
		}
	}


}

class rk
{
	public static void main(String []args)
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
		mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mf.setSize(400,100);
		mf.setLocation(300,300);
	}
}
