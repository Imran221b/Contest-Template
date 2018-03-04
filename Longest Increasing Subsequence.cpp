//Solution to UVA 481. This problem basically asks you to print the LIS given the array.
//Solution complexity is O(n logn). Implemented the technique learnt from lightoj.
 
 
 
int t,n,ar[100005],L[100005],I[100005]; 
 
int main () {
 
    //freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
 
	int x;
 
	while(sc("%d",&x) != EOF) {
		ar[++n] = x;
	}
 
	mem(I,63);
	I[0] = -I[0];
 
	for(int i = 1; i <= n; i++) {
		x = ar[i];
		int lf = 0, ri = n, md, id;
 
		while(lf <= ri) {
			md = (lf + ri) >> 1;
 
			if(I[md] >= x) {
				id = md;
				ri = md-1;
			}
 
			else {
				lf = md+1;
			}
		}
 
		I[id] = x;
		L[i] = id;
 	}
 
 	//rep(i,n) pf("%d %d\n",ar[i],L[i]);
 
 	int high = 0;
 	rep(i,n) high = max(high, L[i]);
 	high++;
 	std::vector<int> v; v.clear();
 
 	for(int i = n; i >= 1; i--) {
 		if(L[i] == high-1) {
 			v.pb(ar[i]);
 			high--;
 		}
 	}
 
 	pf("%lld\n",SZ(v));
 	pf("-\n");
 
 	for(int i = SZ(v)-1; i >= 0; i--) {
 		pf("%d\n",v[i]);
 	}
 
 
    return 0;
}
