#include<stdio.h>
#include<set>
#include<algorithm>
#include<list>

using namespace std;
#define MAX_COLORS 4 // This specifies the maximum number of colors that we will be using to color the graph.
#define MAX_DEGREE 3 // This specifies the maximum degree of the graph.
#define IS_REGULAR 0 // 0 specifies that the graph is not regular and 1 specifies that the graph is regular.

class Vertex
{
	public:
	int vertexNumber;
	list<int>adjacencyList;
};

class Edge
{
	public:
	int start,end,color;
	Edge();
	Edge(int,int);
};
Edge::Edge()
{
}
Edge::Edge(int start,int end)
{
	this->start=start;
	this->end=end;
}
class Graph
{
	public:
	int numberOfVertices,numberOfEdges;
	Vertex* vertexArray;
	list<Edge> edgeList;
	set<int>C;
	
	Graph(int,int);
	void addEdge(int,int);
	void print();
	void deleteGraph();
	void colorEdge(Edge&);
	int findColor(int,int); // given two vertices of graph this function returns its color.
	set<int> findCandidateColors(set<int>const &);
	void assignColors();
};

Graph::Graph(int numberOfVertices,int numberOfEdges)
{
	this->numberOfVertices=numberOfVertices;
	this->numberOfEdges=numberOfEdges;
	vertexArray=new Vertex[numberOfVertices];
	for(int i=0;i<numberOfVertices;i++)
		vertexArray[i].vertexNumber=i;
	for(int i=1;i<=MAX_COLORS;i++)
		C.insert(i);
}
void Graph::addEdge(int start,int end)
{
	Edge*e=new Edge(start,end);
	colorEdge(*e);
	(this->edgeList).push_back(*e);
	//(this->edgeList).push_back(*(new Edge(end,start)));
	
	vertexArray[start].adjacencyList.push_back(end);
	vertexArray[end].adjacencyList.push_back(start);
	printf("################ Successfully pushed %d edges #####################\n",edgeList.size());
}
int Graph::findColor(int a,int b)
{
	printf("Now i am in findcolor with a=%d and b=%d\n",a,b);
	for(list<Edge>::iterator i=edgeList.begin();i!=edgeList.end();i++)
	{
		Edge e;
		e=*i;
		if( ((e.start)==a && (e.end)==b) || ((e.start)==b && (e.end)==a) )
			return e.color;
	}
	return -1;
}
set<int> Graph::findCandidateColors(set<int>const &f)
{
	set<int>candidateColors;
	set_difference(C.begin(),C.end(),f.begin(),f.end(),inserter(candidateColors,candidateColors.begin()));
	return candidateColors;
}
void printSet(set<int>const &a)
{
	printf("Printing the set : ");
	for(set<int>::iterator i=a.begin();i!=a.end();i++)
		printf("%d, ",*i);
	printf("\n");
}
void Graph::colorEdge(Edge&e)
{
	e.color=-1;
	return;
	Vertex v,u;
	printf("***********Doing work for edge : %d %d***********\n",e.start,e.end);
	u=vertexArray[e.start];
	v=vertexArray[e.end];
	printf("***********Doing work for edge : %d %d***********\n",u.vertexNumber,v.vertexNumber);
	
	set<int>fu,fv;
	for(list<int>::iterator i=u.adjacencyList.begin();i!=u.adjacencyList.end();i++)
	{
		printf("hello lavish kothari for the vertex number = %d\n",u.vertexNumber);
		fu.insert(findColor(u.vertexNumber,*i)); // insert the color of Fu into the set.
	}
	for(list<int>::iterator i=v.adjacencyList.begin();i!=v.adjacencyList.end();i++)
	{
		printf("hello rakshit kothari for the vertex number = %d\n",v.vertexNumber);
		fv.insert(findColor(v.vertexNumber,*i)); // insert the color of Fv into the set.
	}
	printSet(fu);
	printSet(fv);
	
	set<int>fuINTERSECTIONfv,fuUNIONfv;
	set_intersection(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuINTERSECTIONfv,fuINTERSECTIONfv.begin()));
	set_union(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuUNIONfv,fuUNIONfv.begin()));
	/* here we will be finding the union of fu and fv and also the intersection of fu and fv */
	if(fuINTERSECTIONfv.size()==0 && fuUNIONfv.size()<4) // no need to check for bichromatic cycles here. // case 1 of the research paper is covered here.
	{
		printf("This case is already handled here %d %d\n",e.start,e.end);
		printf("So filling this color here : %d\n",*(findCandidateColors(fuUNIONfv).begin()));
		e.color=*(findCandidateColors(fuUNIONfv).begin());
	}
	if(fuINTERSECTIONfv.size()==0 && fuUNIONfv.size()==4) // no need to check for bichromatic cycles here.
	{
		/* this means that you will not get any candidate color for the edge (u,v) */
		/* in this case you need to recolor one of the edges. */
		e.color=*(findCandidateColors(fuUNIONfv).begin());
	}
	else if(fuINTERSECTIONfv.size()==1)
	{
		printf("________________________$$ Some this you need to here $$________________________\n");
		set<int>candidateColors=findCandidateColors(fuUNIONfv);
		
	}
	else if(fuINTERSECTIONfv.size()==2)
	{
		printf("________________________$$ Some this you need to here $$________________________\n");
	}
	
}
void Graph::print()
{
	printf("\nThe graph is as follows : \n");
	printf("\nThe number of Vertices in the Graph = %d\n",numberOfVertices);
	printf("The number of Edges in the Graph = %d\n",numberOfEdges);
	printf("\nThe adjacency List of the Graph is as follows : \n");
	for(int i=0;i<numberOfVertices;i++)
	{
		printf("%d : ",i);
		for(list<int>::iterator j=vertexArray[i].adjacencyList.begin();j!=vertexArray[i].adjacencyList.end();j++)
			printf("%d, ",(*j));
		printf("\n");
	}
	printf("\nThe edge List of the Graph is as follows : \n");
	for(list<Edge>::iterator i=edgeList.begin();i!=edgeList.end();i++)
		printf("%d --- %d Color = %d\n",(*i).start,(*i).end,(*i).color);
	printf("\n");
}
void Graph::assignColors() // dropping this Idea---I'll implement it as my backup plan.
{
	/*
		I am planning to remove all the edges that make degree 3 for a vertex 
		meanwhile I will keep the track of all the deleted Edges
		
	*/
}
void Graph::deleteGraph()
{
	
}

int main()
{
	FILE*fp;
	fp=fopen("test.txt","r");
	if(fp)
	{
		int n,e;
		fscanf(fp,"%d%d",&n,&e);
		Graph graph(n,e);
		//printf("Graph initialization complete\n");
		for(int i=0;i<e;i++)
		{
			int s,d;
			fscanf(fp,"%d%d",&s,&d);
			graph.addEdge(s,d);
		}
		graph.assignColors();
		graph.print();
		graph.deleteGraph();
	}
	else printf("There was some error in opening the file.\n");
	return 0;
}

// every thing is fine :)
// really?
