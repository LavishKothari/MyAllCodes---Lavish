#include"one_D_bit_array.h"
int get_one_D_bit_array(int i,unsigned int* arr)
{
	if((arr[i/32]&((unsigned int)1<<(31-i%32)))!=0)
		return 1;
	return 0;
}
void set_one_D_bit_array(int i,unsigned int *arr)
{
	arr[i/32]|=((unsigned int)1<<(31-i%32));  // to set its 31-(n%32) th bit.
}
void reset_one_D_bit_array(int i,unsigned int *arr)
{
	arr[i/32]&=(~((unsigned int)1<<(31-i%32))); // to reset its 31-(n%32) th bit.
}
