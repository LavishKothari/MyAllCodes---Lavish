#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

ll findAnswer(int *a,int n)
{
	long long int sum=0;
	long long int i, dp[n], ci;

	for(i=1;i<=n;i++)
		dp[i]=1;
		
	i = 0;	
	while(i<n ) {
		if(a[i] < a[i+1]) {
			i++;
		}
		else {
		
		}
	
	
	}	
	
}

int main()
{
    int i,n,*arr;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	printf("%lld\n",findAnswer(arr,n));
	return 0;
}
