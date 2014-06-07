import java.applet.*;
import java.awt.*;
/*
	<applet code="MyApplet" width=600 height=500>
	<param name="title" value="hello lavish kothari">
	<param name="fsize" value="hello rakshit kothari">
	</applet>
	*/
public class MyApplet123 extends Applet
{
	String str;
	public void init()
	{
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
	}
	public void paint(Graphics g)
	{
		g.drawString(str,20,20);
	}
}
		
	