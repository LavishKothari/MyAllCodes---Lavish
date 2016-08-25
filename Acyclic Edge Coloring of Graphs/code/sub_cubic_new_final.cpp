/*
	This program is the implementation of the following research paper :
	http://ac.els-cdn.com/S0012365X0701031X/1-s2.0-S0012365X0701031X-main.pdf?_tid=d3694c48-8c88-11e5-9253-00000aab0f01&acdnat=1447695679_6df106f720a587b0e7e4647ca036d9ec
	http://www.sciencedirect.com/science/article/pii/S0012365X0701031X
*/

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
	Edge(Edge const &);
	Edge(int,int);
};
Edge::Edge()
{
}
Edge::Edge(int start,int end)
{
	this->start=start;
	this->end=end;
	this->color=-1;
}

Edge::Edge(Edge const&e)
{
	this->start=e.start;
	this->end=e.end;
	this->color=-1;
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
	void arrangeEdges(); // very important thing. for description see the function definition.
	Vertex& findVertexWithDegreeAtMost2(bool*);
	void colorEdge(Edge&);
	Edge findEdge(int,int); // given vertexNumber number of two vertices, this function returns the edge between them.
	int findColor(int,int); // given two vertices of graph this function returns its color.
	set<int> findCandidateColors(Edge const&); // finds the candidate colors for a given edge.
	set<int> S(int,int); // for S(x,a) this method returns the set of colors {c : c=color(a,b) for every b belongs to N(a)-{x} } where N(a) is the neighbor set of vertex a.
	bool isCriticalPath(Edge const&e,int a,int b); // this method checks where there exists a (e,a,b) critical path whith colors a and b
	void recolor(Edge &e,int c); // recolors the edge e with color c. 
	void colorExchange(Edge &e1,Edge &e2); // exchanges the color of edge e1 and e2.
	bool isInConfigurationA(Vertex const&,Vertex const&,Vertex const&,set<int>const&,set<int>const&); // checks whether the five tuples are in configuration A or not.
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
	(this->edgeList).push_back(*e);
	
	vertexArray[start].adjacencyList.push_back(end);
	vertexArray[end].adjacencyList.push_back(start);
}
int Graph::findColor(int a,int b)
{
	for(list<Edge>::iterator i=edgeList.begin();i!=edgeList.end();i++)
	{
		Edge e;
		e=*i;
		if( ((e.start)==a && (e.end)==b) || ((e.start)==b && (e.end)==a) )
			return e.color;
	}
	return -1;
}
set<int> Graph::S(int a,int b)
{
	set<int>colors;
	for(list<int>::iterator i=vertexArray[b].adjacencyList.begin();i!=vertexArray[b].adjacencyList.end();i++)
	{
		if((*i)!=a)
		{
			colors.insert(findColor(b,*i));
		}
	}
	return colors;
}
set<int> Graph::findCandidateColors(Edge const &e)
{
	Vertex v,u;
	u=vertexArray[e.start];
	v=vertexArray[e.end];
	
	set<int>fu,fv;
	for(list<int>::iterator i=u.adjacencyList.begin();i!=u.adjacencyList.end();i++)
		fu.insert(findColor(u.vertexNumber,*i)); // insert the color of Fu into the set.
	for(list<int>::iterator i=v.adjacencyList.begin();i!=v.adjacencyList.end();i++)
		fv.insert(findColor(v.vertexNumber,*i)); // insert the color of Fv into the set.
	
	set<int>fuUNIONfv;
	set_union(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuUNIONfv,fuUNIONfv.begin()));
	
	set<int>candidateColors;
	set_difference(C.begin(),C.end(),fuUNIONfv.begin(),fuUNIONfv.end(),inserter(candidateColors,candidateColors.begin()));
	return candidateColors;
}
void printSet(set<int>const &a)
{
	printf("Printing the set : ");
	for(set<int>::iterator i=a.begin();i!=a.end();i++)
		printf("%d, ",*i);
	printf("\n");

}
void Graph::recolor(Edge &e,int c)
{
	e.color=c;
}
void Graph::colorExchange(Edge &e1,Edge &e2)
{
	int temp=e1.color;
	e1.color=e2.color;
	e2.color=temp;
}
Edge Graph::findEdge(int a,int b)
{
	for(list<Edge>::iterator i=edgeList.begin();i!=edgeList.end();i++)
	{
		Edge e=*i;
		if( (e.start==a && e.end==b) || (e.start==b && e.end==a) )
			return e;
	}
}

