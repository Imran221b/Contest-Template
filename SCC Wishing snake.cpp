//Accepted
//http://www.lightoj.com/volume_showproblem.php?problem=1168
//SCC, Graph
 
#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <stack>
#include <cctype>
#include <fstream>
#include <sstream>
#include <bitset>
#include <utility>
#include <map>
#include <list>
 
using namespace std;
 
#define loop(x,y,z) for(int x=y;x<=z;x++)
#define pi acos(-1.0)
#define sz(a) (int)(a).size()
#define NMAX 2147483647
#define LMAX 9223372036854775807LL
#define pb push_back
#define mp make_pair
#define ll long long
#define pf printf
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(x,y) for(int x=1;x<=y;x++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gi(k) scanf("%d",&k)
#define gl(k) scanf("%lld",&k)
#define PI acos(-1.0)
#define eps 1e-8
#define fi first
#define sc second
#define inf 1e13
#define endl "\n"
#define FO(i,n) for(int i = 0; i < n; i++)
#define debug(x) cout << #x << ": " << x << endl
 
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
 
#pragma comment (linker,"/STACK:16777216")
#pragma warning(disable:4786)
 
int Set(int N , int pos){return N = N | (1 << pos); }
int Reset(int N , int pos){return N = N & ~(1 << pos); }
bool check(int N, int pos){return (bool) (N & (1<<pos)); }
double dis(int x1, int y1, int x2, int y2) {return hypot(x1-x2, y1-y2);}
ll   GCD(ll a,ll b){ if(b == 0) return a; return GCD(b,a%b);}       //
ll   LCM(ll a,ll b){ return (a/GCD(a,b))*b;}
 
int ans,sum,t,n,k,m,Time,NOC,taken[1002],tk[1002],visited[1002];
int in[1002],out[1002],scc[1002],disc[1002],low[1002];
std::vector<int> v[1002];
std::vector<int> av;
 
int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};
 
void dfs(int id)
{
    disc[id] = low[id] = ++Time;
    visited[id] = 1;
    av.pb(id);
 
    for(int i = 0; i < v[id].size(); i++)
    {
        int x = v[id][i];
 
        if(!visited[x])
        {
            dfs(x);
            low[id] = min(low[id] , low[x]);
        }
 
        else if(visited[x] == 1)
        {
            low[id] = min(low[id] , disc[x]);
        }
    }
 
    if(disc[id] == low[id])
    {
        while(1)
        {
            int x = av[ av.size()-1 ]; av.pop_back();
            scc[x] = NOC;
            visited[x] = 2;
            if(x == id) break;  
        }
 
        NOC++;
    }
}
 
void flood(int id)
{
    tk[id] = 1;
 
    for(int i = 0; i < v[id].size(); i++)
    {
        if(!tk[v[id][i]])
        {
            flood(v[id][i]);
        }
    }
}
 
int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    //freopen("00_input.txt", "r", stdin);freopen("00_output.txt", "w", stdout);
 
    cin >> t;
 
    rep(kas,t)
    {
        mem(taken,0);
        Time = 0; mem(visited,0);
        av.clear();
        int x,y;
        NOC = 0;
        mem(in,0); mem(out,0); mem(scc,0);
        FO(i,1000) v[i].clear();
        mem(disc,-1); mem(low,-1);
 
 
        gi(n);
 
        rep(i,n)
        {
            gi(k);
 
            rep(j,k)
            {
                gi(x); gi(y);
                taken[x] = taken[y] = 1;
 
                v[x].pb(y);
            }
        }
 
        if(v[0].size() == 0){ pf("Case %d: NO\n",kas); continue; }
 
        mem(tk,0);
        flood(0);
        int tag  = 0;
 
        FO(i,1000) 
        { 
            if(taken[i] && tk[i] == 0) { tag = 1; break; } 
        }
 
        if(tag) { pf("Case %d: NO\n",kas); continue; }
 
        FO(i,1000)
        {
            if(taken[i] == 1 && visited[i] == 0)
            {   
                dfs(i);
            }
        }
 
 
        FO(i,1000)
        {
            if(taken[i])
            {
                x = scc[i];
 
                for(int j = 0; j < v[i].size(); j++)
                {
                    y = scc[v[i][j]];
 
                    if(x != y)
                    {
                        in[y]++;
                        out[x]++;
                    }
                }
            }
        }
 
        int flag = 0;
        FO(i, 1000)
        {
            if(taken[i] == 0) continue;
            if(in[scc[i] ] > 1 || out[ scc[i] ] > 1) { flag = 1; break; }
        }
 
         pf("Case %d: ",kas);
        if(flag) pf("NO\n");
        else pf("YES\n");
    }
 
    return 0;
}

