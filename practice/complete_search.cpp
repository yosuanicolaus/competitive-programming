#include "../template/debug.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test_bitset() {
    for (int i = 0; i < 1 << 3; i++) {
        bitset<3> b = i;
        dbg(b, i);
    }
}

void generate_subsets_iter() {
    const int n = 3;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) subset.push_back(j);
        }
        bitset<n> b = i;
        dbg(i, b, subset);
    }
}

int main() {
    /* hello, world! */
    generate_subsets_iter();
    // test_bitset();
}
