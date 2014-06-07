import java.io.*;
import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame implements ActionListener
{
	MenuItem mExit,mAdd;
	MyFrame()
	{
		setSize(600,600);
		setLocation(100,100);
		
		MenuBar mb=new MenuBar();
		Menu menu=new Menu("Menu");
		
		mExit=new MenuItem("Exit");
		mAdd=new MenuItem("Add Rod");
		
		setMenuBar(mb);
		mb.add(menu);
		
		menu.add(mAdd);
		menu.add(mExit);
		
		mAdd.addActionListener(this);
		mExit.addActionListener(this);
		addWindowListener(new MyWindowAdapter(this));
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==mExit)
		{
			System.exit(0);
		}
		else if(ae.getSource()==mAdd)
		{
			setEnabled(false);
			InputFrame inf=new InputFrame();
			inf.setVisible(true);
		}
	}
}
class InputFrame extends Frame implements ActionListener
{
	Button bSubmit,bClear;
	Choice ch;
	TextField tRodLength,trpm;
	Label lRodLength,lrpm,lColor;
	InputFrame()
	{
		setSize(400,300);
		setLocation(100,100);
		
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
		add(p);
		bSubmit.addActionListener(this);
		bClear.addActionListener(this);
		addWindowListener(new MyWindowAdapter(this));
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bClear)
		{
			System.out.println("hello Lavish");
			tRodLength.setText("");
			trpm.setText("");
		}
	}

	public Insets getInsets()
	{
		return new Insets(50,20,20,20);
	}
}

class MyWindowAdapter extends WindowAdapter
{
	InputFrame inf;
	MyFrame mf;
	MyWindowAdapter(InputFrame inf)
	{
		this.inf=inf;
	}
	MyWindowAdapter(MyFrame mf)
	{
		this.mf=mf;
	}
	
	public void windowClosing(WindowEvent e)
	{
		if(mf!=null && e.getSource()==mf)
			System.exit(0);
		else if(inf!=null && e.getSource()==inf)
		{
			inf.dispose();
			mf.setEnabled(true);
		}
	}
}


class Main
{
	public static void main(String args[])
	{
		MyFrame mf=new MyFrame();
		mf.setVisible(true);
	}
}