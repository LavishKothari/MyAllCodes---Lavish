#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int **matrixMultiply(int**a,int r1,int c1,int **b,int r2,int c2)
{
	int **resultMatrix;
	int i,j,k,r,c;
	r=r1;c=c2;
	resultMatrix=(int**)malloc(sizeof(int*)*r);
	for(i=0;i<r;i++)
		resultMatrix[i]=(int*)malloc(sizeof(int)*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			resultMatrix[i][j]=0;
			for(k=0;k<c1;k++)
				resultMatrix[i][j]+=a[i][k]*b[k][j];
		}
	}
	return resultMatrix;
}
void printMatrix(int**matrix,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}
int plainTextToCipherText(char plainText[],int**matrix)
{
	int len,**plainTextMatrix,**resultMatrix,i,j;
	// The matrix will be of dimensions strlen(plainText) by strlen(plainText)
	char *cipherText;
	len=strlen(plainText);
	cipherText=(char*)malloc(sizeof(char)*1000);

	// plainTextMatrix should be of dimension strlen(plainText) by 1
	// allcating memory to plainTextMatrix
	plainTextMatrix=(int**)malloc(sizeof(int*)*len);
	for(i=0;i<len;i++)
		plainTextMatrix[i]=(int*)malloc(sizeof(int)*1);

	// populating the plainTextMatrix
	for(i=0;i<len;i++)
		for(j=0;j<1;j++)
			plainTextMatrix[i][j]=plainText[i]-'a';

	resultMatrix=matrixMultiply(matrix,len,len,plainTextMatrix,len,1);
	
	// taking mod 26 of each element of the result matrix
	for(i=0;i<len;i++)
		for(j=0;j<1;j++)
			resultMatrix[i][j]%=26;

	// Printing the cipher text
	printf("The cipher text is as follows : ");
	for(i=0;i<len;i++)
		for(j=0;j<1;j++)
			printf("%c",resultMatrix[i][j]+'a');
	printf("\n");
	//printMatrix(resultMatrix,len,1);
}
int main()
{
	int len,i,j,**matrix;
	char plainText[1000];
	printf("Enter the word to be encrypted : ");
	scanf(" %s",plainText);
	len=strlen(plainText);

	// allocating memory to matrix
	matrix=(int**)malloc(sizeof(int*)*len);
	for(i=0;i<len;i++)
		matrix[i]=(int*)malloc(sizeof(int)*len);

	printf("Enter the matrix of %d by %d to be used in encryption process : \n",len,len);
	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			scanf("%d",&matrix[i][j]);

	plainTextToCipherText(plainText,matrix);
	return 0;
}
