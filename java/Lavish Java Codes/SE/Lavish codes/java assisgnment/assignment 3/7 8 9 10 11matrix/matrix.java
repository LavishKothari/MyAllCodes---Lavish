
//null matrix
//unit matrix
//symmetric matrix

import java.util.Scanner;

class Matrix
{
	int mat[][];
	int r,c;
	
	Matrix()
	{
		r=0;c=0;
		mat=null;
	}
	Matrix(int r,int c)
	{
		this.r=r;
		this.c=c;
		mat=new int[r][c];
	}
	void getrc()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter row and column : ");
		r=sc.nextInt();
		c=sc.nextInt();
		mat=new int[r][c];
	}
	
	void getData()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the data of matrix : ");
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				mat[i][j]=sc.nextInt();
	}
	
	void printMatrix()
	{
		for(int i=0;i<this.r;i++)
		{			
			for(int j=0;j<this.c;j++)
			{
				System.out.print(this.mat[i][j]+"\t");
			}
			System.out.println();
		}
	}
	
	Matrix add(Matrix m)
	{
		if(this.r==m.r && this.c==m.c)
		{	
			Matrix result=new Matrix(this.r,this.c);
			for(int i=0;i<this.r;i++)
				for(int j=0;j<this.c;j++)
					result.mat[i][j]=this.mat[i][j]+m.mat[i][j];
			return result;
		}
		else
		{
			System.out.println("matrix addition not possible...!!!");
			return null;
		}
	}
	Matrix mul(Matrix m)
	{
		if(this.c==m.r)
		{
			Matrix result=new Matrix(this.r,m.c);
			for(int i=0;i<this.r;i++)
				for(int j=0;j<m.c;j++)
					for(int k=0;k<this.c;k++)
						result.mat[i][j]+=this.mat[i][k]*m.mat[k][j];
			return result;
		}
		else
		{
			System.out.println("matrix multiplication not possible...!!!");
			return null;
		}
	}
	
	Matrix getTranspose()
	{
		if(this.r==this.c)
		{
			Matrix result=new Matrix(this.r,this.c);
			for(int i=0;i<this.r;i++)
				for(int j=0;j<this.c;j++)
					result.mat[i][j]=this.mat[j][i];
			return result;
		}
		else
		{
			System.out.println("transpose of matrix is not possible as matrix is not square matrix");
			return null;
		}
	}
	
	int getTrace()
	{
		if(r==c)
		{
			int sum=0;
			for(int i=0;i<this.r;i++)
				for(int j=0;j<this.c;j++)
					if(i==j)
						sum+=mat[i][j];
			return sum;
		}
		else
			System.out.println("the matrix is not a square matrix...!! so we can't find its trace...");
		return 0;
	}
	
	void printUpperTriangle()
	{	
		if(this.r==this.c)
			for(int i=0;i<this.r;i++)
			{
				for(int j=0;j<this.c;j++)
					if(i<=j)
						System.out.print(mat[i][j]+"\t");
					else
						System.out.print("\t");
				System.out.println();
			}
		else
			System.out.println("not a square matrix...so upper triangle not possible");
	}				
	
	void printLowerTriangle()
	{	
		if(this.r==this.c)
			for(int i=0;i<this.r;i++)
			{
				for(int j=0;j<this.c;j++)
					if(i>=j)
						System.out.print(mat[i][j]+"\t");
					else
						System.out.print(" ");
				System.out.println();
			}			
		else
			System.out.println("not a square matrix...so lower triangle not possible");
	}				
}

class Main
{
	public static void main(String args[])
	{
		Matrix m1,m2;
		m1=new Matrix();
		m1.getrc();
		m1.getData();
		
		m2=new Matrix();
		m2.getrc();
		m2.getData();
		
		Matrix m3=m1.add(m2);
		if(m3!=null)
		{
			System.out.println("Matrix Addition : ");
			m3.printMatrix();
		}
		
		m3=m1.mul(m2);
		if(m3!=null)
		{
			System.out.println("Matrix Multiplication : ");
			m3.printMatrix();
		}
			
		m3=m1.getTranspose();
		if(m3!=null)
		{
			System.out.println("Matrix Transpose : ");
			m3.printMatrix();
		}

		System.out.println("Trace of first matrix : "+m1.getTrace());
		
		System.out.println("Upper triangle of first matrix : ");
		m1.printUpperTriangle();
		
		System.out.println("Lower triangle of first matrix : ");
		m1.printLowerTriangle();
	}
}