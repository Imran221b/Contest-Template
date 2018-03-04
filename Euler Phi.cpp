Euler Phi function: Given a positive integer N, finds the number of positive integers that are less
than N and are relatively prime with N.
 
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


