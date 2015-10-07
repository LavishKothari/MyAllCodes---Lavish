#include<stdlib.h>
#include<stdio.h>

void generateTestCase1(int r,int c)
{
	FILE*f;
	int i,j;
	f=fopen("test1.txt","w");
	if(f)
	{
		fprintf(f,"%d %d\n",2*r,c);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j) fprintf(f,"\\");
				else fprintf(f,"*");
			}
			fprintf(f,"\n");
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i+j==c-1) fprintf(f,"/");
				else fprintf(f,"*");
			}
			fprintf(f,"\n");
		}
		
		fclose(f);
	}
	else printf("There was an error in opening the file...\n");
}
void generateTestCase2(int n,int line)
{
	FILE*f;
	int i,j;
	f=fopen("test2.txt","w");
	if(f)
	{
		fprintf(f,"%d %d\n",n,n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==line && j!=n-1)
					fprintf(f,"-");
				else if(i==line && j==n-1)
					fprintf(f,">");
				else fprintf(f,"*");
			}
			fprintf(f,"\n");
		}
		fclose(f);
	}
	else printf("There was an error in opening the file...\n");
}

char map(char ch)
{
	if(ch=='|') return '-';
	if(ch=='-') return '|';
	if(ch=='^') return '>';
	if(ch=='>') return 'v';
	if(ch=='v') return '<';
	if(ch=='<') return '^';
	if(ch=='\\') return '/';
	if(ch=='/') return '\\';
	return ch;
	
}
void generateRotation(char*input,char*output)
{
	int i,j,in_cols,out_cols,in_rows,out_rows;
	char**inputArray,**outputArray;
	FILE*in,*out;
	in=fopen(input,"r");
	out=fopen(output,"w");
	if(in && out)
	{
		fscanf(in,"%d%d",&in_rows,&in_cols);
		inputArray=(char**)malloc(sizeof(char*)*in_rows);
		for(i=0;i<in_rows;i++)
			inputArray[i]=(char*)malloc(sizeof(char)*in_cols);
		for(i=0;i<in_rows;i++)
			for(j=0;j<in_cols;j++)
				fscanf(in," %c",&inputArray[i][j]);
		/* constructing the output Array. */
		out_rows=in_cols;
		out_cols=in_rows;
		outputArray=(char**)malloc(sizeof(char*)*out_rows);
		for(i=0;i<out_rows;i++)
			outputArray[i]=(char*)malloc(sizeof(char)*out_cols);

		for(i=0;i<in_rows;i++)
			for(j=0;j<in_cols;j++)
				outputArray[j][in_rows-1-i]=map(inputArray[i][j]);
	
		fprintf(out,"%d %d\n",out_rows,out_cols);
		for(i=0;i<out_rows;i++)
		{
			for(j=0;j<out_cols;j++)
				fprintf(out,"%c",outputArray[i][j]);
			fprintf(out,"\n");
		}
	}
	else printf("There was some error in opening the file...\nExiting...\n");
	if(in) fclose(in);
	if(out) fclose(out);
}
int main()
{
	char input[100],output[100];
	generateTestCase1(100,100);
	generateTestCase2(100,15);
	
	printf("Enter the name of input file : ");
	scanf(" %s",input);
	printf("Enter the name of output file : ");
	scanf(" %s",output);
	generateRotation(input,output);
	return 0;
}
