// this is client.

import java.awt.image.BufferedImage;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.security.PublicKey;

import javax.crypto.Cipher;
import javax.imageio.ImageIO;

public class SocketHost1 {
	String filename;
	String secretKey;
	static byte[]hashcode;
	int portNumber=5000;
	static String ipAddress;
	DataOutputStream dos;
	public SocketHost1(String filename) throws IOException, ClassNotFoundException {
		BufferedInputStream bis=null;
		OutputStream os=null;
		Socket server=null;
		try{
			this.filename=filename;
			System.out.println(filename);
			/*****//* creating socket */
			server=new Socket(ipAddress,portNumber);
			dos=new DataOutputStream(server.getOutputStream());
			os=server.getOutputStream();
			
			/*********************************/ // receiving public key
			ObjectInputStream ois=new ObjectInputStream(server.getInputStream());
			PublicKey serverPublicKey=(PublicKey)ois.readObject();
			/**********************************************/ //sending encrypted secrete key to server
			
			secretKey="aishwaryaiashwar";
			byte[]encryptKeyBytes=encryptKey(secretKey.getBytes(), serverPublicKey);
			
			dos.writeUTF(encryptKeyBytes.length+"");
			dos.write(encryptKeyBytes);
			
			/**********************************************/
			
			File myFile = new File(filename);
			System.out.println(myFile.length());
			
			dos.writeUTF(""+myFile.length()); // sending the lenght of byte array
			dos.writeUTF(filename); // sending the filename
			
			BufferedImage bimg = ImageIO.read(new File(filename));
			ImageIO.write(bimg,"bmp",server.getOutputStream());
			
			dos.writeUTF(""+hashcode.length);
			dos.write(hashcode);
			
			
			
		}finally {
            if (bis != null) bis.close();
            if (os != null) os.close();
            if (server!=null) server.close();
          }
	}
	public static byte[] encryptKey(byte[] text, PublicKey key) {
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
}
