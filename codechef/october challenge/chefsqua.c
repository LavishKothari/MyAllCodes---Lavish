#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b)
{
    long long int answer=( *(long long int*)a - *(long long int*)b );
    if(answer==0)
        return 0;
    if(answer>0)
        return 1;
    if(answer<0)
        return -1;
}

int isSquare(long long int a,long long int b,long long int c,long long int d,long long int e,long long int f)
{
    long long int arr[6];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    arr[3]=d;
    arr[4]=e;
    arr[5]=f;
    qsort(arr,6,sizeof(long long int),compare);

    if(arr[0]==arr[1] && arr[2]==arr[1] && arr[2]==arr[3] && arr[4]==arr[5] && arr[3]*2==arr[4])
        return 1;
    return 0;

}
int isRightAngledTriangle(long long int a,long long int b,long long int c)
{
    // here you have to check whether the triangle formed is a isosceles right angled triangle or not
    long long int arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    qsort(arr,3,sizeof(long long int),compare);
    if(arr[0]==arr[1] && arr[1]*2==arr[2])
        return 1;
    return 0;

}
long long int distanceSquare(int a,int b,int c,int d)
{
    return ((c-a)*(long long int)(c-a))+((d-b)*(long long int)(d-b));
}
int isSquareAlreadyPresent(int x[],int y[],int n)
{
    int i,j,k,l;
    long long int a,b,c,d,e,f;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                a=distanceSquare(x[i],y[i],x[j],y[j]);
                b=distanceSquare(x[i],y[i],x[k],y[k]);
                c=distanceSquare(x[j],y[j],x[k],y[k]);
                if(isRightAngledTriangle(a,b,c))
                {

                    for(l=k+1;l<n;l++)
                    {
                        a=distanceSquare(x[i],y[i],x[j],y[j]);
                        b=distanceSquare(x[i],y[i],x[k],y[k]);
                        c=distanceSquare(x[i],y[i],x[l],y[l]);
                        d=distanceSquare(x[j],y[j],x[k],y[k]);
                        e=distanceSquare(x[j],y[j],x[l],y[l]);
                        f=distanceSquare(x[k],y[k],x[l],y[l]);
                        printf("%lld %lld %lld %lld %lld %lld \n",a,b,c,d,e,f);
                        if(isSquare(a,b,c,d,e,f))
                            return 1;
                    }
                }

            }
        }
    }
    return 0;
 }

int main()
{
    int n,i,*x,*y;
    scanf("%d",&n);
    x=(int*)malloc(sizeof(int)*n);
    y=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);

    if(n==0)
        printf("4\n");
    else if(n==1)
        printf("3\n")
    else if(isSquareAlreadyPresent(x,y,n))
        printf("0");

    return 0;
}
