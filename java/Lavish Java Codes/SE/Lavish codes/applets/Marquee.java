// how your code can call the paint methd without resizing the window.
// dynamically determining the size of window
/*
your applet consists of Code Base and Document Base
*/

import java.awt.*;
import java.applet.*;
import java.util.*;

/*
	<applet code="Marquee" width=1366 height=768>
	</applet>
*/

public class Marquee extends Applet implements Runnable
{
	String s;
	int x;
	Thread thd;
	public void init()
	{
		Date dt=new Date();
		s=String.format("%d-%d-%d",dt.getDay()-1,dt.getMonth()+1,dt.getYear()+1900);
		setBackground(new Color(150,150,255));
		setFont(new Font("lucida console",Font.PLAIN,30));
		setForeground(Color.red);
		x=768;
		
		
		thd=new Thread(this);
		thd.start();
	}
	
	public void paint(Graphics g)
	{
		g.drawString(s,x,50);
	}
	
	public void run()
	{
		while(true)
		{
			repaint();
			
			try
			{
				Thread.sleep(20);
			}catch(InterruptedException e)
			{
			}
			
			x-=2;
			if(x<-100)
				x=768;
		}
	}
}	