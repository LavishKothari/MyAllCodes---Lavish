#include"matrix.h"
int getMatrix_i_j(int i,int j,int* arr,int n)
{
	int bitNumber=i*n+j;
	if((arr[bitNumber/32]&((unsigned int)1<<(31-bitNumber%32)))!=0)
		return 1;
	return 0;
}
void setMatrix_i_j(int i,int j,int *arr,int n)
{
	int bitNumber=i*n+j;
	arr[bitNumber/32]|=((unsigned int)1<<(31-bitNumber%32));  // to set its 31-(bitNumber%32) th bit.
}
void resetMatrix_i_j(int i,int j,int *arr,int n)
{
	int bitNumber=i*n+j;
	arr[bitNumber/32]&=(~((unsigned int)1<<(31-bitNumber%32))); // to reset its 31-(bitNumber%32) th bit.
}
