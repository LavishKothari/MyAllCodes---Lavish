#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,x,q,p,k;
    double answer;
    scanf("%lld",&t);
    while(t--)
    {
        scanf(" %lld%lld",&x,&k);
        p=(long long int)log2(k)+1;
        q=k-(long long int)pow(2,p-1)+1;
        answer=(x/pow(2,p))*(2*q-1);
        printf("%f\n",answer);
    }
    return 0;
}
