/*
	window application 
	creating a small paint window
	The window will provide user with an option to choose different shapes to be drawn in different color
	this is the starting program for this application
	This program will just create a basic outline
	
	This program also implements the Exit button 
*/
/*
	to run windows application instead of java <classname> use javaw <classname>
*/

import java.awt.*;
import java.awt.event.*;
// menus are treated as buttons
class MyFrame extends Frame implements ActionListener,MouseListener,MouseMotionListener
{
	/* all MenuItem are datamembers of the class, 
	as we have to handle event based on these items */
	MenuItem sLin,sRec,sElp,sFrh;
	MenuItem mExit,cBlk,cBlu,cRed,cGrn,cYlo;
	
	MyFrame()
	{
		setSize(600,500);
		setLocation(200,100);
		//setResizable(false); 
		// this will not allow the user to resize your window
		
		//setBackground(Color.yellow); 
		// you can set the Background color in this way
		
		sLin=new MenuItem("Line");
		sRec=new MenuItem("Rectangle");
		sElp=new MenuItem("Elipse");
		sFrh=new MenuItem("Free Hand");
		
		mExit=new MenuItem("Exit");
		cBlk=new MenuItem("Black");
		cRed=new MenuItem("Red");
		cGrn=new MenuItem("Green");
		cYlo=new MenuItem("Yellow");
		cBlu=new MenuItem("Blue");
		
		Menu mShape=new Menu("Shape");
		Menu mColor=new Menu("Color");
		
		mShape.add(sLin);
		mShape.add(sRec);
		mShape.add(sElp);
		mShape.add(sFrh);
		mShape.addSeparator(); // to add separator
		mShape.add(mExit);
		
		mColor.add(cBlk);
		mColor.add(cBlu);
		mColor.add(cRed);
		mColor.add(cGrn);
		mColor.add(cYlo);
		
		MenuBar mb=new MenuBar();
		mb.add(mShape);
		mb.add(mColor);
		
		setMenuBar(mb);
		
		addWindowListener(new MyWndAdapter());
		mExit.addActionListener(this);
	}


	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==mExit)
		{
			dispose(); // closes the frame
			System.exit(0); // for closing the application
		}
	}
	
	public void mouseClicked(MouseEvent me){}
	public void mousePressed(MouseEvent me){}
	public void mouseEntered(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	
	public void mouseMoved(MouseEvent me){}
	public void mouseDragged(MouseEvent me){}
}
class MyWndAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}

public class wndapp 
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
	}
}