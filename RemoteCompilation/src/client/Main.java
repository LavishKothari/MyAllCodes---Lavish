/*
 * This is the Main program of Client.
 * */
package client;

import java.io.IOException;
import java.net.UnknownHostException;

public class Main {
	public static void main(String []args) throws UnknownHostException, IOException
	{
		ClientFrame cf=new ClientFrame();
		cf.setVisible(true);
	}
}
