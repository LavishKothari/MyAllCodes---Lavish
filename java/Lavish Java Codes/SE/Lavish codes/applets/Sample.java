import java.awt.*;
import java.applet.*;

/*
	<applet code="Sample" width=1366 height=768>
	</applet>
*/

public class Sample extends Applet
{
	public void init()
	{
		setBackground(new Color(150,150,255));
		setForeground(Color.green);		
	}

	public void paint(Graphics g)
	{
		/**************/
		g.setColor(new Color(205,133,63));
		g.fillRect(250,350,200,300);
		
		g.setColor(new Color(0,0,0));
		g.drawRect(250,350,200,300);
		
		/**************/
		g.setColor(new Color(167, 74, 199));
		g.fillRect(305,450,90,200); 			// gate
		/**************/
		
		{
		g.setColor(new Color(205,133,63));
		int x[]=new int[3];
		int y[]=new int[3];
		x[0]=250;
		x[1]=450;
		x[2]=350;
		y[0]=350;
		y[1]=350;
		y[2]=220;
		
		g.fillPolygon(x,y,3);				// triangle
		}
		/**************/
		
		{
		g.setColor(new Color(126, 53, 23));
		
		int x[]={350,700,800,450};
		int y[]={220,160,290,350};
		g.fillPolygon(x,y,4);				// upper polygon
		}
		/**************/
		
		{
		g.setColor(new Color(127, 82, 23));
		
		int x[]={800,450,450,800};
		int y[]={590,650,350,290};
		g.fillPolygon(x,y,4);				// side polygon
		}
		/**************/
		
		g.setColor(new Color(255, 0, 0));
		
		g.fillOval(325,275,50,50);	
		/**************/
		g.setColor(new Color(167, 74, 199));		// main door
		
		int x[]={625,725,725,625};
		int y[]={620,603,430,448};
		g.fillPolygon(x,y,4);				
		
		

		
		

	}
}
		
	