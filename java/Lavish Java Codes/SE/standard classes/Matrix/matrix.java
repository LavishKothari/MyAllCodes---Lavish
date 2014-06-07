import java.io.*;
//null matrix
//unit matrix
//symmetric matrix

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
	
	void printMatrix()
	{
		for(int i=0;i<this.r;i++)
		{			
			for(int j=0;j<this.c;j++)
				System.out.print(this.mat[i][j]+"\t");
			System.out.println();
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
	
	boolean mul(Matrix m1,Matrix m2)
	{
		if(m1.c==m2.r)
		{
			this.r=m1.r;
			this.c=m2.c;
			this.allotMatrix();
			for(int i=0;i<m1.r;i++)
				for(int j=0;j<m2.c;j++)
					for(int k=0;k<m1.c;k++)
						this.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
			return true;
		}
		else
			return false;
	}
	
	Matrix getTranspose()
	{
		Matrix result=new Matrix(this.r,this.c);
		for(int i=0;i<this.r;i++)
			for(int j=0;j<this.c;j++)
				result.mat[i][j]=this.mat[j][i];
		
		return result;
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
		
		
		
		if(m3.mul(m1,m2))
		{
			System.out.println("Matrix Multiplication : ");
			System.out.println(m3);
		}
		else
			System.out.println("Matrix multiplication not possible!!!");
			
		m3=m1.getTranspose();
		if(m3!=null)
		{
			System.out.println("Matrix Transpose : ");
			System.out.println(m3);
		}

		System.out.println("Trace of first matrix : "+m1.getTrace());
		
		System.out.println("Upper triangle of first matrix : ");
		m1.printUpperTriangle();
		
		System.out.println("Lower triangle of first matrix : ");
		m1.printLowerTriangle();
	}
}