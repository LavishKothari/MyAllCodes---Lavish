import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*
<applet code="event1" width=600 height=600>
</applet>
*/

public class event1 extends Applet implements MouseListener
{
	int prevx=50,prevy=50;
	public void init()
	{
		
		setBackground(Color.yellow);
		setForeground(Color.red);
		
		addMouseListener(this);
	}
	
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mouseClicked(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	public void mousePressed(MouseEvent me)
	{
		Graphics g=getGraphics();
		AudioClip a;
		g.setXORMode(Color.yellow);
		g.drawString("YAHOO !!",prevx,prevy);
		
		a=getAudioClip(getCodeBase(),"yahoo.au");
		a.play();
		
		
		g.drawString("YAHOO !!",me.getX(),me.getY());
		
		prevx=me.getX();
		prevy=me.getY();
	}
}