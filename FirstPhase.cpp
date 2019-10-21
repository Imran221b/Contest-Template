#include <bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dump(x) cerr << "~ " << #x << " = " << x << endl
#define endl "\n"
#define ff first
#define ss second
#define MP make_pair
#define pb push_back
#define SZ(x) ((vlong)(x).size()) 
#define phl printf ( "hello\n" )
#define nl puts ("")
#define pf printf
#define gi(k) scanf("%d",&k)
#define gl(k) scanf("%lld",&k)
#define sc scanf
#define CLR(x,y) memset(x,y,sizeof(x))
#define mem CLR
#define LL long long
#define rep(i,n) for(int i = 1; i <= n; i++)
#define ABS(x) ( (x) < 0 ? -(x) : (x))
#define FABS(x) ( (x) + eps < 0 ? -(x) : (x))
#define LCM(x,y) ( ( x / gcd(x,y) ) * (y) ) 
#define Set(N,cur) N = (N | (1LL << cur))
#define Check(N,cur) ( !((N & (1LL << cur)) == 0) )

typedef long long vlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef unsigned long long uvlong;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;


///_________________Template Ends Here_________________///


int main () {

    #ifdef LOCAL
    freopen ( "input.txt", "r", stdin ); //freopen ( "output.txt", "w", stdout );
    #endif
    
    //fast_cin;

    int t; cin >> t;

    for(int kas = 1; kas <= t; kas++) {


    }


    return 0;
}
