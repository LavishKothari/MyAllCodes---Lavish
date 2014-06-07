import java.awt.*;
import java.applet.*;
/*
<applet code="ball" width=600 height=600>
</applet>
*/

public class ball extends Applet implements Runnable
{
	Thread t;
	int x,y,xincr,yincr;
	Dimension d;
	int ballSize=50;
	AudioClip a1,a2;
	public void init()
	{
		d=getSize();
		x=-25;
		y=-100;
		xincr=2;
		yincr=1;
		setBackground(Color.yellow);
		setForeground(Color.red);
		
		a1=getAudioClip(getCodeBase(),"yahoo.au");
		a2=getAudioClip(getCodeBase(),"spacemusic.au");
		a2.loop();
		t=new Thread(this);
		t.start();
	}
	
	public void run()
	{
		Graphics g = getGraphics();
		g.setXORMode(Color.yellow);
		while(true)
		{
			g.fillOval(x-ballSize/2,y-ballSize/2,ballSize,ballSize); // to draw
			
			try
			{
				Thread.sleep(10);
			}
			catch(InterruptedException e){}
			
			g.fillOval(x-ballSize/2,y-ballSize/2,ballSize,ballSize); // to erase
			
			x+=xincr;
			y+=yincr;
			
			if(x<=ballSize/2)
			{
				a1.play();
				xincr=2;
			}
			if(x>=d.width-ballSize/2)
			{
				a1.play();
				xincr-=2;
			}
			if(y<=ballSize/2)
			{
				a1.play();
				yincr=1;
			}
			if(y>=d.height-ballSize/2)
			{
				a1.play();
				yincr=-1;
			}
		}
		
	}
	public void paint(Graphics g)
	{
		
	}
}