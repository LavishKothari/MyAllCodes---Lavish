import java.util.*;
import java.awt.*;
import java.awt.event.*;

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
			g.setColor(Color.red);
			g.drawLine(200,200,300,300);
			try
			{
				Thread.sleep(1000);
			}
			catch(InterruptedException ie){}
			
			g.setColor(Color.white);
			g.drawLine(200,200,300,300);
			
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
