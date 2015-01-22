#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long long int answer;
    long long int temp,i,n,k,s;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%lld%lld",&n,&k);
        while(n)
        {
            /*
            s=1;
            while(s<=n)
                s*=k;
            s/=k;
            */
            s=(long long int)pow(k,(long long int)(log(n)/log(k)));

            // now s contains closest power
            temp=(long long int)(n/s);

            n%=s;
            answer+=temp;
        }
        printf("%lld\n",answer);
    }
    return 0;
}
