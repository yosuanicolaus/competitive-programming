#include <debug.h>
using namespace std;
using ll = long long;

/* ------------------------------------------------------------ */
/* Policy Based Data Structures */
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

/* ------------------------------------------------------------ */
/*  How to not get hacked when using unordered_map (custom hash)
    https://codeforces.com/blog/entry/62393
    example usage:
        unordered_set<int, chash> safe_set;
        unordered_map<int, int, chash> safe_map;
        gp_hash_table<int, int, chash> safe_hash_table;
    snippet prefix: "chash" */

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

/* ------------------------------------------------------------ */

int main() {
    /* hello, world! */
    unordered_map<int, int, chash> test;
    gp_hash_table<int, int, chash> foo;

    foo[42];
    foo[21] = 42;
    dbg(test, foo);
}
