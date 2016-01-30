#include<stdio.h>

int main()
{
	FILE *fp;
	char str[10000];
	printf("Enter the data : \n");
	scanf("%[^\n]s",str);
	/* writing to the file */
	fp=fopen("DATA.txt","w");
	if(fp)
	{
		fprintf(fp,"%s",str);
		fclose(fp);
	}
	else printf("There was some error in opening the file.\n");
	
	/* reading from the file */
	fp=fopen("DATA.txt","r");
	if(fp)
	{
		fscanf(fp,"%[^\n]s",str);
		printf("The contents of file are : %s\n",str);
		fclose(fp);
	}
	else printf("There was some error in opening the file.\n");
	
	
	return 0;
}
