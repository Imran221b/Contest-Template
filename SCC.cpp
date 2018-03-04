//Given number of nodes and the edges, prints how many SCC there are and which node belongs to which SCC
//Since we are finding SCC, the graph is directed of course :p
//uses Tarjan's algo
 
 
int t,n,num,Time,visited[100005],disc[100005],low[100005],in[100005],ar[100005];
std::vector<int> v[100005]; 
std::vector<int> av;
 
void dfs(int id) {
	disc[id] = low[id] = ++Time;
	visited[id] = 1;
	av.pb(id);
 
	for(int i = 0; i < SZ(v[id]); i++) {
		int x = v[id][i];
 
		if(!visited[x]) {
			dfs(x);
 
			low[id] = min(low[id], low[x]);
		}
 
		else if(visited[x] == 1) {
			low[id] = min(low[id], disc[x]);
		}
	}
 
	if(low[id] == disc[id]) {
 
		++num;
 
		while(1) {
			int x = av[ SZ(av)-1 ]; av.pop_back();
			ar[x] = num;
			visited[x] = 2;
 
			if(x == id) break;
		}
	}
}
 
int main () {
 
 	#ifdef forthright48
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
 	#endif
 
    cin >> t;
 
    rep(kas,t) {
 
    	int m,x,y,ans = 0;
    	mem(in,0);
    	rep(i,100000) {
    		v[i].clear();
    	}
 
    	num = 0;
    	Time = 0;
    	mem(visited,0);
    	mem(disc,0);
    	mem(low,0);
    	av.clear();
    	mem(ar,0);
 
 
    	gi(n); gi(m);
 
    	rep(i,m) {
    		gi(x); gi(y);
 
    		v[x].pb(y);
    	}
 
    	rep(i,n) {
    		if(!visited[i]) {
    			dfs(i);
    		}
    	}
 
    	pf("Number of SCC is %d\n",num);
 
    	rep(i,n) {
    		pf("%d-th node belongs to %d-th scc\n",i,ar[i]);
    	}
    }
 
 
    return 0;
}
