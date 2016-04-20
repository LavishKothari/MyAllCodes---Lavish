/*
	Notepad.java
*/
import java.io.*;
import java.awt.*;
import java.awt.event.*;

class SearchDialog extends Dialog implements ActionListener
{
	int i;
	NotepadFrame fr;
	
	Label ls,lr;
	TextField ts,tr;
	Button bf,br,bc;
	
	SearchDialog(NotepadFrame fr)
	{
		super(fr,false);
		fr.sb=new StringBuffer(fr.ta.getText());
		this.fr=fr;
		
		setTitle("Search and Replace");
		setSize(400,170);	
		ls=new Label("Search what?");
		ls.setFont(new Font("arial",Font.PLAIN,18));
		lr=new Label("Replace with");
		lr.setFont(new Font("arial",Font.PLAIN,18));
		
		ts=new TextField();
		ts.setFont(new Font("arial",Font.PLAIN,18));
		
		tr=new TextField();
		tr.setFont(new Font("arial",Font.PLAIN,18));
		
		bf=new Button("Find");
		bf.setFont(new Font("arial",Font.PLAIN,18));
		
		br=new Button("Replace");
		br.setFont(new Font("arial",Font.PLAIN,18));
		br.setEnabled(false);
		
		bc=new Button("Cancel");
		bc.setFont(new Font("arial",Font.PLAIN,18));
		
		Panel p=new Panel(new GridLayout(3,1,5,5));
		Panel p1=new Panel(new BorderLayout(5,5));
		Panel p2=new Panel(new BorderLayout(10,5));
		Panel p3=new Panel(new GridLayout(1,3,10,5));
		
		p1.add(ls,BorderLayout.WEST);
		p1.add(ts,BorderLayout.CENTER);
		
		p2.add(lr,BorderLayout.WEST);
		p2.add(tr,BorderLayout.CENTER);
			
		p3.add(bf);
		p3.add(br);
		p3.add(bc);
		
		p.add(p1);
		p.add(p2);
		p.add(p3);
		
		add(p);
		bf.addActionListener(this);
		br.addActionListener(this);
		bc.addActionListener(this);
		
		addWindowListener(new DialogAdapter(this));
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bf)
		{
			i=fr.sb.indexOf(ts.getText(),i);
			if(i==-1)//string not found
			{
				bf.setLabel("Find");
				new MsgDialog(fr,"String not found").setVisible(true);
				i=0;
				br.setEnabled(false);
				bf.setLabel("Find");
			}
			else
			{
				bf.setLabel("Find Next");
				fr.ta.select(i,i+ts.getText().length());
				fr.ta.requestFocus();
				i+=ts.getText().length();
				br.setEnabled(true);
			}
		}
		else if(ae.getSource()==br)
		{
			int j=i-ts.getText().length();
			fr.sb.replace(j,i,tr.getText());
			i=j+tr.getText().length();
			fr.ta.setText(fr.sb.toString());
			i=fr.sb.indexOf(ts.getText(),i);
			
			if(i==-1)//string not found
			{
				bf.setLabel("Find");
				new MsgDialog(fr,"String not found").setVisible(true);
				i=0;
				br.setEnabled(false);
				bf.setLabel("Find");
			}
			else
			{
				bf.setLabel("Find Next");
				fr.ta.select(i,i+ts.getText().length());
				fr.ta.requestFocus();
				i+=ts.getText().length();
			}
		}
		else if(ae.getSource()==bc)
		{
			this.dispose();
		}
		
	}
	public Insets getInsets()
	{
		return new Insets(40,15,15,15);
	}

}

class MsgDialog extends Dialog
{
	MsgDialog(NotepadFrame fr,String msg)
	{
		super(fr,true);
		setSize(170,80);
		setLocation(100,100);
		setLayout(new BorderLayout(5,5));
		Label l=new Label(msg);
		l.setFont(new Font("lucida console",Font.PLAIN,18));
		
		add(l,BorderLayout.CENTER);
		addWindowListener(new DialogAdapter(this));
	}
}


class DialogAdapter extends WindowAdapter
{
	Dialog d;
	DialogAdapter(Dialog d)
	{
		this.d=d;
	}
	public void windowClosing(WindowEvent we)
	{
		d.dispose();
	}
}
class NotepadFrame extends Frame implements ActionListener
{
	String fname="";// no space
	StringBuffer sb;
	TextArea ta;
	MenuItem mOpn,mSav,mAs,mExit,mFnR;
	NotepadFrame()
	{
		setSize(1366,768);
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
				fname=dnam+fnam;
				setTitle(fname);
				String str,s;
				str="";
				try
				{
					FileReader fr=new FileReader(fname);
					BufferedReader br=new BufferedReader(fr);
					s=br.readLine();
					while(s!=null)
					{
						str=str+s+"\n";
						s=br.readLine();
					}
					sb=new StringBuffer(str);
					ta.setText(str);
					fr.close();
				}
				catch(Exception e){}
			}
		}
		else if(ae.getSource()==mSav)
		{
			if(fname.length()==0)
				saveAs();
			else
			{
				String s=ta.getText();
				s=s.replace("\n","\r\n");
				
				try
				{
					FileWriter fw=new FileWriter(fname);
					BufferedWriter bw=new BufferedWriter(fw);
					//s=ta.getText();
					bw.write(s);
					bw.flush();
					fw.close();
				}
				catch(Exception e){}
			}
		}
		else if(ae.getSource()==mAs)
		{
			saveAs();
		}
		else if(ae.getSource()==mExit)
		{
			System.exit(0);
		}
		else if(ae.getSource()==mFnR)
		{
			new SearchDialog(this).setVisible(true);
		}
	}
	void saveAs()
	{
		FileDialog fd=new FileDialog(this,"Select File to Open",FileDialog.SAVE);
		fd.setVisible(true);
		String dnam,fnam;
		dnam=fd.getDirectory();
		fnam=fd.getFile();
	
		if(dnam!=null && fnam!=null)			
		{
			fname=dnam+fnam;
			setTitle(fname);
			String str,s;
			str="";
			try
			{
				FileWriter fw=new FileWriter(fname);
				BufferedWriter bw=new BufferedWriter(fw);
				s=ta.getText();
				s=s.replace("\n","\r\n");
				bw.write(s);
				bw.flush();
				fw.close();
			}
			catch(Exception e){}
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
