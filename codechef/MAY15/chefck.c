#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
int **minArray;
long long int min(long long int a,long long int b)
{
    return a<b?a:b;
}
long long int power(long long int a,long long int b,long long int mod)
{
    long long int t;
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    t=power(a,b/2,mod);
    if(b%2==0)
        return (t*t)%mod;
    return (((t*t)%mod)*a)%mod;
}
long long int findMinimum(int arr[],long long int a,long long int b)
{
    int i,min;
    min=arr[a];
    for(i=a+1;i<=b;i++)
        if(min>arr[i])
            min=arr[i];
    return min;
}
int main()
{
    long long int x, i, L, R, a, b, c, d, e, f, r, s, t, m, L1, La, Lc, Lm, D1, Da, Dc, Dm, N, K, Q,sum,product,minimum; 
    int *A;
    scanf("%lld%lld%lld",&N,&K,&Q);
    minArray=(int**)malloc(sizeof(int*)*N);
    for(i=0;i<N;i++)
        minArray[i]=(int*)malloc(sizeof(int)*N);
    
    A=(int*)malloc(sizeof(int)*N);
    printf("done!!!");
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%d",&a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &A[0]);
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&L1, &La, &Lc, &Lm, &D1, &Da, &Dc, &Dm);
    
    for(x = 1 ; x<N ; x++)
	    if(power(t,x+1,s)  <= r)        // Here t^x signifies "t to the power of x"
		    A[x] = (((a*power(A[x-1],2,m))%m + ((b*A[x-1])%m + c))%m) % m;
	    else
		    A[x] = ((d*power(A[x-1],2,m))%m + ((e*A[x-1])%m + f)%m) % m;
    sum=0;
    product=1;
    for(i = 0 ; i<Q ; i++)
	{
	    L1 = ((La * L1)%Lm + Lc) % Lm;
	    D1 = ((Da * D1)%Dm + Dc) % Dm; 
	    L = L1 + 1;
	    R = min(L + K - 1 + D1, N);
	    L--;R--;
	    minimum=findMinimum(A,L,R);
	    sum+=minimum;
	    product=(product*minimum)%MOD;
    }
    printf("%lld %lld\n",sum,product);
    return 0;
}
