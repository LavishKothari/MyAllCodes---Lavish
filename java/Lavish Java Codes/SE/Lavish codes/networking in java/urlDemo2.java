import java.io.*;
import java.net.*;

class Main
{
	public static void main(String []args)throws MalformedURLException
	{
		URL url;
		url=new URL("http://www.google.com:80/index.html");
		System.out.println("URL                   : "+url);
		System.out.println("Protocol              : "+url.getProtocol());
		System.out.println("Host                  : "+url.getHost());
		System.out.println("Port                  : "+url.getPort());
		System.out.println("File                  : "+url.getFile());
		System.out.println("Authority             : "+url.getAuthority());
		System.out.println("Default Port          : "+url.getDefaultPort());
		System.out.println("Query                 : "+url.getQuery());
		System.out.println("User Info             : "+url.getUserInfo());
		System.out.println("-----------------------------------------------------");
		
		url=new URL("https://www.google.com/index.html?name=\"Lavish\"");
		System.out.println("URL                   : "+url);
		System.out.println("Protocol              : "+url.getProtocol());
		System.out.println("Host                  : "+url.getHost());
		System.out.println("Port                  : "+url.getPort());
		System.out.println("File                  : "+url.getFile());
		System.out.println("Authority             : "+url.getAuthority());
		System.out.println("Default Port          : "+url.getDefaultPort());
		System.out.println("Query                 : "+url.getQuery());
		System.out.println("User Info             : "+url.getUserInfo());
		System.out.println("-----------------------------------------------------");
		
	}
}	