#include<stdio.h>
#include<stdlib.h>
int arr[100010],n;
int arr[100010];

int merge(int l,int mid,int r)
{
	int *t,counter,i,j,inversions=0;
	t=(int*)malloc(sizeof(int)*(r-l+1));
	counter=0;
	for(i=l,j=mid+1;i<=mid && j<=r;counter++)
	{
		if(arr[i]<=arr[j])
			t[counter]=arr[i++];
		else 
		{
			inversions+=(mid-i+1);
			t[counter]=arr[j++];
		}
	}
	while(i!=mid+1)
		t[counter++]=arr[i++];
	while(j!=r+1)
		t[counter++]=arr[j++];
	for(i=l;i<=r;i++)
		arr[i]=t[i-l];
	free(t);
	return inversions;
}

int findAnswer(int l,int r)
{
	int mid=(l+r)/2;
	int x,y,z;
	if(r>l)
	{
		x=findAnswer(l,mid);
		y=findAnswer(mid+1,r);
		z=merge(l,mid,r);
		return x+y+z;
	}
	else return 0;
}

int main()
{
	int t,l,r,q,i,counter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		counter=0;
		for(i=0;i<n-2;i++)
			if(arr[i]<=i || arr[i]==i+1 || arr[i]==i+2 || arr[i]==i+3)
				counter++;
		if(counter==n-2)
			printf("%d\n",findAnswer(0,n-1));
		else printf("Too chaotic\n");
	}
	return 0;
}
