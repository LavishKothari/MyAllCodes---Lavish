/*
	Notepad.java
*/
import java.io.*;
import java.awt.*;
import java.awt.event.*;

class NotepadFrame extends Frame implements ActionListener
{
	String fname="";// no space
	StringBuffer sb;
	TextArea ta;
	MenuItem mOpn,mSav,mAs,mExit,mFnR;
	NotepadFrame()
	{
		setSize(500,500);
		setLocation(0,0);
		
		
		MenuBar mb=new MenuBar();
		Menu mFile,mEdit;
		mFile=new Menu("File");
		mEdit=new Menu("Edit");
		
		mOpn=new MenuItem("Open");
		mSav=new MenuItem("Save");
		mAs=new MenuItem("Save As");
		mExit=new MenuItem("Exit");
		mFnR=new MenuItem("Find and Replace");
		
		mb.add(mFile);
		mb.add(mEdit);
		
		mFile.add(mOpn);
		mFile.add(mSav);
		mFile.add(mAs);
		mFile.addSeparator();
		mFile.add(mExit);
		mEdit.add(mFnR);
		
		setMenuBar(mb);
		
		ta=new TextArea();
		ta.setFont(new Font("arial",Font.PLAIN,18));
		setLayout(new BorderLayout(1,1));
		add(ta,BorderLayout.CENTER);
		
		addWindowListener(new NotepadAdapter());
		
		mOpn.addActionListener(this);
		mSav.addActionListener(this);
		mAs.addActionListener(this);
		mExit.addActionListener(this);
		mFnR.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==mOpn)
		{
			FileDialog fd=new FileDialog(this,"Select File to Open",FileDialog.LOAD);
			fd.setVisible(true);
			String dnam,fnam;
			dnam=fd.getDirectory();
			fnam=fd.getFile();
			
			if(dnam!=null && fnam!=null)
			{
				fname=dnam+"\\"+fnam;
				setTitle("Notepad - "+fname);
				try
				{
					StringBuffer str=new StringBuffer();
					File f=new File(dnam+fnam);
					FileInputStream fis=new FileInputStream(f);
					int ch;
					while((ch=fis.read())!=-1)
					{
						str.append((char)ch);
					}
					ta.setText(str.toString());
				}
				catch(IOException ie){}
			}
		}
		else if(ae.getSource()==mSav)
		{
			
			FileDialog fd=new FileDialog(this,"Select File to Open",FileDialog.SAVE);
			fd.setVisible(true);
			String dnam,fnam;
			dnam=fd.getDirectory();
			fnam=fd.getFile();
			
			if(dnam!=null && fnam!=null)
			{
				try
				{
					File f=new File(dnam+fnam);
					f.createNewFile();
					StringBuffer str=new StringBuffer(ta.getText());
					
					FileOutputStream fos=new FileOutputStream(f);
					
					char ch[]=ta.getText().toCharArray();
					for(int i=0;i<ch.length;i++)
						fos.write((int)ch[i]);
				}
				catch(IOException ie){}
			}
		}
		else if(ae.getSource()==mAs)
		{
		}
		else if(ae.getSource()==mExit)
		{
			System.exit(0);
		}
		else if(ae.getSource()==mFnR)
		{
		}
	}
}

class NotepadAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}
class Notepad
{
	public static void main(String args[])
	{
		new NotepadFrame().setVisible(true);
	}
}