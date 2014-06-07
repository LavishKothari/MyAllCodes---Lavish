import java.awt.*;
import java.awt.event.*;
class LoginFrame extends Frame implements ActionListener
{
	TextField tLog,tPas;
	Button bSubmit,bCancel,bHelp;
	
	LoginFrame() 
	{
		super("Login");
		setSize(400,225);
		setLocation(100,100);
		setResizable(false);
		
		Label l1=new Label("User-ID");
		l1.setFont(new Font("lucida console",Font.PLAIN,18));
		Label l2=new Label("Password");
		l2.setFont(new Font("lucida console",Font.PLAIN,18));
		
		tLog=new TextField();
		tLog.setFont(new Font("lucida console",Font.PLAIN,18));
		tPas=new TextField();
		tPas.setFont(new Font("lucida console",Font.PLAIN,18));
		tPas.setEchoChar('*');
		
		bSubmit=new Button("Submit");
		bSubmit.setFont(new Font("lucida console",Font.PLAIN,18));
		bSubmit.setBackground(new Color(220,255,220));
		
		bCancel=new Button("Cancel");
		bCancel.setFont(new Font("lucida console",Font.PLAIN,18));
		bCancel.setBackground(new Color(255,220,220));
		
		bHelp=new Button("Help");
		bHelp.setFont(new Font("lucida console",Font.PLAIN,18));
		bHelp.setBackground(new Color(220,220,255));
		
		
		setLayout(new GridLayout(4,1,10,10));
		
		Panel p1=new Panel();
		p1.setLayout(new BorderLayout(23,5));
		p1.add(l1,BorderLayout.WEST);
		p1.add(tLog,BorderLayout.CENTER);
		
		Panel p2=new Panel();
		p2.setLayout(new BorderLayout(5,5));
		p2.add(l2,BorderLayout.WEST);
		p2.add(tPas,BorderLayout.CENTER);
		
		Panel p3=new Panel();
		p3.setLayout(new GridLayout(1,3,15,5));
		p3.add(bSubmit);
		p3.add(bCancel);
		p3.add(bHelp);
		
		add(p1);
		add(p2);
		add(new Label());
		add(p3);
		
		addWindowListener(new LoginWindowAdapter());
		bCancel.addActionListener(this);
		bSubmit.addActionListener(this);
	}
	public Insets getInsets()
	{
		return new Insets(50,25,25,25);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==bCancel)
		{
			System.exit(0);
		}
		else if(ae.getSource()==bSubmit)
		{
			System.out.println("Hello lavish kothari");
			if(tLog.getText().equals("Lavish") && tPas.getText().equalsIgnoreCase("Paint"))
			{	
				PaintFrame pf=new PaintFrame();
				pf.setVisible(true);
				this.dispose();
			}
			
		}
	}
}

class LoginWindowAdapter extends WindowAdapter
{
	public void windowClosing(WindowEvent we)
	{
		System.exit(0);
	}
}

class Login
{
	public static void main(String args[]) throws InterruptedException
	{
		LoginFrame lf=new LoginFrame();
		lf.setVisible(true);
	}
}