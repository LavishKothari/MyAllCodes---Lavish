import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*
<applet code="event2" width=600 height=600>
</applet>
*/

public class event2 extends Applet implements MouseListener
{
	int x1,y1,x2,y2;
	int counter=0;
	public void init()
	{
		
		setBackground(Color.yellow);
		
		addMouseListener(this);
	}
	
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mouseClicked(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	public void mousePressed(MouseEvent me)
	{
		Graphics g=getGraphics();
		counter++;
		if(counter%2!=0)
		{
			x1=me.getX();
			y1=me.getY();
			g.setColor(Color.blue);
			g.fillOval(me.getX()-2,me.getY()-2,4,4);
		}
		else
		{
			x2=me.getX();
			y2=me.getY();
			g.setColor(Color.blue);
			g.fillOval(me.getX()-2,me.getY()-2,4,4);
			
			g.setColor(Color.red);
			g.drawLine(x1,y1,x2,y2);
		}		

	}
}