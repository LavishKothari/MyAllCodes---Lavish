/*
	by Lavish Kothari
	to run windows application instead of java <classname> use javaw <classname>
*/

import java.awt.*;
import java.awt.event.*;
// menus are treated as buttons
class MyFrame extends Frame implements ActionListener,MouseListener,MouseMotionListener,ItemListener
{
	/* all MenuItem are datamembers of the class, 
	as we have to handle event based on these items */
	CheckboxMenuItem sLin,sRec,sElp,sFrh;
	MenuItem mExit,cBlk,cBlu,cRed,cGrn,cYlo;
	boolean draw,drawLine,drawEllipse,drawRectangle,drawFreeHand;
	Color colorObj=new Color(0,0,0); // setting default color to black.
	int px,py,startX,startY;
	MyFrame()
	{
		setSize(600,500);
		setLocation(200,100);
		//setResizable(false); 
		// this will not allow the user to resize your window
		
		//setBackground(Color.yellow); 
		// you can set the Background color in this way
		
		sLin=new CheckboxMenuItem("Line");
		sRec=new CheckboxMenuItem("Rectangle");
		sElp=new CheckboxMenuItem("Elipse");
		sFrh=new CheckboxMenuItem("Free Hand");
		
		mExit=new MenuItem("Exit");
		cBlk=new MenuItem("Black");
		cBlk.setEnabled(false);
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
		
		sLin.addItemListener(this);
		sRec.addItemListener(this);
		sElp.addItemListener(this);
		sFrh.addItemListener(this);
		
		mExit.addActionListener(this);
		
		cBlk.addActionListener(this);
		cBlu.addActionListener(this);
		cRed.addActionListener(this);
		cGrn.addActionListener(this);
		cYlo.addActionListener(this);
		
		addMouseListener(this);
		addMouseMotionListener(this);
		
	}


