// Use rng() to generate a random number (both 32 bit and 64 bit). See Rand_CF_Blog.cpp for its range and other details.
// If you need 64 bit random number, use rng(), but with mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// If you need a random number between a and b (inclusive), use getInt (it handles inclusive part, don't worry about it) from RandGenerator_forthright48.cpp
// To build tree, use RandGenerator_forthright48.cpp
// Avoid using RandGenerator_flash7.cpp as long as you can. That one uses rand() which has issues. 


---------------------------------------------------------------------------------------------------------------------------------


//See Rand_CF_Blog.cpp for how to use mt19937

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
