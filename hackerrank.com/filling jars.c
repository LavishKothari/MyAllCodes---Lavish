#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long long int  n,m,a,b,k;
    long long int sum=0;
    long long int avg;
    scanf("%lld%lld",&n,&m);
    while(m--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        sum+=k*(b-a+1);
    }
    //printf("sum = %d  ",sum);
    avg=sum/n;
    printf("%lld\n ",(avg));
    return 0;
}