// this method checks where there exists a (e,a,b) critical path whith colors a and b 
// filling color b for edge e will lead to bichromatic cycle
bool Graph::isCriticalPath(Edge const&e,int a,int b) // this is a important method.
{
	int currentVertexNumber=e.start;
	int currentColor=a;
	while(currentVertexNumber!=e.end)
	{
		list<int>::iterator i;
		for(i=vertexArray[currentVertexNumber].adjacencyList.begin();i!=vertexArray[currentVertexNumber].adjacencyList.end();i++)
		{
			if(findColor(currentVertexNumber,*i)==currentColor)
				break;
		}
		if(i==vertexArray[currentVertexNumber].adjacencyList.end())
			return false;
		currentVertexNumber=*i;
		/* here you need to flip the current color */
		if(currentColor==a)
			currentColor=b;
		else 
			currentColor=a;
	}
	return true;
}

bool Graph::isInConfigurationA(Vertex const&u,Vertex const&a,Vertex const&b,set<int>const&NDash,set<int>const&NDoubleDash)
{
	set<int>Sua=S(u.vertexNumber,a.vertexNumber);
	set<int>Sub=S(u.vertexNumber,b.vertexNumber);
	Edge ua=findEdge(u.vertexNumber,a.vertexNumber);
	Edge ub=findEdge(u.vertexNumber,b.vertexNumber);
	if( (Sua.find(ub.color)!=Sua.end()) || (Sub.find(ua.color)!=Sub.end()) )
		return false;
	set<int>intersection1,intersection2;
	set_intersection(NDash.begin(),NDash.end(),Sua.begin(),Sua.end(),inserter(intersection1,intersection1.begin()));
	set_intersection(NDash.begin(),NDash.end(),Sub.begin(),Sub.end(),inserter(intersection2,intersection2.begin()));
	if(intersection1.size()>0 || intersection2.size()>0)
		return false;
	return true;
}
void Graph::colorEdge(Edge&e)
{
	Vertex v,u;
	u=vertexArray[e.start];
	v=vertexArray[e.end];
	
	set<int>fu,fv;
	for(list<int>::iterator i=u.adjacencyList.begin();i!=u.adjacencyList.end();i++)
	{
		int col=findColor(u.vertexNumber,*i);
		if(col!=-1)
			fu.insert(col); // insert the color of Fu into the set.
	}
	for(list<int>::iterator i=v.adjacencyList.begin();i!=v.adjacencyList.end();i++)
	{
		int col=findColor(v.vertexNumber,*i);
		if(col!=-1)
			fv.insert(col); // insert the color of Fv into the set.
	}

	/* here we will be finding the union of fu and fv and also the intersection of fu and fv */
	set<int>fuINTERSECTIONfv,fuUNIONfv;
	set_intersection(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuINTERSECTIONfv,fuINTERSECTIONfv.begin()));
	set_union(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuUNIONfv,fuUNIONfv.begin()));
	
	if(fuINTERSECTIONfv.size()==0) // no need to check for bichromatic cycles here. // case 1 of the research paper is covered here.
	{
		e.color=*(findCandidateColors(e).begin()); // for this case we will definitely get a color that is also valid for the edge 'e'.
	}
	else if(fuINTERSECTIONfv.size()==1) // we need to check for the Bichromatic cycles // case 2 of the research paper
	{
		set<int>candidateColors=findCandidateColors(e);
		if(fuUNIONfv.size()==1) // DONE
		{
			set<int>Sua=S(u.vertexNumber,*(u.adjacencyList.begin()));
			set<int>newSet; // this newSet will contain all the candidate colors which will also be valid for the the current Edge
			Sua.insert(findColor(u.vertexNumber,*(u.adjacencyList.begin())));
			set_difference(candidateColors.begin(),candidateColors.end(),Sua.begin(),Sua.end(),inserter(newSet,newSet.begin()));
			e.color=*(newSet.begin()); // for this case we will definitely get a color that is also valid for the edge 'e'.
		}
		else if(fuUNIONfv.size()==2)
		{
			/* currently working on this. */
			int count=0;
			set<int>::iterator i;
			for(i=candidateColors.begin();i!=candidateColors.end();i++)
			{
				if(isCriticalPath(e,*(fuINTERSECTIONfv.begin()),*i))
					count++;
				else break;
			}
			if(count==candidateColors.size()) // means all the candidate colors are invalid. some recoloring and exchange is essential.
			{
				Vertex x,y; // x is the vertex with degree 1 and y is the vertex with degree 2
				if(vertexArray[e.start].adjacencyList.size()==1)
				{
					x=vertexArray[e.start];
					y=vertexArray[e.end];
				}
				else
				{
					y=vertexArray[e.start];
					x=vertexArray[e.end];
				}
				set<int>newSet;
				set_difference(fuUNIONfv.begin(),fuUNIONfv.end(),fuINTERSECTIONfv.begin(),fuINTERSECTIONfv.end(),inserter(newSet,newSet.begin()));
				Edge e1=findEdge(x.vertexNumber,*(x.adjacencyList.begin()));
				recolor(e1,*(newSet.begin()));
				/* now if still the candidate colors are invalid then there still exists critical paths. */
				/* to remove these critical paths I need to exchange the coloring of ya and yb where a,b are neighbors of y. */
				
				/* we need to calculate the new color which will be in the intersection of Fx and Fy*/
				/* the set of candidate colors will not change here. */
				set_intersection(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuINTERSECTIONfv,fuINTERSECTIONfv.begin()));
				int commonColor=*(fuINTERSECTIONfv.begin());
				count=0;
				for(i=candidateColors.begin();i!=candidateColors.end();i++)
				{
					if(isCriticalPath(e,*(fuINTERSECTIONfv.begin()),*i))
						count++;
					else break;
				}
				if(count==candidateColors.size()) // here i need to apply some color exchange.
				{
					/* here I will exchange the colors of ya and yb where y is the vertex of degree 2 and a & b are its neighbors. */
					Vertex a,b;
					list<int>::iterator it=y.adjacencyList.begin();
					a=vertexArray[*it];
					it++;
					b=vertexArray[*it];
					Edge e1=findEdge(y.vertexNumber,a.vertexNumber);
					Edge e2=findEdge(y.vertexNumber,b.vertexNumber);
					colorExchange(e1,e2);
					
					/* now both the candidate colors will definitely be valid for the edge e. */
					e.color=*(candidateColors.begin());
				}
				else
				{
					e.color=*i;
				}
			}
			else // one of the candidate colors is not forming any critical cycle.
			{
				e.color=*i;
			}
		}
	}
}
Vertex& Graph::findVertexWithDegreeAtMost2(bool *isVertexCovered)
{
	for(int i=0;i<numberOfVertices;i++)
	{
		if(!isVertexCovered[i])
		{
			int deg=0;
			for(list<int>::iterator it=vertexArray[i].adjacencyList.begin();it!=vertexArray[i].adjacencyList.end();it++)
			{
				if(!isVertexCovered[*it])
					deg++;
			}
			if(deg<=2)
				return vertexArray[i];
		}
	}
}
void Graph::arrangeEdges()
{
	bool *isVertexCovered=new bool[numberOfVertices];
	for(int i=0;i<numberOfVertices;i++)
		isVertexCovered[i]=false; // initially no Vertex is covered.
	
	/* now I need to find a vertex which has degree less than equal to 2 */
	list<Edge>newEdgeList;
	
	for(int i=0;i<numberOfVertices;i++)
	{
		Vertex &x=findVertexWithDegreeAtMost2(isVertexCovered);
		isVertexCovered[x.vertexNumber]=true; // now the vertex x is covered.
		/* 
			now traverse the adjacencyList of x (only for the vertices that are uncovered.)
			find the edge that is formed between x and its adjacency
			let this edge be called e
			enumerate e.
		*/
		for(list<int>::iterator it=x.adjacencyList.begin();it!=x.adjacencyList.end();it++)
		{
			if(!isVertexCovered[*it])
			{
				Edge e=findEdge(x.vertexNumber,*it);
				newEdgeList.push_back(*(new Edge(e)));
			}
		}
	}
	edgeList.erase(edgeList.begin(),edgeList.end());
	for(list<Edge>::iterator it=newEdgeList.begin();it!=newEdgeList.end();it++)
	{
		edgeList.push_back(*it);
	}
	delete(isVertexCovered);
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
		printf("%d <--> %d\tColor=%d\n",(*i).start,(*i).end,(*i).color);
	printf("\n");
	/*
		Generating the output file
	*/
	FILE* fp;
	fp=fopen("result.txt","w");
	if(fp)
	{
		fprintf(fp,"%d %d\n",numberOfVertices,numberOfEdges);
		for(list<Edge>::iterator it=edgeList.begin();it!=edgeList.end();it++)
			fprintf(fp,"%d %d %d\n",(*it).start,(*it).end,(*it).color);
		fclose(fp);
	}
	else printf("There was some error in opening the file\n");
}
void Graph::deleteGraph()
{
	
}

