package pe165;

public class pe165 
{
	
	public static int heapLength;
	
	static float x[];
	static float y[];
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
	
	public static void maxHeapify(float[]x,float[]y,int i)
	{
		int l=getLeftChildIndex(i+1)-1; // our array is zero indexed array...
		int r=getRightChildIndex(i+1)-1;
		int largest;
		float tmp;
		if(l<=heapLength-1 && x[l]>x[i])
			largest=l;
		else
			largest=i;
			
		if(r<=heapLength-1 && x[r]>x[largest])
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
	
	public static void buildMaxHeap(float[]x,float[]y)
	{
		for(int i=getParentIndex(x.length)-1;i>=0;i--)
			maxHeapify(x,y,i);
	}
	
	public static void heapSort(float[]x,float[]y)
	{
		buildMaxHeap(x,y);
		float tmp;
		for(int i=x.length-1;i>=1;i--)
		{
			tmp=x[0];
			x[0]=x[i];
			x[i]=tmp;
			
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
	    int i;
	    int s[]=new int[20001];
	    s[0]=290797;
	    t[0]=s[0]%500;
	    for(i=1;i<=20000;i++)
	    {
	        s[i]=(int)((((long)(s[i-1])*s[i-1])%50515093));
	        t[i]=s[i]%500;
	    }
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

	public static void calculateIntersectionPoint(int a,int b,int c,int d,int e,int f,int g,int h)
	{
	    float xcoordinate,ycoordinate;
	    
	    xcoordinate=(((f*g-e*h)*(c-a)+(a*d-b*c)*(g-e)))/(float)((d-b)*(g-e)-(h-f)*(c-a));
	    if(c!=a)
	    	ycoordinate=((d-b)*xcoordinate+b*c-a*d)/(float)(c-a);
	    else
	    	ycoordinate=((h-f)*xcoordinate+f*g-e*h)/(float)(g-e);
	    //System.out.println(a+","+b+"#"+c+","+d+"#"+e+","+f+"#"+g+","+h+"#-->"+xcoordinate+","+ycoordinate);
	    x[indexOfArray]=(xcoordinate);
	    y[indexOfArray]=(ycoordinate);
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
	    int i,j;
	    int t[]=new int[20001];
	    
	    x=new float[2868997];
	    y=new float[2868997];
	    
	    calculateS(t);
	    
	    for(i=0;i<5000;i++)
	    {
	    	//System.out.println(i);
	        for(j=i+1;j<5000;j++)
	            segmentsIntersect(t[i*4+1],t[i*4+2],t[i*4+3],t[i*4+4],t[j*4+1],t[j*4+2],t[j*4+3],t[j*4+4]);
	    }

	    heapLength=size;
		heapSort(x,y);
		/*
		for(i=0;i<500;i++)
			System.out.println(x[i]+","+y[i]);
		*/
		System.out.println("sorted");
	    int answer=size;
	    int answer1=0;
	    for(i=0;i<size;)
	    {
	    	answer1++;
	    	j=i+1;
	    	while(j<size && x[i]==x[j])
	    	{
	    		answer--;
	    		//System.out.println(x[i]+"   "+x[i+1]);
	    		j++;
	    	}
	    	i=j;
	    }
	    System.out.println(answer);
	    System.out.println(answer1);
	}
}
