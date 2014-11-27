import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main 
{
	public static void main(String args[])throws IOException 
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//Encode obj=new Encode(br.readLine());
		Decode obj1=new Decode("d:/alogfile.txt", "d:/aencodedFile.txt");
		
	}
}
