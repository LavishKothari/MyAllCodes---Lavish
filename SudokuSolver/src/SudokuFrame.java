import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import javax.swing.border.MatteBorder;
    

public class SudokuFrame extends JFrame implements MouseListener,ActionListener
{
	JButton sudokuSolverButton,sudokuPuzzleButton;
	JPanel absoluteMainPanel,topPanel;

	int numberArray[][];
	SudokuFrame() throws IOException, URISyntaxException
	{
		 try 
         {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
         }
          catch (Exception e) 
         {
            e.printStackTrace();
         }
        
		initializeGUIComponents();
		constructWelcomeScreen();
	}
	
	public void initializeGUIComponents()
	{
		
		sudokuSolverButton=new JButton();
		sudokuSolverButton.setIcon(new javax.swing.ImageIcon("Images/img4.png"));
		

		sudokuPuzzleButton=new JButton();
		sudokuPuzzleButton.setIcon(new javax.swing.ImageIcon("Images/img3.png")); 
		
		absoluteMainPanel=new JPanel();
		absoluteMainPanel.setOpaque(false);
		topPanel=new JPanel();
	}
	
	public void constructWelcomeScreen() throws IOException, URISyntaxException
	{
        this.setExtendedState(this.getExtendedState() | JFrame.MAXIMIZED_BOTH);
        this.setLayout(new GridBagLayout());
        this.setContentPane(new JLabel(new ImageIcon("Images/b4.jpeg")));
        this.setLayout(new FlowLayout());
        absoluteMainPanel.setLayout(new BorderLayout(10,10));
        JPanel buttonPanel=new JPanel();
        buttonPanel.setLayout(new GridLayout(3,2,10,10));
        buttonPanel.setOpaque(false);
        
        JLabel optionLabel=new JLabel("You have the following choices:");
        optionLabel.setFont(new Font("lucida console",Font.BOLD,24));
        optionLabel.setForeground(Color.BLUE);
        
        buttonPanel.add(optionLabel);
        buttonPanel.add(new JLabel());
        buttonPanel.add(sudokuSolverButton);
        buttonPanel.add(new JLabel());
        buttonPanel.add(sudokuPuzzleButton);
        buttonPanel.add(new JLabel());
        
        JPanel headingPanel=new JPanel();
        headingPanel.setOpaque(false);
        headingPanel.setLayout(new BorderLayout(10,10));
        JPanel centerHeadingPanel=new JPanel();
        centerHeadingPanel.setLayout(new GridLayout(2,1,10,10));
        centerHeadingPanel.setOpaque(false);
        
        BufferedImage myPicture1 = ImageIO.read(new File(("Images/img1.png")));
        JLabel picLabel1 = new JLabel(new ImageIcon(myPicture1));
        centerHeadingPanel.add(picLabel1);
        
        BufferedImage myPicture2 = ImageIO.read(new File(("Images/img2.png")));
        JLabel picLabel2 = new JLabel(new ImageIcon(myPicture2));
        centerHeadingPanel.add(picLabel2);
        headingPanel.add(centerHeadingPanel);
        
        absoluteMainPanel.add(buttonPanel,BorderLayout.CENTER);
        absoluteMainPanel.add(headingPanel,BorderLayout.NORTH);
        JPanel developerPanel=new JPanel();
        developerPanel.setOpaque(false);
        developerPanel.setLayout(new GridLayout(3,1,5,5));
        JLabel lbl1=new JLabel("Developed By : ");
        JLabel lbl2=new JLabel("");
        JLabel lbl3=new JLabel("Lavish Kothari");
        lbl1.setFont(new Font("lucida console",Font.BOLD,20));
        lbl2.setFont(new Font("lucida console",Font.BOLD,20));
        lbl3.setFont(new Font("lucida console",Font.BOLD,20));
        developerPanel.add(lbl1);
        developerPanel.add(lbl2);
        developerPanel.add(lbl3);
        
        absoluteMainPanel.add(developerPanel,BorderLayout.SOUTH);
        this.add(absoluteMainPanel);
        sudokuPuzzleButton.addActionListener(this);
        sudokuSolverButton.addActionListener(this);
        
	}
	
	public void constructTopPanel()
	{
		topPanel.setLayout(new BorderLayout(0,0));
	}
	
	@Override
	public void actionPerformed(ActionEvent ae) {
		System.out.println("hello lavish kothari");
		if(ae.getSource()==sudokuPuzzleButton)
		{
			absoluteMainPanel.removeAll();
			absoluteMainPanel.revalidate();
		}
		else if(ae.getSource()==sudokuSolverButton)
		{
			absoluteMainPanel.removeAll();
			/*
			 * 
			 */
			this.getContentPane().setBackground(new Color(255,253,208));
			//absoluteMainPanel.setBorder(new CompoundBorder(new LineBorder(new Color(255,253,208),50),new EmptyBorder(0,0,0,0)));
			
			absoluteMainPanel.setLayout(new BorderLayout(0,0));
			numberArray=new int[9][9];
	        
	        for(int i=0;i<9;i++)
	        {
	            for(int j=0;j<9;j++)
	            {
	                numberArray[i][j]=0;
	            }
	        }
	        int frameWidth=this.getSize().width;
	        int frameHeight=this.getSize().height;
	        
	        absoluteMainPanel.setPreferredSize(new Dimension(frameWidth,frameHeight));
	        absoluteMainPanel.setBorder(new MatteBorder(20,20,20,20,Color.black));
	        absoluteMainPanel.setBorder(new CompoundBorder(new LineBorder(Color.red,1),new EmptyBorder(0,0,0,0)));
	        JPanel superSp=new JPanel();
	        superSp.setLayout(new FlowLayout(FlowLayout.CENTER,5,5));
	        SolverPanel sp=new SolverPanel(numberArray);
	        JPanel developedPanel=new JPanel();
			developedPanel.setLayout(new FlowLayout(FlowLayout.RIGHT,5,5));
			JLabel developedLabel=new JLabel("Developed by :- Lavish Kothari");
			developedLabel.setFont(new Font("lucida console",Font.ITALIC,20));
			developedPanel.add(developedLabel);
			superSp.add(sp);
			absoluteMainPanel.add(superSp,BorderLayout.CENTER);
			absoluteMainPanel.add(developedPanel,BorderLayout.SOUTH);
			/*
			 * 
			 */
			absoluteMainPanel.revalidate();
		}
	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
