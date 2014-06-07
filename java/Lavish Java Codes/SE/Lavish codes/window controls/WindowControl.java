/*
	Label l=new Label("login");
	l.setFont(new Font("lucida console",font.PLAIN,18));
	lesetBackground(Color.blue);
	l.setForeground(Color.red());

	if Layout to set to null then you have to mannualy specy the coordinates of the awt controls.
	So we usually dont specify the setLayout(null);
	
	setLayout(null);
	l.setLocation(100,100);
	l.setSize(50,30);
	//////////////////////////////////////////////
	Button b=new Label("login");
	b.setFont(new Font("lucida console",font.PLAIN,18));
	b.setBackground(Color.blue);
	b.setForeground(Color.red());
	
	b.setLocation(100,100);
	b.setSize(50,30);
	
	
	Layout Managers
	_______________
	1) FlowLayout - default layout manager - 
	2) GridLayout - 
		setLayout(new GridLayout(2,3,10,15));
			2,3 number of rows and columns
		10 - horizontal spacing
		15 - vertical spacing
		
	3) BorderLayout - divides the full frame into five zones
		BorderLayout.EAST
		BorderLayout.WEST
		BorderLayout.NORTH
		BorderLayout.SOUTH
		BorderLayout.CENTER
		
			setLayout(new BorderLayout(10,15));
				10 - horizontal spacing
				15 - vertical spacing 
		
		
		
	panels = Borderless window/Frame
	Suppose if you have three buttons in the south of a BorderLayout
	
	then you will add all the three buttons in a single panel and then you will
	add this panel in the mainFrame
	
	
	MyFrame()
	{
		.
		.
		.
		.
		.
		.
		.
		b1=new Button("Or");
		b1=new Button("Cancel");
		b1=new Button("Help");
		
		setLayout(new BorderLayout(10,10));
		Panel p=new Panel();
		p.setLayout(new GridLayout(1,3,10,10));
		
		p.add(b1);
		p.add(b2);
		p.add(b3);
		
		add(p,BorderLayout.SOUTH);
	}
*/