Lucas theorem is used to the value of nCr % p where p is a prime number and value of n,r is so big (10^18) that standard 
methods can't be used. First turn n and r to base p, and add leading zeros to r to make the two numbers length equal (if necessary).
Then calculate the binomial coefficients for each pair of corresponding base p digits. The answer is the product of the results mod p.
 
For example, here's how to calculate (472 C 86) % 5
 
Step 1: 472 in base 5 is 3342
	 86 in base 5 is 0321 (notice a leading zero is added)
 
Step 2: (3C0) % 5 = 1
	(3C3) % 5 = 1
	(4C2) % 5 = 6
	(2C1) % 5 = 2
 
Step 3: Multiply all the results -
	(1 * 1 * 6 * 2) % 5 = 12 % 5 = 2
 
Therefore (472 C 86) % 5 = 2 
	
C++ Code:
//Computes C(n,r) % p using Lucas Theorem, where p is a prime
//fact[i] = i! % p
//precalculate fact[i] for 0 <= i <= p-1 (for i >= p, fact[i] == 0)
//Add modInv from base template

vlong ncr(int n, int r, int p) {
    
    if(n < r) return 0;

    vlong res = 1, up, down;
    int a,b;
    
    while(n || r) {
        a = n % p;
        b = r % p;

        if(a < b) {
            return 0;
        }

        up = fact[a];
        down = (fact[b] * fact[a-b]) % p;
        down = modInv(down, p);

        res = (res * ((up * down) % p)) % p;

        n /= p;
        r /= p;
    }

    return res;
}
