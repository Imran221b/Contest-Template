vlong ncr(int n, int r) {
	
	vlong res,up,down;

	up = fact[n];

	down = (fact[r] * fact[n-r]) % mod;
	down = modInv(down,mod);

	res = (up * down) % mod;

	return res;
} 
