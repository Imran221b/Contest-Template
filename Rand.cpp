//See CF_blog.cpp for how to use mt19937

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


//Zahin Bhai
//Returns a random from 0 to (2^30 - 1) range
//32768 or 2^15 is randmax 

srand(time(NULL)); //add this inside main function at the top

int getRand() {
    int res = ( rand() << 15) | rand();
    return res;
}

//For more rand functions using rand(), check flash7_rand.cpp
