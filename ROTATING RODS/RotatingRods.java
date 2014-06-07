import java.util.*;
import java.awt.*;
import java.awt.event.*;

class Rod extends Frame implements Runnable
{
	Thread th;
	Graphics g;
	double degree,a,b,c,d,xAfterRotation,yAfterRotation,rodLength,rpm,delayTime, rotationPointX,rotationPointY;
	Color colorOfRod;
	public static LinkedList<Rod> lst=new LinkedList<Rod>();
	public void setG(Graphics g)
	{
		this.g=g;
	}
	
	Rod(double a,double b,double rodLength,Color colorOfRod,double rpm)
	{
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
		th=new Thread(this);
		this.colorOfRod=colorOfRod;
		this.d=b;
		this.c=this.a+rodLength;
		this.rodLength=rodLength;
		this.xAfterRotation=this.c;
		this.yAfterRotation=this.d;
		this.rpm=rpm;
				
		delayTime=100/(6*rpm);
		degree=1;
		//System.out.println(lst.size());
		
	}
	
	public static double d2r(double d)
	{	
		return (d*3.1415926/180.0);
	}
	public void rotateTheRod(double x,double y)
	{
		xAfterRotation=((c-x)*Math.cos(d2r(degree))-(d-y)*Math.sin(d2r(degree))+x);
		yAfterRotation=((c-x)*Math.sin(d2r(degree))+(d-y)*Math.cos(d2r(degree))+y);
	}
	
	public void drawRotatingRod() throws InterruptedException
	{
		if(g!=null)
		{
			
			g.setColor(colorOfRod);
			g.setXORMode(Color.white);
			while(true)
			{
				if(lst.size()>=2)				
					for(int i=0;i<lst.size();i++)
						lst.get(i).rotateTheRod(300,300);
				g.drawLine((int)a,(int)b,(int)xAfterRotation,(int)yAfterRotation);
				Thread.sleep((long)delayTime);
				g.drawLine((int)a,(int)b,(int)xAfterRotation,(int)yAfterRotation);
				
				
				rotateTheRod(a,b);
				
				c=xAfterRotation;
				d=yAfterRotation;
			}
		}
		else 
			System.out.println("Graphics Object not Initialised");
	}
	public void run()
	{		
		try
		{
			drawRotatingRod();
		}
		catch(InterruptedException e){}
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
			Rod r1=new Rod(windowWidth/2,windowHeight/2,100,Color.red,1);
			Graphics g=getGraphics();
			r1.setG(g);
			r1.th.start();
			
			Rod r2=new Rod(windowWidth/2,windowHeight/2,100,Color.green,2);
			g=getGraphics();
			r2.setG(g);
			r2.th.start();
		}	
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