import java.io.*;
import java.net.*;

class Client
{
	public static void main(String[]args)throws IOException,UnknownHostException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Socket server=new Socket("localhost",1234);
		DataInputStream in=new DataInputStream(server.getInputStream());
		DataOutputStream out=new DataOutputStream(server.getOutputStream());
		while(true)
		{
			out.writeUTF(br.readLine());
			System.out.println(in.readUTF());
		}
	}
}