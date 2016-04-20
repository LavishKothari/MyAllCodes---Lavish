import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.security.PublicKey;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.imageio.ImageIO;

public class HideData {
	public static int imgSize;
	public static BufferedImage img;
	public static byte[]image;
	public static int getIthBit(int i,String message) // i is zero indexed
	{
		int c=message.getBytes()[i/8] & (1<<(7-i%8));
		while(c!=0 && (c&1) == 0)
			c/=2;
		return c;
	}
	public static void hideMessageForEachByte(String message,int sizeOfEachPixel)
	{
		int counter=0;
		//System.out.println("this is aishya's test "+image.length);
		
		for(int i=sizeOfEachPixel/8-1+100;i<img.getHeight()*img.getWidth();i+=sizeOfEachPixel/8)
		{
			
			byte b=image[i];
			b=(byte)(b>>1);
			b=(byte)(b<<1);
			if(counter>=message.length()*8){
				b=(byte)(b>>1);
				b=(byte)(b<<1);	
			}
			else {
			int bit=getIthBit(counter,message);
			counter++;
			
			
			b=(byte)(b+bit);
			}
			image[i]=b;
		}
		
		
	}
	
	public static byte[] hideMessage(String oldFile,String newFile,String message) throws Exception
	{
		File file = new File(oldFile);
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
		System.out.println("this is a test related to img size"+imgSize);
		image=tmp.toByteArray();
		/*
		System.out.println("This si the original image");
		
		for(int i=0;i<image.length;i++)
			System.out.print(image[i]+" ");
		*/
		hideMessageForEachByte(message,sizeOfEachPixel);
		
		
		/*******************************/// calculating messaage digest
		MessageDigest md = MessageDigest.getInstance("MD5");
		md.reset();
        md.update(message.getBytes(), 0, message.getBytes().length);
        
        byte[]dataToSend=md.digest();
        System.out.println("Before encrtypting hash code : "+new String(dataToSend));
        /****************************************///encryption by aes
        Cipher c = Cipher.getInstance("AES");
		String key="aishwaryaiashwar";
		SecretKeySpec k =new SecretKeySpec(key.getBytes(), "AES");
		
		
		c.init(Cipher.ENCRYPT_MODE, k);
		byte[] encryptedData = c.doFinal(dataToSend);
	//	System.out.println(new String(encryptedData));
		
		/*************************************************************///sharing aes encryption key by rsa
	
		/****************************************************///
		
		
		
		
		
		
		OutputStream out = new BufferedOutputStream(new FileOutputStream(newFile));
		out.write(image);
		System.out.println("finished");
		return encryptedData;
		
	}
	/*
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the message : ");
		String message=br.readLine();
		System.out.print("Enter the image file used for steganography name : ");
		String oldFile=br.readLine();
		System.out.print("Enter the new image file name : ");
		String newFile=br.readLine();
		
		hideMessage(oldFile, newFile, message);
		
		
		
	}
	 */
}
