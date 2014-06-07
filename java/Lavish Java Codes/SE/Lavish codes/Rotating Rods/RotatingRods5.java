import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
class Rod
{
	static LinkedList<Rod>lst=new LinkedList<Rod>();
	static Dimension dim;
	Graphics g;
	double angle;
	double rpm,a,b,c,d,rodLength,delayTime;
	Color rodColor;
	Rod(){}
	Rod(double a,double b,double c,double d,double rodLenth,double rpm,String rodColor,Graphics g,Dimension dim)
	{
		this.dim=dim;
		this.g=g;
		this.rodLength=rodLength;
		this.a=a;
		this.b=b;
		this.c=c;
		this.d=d;
		this.rpm=rpm;
		this.delayTime=100;
		this.angle=6*rpm*Math.PI/1800;
		if(rodColor.equals("Black"))
			this.rodColor=Color.black;
		else if(rodColor.equals("Green"))
			this.rodColor=Color.green;
		else if(rodColor.equals("Yellow"))
			this.rodColor=Color.yellow;
		else if(rodColor.equals("Blue"))
			this.rodColor=Color.blue;
		else if(rodColor.equals("Red"))
			this.rodColor=Color.red;
	}
	public void drawRotatingRod()throws InterruptedException
	{
		while(true)
		{
			for(int i=0;i<lst.size();i++)
			{
				g.setColor(lst.get(i).rodColor);
				g.drawLine((int)lst.get(i).a,(int)lst.get(i).b,(int)lst.get(i).c,(int)lst.get(i).d);
			}
			Thread.sleep((long)delayTime);
			g.setColor(Color.white);
			g.fillRect(0,0,dim.width,dim.height);
			for(int i=0;i<lst.size();i++)
				for(int j=i;j<lst.size();j++)
					rotate(lst.get(i).a,lst.get(i).b,lst.get(j),lst.get(i).angle);
		}
		
	}
	public static void rotate(double x,double y,Rod r,double angle)
	{	
		Rod rod=new Rod();
		rod.a=(r.a-x)*Math.cos(angle)-(r.b-y)*Math.sin(angle)+x;
		rod.b=(r.a-x)*Math.sin(angle)+(r.b-y)*Math.cos(angle)+y;
		
		rod.c=(r.c-x)*Math.cos(angle)-(r.d-y)*Math.sin(angle)+x;
		rod.d=(r.c-x)*Math.sin(angle)+(r.d-y)*Math.cos(angle)+y;
		
		r.a=rod.a;
		r.b=rod.b;
		r.c=rod.c;
		r.d=rod.d;
	}
}
class Main extends WindowAdapter implements ActionListener
{
	int submitButtonCounter=0;
	Frame f1=new Frame();
	Frame f2=new Frame();
	Dimension d;
	Button bSubmit,bClear;
	Choice ch;
	TextField tRodLength,trpm;
	Label lRodLength,lrpm,lColor;
	
