#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	return gcd(b,a%b);
}
class line
{
	public:
	int a,b,c,slopex,slopey;
	line(int,int,int);
};
int p(int x)
{
	if(x>=0)
		return x;
	return -x;
}
line::line(int x,int y,int z)
{
	if(x<0)
	{
		x=-x;
		y=-y;
		z=-z;
	}
	else if(x==0)
	{
		if(y<0)
		{
			y=-y;
			z=-z;
		}
	}
	int gcdxy=gcd(p(x),p(y));
	int gc=gcd(gcdxy,p(z));
	
	this->slopex=x/gcdxy;
	this->slopey=y/gcdxy;
	x/=gc;
	y/=gc;
	z/=gc;
	this->a=x;
	this->b=y;
	this->c=z;
	//printf("(%d,%d,%d)\n",a,b,c);
	
}
vector<line>lines;

int maximum2(int x,int y)
{
	return x>y?x:y;
}
int maximum3(int x,int y,int z)
{
	return maximum2(maximum2(x,y),z);
}

bool cslopex(line x,line y)
{
	if(x.slopex>y.slopex)	
		return true;
	return false;
}

bool cslopey(line x,line y)
{
	if(x.slopey>y.slopey)	
		return true;
	return false;
}
int findAnswer()
{
	/*
	printf("this is the initial check = %d\n",lines.size());
	for(int i=0;i<lines.size();i++)
		printf("%d,%d,%d\n",lines[i].a,lines[i].b,lines[i].c);
	*/
	/*
	vector<double>slope(lines.size());
	for(int i=0;i<lines.size();i++)
		slope[i]=-lines[i].a/(double)lines[i].b;
	*/
	
	sort(lines.begin(),lines.end(),cslopex);
	for(int i=0;i<lines.size();)
	{
		int st,en;
		st=en=i;
		while(en<lines.size() && lines[st].slopex==lines[en].slopex)
		{
			i++;
			en++;
		}
		sort(lines.begin()+st,lines.begin()+en,cslopey);
		//i=en;
	}
	/*
	for(int i=0;i<lines.size();i++)
	{
		printf("(%d,%d) => %f \n",lines[i].slopex,lines[i].slopey,lines[i].slopex/(float)lines[i].slopey);
	}
	printf("\n");
	*/
	int start=0,end=0;
	int maxx=1;
	for(int i=1;i<lines.size();i++)
	{
		if(lines[start].slopex==lines[i].slopex && lines[start].slopey==lines[i].slopey)
			end=i;
		else
		{
			if(maxx<end-start+1)
				maxx=end-start+1;
			start=i;end=i;
		}
	}
	if(maxx<end-start+1)
		maxx=end-start+1;
	return maxx;
}

bool ca(line x,line y)
{
	if(x.a>y.a)	
		return true;
	return false;
}
bool cb(line x,line y)
{
	if(x.b>y.b)	
		return true;
	return false;
}
bool cc(line x,line y)
{
	if(x.c>y.c)	
		return true;
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		lines.erase(lines.begin(),lines.end());
		lines.reserve(n);
		
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			lines.push_back(line(x,y,z));
		}
		sort(lines.begin(),lines.end(),ca);
		
		for(int i=0;i<n;)
		{
			//printf("i = %d\n",i);
			int st,en;
			st=en=i;
			while(en<n && lines[st].a==lines[en].a)
			{
				i++;
				en++;
			}
			sort(lines.begin()+st,lines.begin()+en,cb);
			//i=en;
		}
		/*
		printf("this is a test beginning : \n");
		for(int i=0;i<lines.size();i++)
			printf("%d,%d,%d\n",lines[i].a,lines[i].b,lines[i].c);
		*/
		for(int i=0;i<n;)
		{
			int st,en;
			st=en=i;
			while(en<n && lines[st].a==lines[en].a && lines[st].b==lines[en].b)
			{
				i++;
				en++;
			}
			sort(lines.begin()+st,lines.begin()+en,cc);
			//i=en;
		}
		/*
		printf("********************\n");
		for(int i=0;i<lines.size();i++)
			printf("%d,%d,%d\n",lines[i].a,lines[i].b,lines[i].c);
		printf("********************\n");
		*/
		for(int i=0;i<lines.size();i++)
		{
			int st,en;
			st=i;en=i;
			bool flag=false;
			while(en<lines.size() && lines[st].a==lines[en].a && lines[st].b==lines[en].b && lines[st].c==lines[en].c)
			{
				flag=true;
				en++;
				//printf("hello lavish kothari\n");
			}
			if(flag)
			{
				en--;
			}
			if(en>st)
			{
				/*
				printf("st,en = %d,%d\n",st,en);
				for(int j=st;j<en;j++)
					printf("deleting this line %d %d %d\n",lines[j].a,lines[j].b,lines[j].c);
				*/
				lines.erase(lines.begin()+st,lines.begin()+en);
			}
		}
		int withx=0,withy=0;
		/*
		printf("this is a test to print all the lines : \n");
		for(int i=0;i<lines.size();i++)
			printf("%d,%d,%d\n",lines[i].a,lines[i].b,lines[i].c);
		*/
		for(int i=0;i<lines.size();i++)
		{
			if(lines[i].a==0)
			{
				int st,en;
				st=en=i;
				while(en<lines.size() && lines[en].a==0)
				{
					withx++;
					en++;
				}
				lines.erase(lines.begin()+st,lines.begin()+en);
				i--;
				continue;
			}
			if(lines[i].b==0)
			{
				withy++;
				lines.erase(lines.begin()+i);
				i--;
				continue;
			}
		}
		//printf("this is final check : %d %d %d\n",withx,withy,findAnswer());
		printf("%d\n",maximum3(findAnswer(),withx,withy));
	}
	
	return 0;
}
