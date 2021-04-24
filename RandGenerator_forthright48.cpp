/***********Template Starts Here***********/
#include <bits/stdc++.h>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl debug ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/
char buf[100];

/*mt19937 generator (42); ///Change Seed Here

vlong getInt ( vlong a, vlong b ) {

    uniform_int_distribution<vlong> dist(a,b);

    return dist ( generator );

} */

// The above getInt (commented out) was the original file. For the below one, you 
// don't have to manually change seed. This one should be safer as well.
// But in case of any problem, go back to the older one. 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 generator ( rng() ); 

vlong getInt ( vlong a, vlong b ) {

    uniform_int_distribution<vlong> dist(a,b);

    return dist ( generator );

}

void buildTree( int n ) { ///Using Prufer Code, build a random tree. Print N-1 edge

    uniform_int_distribution<int> dist(1,n);

    vector<int> prufer; ///Generate a Prufer Code first

    map<int,int> mp;
    set<int> st;

    FOR(i,1,n-1) {
        int t = dist(generator);
        prufer.pb ( t );
        mp[t]++;
    }

    ///Now build a tree using the prufer code

    FOR(i,1,n) {
        if ( mp.find ( i ) == mp.end() ) st.insert ( i );
    }

    FOR(i,0,n-2){
        int a = prufer[i];

        ///Find the smallest number which is not present in prufer code now
        int b = *(st.begin());

        printf ( "%d %d\n", a, b );

        st.erase ( b );
        mp[a]--;
        if ( mp[a] == 0 ) st.insert ( a );
    }
}

void generateCase( int numKase ) {
    int kase = 100000;

    printf ( "%d\n", kase );

    
    for ( int i = 0; i <= 10000; i++ ) {
        printf ( "%d\n", i );
        kase--;
    }

    vlong large = power(10, 17);
    for ( vlong i = 0; i <= 10000; i++ ) {
        printf ( "%lld\n", large - i );
        kase--;
    }

    while ( kase-- ) {
        vlong n = getInt(10000, large - 10000);
        printf ( "%lld\n", n );
    }

}

void run ( int a, int b ) {
    timeStamp;
    FOR(i,a,b) {
        string inp = "input/input";
        sprintf ( buf, "%02d", i );
        inp += buf; inp += ".txt";

        freopen ( inp.c_str(), "w", stdout );

        generateCase(i);

        timeStamp;
    }
}

int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    run( 0, 0 );

    return 0;
}
