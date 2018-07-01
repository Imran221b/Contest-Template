Euler Phi function: Given a positive integer N, finds the number of positive integers that are less
than N and are relatively prime with N.

 EulerPhi(N) = N * (1 - 1/p) (Here p is all prime that divides N)
 
The below function takes k as parameter and finds phi(k)
 
Here, v is the vector of prime numbers.
 
 
vlong phi(int k) {
 
    int m = k;
    vlong res = k;
 
    for(int i = 0; v[i]*v[i] <= m; i++) {
        if(m % v[i] == 0) {
 
            while(m % v[i] == 0) m /= v[i];
 
            res /= v[i];
            res *= v[i]-1;
        }
    }
 
    if(m > 1) {
        res /= m;
        res *= m-1;
    }
 
    return res;
}



And the below program calculates EulerPhi of all numbers in the range [1,Max]

#include <bits/stdc++.h>
using namespace std;

#define Max 1000000
int phi[Max];

void euler_phi(){
	phi[1] = 0;
 
	for(int i = 2;i<Max;i++){
		if(!phi[i]){
			phi[i] = i-1;
			for(int j = (i<<1);j<Max;j+=i){
				if(!phi[j]){
					phi[j] = j;
				}
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}

}
