import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.security.MessageDigest;
import java.util.Arrays;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class ExtractFrame extends JFrame implements ActionListener{
	JButton uploadButton,submitButton,finalSubmit;
	static JTextArea messageTextArea;
	JTextField newImageName;
	JPanel mainPanel,bottomPanel,centerPanel;static JLabel digestLabel;
	String filename;
	File imageFile;
	
	public ExtractFrame () {
		this.setSize(600, 300);
		filename="";
		this.setResizable(false);
		this.setLayout(new BorderLayout(10,10));
		uploadButton = new JButton("Upload Image");
		submitButton = new JButton("Submit");
		digestLabel=new JLabel("");
		mainPanel=new JPanel(new BorderLayout(5,5));
		messageTextArea=new JTextArea();
		bottomPanel=new JPanel(new GridLayout(3, 1,10,10));
		centerPanel=new JPanel(new BorderLayout(5,5));
		newImageName=new JTextField();
		finalSubmit=new JButton("final submit");
		messageTextArea.setEditable(false);
		centerPanel.add(new JLabel("Hidden message in the image is"),BorderLayout.NORTH);
		centerPanel.add(messageTextArea,BorderLayout.CENTER);
		centerPanel.add(digestLabel,BorderLayout.SOUTH);
		
		JPanel buttonPanel=new JPanel(new GridLayout(1, 5));
		
		bottomPanel.add(new JLabel("Enter name of Image from which messsage is to be extracted"));
		bottomPanel.add(newImageName);
		bottomPanel.add(buttonPanel);
		
		buttonPanel.add(new JLabel(""));
		buttonPanel.add(new JLabel(""));
		buttonPanel.add(finalSubmit);
		buttonPanel.add(new JLabel(""));
		buttonPanel.add(new JLabel(""));
		
		
		mainPanel.add(centerPanel,BorderLayout.CENTER);
		//mainPanel.add(bottomPanel,BorderLayout.NORTH);
		this.add(mainPanel,BorderLayout.CENTER);
		
		uploadButton.addActionListener(this);
		finalSubmit.addActionListener(this);
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		new SocketHost2();
		ExtractFrame h = new ExtractFrame();
		h.setVisible(true);
		h.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		String message=ExtractData.getMessage(SocketHost2.filename);
		System.out.println("this is the hidden message "+message);
		//String rmessage="hello";
		
		//System.out.println(rmessage.equals(message));
		//System.out.println("length of clacculated message"+ message.length());
		String newmessage="";
		for(int i=0;i<message.length();i++)
		{
			if((int)(message.charAt(i)) != 0)
				newmessage+= message.charAt(i);
		}
		
		
		MessageDigest md = MessageDigest.getInstance("MD5");
		md.reset();
        md.update(newmessage.getBytes(), 0, newmessage.getBytes().length);
        byte[]calculatedHash=md.digest();
        
        System.out.println("calculated hash code = "+new String(calculatedHash));
        System.out.println("received hash code = "+new String(SocketHost2.receivedHashCodeBytes));
        String messageDigestCheck="";
        if(Arrays.equals(calculatedHash, SocketHost2.receivedHashCodeBytes))
        {
        	messageDigestCheck="Message Integrity is preserved";
        	System.out.println("the recieved and caculated hash code are same.");
        }
        else {
        	messageDigestCheck="Message Integrity is NOT preserved";
        	System.out.println("the received and calculated hash code are not same.");
        }
        digestLabel.setText(messageDigestCheck);
		System.out.println("the hidden contents are : "+message);
		messageTextArea.setText(message);
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
			if(newImageName.getText().equals(""))
			{
				JOptionPane.showMessageDialog(this, "Fill all enteries");
			}
			else 
			{
				try {
					messageTextArea.setText(ExtractData.getMessage(newImageName.getText()));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
}

