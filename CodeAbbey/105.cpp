#include<stdio.h>
#include<stdlib.h>
double triArea(long long int x1,long long int y1,long long int x2,long long int y2,long long int x3,long long int y3)
{
	double area=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	return area;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *x=(int*)malloc(sizeof(int)*n);
	int *y=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);

	double area=0.0;
	for(int i=1;i<n-1;i++)
	{
		area+=triArea(x[0],y[0],x[i],y[i],x[i+1],y[i+1]);
	}
	printf("%.5lf\n",area);
	return 0;
}
