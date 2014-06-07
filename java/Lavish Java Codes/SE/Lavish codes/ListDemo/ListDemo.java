import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="ListDemo" width="600" height="400">
</applet>
*/
public class ListDemo extends Applet implements ActionListener,KeyListener,FocusListener
{
	TextField t;
	List lst=new List(10,true);
	Button bInsert,bLocate,bClearSelected,bDeleteSelected,bPrintSelected;
	public void paint(Graphics g)
	{
	}
	public void init()
	{
		
		setLayout(new GridLayout(1,2,10,10));
		setBackground(new Color(180,180,255));
		
		lst.setBackground(new Color(240,255,255));
		lst.setFont(new Font("lucida console",Font.PLAIN,20));
		//lst.add("hello lavish kothari");
		t=new TextField();
		t.setFont(new Font("lucida console",Font.PLAIN,28));
		
		bInsert=new Button("Insert");
		bInsert.setFont(new Font("lucida console",Font.PLAIN,20));
		bInsert.enable(false);
		
		bLocate=new Button("Locate");
		bLocate.setFont(new Font("lucida console",Font.PLAIN,20));
		bLocate.enable(false);
		
		bClearSelected=new Button("Clear Selected");
		bClearSelected.setFont(new Font("lucida console",Font.PLAIN,20));
		bClearSelected.enable(false);
		
		bDeleteSelected=new Button("Delete Selected");
		bDeleteSelected.setFont(new Font("lucida console",Font.PLAIN,20));
		bDeleteSelected.enable(false);
		
		bPrintSelected=new Button("Print Selected");
		bPrintSelected.setFont(new Font("lucida console",Font.PLAIN,20));
		bPrintSelected.enable(false);
		
		Panel p=new Panel();
		p.setLayout(new GridLayout(7,1,10,10));
		
		p.add(t);
		p.add(new Label());
		p.add(bInsert);
		p.add(bLocate);
		p.add(bClearSelected);
		p.add(bDeleteSelected);
		p.add(bPrintSelected);
		add(lst);
		add(p);
		
		bInsert.addActionListener(this);
		bLocate.addActionListener(this);
		bClearSelected.addActionListener(this);
		bDeleteSelected.addActionListener(this);
		bPrintSelected.addActionListener(this);
		
		t.addKeyListener(this);
		lst.addFocusListener(this);
	}
	public void start()
	{
	}
	public Insets getInsets()
	{
		return new Insets(20,20,20,20);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bInsert)
		{
			lst.add(t.getText());
			t.setText("");
		}
		else if(ae.getSource()==bLocate)
		{
			for(int i=0;i<lst.getItemCount();i++)
			{
				if(t.getText().equals(lst.getItem(i)))
					lst.select(i);
			}
		}
		else if(ae.getSource()==bClearSelected)
		{
			for(int i=0;i<lst.getItemCount();i++)
			{
				if(lst.isSelected(i))
					lst.deselect(i);
			}
		}
		else if(ae.getSource()==bDeleteSelected)
		{
			for(int i=0;i<lst.getItemCount();i++)
			{
				if(lst.isSelected(i))
					lst.remove(i);
			}
		}
		else if(ae.getSource()==bPrintSelected)
		{
		}
	}
	public void keyPressed(KeyEvent ke)
	{
	}
	public void keyTyped(KeyEvent ke)
	{
		if(t.getText().length()!=0)
		{
			bInsert.enable(true);
			bLocate.enable(true);
		}
		else
		{
			bInsert.enable(false);
			bLocate.enable(false);
		}
	}
	public void keyReleased(KeyEvent ke)
	{
	}
	public void focusGained(FocusEvent fe)
	{
		bClearSelected.enable(true);
		bDeleteSelected.enable(true);
		bPrintSelected.enable(true);
	}
	public void focusLost(FocusEvent fe)
	{
		
	}
}