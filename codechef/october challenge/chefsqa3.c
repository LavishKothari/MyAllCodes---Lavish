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
void bubbleSort(int *x, int*y, int n)
{
    int i,j,tmp,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                flag=1;
                tmp=x[j];
                x[j]=x[j+1];
                x[j+1]=tmp;

                tmp=y[j];
                y[j]=y[j+1];
                y[j+1]=tmp;
            }
        }
        if(flag==0)
            break;
    }
}
int binarySearch(int arr[],int n,int sval)
{
    int first=0;
    int last=n-1;
    int mid;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(arr[mid]==sval)
            return mid;
        if(sval>arr[mid])
            first=mid+1;
        else if(sval<arr[mid])
            last=mid-1;
    }
    return -1;
}

int  calculateNoOfPoints(int *x,int *y,int i,int j,int n)
{
    float x3,y3,x4,y4;
    int a,b,c,d,counter,x5,y5,x6,y6,x7,y7,x8,y8,k,counter1,counter2,max,temp,flag,index;
    long long int distanceSquare,dis1,dis2;
    a=x[i];
    b=y[i];
    c=x[j];
    d=y[j];

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
    flag=0;
    if(isInteger(x3) && isInteger(y3) && isInteger(x4) && isInteger(y4))
        flag=1;

    if(flag==1)
    {
        if((index=binarySearch(x,n,(int)x3))!=-1 && y[index]==(int)y3)
            counter++;
        if((index=binarySearch(x,n,(int)x4))!=-1 && y[index]==(int)y4)
            counter++;
        if(counter==2)
            return 0;

        if((index=binarySearch(x,n,(int)x5))!=-1 && y[index]==(int)y5)
            counter1++;
        if((index=binarySearch(x,n,(int)x7))!=-1 && y[index]==(int)y7)
            counter1++;
        if(counter1==2)
            return 0;

        if((index=binarySearch(x,n,(int)x6)!=-1) && y[index]==(int)y6)
            counter2++;
        if((index=binarySearch(x,n,(int)x8)!=-1) && y[index]==(int)y8)
            counter2++;
        if(counter2==2)
            return 0;

    }
    else
    {
        if((index=binarySearch(x,n,(int)x5))!=-1 && y[index]==(int)y5)
            counter1++;
        if((index=binarySearch(x,n,(int)x7))!=-1 && y[index]==(int)y7)
            counter1++;
        if(counter1==2)
            return 0;

        if((index=binarySearch(x,n,(int)x6)!=-1) && y[index]==(int)y6)
            counter2++;
        if((index=binarySearch(x,n,(int)x8)!=-1) && y[index]==(int)y8)
            counter2++;
        if(counter2==2)
            return 0;
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
        scanf("%d %d",&x[i],&y[i]);

    bubbleSort(x,y,n);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            res=calculateNoOfPoints(x,y,i,j,n);
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
