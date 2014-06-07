import java.applet.*;
import java.awt.*;
/*
	<applet code="MyApplet" width=600 height=500>
	<param name="title" value="hello lavish kothari">
	<param name="fsize" value="hello rakshit kothari">
	</applet>
	*/
public class MyApplet extends Applet implements Runnable
{

	int x,w;
	Thread thd;
	String s,str;
	public void init()
	{
		Dimension d;
		d.getSize();
		w=x=d.width;
		setBackground(Color.yellow);
		setForeground(Color.red);
		
		int n;
		try
		{
			n=Integer.parseInt(getParameter("fsize"));
		}
		catch(Exception e)
		{
			n=20;
		}
		
		setFont(new Font("lucida console",Font.PLAIN,n));
		str=getParameter("title");
		if(str==null)
			str="Dmatics";
			
		thd=new Thread(this);
		thd.start();
	}
	
	public void run()
	{
		
		Graphics g=new getGraphics();
		g.setXORMode(new Color(150,150,255));
		while(true)
		{
			g.drawString(s,x,50); // to draw
			
			try
			{
				Thread.sleep(20);
			}catch(InterruptedException e)
			{
			}
			
			g.drawString(s,x,50); // to erase
			
			x-=2;
			if(x<-100)
				x=768;
		}
	}
	public void paint(Graphics g)
	{
		g.drawString(str,20,20);
	}
}
		
	