	MenuItem mExit,mClear,mAdd;
	public static void main(String args[])
	{
		Main m=new Main();
	}
	Main()
	{
		/*****/
		/* to maximize the window */
		f1.setState(Frame.NORMAL);
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension dimension = toolkit.getScreenSize();
		f1.setSize(dimension);
		/*******/
		f1.setLocation(0,0);
		f1.setResizable(false);
		d=f1.getSize();
		MenuBar mb=new MenuBar();
		Menu menu=new Menu("Menu");
		
		mClear=new MenuItem("Clear");
		mExit=new MenuItem("Exit");
		mAdd=new MenuItem("Add Rod");
		
		f1.setMenuBar(mb);
		mb.add(menu);
		
		menu.add(mAdd);
		menu.add(mClear);
		menu.add(mExit);
		
		mClear.addActionListener(this);
		mAdd.addActionListener(this);
		mExit.addActionListener(this);
		
		f1.addWindowListener(this);
		f1.setVisible(true);
		/******************************/
		f2.setSize(400,300);
		f2.setLocation(100,100);
		
		tRodLength=new TextField();
		tRodLength.setFont(new Font("arial",Font.PLAIN,20));
		trpm=new TextField();
		trpm.setFont(new Font("arial",Font.PLAIN,20));
		
		lRodLength=new Label("Length of rod");
		lRodLength.setFont(new Font("arial",Font.PLAIN,20));
		lrpm=new Label("Rotating speed in rpm");
		lrpm.setFont(new Font("arial",Font.PLAIN,20));
		lColor=new Label("Select a Color");
		lColor.setFont(new Font("arial",Font.PLAIN,20));
		
		ch=new Choice();
		
		ch.add("Red");
		ch.add("Green");
		ch.add("Black");
		ch.add("Blue");
		ch.add("Yellow");
		
		bSubmit=new Button("Submit");
		bClear=new Button("Clear");
		
		
		Panel p=new Panel(new GridLayout(5,1,20,20));
		
		Panel p1=new Panel(new BorderLayout(85,10));
		p1.add(lRodLength,BorderLayout.WEST);
		p1.add(tRodLength,BorderLayout.CENTER);
		
		Panel p2=new Panel(new BorderLayout(10,10));
		p2.add(lrpm,BorderLayout.WEST);
		p2.add(trpm,BorderLayout.CENTER);
		
		Panel p3=new Panel(new BorderLayout(78,10));
		p3.add(lColor,BorderLayout.WEST);
		p3.add(ch,BorderLayout.CENTER);
		
		
		Panel p4=new Panel(new GridLayout(1,5,10,10));
		p4.add(new Label(""));
		p4.add(bSubmit);
		p4.add(new Label(""));
		p4.add(bClear);
		p4.add(new Label(""));
		
		
		p.add(p1);
		p.add(p2);
		p.add(p3);
		p.add(new Label(""));
		p.add(p4);
		f2.add(p);
		
		bSubmit.addActionListener(this);
		bClear.addActionListener(this);
		f2.addWindowListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bClear)
		{
			tRodLength.setText(" ");
			trpm.setText(" ");
		}
		else if(ae.getSource()==mExit)
		{
			System.exit(0);
		}
		else if(ae.getSource()==mAdd)
		{
			f1.setEnabled(false);
			f2.setVisible(true);
			tRodLength.setText("");
			trpm.setText("");
		}
		else if(ae.getSource()==bSubmit)
		{	
			try
			{				
				f1.repaint();
				submitButtonCounter++;
				Graphics g=f1.getGraphics();
				d=f1.getSize();
				Rod r;
				if(submitButtonCounter==1)
				{
					r=new Rod(
								d.width/2.0,
								d.height/2.0,
								Double.parseDouble(tRodLength.getText())+d.width/2.0,
								d.height/2,
								Double.parseDouble(tRodLength.getText()),
								Double.parseDouble(trpm.getText()),
								ch.getSelectedItem(),g,d);
				}
				else
				{
					r=new Rod
								(Rod.lst.get(submitButtonCounter-2).c,
								Rod.lst.get(submitButtonCounter-2).d,
								Double.parseDouble(tRodLength.getText())+Rod.lst.get(submitButtonCounter-2).c,
								Rod.lst.get(submitButtonCounter-2).d,
								Double.parseDouble(tRodLength.getText()),
								Double.parseDouble(trpm.getText()),
								ch.getSelectedItem(),g,d);
				}
				
				Rod.lst.add(r);
				f2.dispose();
				f1.setEnabled(true);
				f1.toFront();	
				MyThread t=new MyThread(r);
			}
			catch(Exception e)
			{
				submitButtonCounter--;
				JOptionPane.showMessageDialog(f2,"Enter a valid Integer");
			}
		}
		else if(ae.getSource()==mClear)
		{	
			Graphics g=f1.getGraphics();
			for(int i=0;i<MyThread.threadList.size();i++)
				MyThread.threadList.get(i).stop();
			g.setColor(Color.white);
			g.fillRect(0,0,d.width,d.height);
			Rod.lst=new LinkedList<Rod>();
			submitButtonCounter=0;
		}
	}
	
	public void windowClosing(WindowEvent e)
	{
		if(e.getSource()==f1)
			System.exit(0);
		else if(e.getSource()==f2)
		{
			f2.dispose();
			f1.setEnabled(true);
			f1.toFront();	
		}
	}
}

class MyThread extends Thread
{
	Thread th;
	Rod r;
	static LinkedList<Thread>threadList=new LinkedList<Thread>();
	MyThread(Rod r)
	{
		this.r=r;
		th=new Thread(this);
		threadList.add(th);
		th.start();
	}
	public void run()
	{	
		try
		{
			r.drawRotatingRod();
		}
		catch(InterruptedException e){}
	}
}