#include<stdio.h>
#include<stdlib.h>

int isInteger(float x)
{
    if(x-(int)x)
        return 0;
    else
        return 1;
}

long long int calculateSquareDistance(int a,int b,int c,int d)
{
    return ((long long int)(a-c)*(a-c)+(long long int)(b-d)*(b-d));
}

int  calculateNoOfPoints(int *x,int *y,int i,int j,int n)
{
    float x3,y3,x4,y4;
    int a,b,c,d,counter,x5,y5,x6,y6,x7,y7,x8,y8,k,counter1,counter2,max,temp;
    long long int distanceSquare,dis1,dis2;
    a=x[i];
    b=y[i];
    c=x[j];
    d=y[j];
    //considering x[i],y[i] and x[j],y[j] as the diagonal points.
    x3=(a-b+c+d)/2.0 ;
    y3=(a+b-c+d)/2.0 ;
    x4=(a+b+c-d)/2.0 ;
    y4=(-a+b+c+d)/2.0 ;

    x5=d-b+a;
    y5=a-c+b;
    x6=b-d+a;
    y6=c-a+b;
    x7=b-d+c;
    y7=c-a+d;
    x8=d-b+c;
    y8=a-c+d;

    distanceSquare=calculateSquareDistance(x[i],y[i],x[j],y[j]);
    dis1=calculateSquareDistance(x5,y5,x7,y7);
    dis2=calculateSquareDistance(x5,y5,x8,y8);

    if(dis1!=distanceSquare)
    {
        temp=x7;
        x7=x8;
        x8=temp;

        temp=y7;
        y7=y8;
        y8=temp;
    }

    counter=counter1=counter2=0;

    for(k=0;k<n;k++)
    {
        if(isInteger(x3) && isInteger(y3) && isInteger(x4) && isInteger(y4))
        {
            if(((int)x3==x[k]&& (int)y3==y[k]) || ((int)x4==x[k] && (int)y4==y[k]))
            {
                counter++;
                if(counter==2)
                    return 0;
            }
        }
        if((x5==x[k]&& y5==y[k]) || (x7==x[k] && y7==y[k]))
        {
            counter1++;
            if(counter1==2)
                return 0;
        }
        if((x6==x[k]&& y6==y[k]) || (x8==x[k] && y8==y[k]))
        {
            counter2++;
            if(counter2==2)
                return 0;
        }
    }


    max=(counter>=counter1)?(counter>=counter2?counter:counter2):(counter1>=counter2?counter1:counter2);
    if(max==0)
        return 2;
    return 1;
}

int main()
{
    int i,j,n,*x,*y,min=4,res;
    scanf("%d",&n);
    if(n==1)
    {
        printf("3");
        return 0;
    }
    if(n==2)
    {
        printf("2");
        return 0;
    }
    x=(int*)malloc(sizeof(int)*n);
    y=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            res=calculateNoOfPoints(x,y,i,j,n);
            //printf("%d,%d = %d\n",i,j,res);
            if(res==0)
            {
                printf("0");
                return 0;
            }
            if(res<min)
                min=res;

        }
    }
    printf("%d",min);
    return 0;
}
