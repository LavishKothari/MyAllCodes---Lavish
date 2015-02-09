#include<stdio.h>

int main()
{
	int test,x,y,z;
	float answer;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&x,&y,&z);
		answer=(z*(x-y))/(float)y;
		if((int)answer!=answer)
			answer=(int)answer+1;
		if(answer<0)
			printf("0\n");
		else
			printf("%g\n",answer);
	}
	return 0;
}
