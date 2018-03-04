//given a and b and a modvalue m, returns (a*b) % m
 
 
LL mulmod ( LL a, LL b, LL m ) {
    if ( a < b ) swap ( a, b );
    LL res = 0, x = a;
    while ( b > 0 ) {
        if ( b & 1 ) {
            res = res + x;
            if ( res >= m ) res -= m;
        }
        x = x * 2;
        if ( x >= m ) x -= m;
        b >>= 1;
     }
     return res % m;
} 
 
 
inline vlong bigmod2(LL a, LL p, LL m) {
    LL res = 1;
    while (p) {
        if (p&1) res = mulmod(res, a, m);
        p >>= 1, a = mulmod(a, a, m);
    }
    return res % m;
}
