//given a bidirectional graph, prints the number of articulation point and the points themselves
//there can be multiple components and articulation point is defined as a node that splits a component in two when it is removed
//n is the number of nodes (numbered from 1 to n) and m is the number of edge
 
/*
An overview of the algorithm (from geeksforgeeks)
 
A O(V+E) algorithm to find all Articulation Points (APs)
The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
 
*/
 
 
 
int t,n,low[100005],disc[100005],visited[100005],Time,m,root;
std::vector<int> v[100005];
std::vector<int>av; 
 
void dfs(int id, int par) {
    disc[id] = low[id] = ++Time;
    visited[id] = 1;
 
    int children = 0, flag = 0;
 
    for(int i = 0; i < SZ(v[id]); i++) {
        int x = v[id][i];
        if(x == par) continue;
 
        if(!visited[x]) {
            children++;
            dfs(x,id);
 
            low[id] = min(low[id], low[x]);
 
            if(id != root && low[x] >= disc[id]) {
                flag = 1;
            }
        }
 
        else {
            low[id] = min(low[id], disc[x]);
        }
    }
 
    if(id == root) {
        if(children > 1) flag = 1;
    }
 
 
    if(flag) av.pb(id);
}
 
int main () {
 
    #ifdef forthright48
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
    #endif
 
    cin >> t;
 
    rep(kas,t) {
 
        gi(n); gi(m);
 
        rep(i,n) {
            v[i].clear();
        }
 
        int x,y,z;
        mem(visited,0);
        mem(low,0);
        mem(disc,0);
        Time = 0;
        av.clear();
 
 
        rep(i,m) {
            gi(x); gi(y);
 
            v[x].pb(y);
            v[y].pb(x);
        }
 
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                root = i;
                dfs(i,-1);
            }
        }
 
        sort(av.begin(), av.end());
 
        pf("%lld = Number of Articulation points.\nAnd they are:\n",SZ(av));
 
        for(int i = 0; i < SZ(av); i++) {
            pf("%d\n",av[i]);
        }
 
        nl;
    }
 
 
    return 0;
}
