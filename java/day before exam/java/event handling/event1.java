//handling mouse events.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="event1" width="200" height="200"></applet>
*/

public class event1 extends Applet implements MouseMotionListener
{
	int x,y;
	public void init()
	{
		addMouseMotionListener(this);
	}
	public void mouseMoved(MouseEvent me)
	{
		x=me.getX();
		y=me.getY();
		repaint();	
	}
	public void mouseDragged(MouseEvent me)
	{
	}
	public void paint(Graphics g)
	{
		g.drawString(x+","+y,20,20);
	}
}