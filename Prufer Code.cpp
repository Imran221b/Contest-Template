The whole thing is taken from CPPS notebook and written by forthright48.
 
Prufer code: How many different trees can you construct given N nodes? The answer is N^(N-2).
From prufer code, we can see that there is a one-to-one correspondence between a tree and a 
sequence of N-2 length which consists of the numbers between 1 to N. Hence, the answer is N^(N-2).
 
Constructing Prufer code from a tree:
A tree (i.e. a connected graph without cycles) with vertices is given (N ≥ 2). Vertices of the tree 
are numbered by the integers 1,…,N. A Prufer code for the tree is built as follows: a leaf (a vertex 
that is incident to the only edge) with a minimal number is taken. Then this vertex and the incident 
edge are removed from the graph, and the number of the vertex that was adjacent to the leaf is written 
down. In the obtained graph once again a leaf with a minimal number is taken, removed and this procedure 
is repeated until there are only 2 vertex is left. The written down set of integers (N−2 numbers, each in 
a range from 1 to N) is called a Prufer code of the graph.
From this, we can see that if a node has degree k, it will appear (k-1) times in the prufer code.
Therefore, leaf nodes will not appear at all. 
 
 
Constructing Tree from the Prufer code:
 
Build a list containing nodes from 1 to N. Find the smallest node from the list which is absent in prufer 
code, and connect it to the first element of the code. Remove the smallest node from the list and remove 
the first element of prufer code. Repeat until prufer code is empty. There will be two nodes left in 
the list. Connect them.
 
Code:
 
vector<int> prufer;
 
void pruferCodeToTree() {
 
    /*Stores number count of nodes in the prufer code*/
    map<int,int> mp;
 
    /* Set of integer absent in prufer code*/
    set<int> st;
 
    int len = prufer.size();
    int n = len + 2;
 
    /*Count frequency of nodes*/
    for ( int i = 0; i < len; i++ ) {
        int t = prufer[i];
        mp[t]++;
    }
 
    /*Find the absent nodes*/
    for ( int i = 1; i <= n; i++ ) {
        if ( mp.find ( i ) == mp.end() ) st.insert ( i );
    }
 
    /*Connect Edges*/
    for ( int i = 0; i < len; i++ ){
        int a = prufer[i]; // First node
 
        /*Find the smallest number which is not present in prufer code now*/
        int b = *st.begin(); // Second node
 
        printf ( "%d %d\n", a, b ); // Edge of the tree
 
        st.erase ( b ); // Remove absent list
        mp[a]--; // Remove from prufer code
        if ( mp[a] == 0 ) st.insert ( a ); // If a becomes absent
    }
 
    /*The final edge*/
    printf ( "%d %d\n", *st.begin(), *st.rbegin() );
}
 
 
Reference problem:
1. http://acm.timus.ru/problem.aspx?num=1069
