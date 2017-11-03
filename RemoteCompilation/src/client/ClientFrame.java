package client;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.TitledBorder;

public class ClientFrame extends JFrame implements ActionListener,KeyListener {

	String secretKey;
	PublicKey serverPublicKey,clientPublicKey;
	PrivateKey clientPrivateKey;

	int portNumber;
	String ipAddress;

	Socket server;
	DataInputStream dis;
	DataOutputStream dos;

	JTabbedPane centerTabbedPane;

	JLabel uploadStatusLabel,exportStatusLabel;
	JPanel topPanel,bottomPanel,centerPanel,mainPanel;
	JButton clearButton,submitButton,exportOutputButton,exportErrorButton,uploadButton,uploadInputFileButton;
	JTextField commandTextField;
	JTextArea inputTextArea,outputTextArea,errorTextArea;
	public ClientFrame() throws UnknownHostException, IOException {
		ipAddress=JOptionPane.showInputDialog(this, "Enter the IP Address of Server");
		if(ipAddress==null || ipAddress.length()<=0)
			System.exit(1); // if no ipaddress was filled
		createSocket();

		this.setTitle("Client Frame");
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		this.setSize(screenSize);
		this.setResizable(true);


		mainPanel=new JPanel();
		mainPanel.setLayout(new BorderLayout(5,5));

		constructTopPanel();
		mainPanel.add(topPanel,BorderLayout.NORTH);

		constructBottomPanel();
		mainPanel.add(bottomPanel,BorderLayout.SOUTH);

		constructCenterPanel();
		mainPanel.add(centerPanel,BorderLayout.CENTER);

		this.add(mainPanel);
		addWindowListener(new MyWndAdapter(dis,dos));
	}
	public void createSocket() 
	{
		try
		{		
			portNumber=9876;
			server=new Socket(ipAddress,portNumber);
			dis=new DataInputStream(server.getInputStream());
			dos=new DataOutputStream(server.getOutputStream());

			ObjectInputStream ois=new ObjectInputStream(server.getInputStream());
			serverPublicKey=(PublicKey)ois.readObject();
			System.out.println(serverPublicKey);

			/***********************************************************************************/
			final KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA"); // Generating public key and private key of client.
			keyGen.initialize(1024);
			final KeyPair key = keyGen.generateKeyPair();
			/*
			   System.out.println(key.getPrivate());
			   System.out.println(key.getPublic());
			 */
			clientPublicKey=key.getPublic();
			clientPrivateKey=key.getPrivate();

			ObjectOutputStream oos=new ObjectOutputStream(server.getOutputStream());
			oos.writeObject(clientPublicKey);
			/***********************************************************************************/

			int len=Integer.parseInt(dis.readUTF());
			byte[]secretKeyBytes=new byte[len];
			dis.readFully(secretKeyBytes,0,len);
			System.out.println("secret key on client. = this is a final test "+new String(secretKeyBytes));
			secretKeyBytes=decryptKey(secretKeyBytes,clientPrivateKey);
			secretKey=new String(secretKeyBytes);
		}
		catch (Exception e)
		{
			JOptionPane.showMessageDialog(this, e.toString()+"\nEither the IP Address you Entered is not valid, or the server is not online\n\nExiting...!!","Connection Error",JOptionPane.ERROR_MESSAGE);
			System.exit(1);
		}
	}
	public byte[] decryptKey(byte[] text, PrivateKey key) {
		System.out.println(text.length);
		System.out.println("in decrypt : "+new String(text));
		byte[] dectyptedText = null;
		try {
			final Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");

			cipher.init(Cipher.DECRYPT_MODE, key);
			dectyptedText = cipher.doFinal(text);

		} catch (Exception ex) {
			System.out.println("here an exception is generated");
			ex.printStackTrace();
		}
		return dectyptedText;
		//return new String(dectyptedText,StandardCharsets.UTF_8);
	}
	public void constructTopPanel()
	{
		topPanel=new JPanel();
		topPanel.setLayout(new BorderLayout(5, 5));

		uploadStatusLabel=new JLabel();

		clearButton=new JButton("Clear");
		submitButton=new JButton("Submit");
		uploadButton=new JButton("Upload Source Code");
		uploadInputFileButton=new JButton("Upload input");
		clearButton.addActionListener(this);
		submitButton.addActionListener(this);
		uploadButton.addActionListener(this);
		uploadInputFileButton.addActionListener(this);

		JLabel enterCmd=new JLabel("Enter the command");
		enterCmd.setFont(new Font("Lucida Console", 1, 12));

		commandTextField=new JTextField();
		commandTextField.setFont(new Font("Lucida Console", 1, 12));
		commandTextField.addKeyListener(this);

		topPanel.add(enterCmd,BorderLayout.WEST);
		topPanel.add(commandTextField,BorderLayout.CENTER);

		JPanel uploadButtonPanel=new JPanel();
		uploadButtonPanel.add(uploadButton);
		//uploadButtonPanel.add(uploadInputFileButton);

		topPanel.add(uploadButtonPanel,BorderLayout.NORTH);

		JPanel buttonPanel=new JPanel();
		buttonPanel.setLayout(new GridLayout(1, 2));
		buttonPanel.add(submitButton);
		buttonPanel.add(clearButton);
		topPanel.add(buttonPanel,BorderLayout.EAST);

	}
	public void constructBottomPanel()
	{
		bottomPanel=new JPanel();
		bottomPanel.setLayout(new BorderLayout(5,5));

		exportStatusLabel=new JLabel("");
		exportStatusLabel.setFont(new Font("Lucida console", 1, 12));

		exportOutputButton=new JButton("Export Output");
		exportOutputButton.addActionListener(this);
		exportErrorButton=new JButton("Export Error");
		exportErrorButton.addActionListener(this);

		JPanel innerPanel=new JPanel();
		innerPanel.add(exportOutputButton);
		innerPanel.add(exportErrorButton);
		innerPanel.add(exportStatusLabel);

		bottomPanel.add(innerPanel,BorderLayout.WEST);
	}
	public void constructCenterPanel()
	{
		centerTabbedPane=new JTabbedPane();

		centerPanel=new JPanel();
		centerPanel.setLayout(new BorderLayout(5,5));
		inputTextArea=new JTextArea();
		outputTextArea=new JTextArea();
		errorTextArea=new JTextArea();

		inputTextArea.setEditable(false);
		outputTextArea.setEditable(false);
		errorTextArea.setEditable(false);

		/*
		   inputTextArea.setColumns(112);
		   outputTextArea.setColumns(112);
		   errorTextArea.setColumns(112);
		 */

		inputTextArea.setRows(1);
		inputTextArea.setFont(new Font("Lucida console", 1, 12));
		outputTextArea.setRows(35);
		outputTextArea.setFont(new Font("Lucida console", 1, 12));
		errorTextArea.setRows(35);
		errorTextArea.setFont(new Font("Lucida console", 1, 12));



		JPanel innerTopPanel,innerCenterPanelOutput,innerCenterPanelError;
		innerTopPanel=new JPanel(new BorderLayout(5,5));
		innerCenterPanelOutput=new JPanel();
		innerCenterPanelError=new JPanel();
		innerCenterPanelOutput.setLayout(new BorderLayout(5,5));
		innerCenterPanelError.setLayout(new BorderLayout(5,5));
		JScrollPane jspOutput = new JScrollPane(outputTextArea,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		JScrollPane jspInput = new JScrollPane(inputTextArea,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		JScrollPane jspError = new JScrollPane(errorTextArea,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		/*
		   outputTextArea.setBounds(5, 35, 385, 330);
		   outputTextArea.setLineWrap(true);
		   outputTextArea.setWrapStyleWord(true);
		 */
		jspOutput.setBounds(20, 30, 100, 40);// You have to set bounds for all the controls and containers incas eof null layout
		jspInput.setBounds(20, 30, 100, 40);
		jspError.setBounds(20, 30, 100, 40);


		TitledBorder titleTop = BorderFactory.createTitledBorder("Input command");
		titleTop.setTitleColor(Color.RED);
		innerTopPanel.setBorder(titleTop);

		TitledBorder titleCenterOutput = BorderFactory.createTitledBorder("Output");
		titleCenterOutput.setTitleColor(Color.RED);
		innerCenterPanelOutput.setBorder(titleCenterOutput);

		TitledBorder titleCenterError = BorderFactory.createTitledBorder("Error / Warnings");
		titleCenterError.setTitleColor(Color.RED);
		innerCenterPanelError.setBorder(titleCenterError);

		innerTopPanel.add(jspInput,BorderLayout.CENTER);
		innerCenterPanelOutput.add(jspOutput);// adding the scroll pane
		innerCenterPanelError.add(jspError);

		centerTabbedPane.addTab("Output", innerCenterPanelOutput);
		centerTabbedPane.addTab("Error / Warnings", innerCenterPanelError);

		centerPanel.add(innerTopPanel,BorderLayout.NORTH);
		centerPanel.add(centerTabbedPane,BorderLayout.CENTER);
	}

	public void submitCommand() throws Exception
	{
		inputTextArea.setText(commandTextField.getText());
		if(inputTextArea.getText().equals(""))
		{
			inputTextArea.setText("");
			outputTextArea.setText("");
			errorTextArea.setText("");
			commandTextField.setText("");
			return;
		}
		else
		{
			try {
				encryptedWrite("COMMAND");
				System.out.println("you are here");
				encryptedWrite(commandTextField.getText()); // command text
				System.out.println("second you are here");
				outputTextArea.setText(encryptedRead());
				errorTextArea.setText(encryptedRead());

				if(!errorTextArea.getText().equals(""))
					centerTabbedPane.setSelectedIndex(1);
				if(!outputTextArea.getText().equals(""))
					centerTabbedPane.setSelectedIndex(0);

			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

			commandTextField.setText("");
		}
	}
	public String getContentsOfFile(String filename) throws IOException
	{
		String contents="",tempString;
		FileInputStream fis=new FileInputStream(filename);
		BufferedReader br=new BufferedReader(new InputStreamReader(fis));

		while((tempString=br.readLine())!=null)
		{
			contents+=tempString+"\n";
		}
		br.close();
		fis.close();
		return contents;
	}

	public void writeContentsToFile(String fileName,String contents) throws IOException
	{
		PrintWriter out=new PrintWriter(fileName);
		out.print(contents);
		out.close();
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==clearButton)
			commandTextField.setText("");
		else if(ae.getSource()==submitButton)
			try {
				submitCommand();
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		else if(ae.getSource()==exportOutputButton)
		{
			JFileChooser chooser=new JFileChooser();
			if(chooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
			{
				try {
					writeContentsToFile(chooser.getSelectedFile().getAbsolutePath(), outputTextArea.getText());
				} catch (IOException e) {
					e.printStackTrace();
				}
				exportStatusLabel.setText("");
				JOptionPane.showMessageDialog(this, "File Saved Successfully");
			}
			else
			{
				JOptionPane.showMessageDialog(this, "File not Saved Successfully");
				exportStatusLabel.setText("");
			}
		}
		else if(ae.getSource()==exportErrorButton)
		{
			JFileChooser chooser=new JFileChooser();
			if(chooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
			{
				try {
					writeContentsToFile(chooser.getSelectedFile().getAbsolutePath(), errorTextArea.getText());
				} catch (IOException e) {
					e.printStackTrace();
				}
				exportStatusLabel.setText("");
				JOptionPane.showMessageDialog(this, "File Saved Successfully");
			}
			else
			{
				exportStatusLabel.setText("");
				JOptionPane.showMessageDialog(this, "File not Saved Successfully");
			}
		}
		else if(ae.getSource()==uploadButton)
		{
			JFileChooser fileChooser=new JFileChooser();
			if(fileChooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
			{
				try {
					/*
					 * first send "UPLOAD"
					 * then send the file name - the name of file selected by user
					 * then send the contents of the file.
					 * */
					encryptedWrite("UPLOAD");
					encryptedWrite(fileChooser.getSelectedFile().getName());
					encryptedWrite(getContentsOfFile(fileChooser.getSelectedFile().getAbsolutePath()));
				} catch (IOException e) {
					e.printStackTrace();
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				uploadStatusLabel.setText("");
				JOptionPane.showMessageDialog(this, "Upload on the server Successful");
			}
			else
			{
				uploadStatusLabel.setText("Upload not Successful");
				JOptionPane.showMessageDialog(this, "Upload on the server not Successful");
			}
		}
		else if(ae.getSource()==uploadInputFileButton)
		{
			JFileChooser fileChooser=new JFileChooser();
			if(fileChooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
			{
				try {
					/*
					 * first send "UPLOAD"
					 * then send the file name - the name of file selected by user
					 * then send the contents of the file.
					 * */
					encryptedWrite("UPLOADINPUT");
					encryptedWrite(fileChooser.getSelectedFile().getName());
					encryptedWrite(getContentsOfFile(fileChooser.getSelectedFile().getAbsolutePath()));
				} catch (IOException e) {
					e.printStackTrace();
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				uploadStatusLabel.setText("");
				JOptionPane.showMessageDialog(this, "Upload on the server Successful");
			}
			else
			{
				uploadStatusLabel.setText("Upload not Successful");
				JOptionPane.showMessageDialog(this, "Upload on the server not Successful");
			}
		}
	}
	@Override
		public void keyTyped(KeyEvent e) {

		}
	@Override
		public void keyPressed(KeyEvent e) {
			if(e.getKeyCode() == KeyEvent.VK_ENTER){
				try {
					submitCommand();
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
	@Override
		public void keyReleased(KeyEvent e) {

		}
	public void encryptedWrite(String s) throws Exception
	{
		/*********/
		Cipher c = Cipher.getInstance("AES");
		SecretKeySpec k =new SecretKeySpec(secretKey.getBytes(), "AES");


		c.init(Cipher.ENCRYPT_MODE, k);
		byte[] barray = c.doFinal(s.getBytes());

		dos.writeUTF(barray.length+"");
		dos.write(barray);
		System.out.println(new String(barray));
	}
	public String encryptedRead() throws Exception
	{
		int len=Integer.parseInt(dis.readUTF());
		byte[]encryptedText=new byte[len];
		dis.readFully(encryptedText,0,len);
		byte[]barray;;

		Cipher c = Cipher.getInstance("AES");

		SecretKeySpec k =new SecretKeySpec(secretKey.getBytes(), "AES");


		c.init(Cipher.DECRYPT_MODE, k);
		barray = c.doFinal(encryptedText);
		System.out.println(new String(barray));
		return new String(barray);
	}

}

class MyWndAdapter extends WindowAdapter
{
	DataInputStream dis;
	DataOutputStream dos;
	MyWndAdapter(DataInputStream dis,DataOutputStream dos)
	{
		this.dis=dis;
		this.dos=dos;
	}
	public void encryptedWrite(String s) throws IOException
	{
		dos.writeUTF(s);
	}
	public void windowClosing(WindowEvent we)
	{
		try {
			encryptedWrite("EXIT");
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.exit(0);
	}
}
