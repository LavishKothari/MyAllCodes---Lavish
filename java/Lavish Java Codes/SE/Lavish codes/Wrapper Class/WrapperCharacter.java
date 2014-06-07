/*
Simple java program illustrating
Character class 
*/

class Main
{
	public static void main(String args[])
	{
		/* this is the only constructor 
		of Character class */
		Character ch=new Character('A');
		char c=ch.charValue();
	
		System.out.println(c);

		
		System.out.println("MAX_RADIX : "+Character.MAX_RADIX);
		System.out.println("MIN_RADIX : "+Character.MIN_RADIX);
		System.out.println("MAX_VALUE : "+Character.MAX_VALUE);
		System.out.println("MIN_VALUE : "+Character.MIN_VALUE);
		System.out.println("TYPE      : "+Character.TYPE);
		System.out.println();
		char a[]={'a','B','?','8',' '};

		for(int i=0;i<a.length;i++)
		{
			if(Character.isDigit(a[i]))
				System.out.println(a[i]+" is a Digit");
			if(Character.isLetter(a[i]))
				System.out.println(a[i]+" is a Letter");
			if(Character.isWhitespace(a[i]))
				System.out.println(a[i]+" is a WhiteSpace");
			if(Character.isUpperCase(a[i]))
				System.out.println(a[i]+" is a UpperCase");
			if(Character.isLowerCase(a[i]))
				System.out.println(a[i]+" is a LowerCase");
		
		}

		System.out.println();

		System.out.println("17 in base 16 is : "+Character.forDigit(17,16)); // no output
		System.out.println("14 in base 16 is : "+Character.forDigit(14,16)); // prints e
		
		int i=Character.digit('5',10); // returns an integer, this will print 5
		System.out.println(i);
		
		i=Character.digit('n',10); 
		System.out.println(i);// this prints -1

	}
}