int main()
{
	system("clear");
	printf("\nYou have the following options : \n");
	printf("1. Give the input in Adjacency Matrix form\n");
	printf("2. Give the input as each edge of the Graph\n");
	printf("3. Give the input from a file\n");
	printf("\nEnter your Choice : ");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		int n,e;
		printf("\nEnter the number of Vertices : ");
		scanf("%d",&n);
		printf("Enter the number of Edges : ");
		scanf("%d",&e);
		Graph graph(n,e);
		printf("Enter the Adjacency Matrix of the graph : \n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int temp;
				scanf("%d",&temp);
				if(i<j && temp==1)
					graph.addEdge(i,j);
			}			
			//graph.addEdge(s,d);
		}
	
		graph.arrangeEdges();
		// this is a test to print the edgelist 
		for(list<Edge>::iterator it=graph.edgeList.begin();it!=graph.edgeList.end();it++)
			graph.colorEdge(*it);
		graph.print();
		graph.deleteGraph();
	}
	else if(choice==2)
	{
		int n,e;
		
		printf("\nEnter the number of Vertices : ");
		scanf("%d",&n);
		printf("Enter the number of Edges : ");
		scanf("%d",&e);
		Graph graph(n,e);
		//printf("Graph initialization complete\n");
		printf("Enter the source and destination of %d number of edges : \n",e);
		for(int i=0;i<e;i++)
		{
			int s,d;
			scanf("%d%d",&s,&d);
			graph.addEdge(s,d);
		}
	
		graph.arrangeEdges();
		// this is a test to print the edgelist 
		for(list<Edge>::iterator it=graph.edgeList.begin();it!=graph.edgeList.end();it++)
			graph.colorEdge(*it);
		graph.print();
		graph.deleteGraph();
	}
	else if(choice==3)
	{
		FILE*fp;
		printf("\nEnter the file name for input : ");
		char fileName[100];
		scanf("%s",fileName);
		fp=fopen(fileName,"r");
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
		
			graph.arrangeEdges();
			// this is a test to print the edgelist 
			for(list<Edge>::iterator it=graph.edgeList.begin();it!=graph.edgeList.end();it++)
				graph.colorEdge(*it);
			graph.print();
			graph.deleteGraph();
			fclose(fp);
		}
		else printf("There was some error in opening the file.\n");
	}
	return 0;
}
