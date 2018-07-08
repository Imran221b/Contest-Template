//Array and Segment tree is indexed from 1
//Works for getting the sum. Change according to problem. 

vlong ar[ARRAY_SIZE], tr[ARRAY_SIZE * 4];

void init(int node, int b, int e) {
    if (b == e) {
        tr[node] = ar[b];
        return;
    }

    int lf = node << 1, ri = lf | 1, md = b+e >> 1;
    
    init(lf, b, md);
    init(ri, md+1, e);
    
    tr[node] = tr[lf] + tr[ri];
}
 
vlong query(int node, int b, int e, int i, int j) {

    if (i > e || j < b) {
        return 0;
    }

    if (b >= i && e <= j) {
        return tr[node];
    }
    
    int lf = node << 1, ri = lf | 1, md = b+e >> 1;

    vlong x = query(lf, b, md, i, j);
    vlong y = query(ri, md+1, e, i, j);

    return x+y;
}


void update(int node, int b, int e, int i, vlong newvalue) {
    if (i > e || i < b) {
        return;
    }

    if (b >= i && e <= i) {
        tr[node] = newvalue;
        return;
    }

    int lf = node << 1, ri = lf | 1, md = b+e >> 1;

    update(lf, b, md, i, newvalue);
    update(ri, md+1, e, i, newvalue);

    tr[node] = tr[lf] + tr[ri];
}
 
 
//LAZY
//TODO: Change the update function so it works for non-associative functions as well
 
struct info {
    vlong prop, sum;
} tr[ARRAY_SIZE * 4];


void update(int node, int b, int e, int i, int j, vlong x) {
    if (i > e || j < b) {
        return;
    }

    if (b >= i && e <= j) {
        tr[node].sum += ((e - b + 1) * x);
        tr[node].prop += x;

        return;
    }

    int lf = node << 1, ri = lf | 1, md = b+e >> 1;

    update(lf, b, md, i, j, x);
    update(ri, md+1, e, i, j, x);
    
    tr[node].sum = tr[lf].sum + tr[ri].sum + (e-b+1) * tr[node].prop;
}
 
vlong query(int node, int b, int e, int i, int j, vlong carry) {
    if (i > e || j < b) {
        return 0;
    }
 
    if (b >= i && e <= j) {
        vlong res = tr[node].sum + (carry * (e-b+1));
        return res;
    }

    int lf = node << 1, ri = lf | 1, md = b+e >> 1;
    
    vlong x = query(lf, b, md, i, j, carry+tr[node].prop);
    vlong y = query(ri, md+1, e, i, j, carry+tr[node].prop);

    return x+y;
}
