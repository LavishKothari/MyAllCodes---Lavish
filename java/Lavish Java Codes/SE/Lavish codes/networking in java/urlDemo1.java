import java.io.*;
import java.net.*;
class Main
{
	public static void main(String []args)throws IOException,MalformedURLException
	{
		URL url;
		
		
		System.out.println("------------------------------------------------");
		url=new URL("http://www.google.com:80/index.html");
		
		System.out.println("URL                   : "+url);
		System.out.println("Protocol              : "+url.getProtocol());
		System.out.println("Host                  : "+url.getHost());
		System.out.println("Port                  : "+url.getPort());
		System.out.println("File                  : "+url.getFile());
		
		System.out.println("------------------------------------------------");
		url=new URL("http://www.google.com/index.html");
		
		System.out.println("URL                   : "+url);
		System.out.println("Protocol              : "+url.getProtocol());
		System.out.println("Host                  : "+url.getHost());
		System.out.println("Port                  : "+url.getPort());
		System.out.println("File                  : "+url.getFile());
		System.out.println("------------------------------------------------");
		
		
		url=new URL("http://www.google.com");
		
		System.out.println("URL                   : "+url);
		System.out.println("Protocol              : "+url.getProtocol());
		System.out.println("Host                  : "+url.getHost());
		System.out.println("Port                  : "+url.getPort());
		System.out.println("File                  : "+url.getFile());
		System.out.println("------------------------------------------------");
		
		url.openConnection(); // throws IOException
	}
}
		