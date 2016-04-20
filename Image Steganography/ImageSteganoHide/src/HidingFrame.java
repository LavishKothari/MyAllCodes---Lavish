import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class HidingFrame extends JFrame implements ActionListener{
	JButton uploadButton,submitButton,finalSubmit;
	JTextArea messageTextArea;
	JTextField newImageName;
	JPanel mainPanel,bottomPanel,centerPanel,buttonpanel1,buttonpanel2,buttonpanel3;
	String filename;
	File imageFile;
	
	public HidingFrame () {
		this.setSize(600, 300);
		filename="";
		this.setResizable(false);
		this.setLayout(new BorderLayout(10,10));
		uploadButton = new JButton("Upload Image");
		submitButton = new JButton("Submit");
		mainPanel=new JPanel(new BorderLayout(5,5));
		messageTextArea=new JTextArea();
		bottomPanel=new JPanel(new GridLayout(3, 1,10,10));
		centerPanel=new JPanel(new BorderLayout(5,5));
		newImageName=new JTextField("",20);
		finalSubmit=new JButton("final submit");
		
		centerPanel.add(new JLabel("enter the message to be hidden in the image"),BorderLayout.NORTH);
		centerPanel.add(messageTextArea,BorderLayout.CENTER);
		
		
		buttonpanel1=new JPanel();
		buttonpanel2=new JPanel();
		buttonpanel3=new JPanel();
		
		
		
	
		buttonpanel1.add(new JLabel("Upload Image\t"));
		buttonpanel1.add(uploadButton);
		buttonpanel1.add(new JLabel(""));
		
		bottomPanel.add(buttonpanel1);
		
		
		//buttonpanel3.add(new JLabel("Enter the name of Image"));
		//buttonpanel3.add(newImageName);
		
		
		bottomPanel.add(buttonpanel3);
		
		buttonpanel2.add(new JLabel("Submit Finally\t"));
		buttonpanel2.add(finalSubmit);
		buttonpanel2.add(new JLabel(""));
		
		bottomPanel.add(buttonpanel2);
		
		mainPanel.add(centerPanel,BorderLayout.CENTER);
		mainPanel.add(bottomPanel,BorderLayout.SOUTH);
		this.add(mainPanel,BorderLayout.CENTER);
		
		uploadButton.addActionListener(this);
		finalSubmit.addActionListener(this);
		System.out.println("jhell");
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==uploadButton)
		{
			JFileChooser chooser=new JFileChooser();
			if(chooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
			{		
				imageFile=chooser.getSelectedFile();
				filename=imageFile.getAbsolutePath();
				System.out.println(filename);
			}
		}
		else if(ae.getSource()==finalSubmit)
		{
			/*-*******************************************/
			File file = new File(filename);
			BufferedImage img=null;
			int imgSize=0;
			try {
				img  = ImageIO.read(file);
			
				ByteArrayOutputStream tmp = new ByteArrayOutputStream();
			    ImageIO.write(img, "bmp", tmp);
			    tmp.close();
			    Integer contentLength = tmp.size();
			    System.out.println(contentLength.intValue());
				
				System.out.println(img.getHeight()+" "+img.getWidth());
				
				int sizeOfEachPixel=(contentLength.intValue()*8)/(img.getWidth()*img.getHeight());
				
				System.out.println(sizeOfEachPixel);
				imgSize=(sizeOfEachPixel/8*img.getWidth()*img.getHeight()-100);
				System.out.println("this is a test related to img size "+imgSize+" "+messageTextArea.getText().length()*8);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			/*-*******************************************/
			if(messageTextArea.getText().equals("") || filename.equals(""))
			{
				JOptionPane.showMessageDialog(this, "Fill all enteries");
			}
			else if(messageTextArea.getText().length()*8>imgSize)
			{
				JOptionPane.showMessageDialog(this, "The content to be hidden is large...\nPlease select bigger image");
			}
			else 
			{
				try {
					SocketHost1.hashcode=HideData.hideMessage(filename, "a.bmp", messageTextArea.getText());
					//new SocketHost1(newImageName.getText());
					new SocketHost1("a.bmp");
					JOptionPane.showMessageDialog(this, "Data Successfully hidden in image \nImage successfully sent to receiver");
					this.dispose();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SocketHost1.ipAddress=JOptionPane.showInputDialog(null,"Enter the IP Address of Server");
		HidingFrame h = new HidingFrame();
		h.setVisible(true);
		h.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
}
