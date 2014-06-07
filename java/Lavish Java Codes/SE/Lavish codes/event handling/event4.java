import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="event4" width=600 height=600>
</applet>
*/

public class event4 extends Applet implements MouseListener, MouseMotionListener
{
	Boolean draw;
	int startX=0,startY=0,px=0,py=0;
	public void init()
	{
		setBackground(Color.yellow);
		setForeground(Color.red);
				
		addMouseListener(this);
		addMouseMotionListener(this);

		String s=String.format("x : %03d   y : %03d",1,1);
		showStatus(s);
	}
	
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mouseClicked(MouseEvent me){}
	public void mouseReleased(MouseEvent me)
	{
		Graphics g=getGraphics();
		g.setPaintMode();
		g.drawLine(startX,startY,me.getX(),me.getY());
		setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		
	}
	public void mousePressed(MouseEvent me)
	{
		setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
		px=startX=me.getX();
		py=startY=me.getY();
	}
	public void mouseMoved(MouseEvent me)
	{
		int x,y;
		x=me.getX();
		y=me.getY();
		String s=String.format("x : %03d   y : %03d",x,y);
		showStatus(s);
	}
	public void mouseDragged(MouseEvent me)
	{
		int x,y;
		x=me.getX();
		y=me.getY();
		
		String s=String.format("x : %03d   y : %03d",x,y);
		showStatus(s);
		
		Graphics g=getGraphics();
		g.setXORMode(Color.yellow);
		//g.setColor(Color.red);
		
		
		g.drawLine(startX,startY,me.getX(),me.getY());
		g.drawLine(startX,startY,px,py);
			
		
		px=me.getX();
		py=me.getY();
	}
}