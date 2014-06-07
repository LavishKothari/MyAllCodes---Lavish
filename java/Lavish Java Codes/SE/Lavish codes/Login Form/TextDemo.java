import java.awt.*;
import java.awt.event.*;

class TextDemoFrame extends Frame implements ActionListener,KeyListener,FocusListener
{
	TextField tSrc,tDst;
	Button bCpy,bMov,bSel,bClr;
	TextDemoFrame()
	{
		setSize(500,250);
		setLocation(100,100);
		setLayout(new GridLayout(4,1,10,10));
		tSrc=new TextField();
		tSrc.setFont(new Font("lucida console",Font.PLAIN,24));
		tDst=new TextField();
		tDst.setFont(new Font("lucida console",Font.PLAIN,24));
		tDst.setEditable(false);
		
		bCpy=new Button("COPY");
		bCpy.setFont(new Font("lucida console",Font.PLAIN,18));
		bMov=new Button("MOVE");
		bMov.setFont(new Font("lucida console",Font.PLAIN,18));
		bSel=new Button("COPYSEL");
		bSel.setFont(new Font("lucida console",Font.PLAIN,18));
		bClr=new Button("CLEAR");
		bClr.setFont(new Font("lucida console",Font.PLAIN,18));
		
		Panel p=new Panel();
		p.setLayout(new GridLayout(1,4,5,5));
		p.add(bCpy);
		p.add(bMov);
		p.add(bSel);
		p.add(bClr);
		this.add(tSrc);
		this.add(tDst);
		this.add(new Label(""));
		this.add(p);
		addWindowListener(new TextDemoAdapter());
		
		bCpy.setEnabled(false);
		bMov.setEnabled(false);
		bSel.setEnabled(false);
		bClr.setEnabled(false);
		
		bCpy.addActionListener(this);
		bMov.addActionListener(this);
		bSel.addActionListener(this);
		bClr.addActionListener(this);
		tSrc.addFocusListener(this);
		tSrc.addKeyListener(this);
	}
	public Insets getInsets()
	{
		return new Insets(50,25,25,25);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bCpy)
		{
			tDst.setText(tSrc.getText());
		}
		else if(ae.getSource()==bMov)
		{
			tDst.setText(tSrc.getText());
			tSrc.setText("");
			bCpy.setEnabled(false);
			bMov.setEnabled(false);
			bSel.setEnabled(false);
		}
		else if(ae.getSource()==bSel)
		{
			tDst.setText(tSrc.getSelectedText());
		}
		else if(ae.getSource()==bClr)
		{
			tDst.setText("");
			tSrc.setText("");
			bCpy.setEnabled(false);
			bMov.setEnabled(false);
			bSel.setEnabled(false);
			bClr.setEnabled(false);
		}
	}
	public void keyPressed(KeyEvent ke){}
	public void keyTyped(KeyEvent ke){}
	public void keyReleased(KeyEvent ke)
	{
		if(tSrc.getText().length()==0)
		{
			bCpy.setEnabled(false);
			bMov.setEnabled(false);
			bSel.setEnabled(false);
			bClr.setEnabled(false);			
		}
		else
		{
			bCpy.setEnabled(true);
			bMov.setEnabled(true);
			bSel.setEnabled(true);
			bClr.setEnabled(true);
		}	
	}
	public void focusLost(FocusEvent fe){}
	public void focusGained(FocusEvent fe)
	{
		tSrc.select(0,tSrc.getText().length());
	}
}

class TextDemoAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent w)
	{
		System.exit(0);
	}
}
class TextDemo
{
	public static void main(String args[])
	{
		TextDemoFrame tdf=new TextDemoFrame();
		tdf.setVisible(true);
	}
}