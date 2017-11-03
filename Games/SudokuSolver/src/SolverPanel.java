import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.AbstractAction;
import javax.swing.ActionMap;
import javax.swing.InputMap;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.KeyStroke;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import javax.swing.border.MatteBorder;


public class SolverPanel extends JPanel implements MouseListener,ActionListener
{
	JPanel mainPanel,buttonPanel;
	JPanel[][] cellPanelArray;
	JPanel currentCellPanel;
	static JLabel labelArray[][];
	JLabel currentCellLabel;
	static int numberArray[][];
	int currentX,currentY;
	JButton submitButton,exitButton,clearButton;

	SolverPanel(int [][] numberArray)
	{
		this.setBorder(new MatteBorder(5,5,5,5,Color.black));
		this.numberArray=numberArray;
		initialiseFrameComponents();
		//this.setPreferredSize(new Dimension(600,600));

		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				mainPanel.add(cellPanelArray[i][j]);
			}
		}
		//parentPanel.setLayout(new FlowLayout());
		this.setLayout(new BorderLayout(0,0));
		this.add(mainPanel,BorderLayout.NORTH);
		this.add(buttonPanel,BorderLayout.SOUTH);


		buttonPanel.add(clearButton);
		buttonPanel.add(submitButton);
		buttonPanel.add(exitButton);

		keyBinding(mainPanel);
		submitButton.addActionListener(this);
		clearButton.addActionListener(this);
		exitButton.addActionListener(this);
	}


	public void keyBinding(JPanel myPanel)
	{

		//////////////////////////////////////////////////
		InputMap im = myPanel.getInputMap(JPanel.WHEN_IN_FOCUSED_WINDOW);
		ActionMap am =myPanel.getActionMap();

		im.put(KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, 0), "RightArrow");
		im.put(KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, 0), "LeftArrow");
		im.put(KeyStroke.getKeyStroke(KeyEvent.VK_UP, 0), "UpArrow");
		im.put(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 0), "DownArrow");
		im.put(KeyStroke.getKeyStroke("1"), "pressed1");
		im.put(KeyStroke.getKeyStroke("2"), "pressed2");
		im.put(KeyStroke.getKeyStroke("3"), "pressed3");
		im.put(KeyStroke.getKeyStroke("4"), "pressed4");
		im.put(KeyStroke.getKeyStroke("5"), "pressed5");
		im.put(KeyStroke.getKeyStroke("6"), "pressed6");
		im.put(KeyStroke.getKeyStroke("7"), "pressed7");
		im.put(KeyStroke.getKeyStroke("8"), "pressed8");
		im.put(KeyStroke.getKeyStroke("9"), "pressed9");
		im.put(KeyStroke.getKeyStroke(KeyEvent.VK_BACK_SPACE,0), "pressedb");


		am.put("RightArrow", new ArrowAction("RightArrow",this));
		am.put("LeftArrow", new ArrowAction("LeftArrow",this));
		am.put("UpArrow", new ArrowAction("UpArrow",this));
		am.put("DownArrow", new ArrowAction("DownArrow",this));
		am.put("pressed1", new ArrowAction("pressed1",this));
		am.put("pressed2", new ArrowAction("pressed2",this));
		am.put("pressed3", new ArrowAction("pressed3",this));
		am.put("pressed4", new ArrowAction("pressed4",this));
		am.put("pressed5", new ArrowAction("pressed5",this));
		am.put("pressed6", new ArrowAction("pressed6",this));
		am.put("pressed7", new ArrowAction("pressed7",this));
		am.put("pressed8", new ArrowAction("pressed8",this));
		am.put("pressed9", new ArrowAction("pressed9",this));
		am.put("pressedb", new ArrowAction("pressedb",this));

	}


	public void initialiseFrameComponents()
	{

		mainPanel=new JPanel();
		mainPanel.setLayout(new GridLayout(9,9,0,0));
		mainPanel.setPreferredSize(new Dimension(600,600));


		currentCellLabel=new JLabel();

		labelArray=new JLabel[9][9];
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]==0)
					labelArray[i][j]=new JLabel("");
				else
					labelArray[i][j]=new JLabel(numberArray[i][j]+"");
				labelArray[i][j].setFont(new Font("lucida console",Font.BOLD,40));
			}
		}

		cellPanelArray=new JPanel[9][9];
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cellPanelArray[i][j]=new JPanel();
				cellPanelArray[i][j].add(labelArray[i][j]);
				cellPanelArray[i][j].setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				cellPanelArray[i][j].addMouseListener(this);
				int x=i/3;
				int y=j/3;
				if((x+y)%2==0)
				{
					cellPanelArray[i][j].setBackground(new Color(255,180,180));
				}
				else
				{
					cellPanelArray[i][j].setBackground(new Color(180,180,255));
				}
			}
		}

		currentCellPanel=new JPanel();

		buttonPanel=new JPanel();
		buttonPanel.setLayout(new GridLayout(1,3,0,0));

		submitButton=new JButton("SUBMIT");
		exitButton=new JButton("EXIT");
		clearButton=new JButton("CLEAR ALL");

	}

	@Override
		public void mouseClicked(MouseEvent me) {
			// TODO Auto-generated method stub
			currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(me.getSource()==cellPanelArray[i][j])
					{
						cellPanelArray[i][j].setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));
						currentCellPanel=cellPanelArray[i][j];
						currentCellLabel=labelArray[i][j];
						currentX=i;
						currentY=j;
					}

				}
			}
		}

	public void printNumberArray()
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				System.out.print(numberArray[i][j]);
			}
			System.out.println();
		}
	}
	@Override
		public void mouseEntered(MouseEvent me) {
			// TODO Auto-generated method stub
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(me.getSource()==cellPanelArray[i][j])
						cellPanelArray[i][j].setBorder(new CompoundBorder(new LineBorder(Color.RED,5),new EmptyBorder(0,0,0,0)));


				}
			}

		}

	@Override
		public void mouseExited(MouseEvent me) {
			// TODO Auto-generated method stub
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(me.getSource()==cellPanelArray[i][j])
						cellPanelArray[i][j].setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				}
			}

			currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));
		}

	@Override
		public void mousePressed(MouseEvent arg0) {
			// TODO Auto-generated method stub

		}

	@Override
		public void mouseReleased(MouseEvent arg0) {
			// TODO Auto-generated method stub

		}


	@Override
		public void actionPerformed(ActionEvent ae) {

			if(ae.getSource()==submitButton)
			{

				if(!Sudoku.isValidSudoku(numberArray))
				{
					JOptionPane.showMessageDialog(null, "The Sudoku you entered is not valid...!!!","ERROR",JOptionPane.ERROR_MESSAGE);
				}
				else
				{
					while(true)
					{
						if(!Sudoku.isSudokuFilled(numberArray))
							Sudoku.solveSudoku(numberArray);

						else
							break;
					}
				}
				updateFrame(numberArray);
				/*this.dispose();
				  SudokuFrame sf=new SudokuFrame(numberArray);
				  sf.setVisible(true);
				  sf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);*/

			}
			else if(ae.getSource()==clearButton)
			{
				for(int i=0;i<9;i++)
				{
					for(int j=0;j<9;j++)
					{
						numberArray[i][j]=0;
					}
				}

				updateFrame(numberArray);
			}
			else if(ae.getSource()==exitButton)
			{
				System.exit(1);
			}	

		}

	public static void updateFrame(int [][] numberArray)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(numberArray[i][j]!=0)
					labelArray[i][j].setText(numberArray[i][j]+"");
				else
					labelArray[i][j].setText("");
			}
		}
	}
}
class ArrowAction extends AbstractAction {

