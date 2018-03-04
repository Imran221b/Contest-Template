//Using forthright48 template
//date: 31st May, 2017
 
int n,t; 
std::vector<int> v[1003];
int depth[2002], vertex[2002], discovery[1002], lca_tr[4004];
int Time;
 
void lca_dfs(int id, int par, int level)
{
    ++Time;
 
    depth[Time] = level;
    vertex[Time] = id;
    discovery[id] = Time;
 
    for(int i = 0; i < v[id].size(); i++)
    {
        int x = v[id][i];
        if(x == par) continue;
 
        lca_dfs(x,id,level+1);
 
        ++Time;
 
        depth[Time] = level;
        vertex[Time] = id;
    }
}
 
 
void lca_init(int node, int b, int e)
{
    if(b == e)
    {
        lca_tr[node] = b;
        return;
    }
 
    int lf = node << 1, ri = lf+1, md = (b+e) >> 1;
 
    lca_init(lf, b, md);
    lca_init(ri, md+1, e);
 
    if( depth[ lca_tr[lf] ] < depth[ lca_tr[ri] ]) lca_tr[node] = lca_tr[lf];
    else lca_tr[node] = lca_tr[ri];
 
    return;
}
 
int lca_query(int node, int b, int e, int i, int j)
{
    if(b >= i && e <= j) return lca_tr[node];
 
    if(b > j || e < i) return 0;
 
    int lf = node << 1, ri = lf+1, md = (b+e) >> 1;
 
    int r1 = lca_query(lf,b,md,i,j);
    int r2 = lca_query(ri,md+1,e,i,j);
 
    int res;
 
    if(depth[r1] < depth[r2]) res = r1;
    else res = r2;
 
    return res;
}
 
int LCA(int x, int y)
{
    int lf = discovery[x], ri = discovery[y];
 
    if(lf > ri) swap(lf, ri);
 
    int id = lca_query(1,1,Time,lf,ri);
 
    return vertex[id];
}
 
int main () {
    //#ifdef forthright48
    //freopen ( "00_input.txt", "r", stdin );
    //freopen ( "00_output.txt", "w", stdout );
    //#endif // forthright48
 
    //fast_cin;
 
    int x,y;
    gi(n); 
 
    rep(i,n-1)
    {
        gi(x); gi(y);
 
        v[x].pb(y);
        v[y].pb(x);
    }
 
    Time = 0;
    lca_dfs(1,-1,1);
 
    lca_init(1,1,Time);
    depth[0] = NMAX;
 
 
    cin >> t;
 
    rep(kas,t)
    {
        cin >> x >> y;
 
        dbug(LCA(x,y));
    }
 
    return 0;
}
Close
Sphere Research Labs. Ideone is powered by Sphere Engine™
home terms of use api faq credits desktop mobile

Feedback & Bugs
 Not using Hotjar yet?
Select an element on the page.

