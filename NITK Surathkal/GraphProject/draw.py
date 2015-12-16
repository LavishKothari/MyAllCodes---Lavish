import networkx as nx
import matplotlib.pyplot as plt

def draw_graph(edges,vertices,graph, labels=None, graph_layout='random',
               node_size=600, node_color='cyan', node_alpha=0.3,
               node_text_size=10,
               edge_color='black', edge_alpha=0.3, edge_tickness=5,
               edge_text_pos=0.3,
               text_font='sans-serif'):

	# create networkx graph
	G=nx.Graph()

	# add edges
	for edge in graph:
		G.add_edge(edge[0], edge[1])

	# these are different layouts for the network you may try
	# shell seems to work best
	if graph_layout == 'spring':
		graph_pos=nx.spring_layout(G)
	elif graph_layout == 'spectral':
		graph_pos=nx.spectral_layout(G)
	elif graph_layout == 'random':
		graph_pos=nx.random_layout(G)
	else:
		graph_pos=nx.shell_layout(G)

	
    # draw graph
	G0=nx.Graph();
	G1=nx.Graph();
	G2=nx.Graph();
	G3=nx.Graph();
	graph0=[]
	graph1=[]
	graph2=[]
	graph3=[]
	for i in range(0,len(labels)):
		if labels[i]==1:
			G0.add_edge(graph[i][0],graph[i][1])
			graph0.append(graph[i])
		if labels[i]==2:
			G1.add_edge(graph[i][0],graph[i][1])
			graph1.append(graph[i])
		if labels[i]==3:
			G2.add_edge(graph[i][0],graph[i][1])
			graph2.append(graph[i])
		if labels[i]==4:
			G3.add_edge(graph[i][0],graph[i][1])
			graph3.append(graph[i])
    
	nx.draw_networkx_nodes(G0,graph_pos,node_size=node_size,alpha=node_alpha, node_color=node_color)
	nx.draw_networkx_nodes(G1,graph_pos,node_size=node_size,alpha=node_alpha, node_color=node_color)
	nx.draw_networkx_nodes(G2,graph_pos,node_size=node_size,alpha=node_alpha, node_color=node_color)
	nx.draw_networkx_nodes(G3,graph_pos,node_size=node_size,alpha=node_alpha, node_color=node_color)
	
	nx.draw_networkx_edges(G0,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color='#ff0000') # red
	nx.draw_networkx_edges(G1,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color='#00ff00') # green
	nx.draw_networkx_edges(G2,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color='#0000ff') # blue
	nx.draw_networkx_edges(G3,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color='#000000') # black
	'''
	nx.draw_networkx_edges(G0,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color=edge_color) # red
	nx.draw_networkx_edges(G1,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color=edge_color) # green
	nx.draw_networkx_edges(G2,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color=edge_color) # blue
	nx.draw_networkx_edges(G3,graph_pos,width=edge_tickness,alpha=edge_alpha,edge_color=edge_color) # black
	'''
	nx.draw_networkx_labels(G0, graph_pos,font_size=node_text_size,font_family=text_font)
	nx.draw_networkx_labels(G1, graph_pos,font_size=node_text_size,font_family=text_font)
	nx.draw_networkx_labels(G2, graph_pos,font_size=node_text_size,font_family=text_font)
	nx.draw_networkx_labels(G3, graph_pos,font_size=node_text_size,font_family=text_font)

	if labels is None:
		labels = range(len(graph))
	
	labels0=[]
	labels1=[]
	labels2=[]
	labels3=[]
	for i in range(0,len(graph0)):
		labels0.append(1)
	for i in range(0,len(graph1)):
		labels1.append(2)
	for i in range(0,len(graph2)):
		labels2.append(3)
	for i in range(0,len(graph3)):
		labels3.append(4)
	
	edge_labels0 = dict(zip(graph0, labels0))
	edge_labels1 = dict(zip(graph1, labels1))
	edge_labels2 = dict(zip(graph2, labels2))
	edge_labels3 = dict(zip(graph3, labels3))    
	
	
	nx.draw_networkx_edge_labels(G0, graph_pos, edge_labels=edge_labels0,label_pos=edge_text_pos)
	nx.draw_networkx_edge_labels(G1, graph_pos, edge_labels=edge_labels1,label_pos=edge_text_pos)
	nx.draw_networkx_edge_labels(G2, graph_pos, edge_labels=edge_labels2,label_pos=edge_text_pos)
	nx.draw_networkx_edge_labels(G3, graph_pos, edge_labels=edge_labels3,label_pos=edge_text_pos)
	
	
	frame1=plt.gca()
	frame1.axes.get_xaxis().set_visible(False)
	frame1.axes.get_yaxis().set_visible(False)
	plt.title("Number of Vertices = "+str(vertices)+"   and   Number of Edges = "+str(edges))
	# show graph
	plt.show()


inFile=open("result.txt",'r')
vertices,edges=map(int,inFile.readline().split())
graph=[]
edgeLabels=[]
for i in range(0,edges):
	a,b,c=map(int,inFile.readline().split())
	graph.append((a,b),)
	edgeLabels.append(c)
draw_graph(edges,vertices,graph, edgeLabels)

