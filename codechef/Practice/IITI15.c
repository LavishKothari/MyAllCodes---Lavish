#include<stdio.h>
#include<stdlib.h>
int arr[20010],n;
int temp[20010];
int merge(int l,int mid,int r)
{
	int *t,counter,i,j,inversions=0;
	t=(int*)malloc(sizeof(int)*(r-l+1));
	counter=0;
	for(i=l,j=mid+1;i<=mid && j<=r;counter++)
	{
		if(temp[i]<=temp[j])
			t[counter]=temp[i++];
		else 
		{
			inversions+=(mid-i+1);
			t[counter]=temp[j++];
		}
	}
	while(i!=mid+1)
		t[counter++]=temp[i++];
	while(j!=r+1)
		t[counter++]=temp[j++];
	for(i=l;i<=r;i++)
		temp[i]=t[i-l];
	free(t);
	return inversions;
}

int findAnswer(int l,int r)
{
	int mid=(l+r)/2,x,y,z;
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
	int l,r,q,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		l--;r--;
		for(i=l;i<=r;i++)
			temp[i-l]=arr[i];
		printf("%d\n",findAnswer(0,r-l));
	}
	return 0;
}
