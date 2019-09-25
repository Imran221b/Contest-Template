/// Calculates the Mod Inverses of 1 to N (w.r.t. mod) in O(N)
/// Taken from - https://forthright48.com/modular-inverse-from-1-to-n/

vlong inv[Size+8]; 
inv[1] = 1;

for (int i = 2; i <= Size; i++ ) {
    inv[i] = (-(mod/i) * inv[mod % i] ) % mod;
    inv[i] = inv[i] + mod;
}
