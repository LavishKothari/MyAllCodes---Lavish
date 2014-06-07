import java.io.*;

class Dept
{
	Console con=System.console();
	String dname;
	int dno;
	public void getInfo()
	{
		System.out.println("enter the department name and department number : ");
		dname=con.readLine();
		dno=Integer.parseInt(con.readLine());
	}
	public void display()
	{
		System.out.println("Dept Name = "+dname+"\nDept No. = "+dno);
	}
}

interface College
{
	String cname="MBM";
}

class Teacher extends Dept implements College
{
	String name,desig;
	public void getInfo()
	{
		super.getInfo();
		System.out.println("enter the name and designation of the teacher : ");
		name=con.readLine();
		desig=con.readLine();
	}
	public void show()
	{	
		super.display();
		System.out.println("college name = "+cname
							+"\nteacher Name : "+name
							+ "\nDesignation : "+desig);
	}
}

class Main
{
	public static void main(String args[])
	{
		Teacher t=new Teacher();
		t.getInfo();
		t.show();
	}
}