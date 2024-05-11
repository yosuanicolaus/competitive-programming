#if LOCAL
#include <debug.h>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> umsi;
        int n = (int)word.size();
        int blen = 0;

        for (int i = 0; i < n; i += k) {
            string sw = word.substr(i, k);
            umsi[sw]++;
            blen = max(blen, umsi[sw]);
        }

        return n / k - blen;
    }
};
