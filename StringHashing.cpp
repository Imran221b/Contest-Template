Source: 
1. https://threads-iiith.quora.com/String-Hashing-for-competitive-programming
2. https://codeforces.com/blog/entry/4898(


Let a string S = s1 s2 s3 ... sn

Then we define a hash function of S as, 
hash(S) = sumOf(for i = 1 to n) (S[i] * (p ^ (i-1) )) % mod

To implement this, we will do:

hash(S[0]) = 0;

for(i = 1 to n), 
    hash(S[i]) = hash(S[i-1]) + ( (s[i]) * (p ^ i) ) % mod;

Then, Hash value of substring [L,R] of S is:
hash(L,R) = ( hash(R) - hash(L-1) ) / ( p ^ L ); 


Here, mod is a prime number greater than 10^9 and p is a prime greater than number of distinct element in our string (29 or 31 works in case of lowecase english letters). p is chosen as a prime because we will have to calculate modInverse to get the hash value of a substring in O(1) time. 


Remember that this is only one hash function and there can be lots of other good hash functions that avoid collisions. 

You can use double hash function to have very high probability that your result will be correct. To do double hash, we use two different mod values. But mod1 * mod2 must not result in overflow. (10^9 + 7) and (10^9 + 9) works.


The following is my C++ implementation of lightoj 1255 (Substring Frequency):

Problem Statement: A string and a pattern string is given (both contains lowercase english letter only and length <= 10^6). Find out how many times the pattern string occurs in the given string (as a substring). 

C++ Code:

//Add template here

#define N 1000000
 
vlong p,primepow[N+8],inv[N+8],fhash[N+8];
char s[N+8],ps[N+8];
 
int main () {
 
    #ifdef forthright48
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
    #endif
 

    //mod = 10^9 + 7
    p = 29; //our chosen prime value

 
    primepow[0] = 1;
    rep(i,N) primepow[i] = (primepow[i-1] * p) % mod; 
 
    /*pre-calculating the inversions of all powers of 29 because we will need the modInverses 
    to calculate hash values */
    inv[0] = 1;
    inv[1] = modInv(p,mod);
    for(int i = 2; i <= N; i++) inv[i] = (inv[i-1] * inv[1]) % mod;
 
    int t; cin >> t;
 
    rep(kas,t) {
 
        int ans = 0,len,plen;
        vlong x,y;
 
        sc(" %s",s+1); //given string
        sc(" %s",ps+1); //pattern string 
 
 
        len = strlen(s+1);
        plen = strlen(ps+1);

        //calculating hash of the given string
        fhash[0] = 0;
        for(int i = 1; i <= len; i++) {
            fhash[i] = (fhash[i-1] + ( (primepow[i] * (s[i])) % mod)) % mod;
        }

        //calculating hash value of the pattern string
        //we just need the total hash value of the pattern string
        //that's why not storing all the intermediate hash values in an array like the given string
        x = 0;
        for(int i = 1; i <= plen; i++) {
            x = (x + ((primepow[i-1] * (ps[i]) ) % mod) ) % mod;
        }
        
        
        for(int i = 1; i <= len-plen+1; i++) {
           
            y = (fhash[i+plen-1] - fhash[i-1] + mod) % mod;
            y = (y * inv[i]) % mod;
 
            if(x == y) ans++; //match found
        }
 
        pf("Case %d: %d\n",kas,ans);
    }
   
 
    return 0;
}
