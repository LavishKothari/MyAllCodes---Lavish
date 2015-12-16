#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[101];
		int mina,minb;
		mina=minb=101;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			int a,b;
			a=b=0;
			for(int j=0;str[j];j++)
				if(str[j]=='a')
					a++;
				else b++;
			if(a<mina)
				mina=a;
			if(b<minb)
				minb=b;
		}
		printf("%d\n",mina<minb?mina:minb);
	}
	return 0;
}
