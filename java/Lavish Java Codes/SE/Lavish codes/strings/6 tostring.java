//toString()
import java.io.*;

class complex
{
	double r,i;
	complex(){}

	complex(double r,double i)
	{
		this.r=r;
		this.i=i;
	}

	public complex add(complex c)
	{
		complex ans=new complex(this.r+c.r,this.i+c.i);
		return ans;
	}

	public String toString()
	{
		String str;
		str=String.format("real part = %f\nimag part = %f",this.r,this.i);
		return str;
	}	
}

class Main
{
	public static void main(String[]args)
	{
		complex c1=new complex(5,3);
		complex c2=new complex(15,31);
		complex c3=new complex();
		c3=c1.add(c2);
		System.out.println(c3);
	}
}