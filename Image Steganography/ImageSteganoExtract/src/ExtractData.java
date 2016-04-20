import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;

import javax.imageio.ImageIO;

public class ExtractData{
	static BufferedImage img;
	public static String getMessage1(byte[]image,int sizeOfEachPixel)
	{
		String message="";
		int [] buffer = new int [image.length*8/sizeOfEachPixel];
		int counter = 0;
		for(int i=sizeOfEachPixel/8-1+100;i<img.getHeight()*img.getWidth();i+=sizeOfEachPixel/8)
		{
			byte b=image[i];
			
			buffer[counter] = (int) (b & 1);
			counter++;
		}
		
		int counter1 = 7,sum = 0;
		for(int i=0; i<counter; i++) {
			if(counter1>=0) {
				sum   = sum + (buffer[i] * (1<< counter1));
				counter1--;
			}
			else {
				message += (char) sum;
				sum = 0;
				counter1 = 7;
				i--;
			}
		}
		return message;
		
	}
	
	public static String getMessage(String fileName) throws IOException
	{
		
		File file = new File(fileName);
		img  = ImageIO.read(file);
		
		ByteArrayOutputStream tmp = new ByteArrayOutputStream();
	    ImageIO.write(img, "bmp", tmp);
	    tmp.close();
	    
	    Integer contentLength = tmp.size();
	    System.out.println(contentLength.intValue());
		
		System.out.println(img.getHeight()+" "+img.getWidth());
		
		int sizeOfEachPixel=(contentLength.intValue()*8)/(img.getWidth()*img.getHeight());
		
		System.out.println(sizeOfEachPixel);
	    
		byte[]image=tmp.toByteArray();
		
		return getMessage1(image,sizeOfEachPixel);
		
	}
	/*
	public static void main(String[] args) throws IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter the image file used for steganography name : ");
		String fileName=br.readLine();
		String message=getMessage(fileName);
		System.out.println(message);
		
	}
	*/
}
