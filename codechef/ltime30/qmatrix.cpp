#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *l,*r;
	bool *row,*col;
	l=(int*)malloc(sizeof(int)*n);
	r=(int*)malloc(sizeof(int)*n);
	row=(bool*)malloc(sizeof(bool)*n);
	col=(bool*)malloc(sizeof(bool)*n);
	// 1 for true
	// 0 for false
	long long int c=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		l[i]--;
		r[i]--;
		c+=r[i]-l[i]+1;
		row[i]=(r[i]-l[i]+1)%2!=0;
	}
	bool totalParity=(c%2==1);

	for(int i=0;i<n;i++)
	{
		int counter=0;
		for(int j=0;j<n;j++)
			if(i>=l[j] && i<=r[j])
				counter++;
		col[i]=counter%2==1;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		long long int temp=c-(int)row[x]-(int)col[y];
		if(l[x]<=y && r[x]>=y)
			temp--;
		if(temp%2==0)
			printf("E\n");
		else printf("O\n");
	}
	return 0;
}
