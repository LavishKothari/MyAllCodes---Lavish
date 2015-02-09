package pe165;

public class pe165 
{
	
	public static int heapLength;
	
	static Fraction x[];
	static Fraction y[];
	static int size=2868997;
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
	public static void calculateS(long t[])
	{
	    int i;
	    long s[]=new long[20001];
	    s[0]=290797;
	    t[0]=s[0]%500;
	    for(i=1;i<=20000;i++)
	    {
	        s[i]=(s[i-1]*s[i-1])%50515093;
	        t[i]=s[i]%500;
	        //System.out.println("t["+i+"] = "+t[i]);
	    }
	}

	public static long direction(long xi,long yi,long xj,long yj,long xk,long yk)
	{
		long ax,ay,bx,by;
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
	    xNumerator=-a*d*e + a*d*g + a*e*h - a*f*g + b*c*e - b*c*g - c*e*h + c*f*g;
	    xDenominator=-a*f + a*h + b*e - b*g + c*f - c*h - d*e + d*g;
	    
	    yNumerator=a*d*f - a*d*h - b*c*f + b*c*h - b*e*h + b*f*g + d*e*h - d*f*g;
	    yDenominator=a*f - a*h - b*e + b*g - c*f + c*h + d*e - d*g;
	    
	    
	    Fraction xFraction=new Fraction(xNumerator,xDenominator);
	    Fraction yFraction=new Fraction(yNumerator,yDenominator);
	    
	    /*
	    the following is the check for the true intersection point. 
	    if((xFraction.d==1&&yFraction.d==1) && ((xFraction.n==a&&yFraction.n==b) || (xFraction.n==c&&yFraction.n==d) || (xFraction.n==e&&yFraction.n==f) || (xFraction.n==g&&yFraction.n==h)))
	    	return ;
	    */
	    
	    x[indexOfArray]=xFraction;
	    y[indexOfArray]=yFraction;
	    
	    //System.out.println(a+","+b+"#"+c+","+d+"#"+e+","+f+"#"+g+","+h+"\t"+"xn="+x[indexOfArray].n+" xd="+x[indexOfArray].d+" yn="+y[indexOfArray].n+" yd="+y[indexOfArray].d);
	    
	    indexOfArray++;
	}

	public static int segmentsIntersect(long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4)
	{
		long d1,d2,d3,d4;
	    d1=direction(x3,y3,x4,y4,x1,y1);
	    d2=direction(x3,y3,x4,y4,x2,y2);
	    d3=direction(x1,y1,x2,y2,x3,y3);
	    d4=direction(x1,y1,x2,y2,x4,y4);
	    if(((d1>0&&d2<0) || (d1<0&&d2>0)) && ((d3>0&&d4<0) || (d3<0&&d4>0)))
	    {
	        // means segments have a true intersection point.
	        calculateIntersectionPoint(x1,y1,x2,y2,x3,y3,x4,y4); // this function calculates the true intersection point of the the two given segemnts.
	        return 1;
	    }
	    return 0;
	}

	public static void main(String args[])
	{
		System.out.println("Started");
	    int i,j;
	    long t[]=new long[20001];
	    
	    x=new Fraction[size];
	    y=new Fraction[size];
	    
	    calculateS(t);
	    Segment segmentArray[]=new Segment[5000];
	    for(i=0;i<5000;i++)
	    {
	    	segmentArray[i]=new Segment(t[i*4+1],t[i*4+2],t[i*4+3],t[i*4+4]);
	    }
	    
	    for(i=0;i<5000;i++)
	    {
	    	//System.out.println(i);
	        for(j=i+1;j<5000;j++)
	            segmentsIntersect(segmentArray[i].a,segmentArray[i].b,segmentArray[i].c,segmentArray[i].d,segmentArray[j].a,segmentArray[j].b,segmentArray[j].c,segmentArray[j].d);
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
	    
	    /*
	    for(i=0;i<50;i++)
	    	System.out.println("for x=>n = "+x[i].n+"\t d = "+x[i].d+"\t for y=>n = "+y[i].n+"\t d = "+y[i].d);
		*/
	    System.out.println("you are now entering to eliminate the duplicate elements...");
	    
		boolean booleanArray[]=new boolean[indexOfArray];
		
		for(i=0;i<indexOfArray;i++)
			booleanArray[i]=false;
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
	    	/*
	    	if(j==i+1)
	    	{
	    		i++;
	    		continue;
	    	}
	    	*/
	    	for(int p=i;p<j;p++)
	    	{
	    		if(booleanArray[i]==false)
	    		{
		    		for(int q=p+1;q<j;q++)
		    		{
		    			if(x[p].equals(x[q]) && y[p].equals(y[q]) && booleanArray[q]==false)
		    			//if(x[p].value==x[q].value && y[p].value==y[q].value)
		    			{
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
