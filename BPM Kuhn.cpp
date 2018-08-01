Some theoretical stuff on Bipartite graph:

Vertex cover: Set of vertices that cover all the edges of the graph

Independent Set: Set of vertices that don't have any edges between them

Clique: Set of vertices that have all pair edges between them (from left to right only ofcourse)

Complement graph: Complement of a bipartite graph is a graph where a pair of nodes have edges between them if the 
original graph don't and vice versa. Edges will be from left to right (i.e., no edges on the same side in the complement
graph, so it still remains a bipartite graph)

König's theorem says that min vertex cover == max match on bipartite graphs. 
	
Min vertex cover is trivially the same as max independent set (a set of vertices forms a min cover if all vertices 
not in the set are independent).
	
Therefore, Max match = Min vertex cover = #of nodes - Max independent set

Every independent set induces a clique in the complement graph.
Therefore, Size of max clique = Max independent set in complement graph



// Kuhn's Algo for finding Maximum matching

// README
//
// How to use it:
// 1. Take an instance of KUHN structure. Let it be called kuhn
// 2. Clear the instance: kuhn.clear(n)
// 3. Build the graph by pushing edges to adj[NODE]. If an edge goes from u to v,
//    where u is memeber of left side and v is member of right side, then:
//    adj[u].push_back(v)
// 3. Get maximum matching by calling: kuhn.match(n)
// 4. Who is matched with whom is stored in left[] and right[]
// 5. If you want to print vertex cover, call kuhn.findVertexCover(n). Then,
//    membership of vertex cover is stored in lcover[] and rcover[]

/*
   remember, both sides have nodes from 1 to N.
   do not address right side nodes starting from N+1.
*/

#define NODE xxx

struct KUHN{
    int left[NODE]; // Contains who is matched with ith vertex on left side
    int right[NODE]; // Contains who is matched with ith vertex on right side
    int vis[2*NODE]; ///Node double in vis for vertex print
    int cc;
    vector<int> adj[NODE]; // For each node on left side, push its neighbor here

    KUHN() : cc(1) {}

    void clear( int n ) {
        FOR(i,0,n) adj[i].clear();
    }

    bool tryK ( int v ) {
        if ( vis[v] == cc ) return false;
        vis[v] = cc;
        for ( int i = 0; i < SZ(adj[v]); i++ ) {
            int t = adj[v][i];
            if ( right[t] == -1 ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        for ( int i = 0; i < SZ(adj[v]); i++ ) {
            int t = adj[v][i];
            if ( tryK ( right[t] ) ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        return false;
    }

    int match(int n) {
        int res = 0;
        bool done;
        CLR(left,-1); CLR(right,-1);
        do {
            done = true; cc++;
            FOR(i,0,n) {
                if(left[i]==-1 && tryK(i)) {
                    done = false;
                }
            }
        } while(!done);
        FOR(i,0,n) res += (left[i]!=-1);
        return res;
    }

    ///Careful. Loop runs from 0 to n-1
    ///Make sure match() has been run
    int lcover[NODE]; // If lcover[i] is 1, then ith node of left side is a member of vertex cover
    int rcover[NODE]; // If rcover[i] is 1, then ith node of right side is a member of vertex cover
    void findVertexCover ( int n ) {
		queue<int> q;
		cc++;
		FOR(i,0,n-1){
			if ( left[i] == -1 ) {
				q.push ( i );
				vis[i] = cc;
			}
		};

		while ( !q.empty() ) {
			int s = q.front(); q.pop();
			FOR(i,0,SZ(adj[s])-1){
				int t = adj[s][i];
				if ( t == left[s] ) continue;

				int xt = t + n;
				if ( vis[xt] == cc ) continue;

				vis[xt] = cc;
				xt = right[t];

				if ( xt != -1 && vis[xt] != cc ) {
					vis[xt] = cc;
					q.push ( xt );
				}

			};
		}

		FOR(i,0,n-1){
			if ( vis[i] != cc ) lcover[i] = 1;
			else lcover[i] = 0;
		};
		FOR(i,0,n-1){
			if ( vis[i+n] == cc ) rcover[i] = 1;
			else rcover[i] = 0;
		};

	}
}kuhn;
