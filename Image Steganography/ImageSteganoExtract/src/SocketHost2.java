// this is server

import java.awt.image.BufferedImage;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.imageio.ImageIO;

public class SocketHost2 {
	int portNumber=5000;
	String secretKey;
	public static String filename;
	DataInputStream dis;
	BufferedOutputStream bos=null;
	InputStream is=null;
	Socket client=null;
	FileOutputStream fos=null;
	static byte[]receivedHashCode;
	static byte[] receivedHashCodeBytes;
	public SocketHost2() throws Exception {
		try
		{
			ServerSocket ss=new ServerSocket(portNumber);
			System.out.println("Server waiting for client");
			client=ss.accept();
			dis=new DataInputStream(client.getInputStream());
			
			/***************************************/// rsa key generation
			final KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
		    keyGen.initialize(1024);
		    final KeyPair key1 = keyGen.generateKeyPair();
		    /*
		    System.out.println(key.getPrivate());
		    System.out.println(key.getPublic());
		    */
		    PublicKey publicKey=key1.getPublic();
		    PrivateKey privateKey=key1.getPrivate();
		    
		    ObjectOutputStream oos=new ObjectOutputStream(client.getOutputStream());
		    oos.writeObject(publicKey);
		    
		    
		    /*******************************************///receiving encrtypted secret key
		    int len=Integer.parseInt(dis.readUTF());
		    
		    byte[]encryptedSecretKey=new byte[len];
		    dis.readFully(encryptedSecretKey,0,len);

		    secretKey=new String(decryptKey(encryptedSecretKey,privateKey));
		    
		    System.out.println("Aishwarya this is the secret key : "+secretKey);
		    
		    
			/**************************************/
			
			
			int lengthOfByteArray=Integer.parseInt(dis.readUTF());// reading the length of file
			filename="new"+dis.readUTF(); // reading the name of file
			
			
			BufferedImage img=ImageIO.read(ImageIO.createImageInputStream(client.getInputStream()));
			ImageIO.write(img, "bmp", new File(filename));
			
			
			len=Integer.parseInt(dis.readUTF());
			receivedHashCode=new byte[len];
			dis.readFully(receivedHashCode,0,receivedHashCode.length);
			
			/******************************************///decrypting the received hash code
			
			Cipher c = Cipher.getInstance("AES");
			//String key="aishwaryaiashwar";
			SecretKeySpec k =new SecretKeySpec(secretKey.getBytes(), "AES");
			
			
			c.init(Cipher.DECRYPT_MODE, k);
			receivedHashCodeBytes = c.doFinal(receivedHashCode);
			System.out.println("hash code on receivers side : "+new String(receivedHashCodeBytes));
			
			
		}
	    finally {
	      if (fos != null) fos.close();
	      if (bos != null) bos.close();
	      if (client!= null) client.close();
	    }
	}
	public static byte[] decryptKey(byte[] text, PrivateKey key) {
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			
	}

}
