#include<stdio.h>

int main()

{

int array[]={1,8,5,7,10,9,2};

int firstmax=array[0];

int secondmax=array[1];

int temp,i;

if(firstmax<secondmax)

{

temp=secondmax;

secondmax=firstmax;

firstmax=temp;

}



for(int i=0;i<7;i++)

{

if(firstmax<array)

{

secondmax=firstmax;

firstmax=array;

}

if((firstmax>array)&&(array>secondmax))

{

secondmax=array;

}

}

printf("second max:%dn",secondmax);

return 0;

}
