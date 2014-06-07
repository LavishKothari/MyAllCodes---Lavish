/*
	by Dmatics Sir
	to run windows application instead of java <classname> use javaw <classname>
*/
import java.util.*;
import java.awt.*;
import java.awt.event.*;
// menus are treated as buttons
class Record
{
	int ox,oy,px,py,w,h;
	Color drawColor;
	String shp;
	
	Record(int ox,int oy,int px,int py,int w, int h, Color drawColor,String shp)
	{
		this.ox=ox;
		this.oy=oy;
		this.px=px;
		this.py=py;
		this.drawColor=drawColor;
		this.w=w;
		this.h=h;
		this.shp=shp;
	}
}	
		
class PaintFrame extends Frame implements ActionListener,MouseListener,MouseMotionListener,ItemListener
{
	
	/* all MenuItem are datamembers of the class, 
	as we have to handle event based on these items */
	
	CheckboxMenuItem sLin,sRec,sElp,sFrh;
	MenuItem mExit,cBlk,cBlu,cRed,cGrn,cYlo;
	
	String shp=new String(""); // this string will store the shape to be drawn as selected by the user
	
	Color drawColor=new Color(0,0,0); // setting default color to black.
	
	int px,py,ox,oy,w,h;
	
	LinkedList <Record> lst=new LinkedList<Record>();
	
	PaintFrame()
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
		
		addWindowListener(new PaintWndAdapter(this));
		
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
			drawColor=Color.black;
		}
		else if(ae.getSource()==cBlu)
		{
			cBlu.setEnabled(false);
			drawColor=Color.blue;
		}
		else if(ae.getSource()==cRed)
		{
			cRed.setEnabled(false);
			drawColor=Color.red;
		}
		else if(ae.getSource()==cGrn)
		{
			cGrn.setEnabled(false);
			drawColor=Color.green;
		}
		else if(ae.getSource()==cYlo)
		{
			cYlo.setEnabled(false);
			drawColor=Color.yellow;
		}
		
	}
	public void itemStateChanged(ItemEvent ie)
	{
		sLin.setState(false);
		sRec.setState(false);
		sElp.setState(false);
		sFrh.setState(false);
		
		if(ie.getSource()==sLin)
		{
			sLin.setState(true);
			shp="Line";
		}
		if(ie.getSource()==sRec)
		{
			sRec.setState(true);
			shp="Rectangle";
		}
		if(ie.getSource()==sElp)
		{
			sElp.setState(true);
			shp="Ellipse";
		}
		if(ie.getSource()==sFrh)
		{
			sFrh.setState(true);
			shp="FreeHand";
		}
		
	}
	
	
	public void mouseEntered(MouseEvent me){}
	public void mouseExited(MouseEvent me){}
	public void mouseClicked(MouseEvent me){}
	public void mouseMoved(MouseEvent me){}
	public void mouseReleased(MouseEvent me)
	{
		Graphics g=getGraphics();
		g.setPaintMode();
		g.setColor(drawColor);
		
		if(shp=="Line")
			g.drawLine(ox,oy,px,py);
		else if(shp=="Rectangle")
			g.drawRect(px,py,w,h);
		else if(shp=="Ellipse")
			g.drawOval(px,py,w,h);
		
		Record r=new Record(ox,oy,px,py,w,h,drawColor,shp);
		lst.add(r);
		
		setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		w=h=0;
	}
	public void mousePressed(MouseEvent me)
	{	
		ox=px=me.getX();
		oy=py=me.getY();
		w=h=0;
		setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
	}
	public void mouseDragged(MouseEvent me)
	{
		Graphics g=getGraphics();
		g.setColor(drawColor);
		if(shp=="FreeHand")
			g.setPaintMode();
		else
			g.setXORMode(Color.white);
		
		if(shp=="Line")
			g.drawLine(ox,oy,px,py);
		else if(shp=="Rectangle")
		{	
			g.drawRect(px,py,w,h);
		}
		else if(shp=="Ellipse")
			g.drawOval(px,py,w,h);
		
		px=me.getX();
		py=me.getY();
		
		if(shp=="Line")
			g.drawLine(ox,oy,px,py);
		else if(shp=="FreeHand")
		{
			g.drawLine(ox,oy,px,py);
			ox=px;
			oy=py;
		}
		else if(shp=="Rectangle")
		{	
			w=px-ox;
			h=py-oy;
			if(w<0)
				w=-w;
			else
				px=ox;
				
			if(h<0)
				h=-h;
			else
				py=oy;
				
			g.drawRect(px,py,w,h);
		}
		else if(shp=="Ellipse")
		{	
			w=px-ox;
			h=py-oy;
			if(w<0)
				w=-w;
			else
				px=ox;
				
			if(h<0)
				h=-h;
			else
				py=oy;
				
			g.drawOval(px,py,w,h);
		}
	}
	public void paint(Graphics g)
	{
		for(int i=0;i<lst.size();i++)
		{
			Record r=lst.get(i);
			g.setColor(r.drawColor);
			if(r.shp=="Line")
				g.drawLine(r.ox,r.oy,r.px,r.py);
			if(r.shp=="Rectangle")
				g.drawRect(r.px,r.py,r.w,r.h);
			if(r.shp=="Ellipse")
				g.drawOval(r.px,r.py,r.w,r.h);
		}
			
	}
}

class PaintWndAdapter extends WindowAdapter
{
	PaintFrame pf;
	PaintWndAdapter(PaintFrame pf)
	{
		this.pf=pf;
	}
	public void windowClosing(WindowEvent we)
	{
		
		LoginFrame lf=new LoginFrame();
		lf.setVisible(true);
		
		pf.dispose();
	}
}
/*
public class wndapp3 
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
	}
}
*/
/*
	after minimizing the window and then again maximizing you will find that everything gets cleared.
	this is because the paint method is called when you maximize the window again;
	
	Solution : 
	
	we will record all the data related to shape and then again draw all the shapes in the 

*/