	public void actionPerformed(ActionEvent ae)
	{
		
		if(ae.getSource()==mExit)
		{
			dispose(); // for closing the frame
			System.exit(0); // for closing the application
		}
		
		cRed.setEnabled(true);
		cBlk.setEnabled(true);
		cBlu.setEnabled(true);
		cGrn.setEnabled(true);
		cYlo.setEnabled(true);
		
		
		if(ae.getSource()==cBlk)
		{
			cBlk.setEnabled(false);
			colorObj=Color.black;
		}
		else if(ae.getSource()==cBlu)
		{
			cBlu.setEnabled(false);
			colorObj=Color.blue;
		}
		else if(ae.getSource()==cRed)
		{
			cRed.setEnabled(false);
			colorObj=Color.red;
		}
		else if(ae.getSource()==cGrn)
		{
			cGrn.setEnabled(false);
			colorObj=Color.green;
		}
		else if(ae.getSource()==cYlo)
		{
			cYlo.setEnabled(false);
			colorObj=Color.yellow;
		}
		
	}
	public void itemStateChanged(ItemEvent ie)
	{
		drawLine=false;
		drawRectangle=false;
		drawEllipse=false;
		drawFreeHand=false;
		
		sLin.setState(false);
		sRec.setState(false);
		sElp.setState(false);
		sFrh.setState(false);
		
		
		if(ie.getSource()==sLin)
		{
			sLin.setState(true);
			drawLine=true;
		}
		if(ie.getSource()==sRec)
		{
			sRec.setState(true);
			drawRectangle=true;
		}
		if(ie.getSource()==sElp)
		{
			sElp.setState(true);
			drawEllipse=true;
		}
		if(ie.getSource()==sFrh)
		{
			sFrh.setState(true);
			drawFreeHand=true;
		}
		
	}
	
	
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mouseClicked(MouseEvent me){}
	public void mouseReleased(MouseEvent me)
	{
		if(drawLine==true)
		{
			Graphics g=getGraphics();
			g.setPaintMode();
			g.setColor(colorObj);
			g.drawLine(startX,startY,me.getX(),me.getY());
			setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		}
		
		if(drawRectangle==true)
		{
			Graphics g=getGraphics();
			g.setPaintMode();
			g.setColor(colorObj);
			g.drawRect(startX,startY,me.getX()-startX,me.getY()-startY);
			setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		}
		if(drawEllipse==true)
		{
			Graphics g=getGraphics();
			g.setPaintMode();
			g.setColor(colorObj);
			g.drawOval(startX,startY,me.getX()-startX,me.getY()-startY);
			setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		}
		if(drawFreeHand==true)
		{
			setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
			draw=false;
		}
	}
	public void mousePressed(MouseEvent me)
	{
		if(drawLine==true)
		{
			setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
			px=startX=me.getX();
			py=startY=me.getY();
		}
		if(drawRectangle==true)
		{
			setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
			px=startX=me.getX();
			py=startY=me.getY();
		}
		if(drawEllipse==true)
		{
			setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
			px=startX=me.getX();
			py=startY=me.getY();
		}
		if(drawFreeHand==true)
		{
			setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
			px=me.getX();
			py=me.getY();
		}
		
	}
	public void mouseMoved(MouseEvent me){}
	public void mouseDragged(MouseEvent me)
	{
		if(drawLine==true)
		{
			Graphics g=getGraphics();
			
			g.setColor(colorObj);
			
			g.setXORMode(new Color(255,255,255));
			
			g.drawLine(startX,startY,me.getX(),me.getY());
			g.drawLine(startX,startY,px,py);
			
			px=me.getX();
			py=me.getY();
		}
		if(drawRectangle==true)
		{
			Graphics g=getGraphics();
			g.setColor(colorObj);
			
			g.setXORMode(new Color(255,255,255));
			
			
			//for first quadrant
			g.drawRect(startX,me.getY(),me.getX()-startX,startY-me.getY());
			g.drawRect(startX,py,(px-startX),(startY-py));
			
			// for second quadrant
			g.drawRect(px,py,startX-px,startY-py);
			g.drawRect(me.getX(),me.getY(),startX-me.getX(),startY-me.getY());
			
			// for third quadrant
			g.drawRect(px,startY,startX-px,py-startY);
			g.drawRect(me.getX(),startY,startX-me.getX(),me.getY()-startY);
			
			
			// for fourth quadrant
			g.drawRect(startX,startY,me.getX()-startX,me.getY()-startY);
			g.drawRect(startX,startY,px-startX,py-startY);
			
			px=me.getX();
			py=me.getY();
		}
		if(drawEllipse==true)
		{
			Graphics g=getGraphics();
			g.setColor(colorObj);
			
			g.setXORMode(new Color(255,255,255));
			
			
			//for first quadrant
			g.drawOval(startX,me.getY(),me.getX()-startX,startY-me.getY());
			g.drawOval(startX,py,(px-startX),(startY-py));
			
			// for second quadrant
			g.drawOval(px,py,startX-px,startY-py);
			g.drawOval(me.getX(),me.getY(),startX-me.getX(),startY-me.getY());
			
			// for third quadrant
			g.drawOval(px,startY,startX-px,py-startY);
			g.drawOval(me.getX(),startY,startX-me.getX(),me.getY()-startY);
			
			
			// for fourth quadrant
			g.drawOval(startX,startY,me.getX()-startX,me.getY()-startY);
			g.drawOval(startX,startY,px-startX,py-startY);
				
			px=me.getX();
			py=me.getY();
		}
		if(drawFreeHand==true)
		{
			Graphics g=getGraphics();
			g.setColor(colorObj);
			
			if(draw==true)
				g.drawLine(px,py,me.getX(),me.getY());
				
			draw=true;
			px=me.getX();
			py=me.getY();
		}
	}
}

class MyWndAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}

public class wndapp2 
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
	}
}