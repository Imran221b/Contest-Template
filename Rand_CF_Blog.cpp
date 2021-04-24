//From CF blog - https://codeforces.com/blog/entry/61587

What's the solution?
Don't worry, as of C++11 there are much better random number generators available in C++. The only thing you need to remember is to use mt19937, included in the <random> header. This is a Mersenne Twister based on the prime 2^19937 - 1, which also happens to be its period. It's a much higher-quality RNG than rand(), in addition to being much faster (389 ms to generate and add 108 numbers from mt19937 in Custom Invocation, vs. 1170 ms for rand()). It also produces full 32-bit unsigned outputs between 0 and 2^32 - 1 = 4294967295, rather than maxing out at a measly 32767.

To replace random_shuffle(), you can now call shuffle() and pass in your mt19937 as the third argument; the shuffle algorithm will use your provided generator for shuffling.

C++11 also gives you some nifty distributions. uniform_int_distribution gives you perfectly uniform numbers, without the bias of mod -- i.e., rand() % 10000 is more likely to give you a number between 0 and 999 than a number between 9000 and 9999, since 32767 is not a perfect multiple of 10000. There are many other fun distributions as well including normal_distribution and exponential_distribution.

To give you a more concrete idea, here's some code using several of the tools mentioned above. Note that the code seeds the random number generator using a high-precision clock. This is important for avoiding hacks specifically tailored to your code, since using a fixed seed means that anyone can determine what your RNG will output. For more details, see How randomized solutions can be hacked, and how to make your solution unhackable.

One last thing: if you want 64-bit random numbers, just use mt19937_64 instead.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

const int N = 3000000;

double average_distance(const vector<int> &permutation) {
    double distance_sum = 0;

    for (int i = 0; i < N; i++)
        distance_sum += abs(permutation[i] - i);

    return distance_sum / N;
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> permutation(N);

    for (int i = 0; i < N; i++)
        permutation[i] = i;

    shuffle(permutation.begin(), permutation.end(), rng);
    cout << average_distance(permutation) << '\n';

    for (int i = 0; i < N; i++)
        permutation[i] = i;

    for (int i = 1; i < N; i++)
        swap(permutation[i], permutation[uniform_int_distribution<int>(0, i)(rng)]);

    cout << average_distance(permutation) << '\n';
}
Both shuffles result in almost exactly 106 average distance, like we originally expected.

 
