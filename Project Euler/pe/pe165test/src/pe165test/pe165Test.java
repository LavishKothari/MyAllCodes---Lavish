package pe165test;

public class pe165Test 
{
	
	public static int heapLength;
	
	static Fraction x[];
	static Fraction y[];
	static int size=3868997;
	static int indexOfArray=0;
	
	
	/****************/
	/*
	 * for heap sort
	 */

	public static int getParentIndex(int n)
	{
		return (n/2);
	}
	public static int getLeftChildIndex(int n)
	{
		return n*2;
	}
	public static int getRightChildIndex(int n)
	{
		return n*2+1;
	}
	
	public static void maxHeapify(Fraction[]x,Fraction[]y,int i)
	{
		int l=getLeftChildIndex(i+1)-1; // our array is zero indexed array...
		int r=getRightChildIndex(i+1)-1;
		int largest;
		Fraction tmp;
		if(l<=heapLength-1 && x[l].n>x[i].n)
			largest=l;
		else
			largest=i;
			
		if(r<=heapLength-1 && x[r].n>x[largest].n)
			largest=r;
		
		// exchange x[i] and x[largest]
		if(largest!=i)
		{
			tmp=x[i];
			x[i]=x[largest];
			x[largest]=tmp;
			
			tmp=y[i];
			y[i]=y[largest];
			y[largest]=tmp;
			
			maxHeapify(x,y,largest);
		}
	}
	
	public static void buildMaxHeap(Fraction[]x,Fraction[]y)
	{
		for(int i=getParentIndex(indexOfArray)-1;i>=0;i--)
			maxHeapify(x,y,i);
	}
	
	public static void heapSort(Fraction[]x,Fraction[]y)
	{
		buildMaxHeap(x,y);
		Fraction tmp;
		for(int i=indexOfArray-1;i>=1;i--)
		{
			tmp=x[0];
			x[0]=x[i];
			x[i]=tmp;
			
			tmp=y[0];
			y[0]=y[i];
			y[i]=tmp;
			
			heapLength--;
			maxHeapify(x,y,0);
		}
	}
	/*
	 * heap sort code finishes here
	 */
	/*******************/
	public static void calculateS(int t[])
	{
		/*
		t[1]=0;
		t[2]=1;
		t[3]=2;
		t[4]=1;
		
		t[5]=1;
		t[6]=0;
		t[7]=1;
		t[8]=2;
		
		t[9]=0;
		t[10]=0;
		t[11]=5;
		t[12]=5;
		
		t[13]=6;
		t[14]=0;
		t[15]=6;
		t[16]=6;

		t[17]=5;
		t[18]=2;
		t[19]=17;
		t[20]=2;

		t[21]=5;
		t[22]=3;
		t[23]=17;
		t[24]=3;

		t[25]=10;
		t[26]=0;
		t[27]=10;
		t[28]=10;
		*/	
		/*
		t[1]=1;
		t[2]=3;
		t[3]=0;
		t[4]=3;
		
		t[5]=0;
		t[6]=2;
		t[7]=1;
		t[8]=2;
		
		t[9]=0;
		t[10]=1;
		t[11]=1;
		t[12]=1;
		
		t[13]=7;
		t[14]=499;
		t[15]=4;
		t[16]=0;

		t[17]=5;
		t[18]=0;
		t[19]=6;
		t[20]=499;

		t[21]=6;
		t[22]=0;
		t[23]=5;
		t[24]=499;

		t[25]=0;
		t[26]=4;
		t[27]=1;
		t[28]=4;
		*/

		t[1]=0;
		t[2]=0;
		t[3]=100;
		t[4]=100;
		
		t[5]=5;
		t[6]=0;
		t[7]=0;
		t[8]=5;
		
		t[9]=0;
		t[10]=10;
		t[11]=10;
		t[12]=0;
		
		t[13]=7;
		t[14]=0;
		t[15]=0;
		t[16]=7;

		t[17]=50;
		t[18]=0;
		t[19]=0;
		t[20]=50;

		t[21]=69;
		t[22]=0;
		t[23]=0;
		t[24]=69;

		t[25]=1;
		t[26]=0;
		t[27]=99;
		t[28]=100;

	}

	public static int direction(int xi,int yi,int xj,int yj,int xk,int yk)
	{
	    int ax,ay,bx,by;
	    ax=xk-xi;
	    ay=yk-yi;
	    bx=xj-xi;
	    by=yj-yi;

	    return (ax*by-bx*ay);
	}

