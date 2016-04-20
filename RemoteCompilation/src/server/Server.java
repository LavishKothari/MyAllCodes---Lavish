package server;

import java.io.BufferedReader; 
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.LinkedList;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

class ServerThread implements Runnable {
	Socket client;
	String secretkey="lavishlavishlavi";
	
	PublicKey serverPublicKey,clientPublicKey;
	PrivateKey serverPrivateKey;

	DataInputStream dis;
	DataOutputStream dos;
	
	ServerThread(Socket client) {
		this.client=client;
		Thread t=new Thread(this);
		t.start();
	}
	
	public void encryptedWrite(String s) throws Exception
	{
		/*********/
		Cipher c = Cipher.getInstance("AES");
		SecretKeySpec k =new SecretKeySpec(secretkey.getBytes(), "AES");
		
		
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
		
		SecretKeySpec k =new SecretKeySpec(secretkey.getBytes(), "AES");
		
		
		c.init(Cipher.DECRYPT_MODE, k);
		barray = c.doFinal(encryptedText);
		
		System.out.println(new String(barray));
		return new String(barray);
	}
	public byte[] encryptKey(byte[] text, PublicKey key) {
		System.out.println("in encrypt: "+new String(text));
		byte[] cipherText = null;
	    try {
	    	final Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
	    	cipher.init(Cipher.ENCRYPT_MODE, key);
	    	cipherText = cipher.doFinal(text);
	    } catch (Exception e) {
	    	e.printStackTrace();
	    }
	    return cipherText;
	  }
	public void run() {
		try
		{
			dos=new DataOutputStream(client.getOutputStream());
			dis=new DataInputStream(client.getInputStream());		
			
			
			// Key exchange starting here.
			/************************************************************************/ // writing server's public key and reading client's public key.
			final KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA"); // rsa key generation
		    keyGen.initialize(1024);
		    final KeyPair key = keyGen.generateKeyPair();
		    /*
		    System.out.println(key.getPrivate());
		    System.out.println(key.getPublic());
		    */
		    serverPublicKey=key.getPublic();
		    serverPrivateKey=key.getPrivate();
		    
		    ObjectOutputStream oos=new ObjectOutputStream(client.getOutputStream());
		    oos.writeObject(serverPublicKey); // writing server's public key
		    
		    ObjectInputStream ois=new ObjectInputStream(client.getInputStream());
		    clientPublicKey=(PublicKey)ois.readObject(); // writing client's public key
		    /************************************************************************/
		    /* sending secret key by encrypting with clients public key */
		    secretkey="lavishlavishlavi"; // generating the secret key on server side and sending it to the client after encrtypting
		    byte[]secretKeyBytes=encryptKey(secretkey.getBytes(),clientPublicKey);
		    System.out.println("secret key on server = this is  a final test "+new String(secretKeyBytes));
		    dos.writeUTF(""+(secretKeyBytes).length);
		    dos.write(secretKeyBytes);
			/************************************************************************/
		    
		    
		    while(true) {
				String optionString=encryptedRead();
				if(optionString.equals(new String("EXIT")))
				{
					dis.close();
					dos.close();
					break;
				}
				String append="";String inputFileName="input.txt";
				if(optionString.equals("UPLOADINPUT"))
				{
					String contents;
					inputFileName=encryptedRead();
					contents=encryptedRead();
					writeContentsToFile(inputFileName,contents);
				}
				if(optionString.equals("COMMAND"))
				{
					File f=new File(inputFileName);
					String commandString;
					/*
					if(f.exists())
						commandString="cat "+getContentsOfFile(inputFileName)+" | "+encryptedRead();
					else */
						commandString=encryptedRead();
					executeCommand("/bin/sh -c");
					executeCommand(commandString);
					String outputFileContents=getContentsOfFile("outputFile.txt");
					String errorFileContents=getContentsOfFile("errorFile.txt");
					encryptedWrite(outputFileContents);
					encryptedWrite(errorFileContents);
				}
				else if(optionString.equals("UPLOAD"))
				{
					String fileName,contents;
					fileName=encryptedRead();
					contents=encryptedRead();
					writeContentsToFile(fileName,contents);
				}
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void writeContentsToFile(String fileName,String contents) throws IOException
	{
		PrintWriter out=new PrintWriter(fileName);
		out.print(contents);
		out.close();
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
	public void executeCommand(String commandString) 
	{
		try
		{
			//commandString="/bin/sh -c "+commandString;
			File outputFile=new File("outputFile.txt");
			File errorFile=new File("errorFile.txt");
			java.util.List<String> commandList=new LinkedList<String>();
			
			for (String retval: commandString.split(" "))
		        commandList.add(retval);
		    
			ProcessBuilder pb=new ProcessBuilder(commandList);
			pb.redirectOutput(outputFile);
			pb.redirectError(errorFile);
			/*
			pb.redirectErrorStream(true);
			*/
			Process process=pb.start();
			process.waitFor();
		}
		catch (Exception e)
		{
			try {
				writeContentsToFile("errorFile.txt", "Either this is an invalid commnad\nor\nYou are not allowed to execute this command");
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}
	
}
public class Server {
	public static int portNumber=9876;
	public static void main(String[] args) throws IOException {
		ServerSocket serverSocket=new ServerSocket(portNumber);
		while(true) {
			Socket client=serverSocket.accept();
			new ServerThread(client);
		}
		
		//serverSocket.close();
		
	}

}
