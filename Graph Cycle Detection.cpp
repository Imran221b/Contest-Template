For Directed graph: Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graph produces a tree. 
There is a cycle in a graph only if there is a back edge present in the graph. A backedge is an edge from a grey to a grey 
node. In dfs, a white node is an unseen node, a black node is a node whose work has been finished and a grey node is a node 
that is visited but still inside the dfs stack. For a disconnected graph, to detect cycle, we can check for cycle in 
individual trees by checking back edges. 
 
 
For Undirected graph: We do a DFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ 
such that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find such an adjacent 
for any vertex, we say that there is no cycle. The assumption of this approach is that there are no parallel edges between 
any two vertices.
