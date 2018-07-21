An undirected graph has an Eulerian cycle if and only if every vertex has even degree, and all of its 
vertices with nonzero degree belong to a single connected component.
An undirected graph can be decomposed into edge-disjoint cycles if and only if all of its vertices have even degree. 
So, a graph has an Eulerian cycle if and only if it can be decomposed into edge-disjoint cycles and its nonzero-degree 
vertices belong to a single connected component.
  
An undirected graph has an Eulerian trail if and only if exactly zero or two vertices have odd degree, and all of its 
vertices with nonzero degree belong to a single connected component.

  
A directed graph has an Eulerian cycle if and only if every vertex has equal in degree and out degree, and all of its 
vertices with nonzero degree belong to a single strongly connected component. Equivalently, a directed graph has an 
Eulerian cycle if and only if it can be decomposed into edge-disjoint directed cycles and all of its vertices with 
nonzero degree belong to a single strongly connected component.

A directed graph has an Eulerian trail if and only if at most one vertex has (out-degree) − (in-degree) = 1, at most 
one vertex has (in-degree) − (out-degree) = 1, every other vertex has equal in-degree and out-degree, and all of 
its vertices with nonzero degree belong to a single connected component of the underlying undirected graph.
  
  
Euler Graph printing: For directed graph, we can use Hierholzer’s Algorithm. Using this algorithm, we can find
Euler path/circuit in O(E) time, i.e., linear time. 
  
First, we have to fix the starting node. For circuit, we can choose any node as this node. For path, this node is the
node whose out_degree is greater than in_degree. Of course, if there are no such node, that graph is a circuit and 
we can choose any node as the starting node. The idea is to traverse each edge exactly once and whenever we get to a 
dead end where we cant move further, we push that node in a stack and return. The final ordering will be that of the 
stack. 
  
In my implementation, I used a vector as the adjacency list and another array pos[] to keep track of the edges being 
visited. Instead of a stack, I used a vector named final to keep the final ordering of the path. SZ(final)-1 is the
index of the starting node and 0 is the index of the last node. 

vector<int> v[NODE]; //adjacency list
int pos[NODE]; //to keep track of which position we are in of a node's adjacency list. Initialize this with 0.
vector<int>final; //this will keep the final path/circuit
  
void dfs(int x) {

    while(1) {
        if(pos[x] == SZ(v[x])) {
            final.pb(x); 
            return;
        }

        pos[x]++;
        dfs(v[x][pos[x]-1]);
    }
}

main() {
    
   //call the dfs fucntion with the starting node from main function
`
}



We can accomodate the directed graph using the same algorithm. The idea is to traverse each edge exactly once. So we will
have to keep a edge-wise flag which will denote whether this edge has been visited before or not. The rest of the algo 
will remain same (push to stack when we get to a dead end). The implementation may look different from the above code.
[Update this after solving for undirected graph]
