/*
	dialog box have only close button
	there are two types of dialog boxes - 
		model
		and modeless
*/

import java.awt.*;
import java.awt.event.*;

class Dlg1 extends Dialog
{
	Dlg1(Frame f)// or Dlg1(DlgFrame f)
	{	
		super(f,true);
		setSize(300,200);
		setTitle("Modal Dialog Box");
		addWindowListener(new DlgAdapter(this));
	}
}
class Dlg2 extends Dialog
{
	Dlg2(Frame f)// or Dlg2(DlgFrame f)
	{	
		super(f);
		setSize(300,200);
		setTitle("Modaless Dialog Box");
		addWindowListener(new DlgAdapter(this));
	}
}
class DlgAdapter extends WindowAdapter
{
	Dialog d;
	DlgAdapter(Dialog d)
	{
		this.d=d;
	}
	public void windowClosing(WindowEvent we)
	{
		d.dispose();
	}
}

class DlgFrame extends Frame implements ActionListener
{
	MenuItem modal,modaless;
	DlgFrame()
	{
		super("Demonstration of Dialog Boxes");
		setSize(500,500);
		setLocation(100,100);
		Menu mDlg=new Menu("Dialog");
		MenuBar mb=new MenuBar();
		
		modal=new MenuItem("Modal");
		modaless=new MenuItem("Modaless");
		
		mDlg.add(modal);
		mDlg.add(modaless);
		
		mb.add(mDlg);
		setMenuBar(mb);
		addWindowListener(new FrameAdapter());
		modal.addActionListener(this);
		modaless.addActionListener(this);
		
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==modal)
		{
			new Dlg1(this).setVisible(true);
		}
		else if(ae.getSource()==modaless)
		{
			new Dlg2(this).setVisible(true);
		}
	}	
}

class FrameAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}
class DlgDemo
{
	public static void main(String[]args)
	{
		DlgFrame df=new DlgFrame();
		df.setVisible(true);
	}
}