#include<stdio.h>
#include<math.h>
int level(int a)
{
	return (int)(log2(a));
}
int main()
{	
	int t,a,b,answer;
	scanf("%d",&t);
	while(t--)
	{
		answer=0;
		scanf("%d%d",&a,&b);
		while(level(a)!=level(b))
		{
			if(a>b)
			{
				a/=2;
				answer++;
			}
			else
			{
				b/=2;
				answer++;
			}
		}
		while(a>1 && a!=b)
		{
			a/=2;
			b/=2;
			answer+=2;
		}
		if(answer>0)
			answer--;
		if(answer%2==0)
			printf("Bike %d\n",answer);
		else printf("Car %d\n",answer);
	}
	return 0;
}
