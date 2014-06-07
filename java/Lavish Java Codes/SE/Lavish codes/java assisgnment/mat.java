import java.io.*;
class Matrix
{
	int mat[][];
	int r,c;
	
	Matrix(){}
	
	Matrix(int r,int c)
	{
		this.r=r;
		this.c=c;
		allotMatrix();
	}
	
	void allotMatrix()
	{
		mat=new int[r][c];
	}
	
	void getrc()
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("enter row and column : ");
		try
		{
			r=Integer.parseInt(br.readLine());
			c=Integer.parseInt(br.readLine());
		}
		catch(IOException e)
		{
			System.out.println("Enter a valid number!!!");
		}
		
		allotMatrix();
	}
	
	void getData()
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("enter the data of matrix : ");
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				try
				{
					mat[i][j]=Integer.parseInt(br.readLine());
				}
				catch(IOException e)
				{
					System.out.println("Enter a valid number!!!");
				}
	}

	
	boolean add(Matrix m1,Matrix m2)
	{
		if(m1.r==m2.r && m1.c==m2.c)
		{	
			this.r=m1.r;
			this.c=m1.c;
			this.allotMatrix();
			for(int i=0;i<m1.r;i++)
				for(int j=0;j<m1.c;j++)
					this.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
			return true;
		}
		else
			return false;
	}
	
	public String toString()
	{
		String str="";
		for(int i=0;i<this.r;i++)
		{			
			for(int j=0;j<this.c;j++)
				str += this.mat[i][j]+"\t";
			str+="\n";
		}
		return str;
	}
}

class Main
{
	public static void main(String args[])
	{
		Matrix m1,m2,m3;
		m3=new Matrix();
		
		m1=new Matrix();
		m1.getrc();
		m1.getData();
		
		m2=new Matrix();
		m2.getrc();
		m2.getData();
		
		
		if(m3.add(m1,m2))
		{
			System.out.println("Matrix Addition : ");
			System.out.println(m3);
		}
		else
			System.out.println("Matrix addition not possible!!!");
	}
}