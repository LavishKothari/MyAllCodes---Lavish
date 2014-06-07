/*
	dialog box have only close button
	there are two types of dialog boxes - 
		model 
		and modeless
*/

import java.awt.*;
import java.awt.event.*;

class DlgFrame extends WindowAdapter implements ActionListener
{
	Frame f1,f2,f3;
	MenuItem modal,modaless;
	
	public static void main(String[]args)
	{
		DlgFrame df=new DlgFrame();
		
	}
	DlgFrame()
	{
		f1=new Frame();
		f1.setSize(500,500);
		f1.setLocation(100,100);
		f1.setVisible(true);
		Menu menu=new Menu("Dialog");
		MenuBar mb=new MenuBar();
		
		modal=new MenuItem("Modal");
		modaless=new MenuItem("Modaless");
		
		menu.add(modal);
		menu.add(modaless);
		
		mb.add(menu);
		f1.setMenuBar(mb);
		f1.addWindowListener(this);
		modal.addActionListener(this);
		modaless.addActionListener(this);
		
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==modal)
		{
			
			Frame f2=new Frame();
			f2.setSize(200,200);
			f2.setLocation(200,200);
			f2.setVisible(true);
			f2.addWindowListener(this);
			f1.setEnabled(false);	
		}
		else if(ae.getSource()==modaless)
		{
			
		}
	}	
	
	public void windowClosing(WindowEvent we)
	{
		if(we.getSource()==f1)
		{
			System.exit(0);
		}
		else if(we.getSource()==f2)
		{
			f2.dispose();
		}
	}
}
