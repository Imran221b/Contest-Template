/*Given n equations in the form -
x == a1 (mod m1) //Read == as congruent to
x == a2 (mod m2)
.
. 
.
x == a_n (mod m_n)
 
CRT finds the smallest x that satisfies these n equations or tells that no solution exists.
*/
 
/** Works for non-coprime moduli.
    Returns {-1,-1} if solution does not exist or input is invalid.
    Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<int, int> chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];
 
        int g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        int p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        int mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        int x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
        // vlong x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;
        //use this line instead, taken from forthright's github
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}
