import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*
<applet code="event3" width=600 height=600>
</applet>
*/

public class event3 extends Applet implements MouseListener
{
	int px,py;
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
		
		if((me.getButton()&2)==2)
		{
			counter=0;
			return ;
		}
		g.setColor(Color.blue);
		g.fillOval(me.getX()-2,me.getY()-2,4,4);
		if(counter!=1)
		{
			g.setColor(Color.red);
			g.drawLine(px,py,me.getX(),me.getY());
		}
		px=me.getX();
		py=me.getY();
	
	}
}
/*
implements MouseListener, MouseMotionListener
addMouseMotionListener(this)
mouseMoved(MouseEvent e)
mouseDragged
*/