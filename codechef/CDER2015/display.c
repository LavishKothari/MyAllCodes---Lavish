#include<stdio.h>
int findDashes(int n)
{
	switch(n)
	{
		case 0: return 6;
		case 1: return 2;
		case 2: return 5;
		case 3: return 5;
		case 4: return 4;
		case 5: return 5;
		case 6: return 6;
		case 7: return 3;
		case 8: return 7;
		case 9: return 6;
	}
}
int main()
{
	int i,answer=0;
	char str[101];
	scanf("%s",str);
	for(i=0;str[i];i++)
		answer+=findDashes(str[i]-'0');
	printf("%d\n",answer);
	return 0;
}
