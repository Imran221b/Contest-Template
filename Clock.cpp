int main () {
    
    double start_time = clock();

    vlong sum = 0;

    FOR(i,1,1e7) {
        sum += rand();
    }

    cout << sum << endl;

    double end_time = clock();

    pf("%.8lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
