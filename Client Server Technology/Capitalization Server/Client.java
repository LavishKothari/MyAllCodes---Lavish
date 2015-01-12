// Client program giving Strings for Capitalization
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client 
{
	public static void main(String[] args) throws IOException
	{
		Socket server=new Socket("localhost",1234);
		DataInputStream dis=new DataInputStream(server.getInputStream());
		DataOutputStream dos=new DataOutputStream(server.getOutputStream());
		BufferedReader br;
		boolean a=true;
		while(a==true)
		{
			br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter a string : ");
			dos.writeUTF(br.readLine());
			System.out.println(dis.readUTF());
			System.out.println("do you want to enter another number ??");
			int ch=br.read();
			if(ch=='0')
			{
				a=false;
				dos.writeUTF("END");
			}
		}
	}
}
