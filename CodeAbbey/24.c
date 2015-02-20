#include<stdio.h>
#define MAX 10000
int main()
{
	int t,counter,cn,i,n,arr[MAX];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<MAX;i++)
			arr[i]=-1;
		scanf("%d",&n);
		cn=n;
		counter=0;
		arr[cn]++;
		do{
			cn=((cn*cn)/100)%10000;
			if(arr[cn]!=-1)
				break;
			arr[cn]++;
			counter++;
		}while(1);
		printf("%d ",counter+1);
	}
	return 0;
}
