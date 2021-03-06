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
	int start,end,color,edgeNumber;
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
	//void arrangeEdges(); // very important thing. for description see the function definition.
	void colorEdge(Edge&);
	Edge findEdge(int,int); // given vertexNumber number of two vertices, this function returns the edge between them.
	int findColor(int,int); // given two vertices of graph this function returns its color.
	set<int> findCandidateColors(Edge const&); // finds the candidate colors for a given edge.
	set<int> S(int,int); // for S(x,a) this method returns the set of colors {c : c=color(a,b) for every b belongs to N(a)-{x} } where N(a) is the neighbor set of vertex a.
	bool isCriticalPath(Edge const&e,int a,int b); // this method checks where there exists a (e,a,b) critical path whith colors a and b
	void recolor(Edge &e,int c); // recolors the edge e with color c. 
	void colorExchange(Edge &e1,Edge &e2); // exchanges the color of edge e1 and e2.
	bool isInConfigurationA(Vertex const&,Vertex const&,Vertex const&,set<int>const&,set<int>const&); // checks whether the five tuples are in configuration A or not.
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
		if( (e.start==a && e.end==b) || e.start==b && e.end==a )
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
	printf("\n***********Doing work for edge : %d %d***********\n",e.start,e.end);
	u=vertexArray[e.start];
	v=vertexArray[e.end];
	
	set<int>fu,fv;
	for(list<int>::iterator i=u.adjacencyList.begin();i!=u.adjacencyList.end();i++)
	{
		fu.insert(findColor(u.vertexNumber,*i)); // insert the color of Fu into the set.
	}
	for(list<int>::iterator i=v.adjacencyList.begin();i!=v.adjacencyList.end();i++)
	{
		fv.insert(findColor(v.vertexNumber,*i)); // insert the color of Fv into the set.
	}
	
	printSet(fu);
	printSet(fv);
	
	set<int>fuINTERSECTIONfv,fuUNIONfv;
	set_intersection(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuINTERSECTIONfv,fuINTERSECTIONfv.begin()));
	set_union(fu.begin(),fu.end(),fv.begin(),fv.end(),inserter(fuUNIONfv,fuUNIONfv.begin()));
	
	/* here we will be finding the union of fu and fv and also the intersection of fu and fv */
	if(fuINTERSECTIONfv.size()==0) // no need to check for bichromatic cycles here. // case 1 of the research paper is covered here.
	{
		if(fuUNIONfv.size()<4) // DONE
		{
			printf("This case is already handled here %d %d\n",e.start,e.end);
			printf("So filling this color here : %d\n",*(findCandidateColors(e).begin()));
			e.color=*(findCandidateColors(e).begin()); // for this case we will definitely get a color that is also valid for the edge 'e'.
		}
		else if(fuUNIONfv.size()==4) // this case is still remaining.
		{
			/* this means that you will not get any candidate color for the edge (u,v) */
			/* in this case you need to recolor one of the edges. */
			printf("________________________$$ Some this you need to here $$________________________1\n");
		}
	}
	else if(fuINTERSECTIONfv.size()==1) 
	{
		set<int>candidateColors=findCandidateColors(e);
		if(fuUNIONfv.size()==1) // DONE
		{
			set<int>Sua=S(u.vertexNumber,*(u.adjacencyList.begin()));
			set<int>newSet;
			Sua.insert(findColor(u.vertexNumber,*(u.adjacencyList.begin())));
			set_difference(candidateColors.begin(),candidateColors.end(),Sua.begin(),Sua.end(),inserter(newSet,newSet.begin()));
			e.color=*(newSet.begin()); // for this case we will definitely get a color that is also valid for the edge 'e'.
			printf("this is for the edge (%d,%d) -> filling the color %d here\n",e.start,e.end,*(newSet.begin()));
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
		else if(fuUNIONfv.size()==3)// this case is still remaining.
		{
			/* In this case we will have only one candidate color. */
			int cc=*(candidateColors.begin()); // cc denotes the only candidate color.
			
			if(isCriticalPath(e,*(fuINTERSECTIONfv.begin()),cc)) // if critical path exists then we need ot do something.
			{
				printf("________________________$$ Some this you need to here $$________________________2\n");
			
				// finding out the configurationA
				set<int>NDash,NDoubleDash; // these are the two partitions of neighbor set of u - {a,b}
			
				Vertex a,b;
				list<int>::iterator it=u.adjacencyList.begin();
				a=vertexArray[*it];
				it++;
				b=vertexArray[*it];
			
				if(isInConfigurationA(u,a,b,NDash,NDoubleDash))
				{
					/* as this is in configuration A and |NDash| = 0 and |NDoubleDash| = 0 
						so the colorExchange(ua,ub) is valid.
					*/
					Edge e1=findEdge(u.vertexNumber,a.vertexNumber);
					Edge e2=findEdge(u.vertexNumber,b.vertexNumber);
					colorExchange(e1,e2);
					/* now the  candidate color that was invalid before the color exchange now becomes valid. */
					e.color=cc;
					printf("Assigning to the edge (%d,%d) -> color=%d\n",e.start,e.end,cc);
				}
				else // it is not in configuration A.// this case is still remaining.
				{
					/* find Sua and Sub */
					set<int>Sua=S(u.vertexNumber,a.vertexNumber);
					set<int>Sub=S(u.vertexNumber,b.vertexNumber);
					Edge ua=findEdge(u.vertexNumber,a.vertexNumber);
					Edge ub=findEdge(u.vertexNumber,b.vertexNumber);
					if(Sua.find(ub.color)!=Sua.end())
					{
						/* here I need to recolor ua with fv-fuINTERSECTIONfv */
						// tochange=ua;
						set<int>newSet;
						set_difference(fv.begin(),fv.end(),fuINTERSECTIONfv.begin(),fuINTERSECTIONfv.end(),inserter(newSet,newSet.begin()));
						
						/* the following recoloring could lead to bichromatic cycles. */ /* confused. */
						recolor(ua,*(newSet.begin())); 
						
						/*  */
						e.color=cc;
					}
					else if(Sub.find(ua.color)!=Sub.end())
					{
						//tochange=ub;
						// this case is still remaining.
					}
					else {} // this part of code will never be executed. 
				}
			}
			else // this means that candidate color dont form a critical path and so candidate color is valid.
			{
				e.color=cc;
				printf("Assigning to edge e=(%d,%d) -> color=%d\n",e.start,e.end,cc);
			}
		}	
	}
	else if(fuINTERSECTIONfv.size()==2) // this means that fuUNIONfv.size() is equal to 2 // this case is still remaining.
	{
		printf("________________________$$ Some this you need to here $$_______________________3\n");
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
		printf("%d <--> %d   Color=%d\n",(*i).start,(*i).end,(*i).color);
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
