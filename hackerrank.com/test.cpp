#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

double x1, x2, z1, y2, v1, v2,x,y;

double findx() {

	double m;
	m = (y2-z1)/(x2-x1);
	return (x1*m-z1)/m;

}

double findDist(double x, double y,double x1,double z1) {

	return sqrt((x-x1)*(x-x1)+(y-z1)*(y-z1));

}

double findtm(double x, double y) {

	double dist,tm=0.0;

	dist = findDist(x,y,x1,z1);

	tm = tm + dist/v1;

	dist = findDist(x,y,x2,y2);

	tm = tm + dist/v2;

	return tm;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%lf%lf%lf%lf%lf%lf",&x1, &z1, &x2, &y2, &v1, &v2);
		double tm = 0.0,tm1,tm2;
		double dist = 0;
		if(x1 == x2) {
			tm = tm + -z1/v1 + y2/v2;   		
			printf("%.5lf\n",tm);

			continue;
		}



		x = findx();
		y = 0;

		tm = findtm(x1,0);
		tm1 = findtm(x,y);
		tm2 = findtm(x2,0);
		cout<<"tm = "<<tm<<" tm1 = "<<tm1<<" tm2 = "<<tm2<<"\n"; 

		tm = min(min(tm,tm1),tm2);

		printf("%.5lf\n",tm);



	}
	return 0;
}

