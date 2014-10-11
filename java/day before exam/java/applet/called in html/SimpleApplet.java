import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="SimpleApplet" width="200" height="200">
</applet>
*/
public class SimpleApplet extends Applet implements ActionListener
{
	TextField t1,t2;
	String msg="";
	public void init()
	{
		t1=new TextField();
		t2=new TextField();
		Button b1=new Button("add");
		setBackground(Color.green);
		setForeground(Color.red);
		add(t1);
		add(t2);
		add(b1);
		b1.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e)
	{
		int sum=Integer.parseInt(t2.getText())+Integer.parseInt(t1.getText());		
		msg=sum+"";
		repaint();
	}

	public void paint(Graphics g)
	{
		System.out.println("hello lavish kothari");
		g.drawString(msg,20,50);
	}
				
}
	