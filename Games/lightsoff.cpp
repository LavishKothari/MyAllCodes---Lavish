#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll createNumber(string & s) // converts a string of '0' and '1' into long long int 
{
	ll answer=0;
	for(int i=0;i<s.size();i++)
		answer=answer*2+s[i]-'0';
	return answer;
}
int getLinear(int N,int x,int y) // convert 2-D coordinates for N*N matrix into linear representation
{
	return N*x+y;
}
void flipChar(string &s,int index) // flip the character at index 
{
	if(index>=0 && index<s.size())
	{
		if(s[index]=='0')
			s[index]='1';
		else if(s[index]=='1')
			s[index]='0';
	}
}
string flip(int N,string s,int row,int col) // cursor clicked at coordinate x,y.
{
	int a,b,c,d,e;
	if(col-1>=0)
		flipChar(s,getLinear(N,row,col-1));
	if(col+1<N)
		flipChar(s,getLinear(N,row,col+1));
	if(row+1<N)
		flipChar(s,getLinear(N,row+1,col));
	if(row-1>=0)
		flipChar(s,getLinear(N,row-1,col));
	flipChar(s,getLinear(N,row,col));
	return s;
}
vector<string>findAdjacent(int N, string &s) 
{
	vector<string>result;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			result.push_back(flip(N,s,i,j));
			//cout<<flip(N,s,i,j)<<endl;
		}
	return result;
}
pair<int,int>getMove(int N,string current,string parent)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(flip(N,current,i,j)==parent)
				return make_pair(i,j);
		}
}
vector< pair<int,int> >findSequenceBFS(int N,string &s)
{
	set<ll>visited;
	vector<string>Q;
	Q.push_back(s);
	visited.insert(createNumber(s));

	map<string,string>parent;
	bool solFound=false;
	while(!Q.empty())
	{
		string current=Q[0];
		Q.erase(Q.begin());
		vector<string>adjacent=findAdjacent(N,current);
		for(int i=0;i<adjacent.size();i++)
		{
			//cout<<adjacent[i]<<endl; 
			if(visited.find(createNumber(adjacent[i]))==visited.end())
			{
				visited.insert(createNumber(adjacent[i]));
				Q.push_back(adjacent[i]);
				parent[adjacent[i]]=current;
				if(createNumber(adjacent[i])==0)
				{
					solFound=true;
					break;
				}
			}
			if(solFound)
				break;

		}
		if(Q.size()%1000==0)
			cout<<current<<" "<<Q.size()<<endl;
	}
	if(solFound==true)
	{
		cout<<"you got a solution\n";
		vector< pair<int,int> >result;
		string current(N*N,'0');
		while(current!=s)
		{
			string p=parent[current];
			pair<int,int>xy=getMove(N,current,p);
			result.push_back(xy);
			current=p;
		}
		reverse(result.begin(),result.end());
		return result;
	}
	else 
		return vector< pair<int,int> >(0);
}

/*********************heuristics***************************/
/***************not working properly***************************/

double heuristic(int N,string s,int x,int y)
{
	string f=flip(N,s,x,y);
	int onTOoff=0,offTOon=0;
	for(int i=0;i<N*N;i++)
	{
		if(s[i]=='1' && f[i]=='0')
			onTOoff++;
		else if(s[i]=='0' && f[i]=='1')
			offTOon++;
	}
	if(offTOon!=0)
		return (double)onTOoff/offTOon;
	return 6.0;
}

vector< pair<int,int> >findSequenceUsingHeuristics(int N,string &s)
{
	vector< pair<int,int> >result;
	string goal(N*N,'0');
	while(s!=goal)
	{
		double max_h=0.0;
		int movex,movey;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				double h=heuristic(N,s,i,j);
				if(h>max_h)
				{
					movex=i;
					movey=j;
					max_h=h;
				}
			}
		}
		result.push_back(make_pair(movex,movey));
		s=flip(N,s,movex,movey);
	}
	return result;
}

/*********************brute force***************************/

vector< pair<int,int> >findSequenceBruteForce(int N,string &s)
{
	string goal(N*N,'0');
	for(int move_no=1;move_no<=25;move_no++)
	{
		cout<<"searching for move_no : "<<move_no<<endl;
		vector<int>move;
		for(int i=0;i<N*N-move_no;i++)
			move.push_back(0);
		for(int i=0;i<move_no;i++)
			move.push_back(1);
		// initial move ready.

		do
		{
			string currentState=s;
			vector< pair<int,int> >result;
			for(int i=0;i<N*N;i++)
			{
				if(move[i]==1)
				{
					int x,y;
					x=i/N;
					y=i%N;
					result.push_back(make_pair(x,y));
					currentState=flip(N,currentState,x,y);
				}
			}
			if(currentState==goal)
			{
				return result;
			}
		}while(next_permutation(move.begin(),move.end()));
	}
	cout<<"you are here\n";
	vector< pair<int,int> >result(0);
	return result;
}
/*********************brute force over**********************************/
int main()
{

	int N;
	cout<<"Enter N : ";
	cin>>N;
	cout<<"Enter the current state : ";
	string s;
	cin>>s;
	/*
	   vector< pair<int,int> >result=findSequenceBFS(N,s);
	   for(int i=0;i<result.size();i++)
	   cout<<result[i].first<<","<<result[i].second<<endl;
	 */

	vector< pair<int,int> >result=findSequenceBruteForce(N,s);
	for(int i=0;i<result.size();i++)
		cout<<result[i].first<<","<<result[i].second<<endl;
	return 0;
}
