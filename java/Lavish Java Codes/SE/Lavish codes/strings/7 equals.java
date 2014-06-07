//equals()

import java.io.*;

class Main
{
	public static void main(String []args)
	{	
		//creating different references with same content of the string
		String s1=new String("hello");
		String s2=new String("hello");
		System.out.println(s1.equals(s2));		//prints true
		System.out.println(s1==s2);			//prints false
				
		//creating two different strings in the same string pool
		String str1="hello";
		String str2="hello";
		System.out.println(str1.equals(s1));		//prints true
		System.out.println(str1==str2);			//prints true
		System.out.println(str1=="hello");		//prints true
		
		System.out.println(str1==s2);			//prints false
	}
}		