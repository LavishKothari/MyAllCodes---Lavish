#include<stdio.h>

int main()
{
	int t,w;
	float bmi,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%f",&w,&h);
		bmi=w/(h*h);
		if(bmi<18.5) printf("under ");
		else if(bmi>=18.5 && bmi<25.0) printf("normal ");
		else if(bmi>=25.0 && bmi<30.0) printf("over ");
		else if(bmi>=30.0) printf("obese ");
	}
	return 0;
}

