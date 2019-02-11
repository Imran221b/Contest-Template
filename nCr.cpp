vlong ncr(int n, int r) {
	
	vlong res,up,down;

	up = fact[n];

	down = (fact[r] * fact[n-r]) % mod;
	down = modInv(down,mod);

	res = (up * down) % mod;

	return res;
} 


vlong ncr(int n, int r) {
	
    vlong &res = dp[n][r];
    if(res != -1) return res;

    if(n == r) return res = 1;
    if(r == 0) return res = 1;
	
    res = (ncr(n-1,r) + ncr(n-1,r-1)) % mod;
    
    return res;
}
