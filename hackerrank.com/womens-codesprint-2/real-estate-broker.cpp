#include <bits/stdc++.h>
using namespace std;
int M,N; // m is number of clients // n is number of houses

// clients = jobs - m in number
// houses = employees - n in number

class Element
{
public:
	int price,area;
};
bool recurse(vector< vector<int> >& matrix, int start, bool isVisited[], int assign_array[])
{
    for (int v = 0; v < N; v++)
    {
        if (matrix[start][v] && !isVisited[v])
        {
            isVisited[v] = true; // Mark v as visited
 			if (assign_array[v] < 0 || recurse(matrix, assign_array[v], isVisited, assign_array))
            {
                assign_array[v] = start;
                return true;
            }
        }
    }
    return false;
}
 
int findAnswer(vector< vector<int> >& matrix)
{
    int assign_array[N];
    memset(assign_array, -1, sizeof(assign_array));
 
    int answer = 0;
    for (int u = 0; u < M; u++)
    {
        bool isVisited[N];
        memset(isVisited, 0, sizeof(isVisited));
 	    if (recurse(matrix, u, isVisited, assign_array))
            answer++;
    }
    return answer;
}

int main()
{
	cin>>M>>N;
	vector< vector<int> >graph;
	if(N>=M)
	{
		vector<Element>client(M);
		vector<Element>house(N);
		for(int i=0;i<M;i++)
			cin>>client[i].area>>client[i].price;
		for(int j=0;j<N;j++)
			cin>>house[j].area>>house[j].price;

		graph=vector< vector<int> >(N,vector<int>(M,0));

		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(client[i].area<house[j].area && client[i].price>=house[j].price)
					graph[j][i]=1;
				else graph[j][i]=0;
			}
		}
	}
	else
	{
		swap(M,N);
		// now N represents clients
		// M represents house
		vector<Element>client(N);
		vector<Element>house(M);
		for(int i=0;i<N;i++)
			cin>>client[i].area>>client[i].price;
		for(int j=0;j<M;j++)
			cin>>house[j].area>>house[j].price;

		graph=vector< vector<int> >(N,vector<int>(M,0));

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(client[i].area<house[j].area && client[i].price>=house[j].price)
					graph[i][j]=1;
				else graph[i][j]=0;
			}
		}
	}
	/*
	for(int i=0;i<N;i++)
	{
		cout<<"i = "<<i<<" : ";
		for(int j=0;j<M;j++)
		{
			cout<<graph[i][j];
		}
		cout<<endl;
	}
	*/
	cout<<findAnswer(graph)<<endl;
	return 0;
}

/*
3
4
5 110
6 200
4 170
10 100
6 110 
7 150 
6 110
*/