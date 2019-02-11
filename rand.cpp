int getRand() {
    int res = ( rand() << 15) | rand();
    return res;
}
