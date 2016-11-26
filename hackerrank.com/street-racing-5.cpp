/*
///////////////////
4 3 90
1 1
0 1
1 1
1 0
0 0
1 2
2 3
1 3

////////////////////

6 5 90
1 6

0 0
4 0
0 -1
4 -1
0 -2
4 -2

1 2
2 3
3 4
4 5
5 6

/////////////////////

4 3 90
1 4
0 1
1 1
1 0
0 0
1 2
2 3
3 4

/////////////////////

11 15 90
1 7

1 1
4 1
4 -1
2 -2
0 -2
0 -1
0 0
1 0
2 0
1 -1
2 -1

1 2
2 3
3 11
11 4
5 4
5 6
6 7
7 10
10 8
8 9
1 9
8 11
5 11
9 11
6 10

///////////////////////////

11 1 90
1 7

1 1
4 1
4 -1
2 -2
0 -2
0 -1
0 0
1 0
2 0
1 -1
2 -1

2 5

//////////////////////////

6 5 90
1 5

0 0
4 0
6 0
6 -2
4 -2
0 -2

1 2
2 3
3 4
4 5
5 6


*/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
class point
{
	public:
		int x,y;
	point(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	point(){}
};
double dist2(int a,int b,vector<point>&v)
{
	return sqrt((v[a].x-v[b].x)*(v[a].x-v[b].x) + (v[a].y-v[b].y)*(v[a].y-v[b].y));
}
double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double findAngle(point a,point b,point c)
{
	double x1,x2,x3,y1,y2,y3;
	x1=a.x;
	x2=b.x;
	x3=c.x;
	y1=a.y;
	y2=b.y;
	y3=c.y;
	
	double ctheta=((x2-x1)*(x3-x2)+(y2-y1)*(y3-y2))/(dist(x1,y1,x2,y2)*dist(x3,y3,x2,y2));
	//cout<<ctheta<<endl;
	
	double angle=acos(ctheta)*180.0/M_PI;	
	//cout<<angle<<endl;
	if(angle>180.0)
		return angle-180.0;
	else return angle;
}
vector<double> dij(double **graph,int n,int start,int finish, int angle,vector<point>&v)
{
	//cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
	vector<bool>iscompleted(n,false);
	vector<double>sd(n,INT_MAX);
	vector<int>parent(n,-1);

	iscompleted[start]=true;
	sd[start]=0.0;
	parent[start]=-1;

	int current=start;
	int index;
	while(current!=finish)
	{
		//cout<<"current = "<<current+1<<" "<<sd[current]<<endl;
		//cout<<"these are sd ";
		/*
		for(int i=0;i<n;i++)
			cout<<sd[i]<<" ";
		cout<<endl;
		*/
		for(int i=0;i<n;i++)
		{
			if(i!=current && iscompleted[i]==false && graph[i][current]<INT_MAX && graph[i][current]>0 && (sd[i]==INT_MAX ||  sd[current]+graph[i][current]<sd[i]))
			{
				sd[i]=sd[current]+graph[i][current];
				parent[i]=current;
				//cout<<"updating parent of "<<i+1<<" as "<<current+1<<endl;
			}
		}
		iscompleted[current]=true;
		
		// now finding minimum amongst those which are not completed
		index=-1;
		double mi=INT_MAX;

		for(int i=0;i<n;i++)
		{
			if(iscompleted[i]==false && sd[i]<mi)
			{
				mi=sd[i];
				index=i;
			}
		}
		//cout<<"**********************\n";
		//cout<<"index = "<<index+1<<endl;
		if(index==-1) // no vertex is now reachable
			break;
		current=index;		
	}
	// normal dijkstra finished here

	//cout<<"you are here "<<endl;
	if(current==finish)
	{
		// found a path from start to finish
		vector<int>path;
		path.push_back(finish);
		for(current=finish;current!=start;current=parent[current])
			path.push_back(parent[current]);
		//path.push_back(start);

		reverse(path.begin(),path.end());

		/*
		cout<<"this is the shortest path ";
		for(int i=0;i<path.size();i++)
			cout<<path[i]+1<<" ";
		cout<<endl;
		
		cout<<"this is the parent array ";
		for(int i=0;i<n;i++)
			cout<<parent[i]+1<<" ";
		cout<<endl;
		*/
		//path found;

		for(int i=0;i+2<path.size();i++)
		{
			double a=findAngle(v[path[i]],v[path[i+1]],v[path[i+2]]);
			//cout<<"the angle is "<<a<<endl;
			if(a>angle)
			{
				vector<double>vec(4);
				vec[0]=-1; // means i found a ganda angle
				vec[1]=path[i];
				vec[2]=path[i+1];
				vec[3]=path[i+2];
				//cout<<"the angle is more so inserting "<<path[i]+1<<" "<<path[i+1]+1<<" "<<path[i+2]+1<<endl;
				//cout<<"returning from here\n"; 
				return vec;
			}
		}
		/*
		for(int i=0;i<n;i++)	
			cout<<"this is sd = "<<i+1<<" "<<sd[i]<<endl;
		*/
		vector<double>vec(1,sd[finish]);
		return vec;
	}
	else 
	{
		vector<double>vec(1,-2); //this represents that finish is not reachable
		return vec;
	}
}
void addEdge(double **graph,int n,int a,int b,vector<point>&v)
{
	graph[a][b]=dist2(a,b,v);
	graph[b][a] = graph[a][b];
}
void removeEdge(double**graph,int n,int a,int b)
{
	graph[a][b]=INT_MAX;
	graph[b][a] = INT_MAX;
}
bool isreachable(double**graph,int n,int s,int f)
{
	vector<int>Q;
	vector<bool> isvisited(n,false);
	
	Q.push_back(s);
	isvisited[s]=true;

	while(!Q.empty())
	{
		int current=Q[0];
		Q.erase(Q.begin());

		for(int i=0;i<n;i++)
		{
			if(graph[current][i]!=INT_MAX && isvisited[i]==false)
			{
				Q.push_back(i);
				isvisited[i]=true;
				if(i==f)
					return true;
			}
		}
	}
	return false;

}
double findAnswer(double **graph,int n,int s,int f,vector<point>&v,int angle)
{
	//cout<<"dij called\n";
	if(s==f)
		return 0.0;
	vector<double>vec=dij(graph,n,s,f,angle,v);
	if(vec.size()==1 && vec[0]==-2) // node not reachable
		return -1;
	////////
	/*
	cout<<"dij returned ";
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]+1<<" ";
	cout<<endl;
	*/
	//////////
	if(vec.size()==1)
		return vec[0];
	//cout<<"hello\n";
	
	double x=-1,y=-1;
	
	removeEdge(graph,n,vec[1],vec[2]);
	if(isreachable(graph,n,s,f))
	{
		//cout<<"1 removing "<<vec[1]+1<<" "<<vec[2]+1<<endl;
		x=findAnswer(graph,n,s,f,v,angle);
	}
	addEdge(graph,n,vec[1],vec[2],v);
	
	//////////////////////////////////
	removeEdge(graph,n,vec[3],vec[2]);
	if(isreachable(graph,n,s,f))
	{
		//cout<<"2 removing "<<vec[3]<<" "<<vec[2]<<endl;
		y=findAnswer(graph,n,s,f,v,angle);
	}
	addEdge(graph,n,vec[3],vec[2],v);
	
	if(x<0 && y<0)
		return -1;
	if(x<0)
		return y;
	if(y<0)
		return x;
	return min(x,y);
}

bool isCritical(point a,point b,point c,double angle)
{
	double an=findAngle(a,b,c);
	if(an>angle)
		return true;
	return false;
	///return !(findAngle(a,b,c)>angle);

}
double findAnswer1(double **graph,int n,int start,int parent_start,double currentDist,int finish,vector<point>&v,int angle,vector<bool> isvisited)
{
	if(start==finish)
		return 0;
	double mi=DBL_MAX;
	isvisited[start]=true;
	for(int i=0;i<n;i++)
	{
		if(isvisited[i]==false && i!=parent_start && i!=start && graph[i][start]!=INT_MAX && (parent_start==-1 || !isCritical(v[parent_start],v[start],v[i],angle)))
		{
			isvisited[i]=true;
			mi=min(mi,/*currentDist+*/graph[start][i]+findAnswer1(graph,n,i,start,currentDist+graph[i][start],finish,v,angle,isvisited));
		}
	}
	return mi;
}
int main()
{
	int n,m,angle,s,f;
	scanf("%d%d%d%d%d",&n,&m,&angle,&s,&f);
	
	
	vector<point>v(n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[i]=point(x,y);
	}
	double **graph;
	
	graph=new double *[n];
	for(int i=0;i<n;i++)
		graph[i]=new double [n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			graph[i][j]=INT_MAX;
			if(i==j)
				graph[i][j] = 0;
		}
			
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a-1][b-1]=dist2(a-1,b-1,v);
		graph[b-1][a-1] = graph[a-1][b-1];
	}
	vector<bool>isvisited(n,false);
	double answer=findAnswer1(graph,n,s-1,-1,0,f-1,v,angle,isvisited);
	//double answer=findAnswer1(graph,n,s-1,f-1,v,angle);
	if(answer<DBL_MAX)
		printf("%0.3lf\n",answer);
	else 
		cout<<"-1.000\n";
	return 0;
}
/*
6 7 90
1 6

0 0
4 0
6 0
6 -2
4 -2
0 -2

1 2
2 3
3 4
1 6
4 5
5 6
2 5

*/