	public static void calculateIntersectionPoint(long a,long b,long c,long d,long e,long f,long g,long h)
	{
		/*
		 * this method calculate the intersection point and stores it in x and y array as Fraction
		 */
	    long xNumerator,xDenominator,yNumerator,yDenominator;
	    
	    /*
	    xNumerator=(f*g-e*h)*(c-a)+(a*d-b*c)*(g-e);
	    xDenominator=(d-b)*(g-e)-(h-f)*(c-a);
	    
	    if(c!=a)
		{
	    	yNumerator=xNumerator*(d-b)+(b*c-a*d)*xDenominator;
	    	yDenominator=xDenominator*(c-a);
		}
	    else
	    {
	    	yNumerator=xNumerator*(h-f)+(f*g-e*h)*xDenominator;
	    	yDenominator=xDenominator*(g-e);
	    }
	    
	    if(xDenominator==0 || yDenominator==0)
	    	return;
	    
	    
	    */
	    
	    xNumerator=-a*d*e + a*d*g + a*e*h - a*f*g + b*c*e - b*c*g - c*e*h+c*f*g;
	    xDenominator=-a*f + a*h + b*e - b*g + c*f - c*h - d*e + d*g;
	    
	    yNumerator=a*d*f - a*d*h - b*c*f + b*c*h - b*e*h + b*f*g + d*e*h - d*f*g;
	    yDenominator=a*f - a*h - b*e + b*g - c*f + c*h + d*e - d*g;
	    
	    
	    Fraction xFraction=new Fraction(xNumerator,xDenominator);
	    Fraction yFraction=new Fraction(yNumerator,yDenominator);
	    
	    if((xFraction.d==1&&yFraction.d==1) && ((xFraction.n==a&&yFraction.n==b) || (xFraction.n==c&&yFraction.n==d) || (xFraction.n==e&&yFraction.n==f) || (xFraction.n==g&&yFraction.n==h)))
	    	return ;
	    
	    x[indexOfArray]=xFraction;
	    y[indexOfArray]=yFraction;
	    
	    System.out.println("i="+indexOfArray+"  "+a+","+b+"#"+c+","+d+"#"+e+","+f+"#"+g+","+h+"\t"+"xn="+x[indexOfArray].n+" xd="+x[indexOfArray].d+" yn="+y[indexOfArray].n+" yd="+y[indexOfArray].d);
	    
	    indexOfArray++;
	}

	public static int segmentsIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
	{
	    int d1,d2,d3,d4;
	    d1=direction(x3,y3,x4,y4,x1,y1);
	    d2=direction(x3,y3,x4,y4,x2,y2);
	    d3=direction(x1,y1,x2,y2,x3,y3);
	    d4=direction(x1,y1,x2,y2,x4,y4);
	    if(((d1>0&&d2<0) || (d1<0&&d2>0)) && ((d3>0&&d4<0) || (d3<0&&d4>0)))
	    {
	        // means segments have a true intersection point.
	        calculateIntersectionPoint(x1,y1,x2,y2,x3,y3,x4,y4);
	        return 1;
	    }
	    return 0;
	}

	public static void main(String args[])
	{
		System.out.println("Started");
	    int i,j;
	    int t[]=new int[29];
	    
	    x=new Fraction[size];
	    y=new Fraction[size];
	    
	    calculateS(t);
	    
	    for(i=0;i<7;i++)
	    {
	    	//System.out.println(i);
	        for(j=i+1;j<7;j++)
	            segmentsIntersect(t[i*4+1],t[i*4+2],t[i*4+3],t[i*4+4],t[j*4+1],t[j*4+2],t[j*4+3],t[j*4+4]);
	    }
	    System.out.println("this is a check : "+indexOfArray);
	    heapLength=indexOfArray;
		heapSort(x,y);
		/*
		for(i=0;i<500;i++)
			System.out.println(x[i]+","+y[i]);
		*/
		System.out.println("sorted");
	    int answer=indexOfArray;
	    
	    for(i=0;i<indexOfArray;i++)
	    	System.out.println("i="+i+" for x=>n = "+x[i].n+"\t d = "+x[i].d+"\t for y=>n = "+y[i].n+"\t d = "+y[i].d);
		
	    System.out.println("you are now entering to eliminate the duplicate elements...");
	    
		boolean booleanArray[]=new boolean[indexOfArray];
		
		for(i=0;i<indexOfArray;i++)
			booleanArray[i]=false;
		
		/* this is the brute force to eliminate the duplicate. */
		
		/* 
		System.out.println("The long process has started...");
		for(i=0;i<indexOfArray;i++)
		{
			System.out.println(i);
			if(booleanArray[i]==false)
			{
				for(j=i+1;j<indexOfArray;j++)
				{
					if(x[i].equals(x[j]) && y[i].equals(y[j]))
					{
						System.out.println("Found an enemy");
						booleanArray[i]=booleanArray[j]=true;
						answer--;
					}
				}
			}
		}
		*/
		for(i=0;i<indexOfArray;)
	    {
	    	for(j=i+1;j<indexOfArray && x[i].n==x[j].n;j++);
	    	
	    	for(int p=i;p<j;p++)
	    	{
	    		if(booleanArray[i]==false)
	    		{
		    		for(int q=p+1;q<j;q++)
		    		{
		    			if(x[p].equals(x[q]) && y[p].equals(y[q]))
		    			{
		    				booleanArray[p]=true;
		    				booleanArray[q]=true;
		    				System.out.println("You got an enemy");
		    				answer--;
		    			}
		    		}
	    		}
	    	}
	    	i=j;
	    }
	    
		System.out.println(answer);
	}
}