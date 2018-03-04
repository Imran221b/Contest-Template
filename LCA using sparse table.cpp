//Using forthright48 template
//date: 31st May, 2017
 
int n,t,k,two[35],depth[100005],par[100005],table[100005][22],root; 
std::vector<int> v[100005];
 
int find_par(int id, int x) // finds id's k-th parent
{
    for(int i = k; i >= 0; i--) {
 
        if(two[i] <= x) {
            id = table[id][i];
            x -= two[i];
        }
    }
 
    return id;
}
 
void dfs(int id, int parent_of_id, int height)
{
    par[id] = parent_of_id;
    depth[id] = height;
 
    for(int i = 0; i < SZ(v[id]); i++) {
 
        int x = v[id][i];
        if(x == parent_of_id) continue;
 
        dfs(x,id,height+1);
    }
}
 
void build_table()
{
    dfs(root,-1,0);
 
    CLR(table,-1);
    for(int i = 1; i <= n; i++) table[i][0] = par[i];
 
    rep(i,k)
    {
        rep(j,n)
        {   
            if(table[j][i-1] != -1)
                table[j][i] = table[ table[j][i-1] ][ i-1 ];
        }
    }
}
 
int lca(int x, int y)
{
    if(depth[x] < depth[y]) swap(x,y);
 
    if(depth[x] > depth[y])
    {
        x = find_par(x,depth[x]-depth[y]);
    }
 
    if(x == y) return x;
 
    for(int i = k; i >= 0; i--)
    {
        if(table[x][i] != -1 && table[x][i] != table[y][i])
            x = table[x][i], y = table[y][i];
    }
 
    return par[x];
}
 
int main () {
    //#ifdef forthright48
    //freopen ( "00_input.txt", "r", stdin );
    //freopen ( "00_output.txt", "w", stdout );
    //#endif // forthright48
 
    //fast_cin;
 
    int x,y,m;
 
    k = 20;
    two[0] = 1;
    rep(i,20) two[i] = 1 << i;
 
    gi(n);
    root = 1;
 
    rep(i,n-1)
    {
        gi(x); gi(y);
 
        v[x].pb(y);
        v[y].pb(x);
    }
 
    build_table();
 
    gi(m);
    rep(i,m)
    {
        gi(x); gi(y);
        cout << lca(x,y) << endl;
    }
 
 
    return 0;
}

