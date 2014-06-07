import java.awt.*;
import java.applet.*;
/*
<applet code="MovingBall" width=500 height=500>
</applet>
*/

public class MovingBall extends Applet implements Runnable
{
	Thread t;
	int x=100;
	int y=100;
	public void init()
	{
		setBackground(Color.yellow);
		setForeground(Color.red);
		t=new Thread(this);
		t.start();
	}
	
	public void run()
	{
		Graphics g = getGraphics();
		g.setXORMode(Color.yellow);
		while(true)
		{
			System.out.println("h");
			g.fillOval(x,y,50,50); // to draw
			
			try
			{
				Thread.sleep(2000);
			}
			catch(InterruptedException e){}
			g.fillOval(x,y,50,50); // to erase
			
		}
		
	}
	public void paint()
	{
		
	}
}
		