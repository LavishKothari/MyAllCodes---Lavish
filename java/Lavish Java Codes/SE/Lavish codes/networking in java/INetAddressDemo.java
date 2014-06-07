import java.net.*;
class Main
{
	public static void main(String args[])throws UnknownHostException
	{
		System.out.println("-----------------------------------------------");
		
		System.out.println("Loop-back Address       : "+InetAddress.getLoopbackAddress());
		
		System.out.println("-----------------------------------------------");
		
		InetAddress address;
		address=InetAddress.getLocalHost();
		System.out.println("Host Name and Address   : "+address);
		System.out.println("Host Name               : "+address.getHostName());
		System.out.println("Host Address            : "+address.getHostAddress());
		System.out.println("isAnyLocalAddress       : "+address.isAnyLocalAddress());
		System.out.println("isMultiCastAddress      : "+address.isMulticastAddress());
		System.out.println("-----------------------------------------------");
		
		
		address=InetAddress.getByName("Lavish");
		System.out.println("Host Name and Address   : "+address);
		System.out.println("Host Name               : "+address.getHostName());
		System.out.println("Host Address            : "+address.getHostAddress());
		System.out.println("isAnyLocalAddress       : "+address.isAnyLocalAddress());
		System.out.println("isMultiCastAddress      : "+address.isMulticastAddress());
		
		byte b[]=address.getAddress();
		for(byte i : b)
			System.out.print(i+" ");
		System.out.println("\n-----------------------------------------------");

	}
}