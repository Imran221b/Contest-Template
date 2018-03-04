//Given a bidirectional graph, prints the number of articulation bridges and the bridges sorted in ascendind order
//n is the number of nodes (numbered from 1 to n) and m is the number of edges
//The graph may not be connected and bridge is defined as an edge that disconnects a component when it gets deleted
//uses Tarjan's algo
 
 
int t,n,low[100005],disc[100005],visited[100005],Time,m;
std::vector<int> v[100005];
std::vector<pii> av; 
 
void dfs(int id, int par) {
    disc[id] = low[id] = ++Time;
    visited[id] = 1;
 
    for(int i = 0; i < SZ(v[id]); i++) {
        int x = v[id][i];
        if(x == par) continue;
 
        if(!visited[x]) {
            dfs(x,id);
 
            low[id] = min(low[id], low[x]);
 
            if(low[x] > disc[id]) {
                av.pb(MP( min(id,x), max(id,x) ));
            }
        }
 
        else {
            low[id] = min(low[id], disc[x]);
        }
    }
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
                dfs(i,-1);
            }
        }
 
        sort(av.begin(), av.end());
 
        pf("%lld = Number of Articulation bridges.\nAnd they are:\n",SZ(av));
 
        for(int i = 0; i < SZ(av); i++) {
            pf("%d - %d\n",av[i].ff, av[i].ss);
        }
 
        nl;
    }
 
 
    return 0;
}
