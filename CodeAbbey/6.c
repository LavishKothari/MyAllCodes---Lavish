#include<math.h>
#include<stdio.h>
int main()
{
    int t,a,b;
    FILE*f;
    f=fopen("a.txt","r");
    fscanf(f,"%d",&t);
    while(t--)
    {
        fscanf(f,"%d%d",&a,&b);
        printf("%d ",(int)round(a/(double)b));
    }
    return 0;
}
