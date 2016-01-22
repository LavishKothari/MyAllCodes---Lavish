#include<stdio.h>
#include<utility>
#include<cmath>
#include<vector>
using namespace std;
#define N 1000
double area(pair<int,int>a,pair<int,int>b,pair<int,int>c)
{
	return abs(0.5*(a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second)));
}
bool isFavourable(vector<pair<int,int> >points)
{
	double a1=area(points[0],points[1],make_pair(0,0));
	double a2=area(points[1],points[2],make_pair(0,0));
	double a3=area(points[0],points[2],make_pair(0,0));
	double a4=area(points[0],points[1],points[2]);
	if(a1+a2+a3>a4)
		return false;
	return true;
}
int main()
{
	int answer=0;
	FILE *fp=fopen("triangles.txt","r");
	if(!fp)
	{
		printf("there was some error in opening the file\n");
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		vector< pair<int,int> >points;
		int a,b,c,d,e,f;char ch;
		fscanf(fp,"%d %c %d %c %d %c %d %c %d %c %d",&a,&ch,&b,&ch,&c,&ch,&d,&ch,&e,&ch,&f);
		points.push_back(make_pair(a,b));
		points.push_back(make_pair(c,d));
		points.push_back(make_pair(e,f));
		if(isFavourable(points))
			answer++;
	}
	fclose(fp);
	printf("The answer is : %d\n",answer);
	return 0;
}
