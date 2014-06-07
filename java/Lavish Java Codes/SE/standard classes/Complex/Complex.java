import java.util.Scanner;

class Complex
{
	double real,imag;
	Complex()
	{
		real=0;
		imag=0;
	}

	Complex(Complex c)
	{
		this.real=c.real;
		this.imag=c.imag;
	}	
	
	Complex(double real,double imag)	
	{
		this.real=real;
		this.imag=imag;
	}

	public void getData()
	{	
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the real and imaginary part :");
		real=sc.nextDouble();	
		imag=sc.nextDouble();
	}

	double modulus()
	{
		return Math.sqrt(real*real+imag*imag);
	}
	
	public Complex add(Complex c)
	{
		return new Complex(c.real+this.real,c.imag+this.imag);
	}

	public Complex sub(Complex c)
	{
		return new Complex(c.real-this.real,c.imag-this.imag);
	}

	public Complex mul(Complex c)
	{
		return new Complex(c.real*this.real-c.imag*this.imag , this.real*c.imag+this.imag*c.real);
	}

	public Complex div(Complex c)
	{	
		Complex tmp=new Complex(c.real,-c.imag);
		Complex result;
		result=this.mul(tmp);
		result.real=result.real/(c.modulus()*c.modulus());
		result.imag=result.imag/(c.modulus()*c.modulus());
		return result;	
	}
	
	public void printComplex()
	{	
		System.out.println("x + iy = " +this.real+ " + i" +this.imag);
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Complex c1=new Complex(2,3);
		Complex c2=new Complex(8,6);
	
		Complex result;

		result=c1.add(c2);
		result.printComplex();	

		result=c1.sub(c2);
		result.printComplex();	

		result=c1.mul(c2);
		result.printComplex();	

		result=c1.div(c2);
		result.printComplex();	

		while(true)	
		{
			int ch;
			System.out.println("_________menu_________");
			System.out.println("1. Add two complex numbers");
			System.out.println("2. Subtract two complex numbers");
			System.out.println("3. Multiply two complex numbers");
			System.out.println("4. Divide two complex numbers");
			System.out.println("5. Exit");
		
			System.out.println();
			System.out.print("enter your choice : ");
						
			ch=sc.nextInt();
			switch(ch)
			{
				case 1:
					c1.getData();
					c2.getData();
					c1.add(c2).printComplex();
					break;
	
				case 2:
					c1.getData();
					c2.getData();
					c1.sub(c2).printComplex();
					break;
	
				case 3:
					c1.getData();
					c2.getData();
					c1.mul(c2).printComplex();
					break;
	
				case 4:
					c1.getData();
					c2.getData();
					c1.div(c2).printComplex();
					break;
	
				case 5:
					System.exit(1);
				default:
					System.out.println("you have entered a wrong choice!!!");
	}
}