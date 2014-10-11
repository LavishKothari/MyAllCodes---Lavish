#include<stdio.h>
#include<math.h>

long long int findAnswer(long long int n)
{
    long long int answer,nearestPower;
    answer=(int)pow(n,1/3.0);
    while(answer*(answer+1)*(2*answer+1)/6 <= n)
        answer++;
    answer--;
    return answer;

}
int main()
{
    long long int t,n,answer;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        answer=findAnswer(n);
        printf("%lld\n",answer);
    }
    return 0;
}
