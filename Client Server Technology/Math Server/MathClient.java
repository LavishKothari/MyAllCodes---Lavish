import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;


public class MathClient 
{
	public static void main(String[] args) throws IOException
	{
		Socket server=new Socket("localhost",4567);
		DataInputStream dis=new DataInputStream(server.getInputStream());
		DataOutputStream dos=new DataOutputStream(server.getOutputStream());
		boolean a=true;
		while(a==true)
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter first Operand : ");
			dos.writeUTF(br.readLine());
			System.out.print("Enter second Operand : ");
			dos.writeUTF(br.readLine());
			System.out.print("Enter the operator : ");
			dos.writeUTF(br.readLine());
			
			System.out.println("Waiting for answer from server");
			System.out.println(dis.readUTF());
			System.out.println("\nDo you want to do some other computation?[1,0]");
			String str=br.readLine();
			if(str.equals("0"))
			{
				a=false;
				dos.writeUTF("END");
			}
		}
	}
}
