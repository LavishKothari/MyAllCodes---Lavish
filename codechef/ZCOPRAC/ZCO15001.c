#include<stdio.h>
int n,arr[301];
int isPalindrome(int start,int end)
{
	int i,j;
	for(i=start,j=end;i<j;i++,j--)
		if(arr[i]!=arr[j])
			return 0;
	return 1;
}
int findLongest(int start,int end)
{
	int i;
	for(i=end;i>=start;i--)
		if(isPalindrome(start,i))
			return i;
}
int findAnswer(int start,int end)
{
	printf("%d %d\n",start,end);
	int myend,realend,max,i,realstart;
	if(end<start || end<0 || start>n)
		return 0;
	if(end==start)
		return 1;
	max=0;
	for(i=start;i<=end;i++)
	{
		myend=findLongest(start,end);
		if(myend-i+1>max)
		{
			realstart=i;
			realend=myend;
			max=myend-i+1;
		}
	}
	
	return findAnswer(start,realstart-1)+1+findAnswer(realend+1,end);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		scanf("%d",&arr[i]);
	}
	printf("%d\n",findAnswer(0,n-1));
	return 0;
}
