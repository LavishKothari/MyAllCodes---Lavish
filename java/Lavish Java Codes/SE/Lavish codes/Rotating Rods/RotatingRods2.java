import java.util.*;
import java.awt.*;
import java.awt.event.*;

class Rod extends Frame 
{
	Graphics g;
	double degree,a,b,c,d,rodLength,rpm,delayTime;
	static double xAfterRotation,yAfterRotation;
	Color colorOfRod;
	public static LinkedList<Rod> lst=new LinkedList<Rod>();
	
	Rod(double a,double b,double rodLength,Color colorOfRod,double rpm,Graphics g)
	{
		this.g=g;
		lst.add(this);
		if(lst.size()==1)
		{
			this.a=a;
			this.b=b;
		}
		else
		{
			this.a=lst.getLast().c;
			this.b=lst.getLast().d;
		}
		this.colorOfRod=colorOfRod;
		this.d=b;
		this.c=this.a+rodLength;
		this.rodLength=rodLength;
		this.xAfterRotation=this.c;
		this.yAfterRotation=this.d;
		this.rpm=rpm;
				
		delayTime=100/(6*rpm);
		degree=1;
	}
	
	public static double d2r(double d)
	{	
		return (d*Math.PI/180.0);
	}
	public static void rotateTheRod(double xc,double yc,double x,double y,double d)
	{
		xAfterRotation=((x-xc)*Math.cos(d2r(d))-(y-yc)*Math.sin(d2r(d))+xc);
		yAfterRotation=((x-xc)*Math.sin(d2r(d))+(y-yc)*Math.cos(d2r(d))+yc);
	}
	
	public void drawRotatingRod()throws InterruptedException
	{
		while(true)
		{		
			g.setColor(colorOfRod);
			
			for(int i=0;i<lst.size();i++)
				g.drawLine((int)lst.get(i).a,(int)lst.get(i).b,(int)lst.get(i).c,(int)lst.get(i).d);
			
			Thread.sleep((long)delayTime);
			
			g.setColor(Color.white);
			
			for(int i=0;i<lst.size();i++)
				g.drawLine((int)lst.get(i).a,(int)lst.get(i).b,(int)lst.get(i).c,(int)lst.get(i).d);
			
			for(int i=lst.size()-1;i>=0;i--)
			{
				for(int j=i;j<lst.size();j++)
				{
					rotateTheRod(lst.get(i).c,lst.get(i).d,lst.get(j).c,lst.get(j).d,lst.get(j).degree);
					lst.get(j).c=xAfterRotation;
					lst.get(j).d=yAfterRotation;
				} 
			}	
		}
	}
}
class MainFrame extends Frame implements ActionListener
{
	MenuItem exitMenu,addRodMenu;
	int windowWidth=600,windowHeight=600;
	MainFrame() 
	{
		super("Rotating Rods");
		setSize(windowWidth,windowHeight);
		setLocation(100,100);
		
		setResizable(false);
		
		exitMenu=new MenuItem("Exit");
		addRodMenu=new MenuItem("Add Rod");
		Menu menu=new Menu("Menu");
		
		MenuBar mb=new MenuBar();
		menu.add(addRodMenu);
		menu.addSeparator();
		menu.add(exitMenu);
		mb.add(menu);
		
		setMenuBar(mb);
		
		addRodMenu.addActionListener(this);
		exitMenu.addActionListener(this);
		addWindowListener(new MyWindowAdapter());	
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==exitMenu)
		{
			System.exit(0);
		}
		if(ae.getSource()==addRodMenu)
		{			
			Graphics g=getGraphics();
			Rod r=new Rod(windowWidth/2,windowHeight/2,100,Color.red,1,g);
			MyThread th=new MyThread(r);	
		}
	}
}
class MyThread extends Thread
{
	Rod r;
	MyThread(Rod r)
	{
		this.r=r;
		Thread th=new Thread(this);
		th.start();
	}
	public void run()
	{
		try
		{
			r.drawRotatingRod();
		}
		catch(InterruptedException e)
		{}
	}
	
}
class MyWindowAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}

class Main
{
	public static void main(String args[]) throws InterruptedException
	{
		MainFrame mf=new MainFrame();
		mf.setVisible(true);
	}
}