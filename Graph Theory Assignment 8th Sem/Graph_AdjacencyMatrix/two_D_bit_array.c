#include"two_D_bit_array.h"

/* 	
		this function will return bit value in 
		ith row and 
		jth column
		from the array 'arr'
		which provides an abstraction of 2-D bit array of size n * n.
*/ 
int get_two_D_bit_array(int i,int j,int* arr,int n)
{
	int bitNumber=i*n+j;
	if((arr[bitNumber/32]&((unsigned int)1<<(31-bitNumber%32)))!=0)
		return 1;
	return 0;
}

/* 	
		this function will set the bit value in 
		ith row and 
		jth column
		in the array 'arr'
		which provides an abstraction of 2-D bit array of size n * n
		to 1.
*/ 
void set_two_D_bit_array(int i,int j,int *arr,int n)
{	
	int bitNumber=i*n+j;
	arr[bitNumber/32]|=((unsigned int)1<<(31-bitNumber%32));  // to set its 31-(bitNumber%32) th bit.
}

/* 	
		this function will set the bit value in 
		ith row and 
		jth column
		in the array 'arr'
		which provides an abstraction of 2-D bit array of size n * n
		to 0.
*/ 
void reset_two_D_bit_array(int i,int j,int *arr,int n)
{
	int bitNumber=i*n+j;
	arr[bitNumber/32]&=(~((unsigned int)1<<(31-bitNumber%32))); // to reset its 31-(bitNumber%32) th bit.
}
