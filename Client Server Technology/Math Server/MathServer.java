import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class MathServer 
{
	public static void main(String[] args) throws IOException
	{
		ServerSocket serverSocket=new ServerSocket(4567);
		while(true)
		{
			Socket client=serverSocket.accept();
			DataInputStream dis=new DataInputStream(client.getInputStream());
			DataOutputStream dos=new DataOutputStream(client.getOutputStream());
			while(true)
			{
				String str=dis.readUTF();
			
				if(str.equals("END"))
					break;
				double a=Double.parseDouble(str);
				double b=Double.parseDouble(dis.readUTF());
				char ch=((dis.readUTF()).toCharArray())[0];
				double answer;
				switch(ch)
				{
				case '+':
					answer=a+b;
					break;
				case '-':
					answer=a-b;
					break;
				case '*':
					answer=a*b;
					break;
				case '/':
					answer=a/b;
					break;
				default : 
					dos.writeUTF("Not a valid Operator");
					continue;
				}
				dos.writeUTF(answer+"");
			}
		}
	}

}
