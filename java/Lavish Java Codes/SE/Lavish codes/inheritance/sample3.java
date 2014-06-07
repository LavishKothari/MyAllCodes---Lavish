// super class reference can't access the exclusive members of sub-class

/*
while a super class reference can refer to sub class object but it can access only those members 
of sub class that have been inherited form hte super class. it cannot access exclusive members of subclass.
*/

class Alfa
{
	void show()
	{
		System.out.println("you are in the show of Alfa");
	}
}

class Beta extends Alfa
{
	void show1()	
	{	
		System.out.println("you are in the show of Beta");
	}	
}

class Main
{
	public static void main(String args[])
	{
		Alfa a=new Beta();				
		// a.show1();		---> error
		// super class reference can't access the exclusive members of sub-class	
		a.show();		//correct

		Beta b=new Beta();
		b.show();
		b.show1();
	}
}