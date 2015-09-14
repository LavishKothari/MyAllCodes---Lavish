#include<stdio.h>

int main()
{
	char str[3];
	printf("Ready\n");
	while(1)
	{
		gets(str);
		//printf("%s\n",str);
		if(str[0]==str[1] && str[1]==' ')
			break;
		if(str[0]=='d' && str[1]=='b')
			printf("Mirrored pair\n");
		else if(str[0]=='b' && str[1]=='d')
			printf("Mirrored pair\n");
		else if(str[0]=='p' && str[1]=='q')
			printf("Mirrored pair\n");
		else if(str[0]=='q' && str[1]=='p')
			printf("Mirrored pair\n");
		else 
			printf("Ordinary pair\n");
	}
	return 0;
}
