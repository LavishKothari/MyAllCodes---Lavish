MAX_INT=2147483647
tree=[]
numberOfVertices=40
 
class GraphNode:
    visited=0
    nodeNumber=0
    adjacencyList=[]
    key=-1
    def __init__(self,nodeNumber):
        self.key=MAX_INT
        self.adjacencyList=[]
        self.nodeNumber=nodeNumber
        self.visited=0
 
    def updateAdjacencyList(self,nodeList,adjacencyMatrix):
        for i in range(numberOfVertices):
            if adjacencyMatrix[self.nodeNumber][i]!=-1:
                self.adjacencyList.append(nodeList[i])
 
def extractMin(Q,adjacencyMatrix,answer):
    minNode=None
    minNodev=None
    min=MAX_INT
    for i in range(len(tree)):
        v=tree[i]
        for j in range(len(v.adjacencyList)):
            u=v.adjacencyList[j]
            if u.visited==0 and adjacencyMatrix[v.nodeNumber][u.nodeNumber] < min :
                min=adjacencyMatrix[u.nodeNumber][v.nodeNumber]
                minNode=u
                minNodev=v
    answer+=adjacencyMatrix[minNodev.nodeNumber][minNode.nodeNumber]
    Q.remove(minNode)
    minNode.visited=1
    return [minNode,answer]
def isNodeInQ(v,Q):
    for i in range(len(Q)):
        if Q[i]==v:
            return 1
    return 0
def MST_Prim(nodeList,adjacencyMatrix):
    answer=0
    nodeList[0].key=0
    nodeList[0].visited=1
    tree.append(nodeList[0])
    Q=[]
    for i in range(1,numberOfVertices):
        Q.append(nodeList[i])
    while len(Q)!=0:
        tempList=extractMin(Q,adjacencyMatrix,answer)
        u=tempList[0]
        answer=tempList[1]
        tree.append(u)
        for i in range(len(u.adjacencyList)):
            v=u.adjacencyList[i]
            if isNodeInQ(v,Q)==1 and adjacencyMatrix[u.nodeNumber][v.nodeNumber]<v.key:
                v.key=adjacencyMatrix[u.nodeNumber][v.nodeNumber]
    return answer
 
test_file=open("a.txt","r+")
adjacencyMatrix=test_file.read().split('\n')
 
for i in range(numberOfVertices):
    adjacencyMatrix.append(adjacencyMatrix[0].split(','))
    adjacencyMatrix.remove(adjacencyMatrix[0])
totalWeight=0

for i in range(numberOfVertices):
    for j in range(numberOfVertices):
        if adjacencyMatrix[i][j]!='-':
            adjacencyMatrix[i][j]=int(adjacencyMatrix[i][j])
            totalWeight+=adjacencyMatrix[i][j]
        else:
            adjacencyMatrix[i][j]=-1
nodeList=[]
counter=0
for i in range(numberOfVertices):
    nodeList.append(GraphNode(counter))
    counter+=1
 
# updating the adjacency list of each node
for i in range(len(nodeList)):
    nodeList[i].updateAdjacencyList(nodeList,adjacencyMatrix)
 
# applying Prim's Algorithm for finding Minimum Spanning Tree
reducedWeight=MST_Prim(nodeList,adjacencyMatrix)
print "Savings :", totalWeight/2-reducedWeight