	private String cmd;
	SolverPanel sf;
	ArrowAction(String cmd,SolverPanel sf)
	{	
		this.sf=sf;
		this.cmd = cmd;
	}

	@Override
		public void actionPerformed(ActionEvent e) {
			if (cmd.equalsIgnoreCase("LeftArrow"))
			{
				sf.currentY--;
				if(sf.currentY==-1)
				{
					sf.currentY=8;
				}
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				sf.currentCellPanel=sf.cellPanelArray[sf.currentX][sf.currentY];
				sf.currentCellLabel=sf.labelArray[sf.currentX][sf.currentY];
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));

			}

			else if (cmd.equalsIgnoreCase("RightArrow")) 
			{
				sf.currentY++;
				if(sf.currentY==9)
				{
					sf.currentY=0;
				}
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				sf.currentCellPanel=sf.cellPanelArray[sf.currentX][sf.currentY];
				sf.currentCellLabel=sf.labelArray[sf.currentX][sf.currentY];
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));

			}

			else if (cmd.equalsIgnoreCase("UpArrow")) {

				sf.currentX--;

				if(sf.currentX==-1)
				{
					sf.currentX=8;
				}
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				sf.currentCellPanel=sf.cellPanelArray[sf.currentX][sf.currentY];
				sf.currentCellLabel=sf.labelArray[sf.currentX][sf.currentY];
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));


			}

			else if (cmd.equalsIgnoreCase("DownArrow"))
			{
				sf.currentX++;

				if(sf.currentX==9)
				{
					sf.currentX=0;
				}
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.BLACK,1),new EmptyBorder(0,0,0,0)));
				sf.currentCellPanel=sf.cellPanelArray[sf.currentX][sf.currentY];
				sf.currentCellLabel=sf.labelArray[sf.currentX][sf.currentY];
				sf.currentCellPanel.setBorder(new CompoundBorder(new LineBorder(Color.GREEN,5),new EmptyBorder(0,0,0,0)));

			}

			else if (cmd.equalsIgnoreCase("pressed1"))
			{
				sf.currentCellLabel.setText("1");
				sf.numberArray[sf.currentX][sf.currentY]=1;
			}
			else if (cmd.equalsIgnoreCase("pressed2"))
			{
				sf.currentCellLabel.setText("2");
				sf.numberArray[sf.currentX][sf.currentY]=2;
			}

			else if (cmd.equalsIgnoreCase("pressed3"))
			{
				sf.currentCellLabel.setText("3");
				sf.numberArray[sf.currentX][sf.currentY]=3;
			}

			else if (cmd.equalsIgnoreCase("pressed4"))
			{
				sf.currentCellLabel.setText("4");
				sf.numberArray[sf.currentX][sf.currentY]=4;
			}

			else if (cmd.equalsIgnoreCase("pressed5"))
			{
				sf.currentCellLabel.setText("5");
				sf.numberArray[sf.currentX][sf.currentY]=5;
			}

			else if (cmd.equalsIgnoreCase("pressed6"))
			{
				sf.currentCellLabel.setText("6");
				sf.numberArray[sf.currentX][sf.currentY]=6;
			}

			else if (cmd.equalsIgnoreCase("pressed7"))
			{
				sf.currentCellLabel.setText("7");
				sf.numberArray[sf.currentX][sf.currentY]=7;
			}

			else if (cmd.equalsIgnoreCase("pressed8"))
			{
				sf.currentCellLabel.setText("8");
				sf.numberArray[sf.currentX][sf.currentY]=8;
			}

			else if (cmd.equalsIgnoreCase("pressed9"))
			{
				sf.currentCellLabel.setText("9");
				sf.numberArray[sf.currentX][sf.currentY]=9;
			}

			else if (cmd.equalsIgnoreCase("pressedb"))
			{
				sf.currentCellLabel.setText("");
				sf.numberArray[sf.currentX][sf.currentY]=0;
			}


		}


}

