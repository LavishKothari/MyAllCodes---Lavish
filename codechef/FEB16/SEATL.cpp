#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
typedef map<int,int> mymap;
typedef vector< map<int,int> >myvector;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&n,&m);
		int**arr=new int*[n];
		for(int i=0;i<n;i++)
			arr[i]=new int[m];
		myvector row(n);
		myvector col(m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
				map<int,int>::iterator it=row[i].find(arr[i][j]);
				if(it==row[i].end())
					row[i][arr[i][j]]=1;
				else	
					row[i][arr[i][j]]++;
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<m;i++)
			{
				map<int,int>::iterator it=col[j].find(arr[i][j]);
				if(it==col[j].end())
					col[j][arr[i][j]]=1;
				else	
					col[j][arr[i][j]]++;
			}
		}
		int maxi=0;
		//printf("\n\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(map<int,int>::iterator iter=row[i].begin();iter!=row[i].end();iter++)
				{
					int add;
					add=iter->second;
					if(arr[i][j]==(iter->first))
					{
						//printf("hello%d   ",add);
						add--;
					}
					map<int,int>::iterator iter1=col[j].find(iter->first);
					if(iter1!=col[j].end())
					{
						//printf("%d    ",iter1->second);
						add+=iter1->second;
					}
					//printf("%d,%d = %d of %d\n",i,j,add,iter->first);
					if(add>maxi)
					{
						maxi=add;
						//printf("max = %d\n",maxi);
					}
				}
			}
			//printf("\n");	
		}
		printf("%d\n",maxi);
		
	}
	
	return 0;
}
