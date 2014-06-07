#include<stdio.h>
#include<math.h>
#include<conio.h>
int counter_variable=0;
long double roundoff(long double);
long double reduceit(long double num,long double counter, long double z,long double i);
long double power(long double,long double);
long double cal(long double num,long double p)
{
	long double i=0,j,answer,counter=4,z=1,ans;

	for(j=0;j<20;j++)
	{
		i=reduceit(num,counter,z,i);
		z/=10;
	}

	p=(p*power(10,counter));
	p=roundoff(p);
	answer=power(i,p);
	return answer;
}


long double reduceit(long double num,long double counter, long double z,long double i)
{
	while(1)
	{
		if((power(i,power(10,counter))) > num)
		{
			i=i-z;
			break;
		}
		i=i+z;
	}
	counter_variable++;
	//printf("%d  %Lf\n",counter_variable,i);
	return i;
}

long double roundoff(long double num)
{
	long double limit;
	limit=(int)num+0.5;
	if(num>limit)
		return ((int)num + 1 );
	else
		return ((int)num);
}

long double power(long double num,long double i)
{

	long double j;
	long double product=1;

	for(j=0;j<i;j++)
	{
		product*=num;
	}
	return product;
}


int main()
{
	long double num,p,a,b,pi,pf,answer;
	clrscr();
	printf("ENTER ANY NUMBER : ");
	scanf("%Lf",&num);

	printf("ENTER THE POWER : ");
	scanf("%Lf",&p);
	pi=(int)p;
	pf=p-pi;

	a=cal(num,pf);
	b=power(num,pi);

	answer=a*b;

	printf("\n\nmy answer = %Lf\n"
			   "co answer = %f",answer,pow((double)num,(double)p));

	getch();
	return 1;
}