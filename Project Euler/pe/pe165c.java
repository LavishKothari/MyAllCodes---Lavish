package pe165;

public class pe165
{

	public static int heapLength;

	static Float x[];
	static Float y[];
	int size=2868997;
	static int indexOfArray=0;

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
	    xcoordinate=((float)(f*g+a*d-e*h-b*c)*(c-a)*(g-e))/((d-b)*(g-e)-(h-f)*(c-a));
	    ycoordinate=((float)(f*g+a*d-e*h-b*c)*(c-a)*(g-e))/((d-b)*(g-e)-(h-f))*((d-b))+b*c-a*d;

	    x[indexOfArray]=new Float(xcoordinate);
	    y[indexOfArray]=new Float(ycoordinate);
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
	    x=new Float[2868997];
	    y=new Float[2868997];

	    calculateS(t);

	    for(i=0;i<5000;i++)
	    {
	    	System.out.println(i);
	        for(j=i+1;j<5000;j++)
	            segmentsIntersect(t[i*4+1],t[i*4+2],t[i*4+3],t[i*4+4],t[j*4+1],t[j*4+2],t[j*4+3],t[j*4+4]);
	    }
	    boolean flag[]=new boolean[2868997];
	    for(i=0;i<2868997;i++)
	    {
	    	flag[i]=true;
	    }
	    int enemy=0;
	    for(i=0;i<indexOfArray;i++)
	    {
	    	if(i%100==0)
	    		System.out.println("helllo -> "+i+"   enemy = "+enemy);
	    	if(flag[i]==true)
	    	{
	    		for(j=i+1;j<indexOfArray;j++)
		    	{
		    		if(x[i].equals(x[j]) && y[i].equals(y[j]))
		    		{
		    			enemy++;
		    			flag[j]=false;
		    		}
		    	}
	    	}
	    }
	    int answer=0;
	    for(i=0;i<2868997;i++)
		    if(flag[i])
		    	answer++;
	    System.out.println("Answer is "+answer);
	}

}
