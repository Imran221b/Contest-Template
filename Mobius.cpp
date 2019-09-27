/// Definition: Square free number is a number which doesn't have a prime 
/// factor in its prime factorization more than once (Therefore not divisible by a square number other than 1)

/// Mobius function is a function which has one of the following values:
/// mobius(x) = -1 : square free number with odd number of distinct prime factors
/// mobius(x) = 1  : square free number with even number of distinct prime factors
/// mobius(x) = 0  : not a square free number
/// Store all the prime till N in vector prime by calling getPrime(N), then call mobiusCalc(N)


int status[Size+10];
vector<int> prime;

int mobius[Size+10];

void getPrime(int n) {
    for(int i = 4; i <= n; i += 2) status[i] = 1;

    for(int i = 3; i*i <= n; i += 2) {
        if(!status[i]) {
            for(int j = i*i; j <= n; j += i+i) {
                status[j] = 1;
            }
        }
    }
    
    prime.pb(2);
    for(int i = 3; i <= n; i += 2) {
        if(!status[i]) prime.pb(i);
    }
}

void mobiusCalc(int n){

    for(int i = 1; i <= n; i++) mobius[i] = 1; ///Initially all value is 1

    ///Mark all numbers with square factors 0
    int sqrtn = sqrt(n)+1;

    for(int i = 0; i < SZ(prime); i++) {
        
        if(prime[i] > sqrtn) break;

        int x = prime[i] * prime[i]; 
        for(int j = x; j <= n; j += x) mobius[j] = 0;
    }

    ///For each prime, all it's multiple gets multiplied by -1
    for(int i = 0; i < SZ(prime); i++) {
        for(int j = prime[i]; j <= n; j += prime[i]) mobius[j] = -mobius[j];
    }
}


