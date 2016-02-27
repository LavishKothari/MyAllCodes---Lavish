#include<stdio.h>

int main()
{
	int t,a,b;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
			printf("Bipin %d\n",a-b);
		else if(b>a)
			printf("Balaji %d\n",b-a);
		else printf("No Winner\n");
	}
	return 0;
}
