#include<stdio.h>
#include<stdlib.h>
int **s;
 	
int issum(int arr[], int sum, int n)
{
	int i,j;
	s=(int**)malloc(sizeof(int*)*(sum+1));
	for(i=0;i<sum+1;i++)
		s[i]=(int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<=n;++i) s[0][i]=1;
 
    for(i=1;i<=sum;++i) s[i][0]=0;
 
	for(i=1;i<=sum;++i)
    	for(j=1;j<=n;++j)
   	    {
        	s[i][j] = s[i][j-1];
         	if(i >= arr[j-1]) s[i][j]=s[i][j]||s[i-arr[j-1]][j-1];
       	}
    return s[sum][n];
}

int main()
{
	int t,i,*arr,sum,n;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		if(sum%2==0)
		{
			sum=sum/2;
			if(issum(arr,sum,n))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			printf("NO\n");
		}
		free(arr);
	}
	return 0;
}
