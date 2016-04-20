#include<stdio.h>
#include<math.h>
struct Point
{
	int x,y,z;
};
double magnitude(int x,int y,int z)
{
	return sqrt(x*x+y*y+z*z);
}
double find(struct Point p1,struct Point p2,struct Point p3)
{
	return acos(( (p2.x-p1.x)*(p2.x-p3.x) + (p2.y-p1.y)*(p2.y-p3.y) + (p2.z-p1.z)*(p2.z-p3.z) ) / (magnitude(p2.x-p1.x,p2.y-p1.y,p2.z-p1.z) * magnitude(p2.x-p3.x,p2.y-p3.y,p2.z-p3.z)));
}
int main()
{
	int n,i,j,k;
	double sum;
	struct Point parray[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&parray[i].x,&parray[i].y,&parray[i].z);
	sum=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for(k=j+1;k<n;k++)
				sum+=find(parray[i],parray[j],parray[k]);
	sum=6*sum/(n*(n-1)*(n-2));
	printf("%0.12lf\n",sum);
	return 0;
}
