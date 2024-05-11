#if LOCAL
#include <debug.h>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// upsolved after contest
// lesson: map<> id should be erased if it's 0

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = (int)s.size();
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
            unordered_map<char, int> mci;
            for (int j = 0; j <= i; j++) {
                mci[s[j]]++;
            }
            int j = 0;
            while (j < i) {
                if (is_good_mci(mci)) {
                    if (j == 0) {
                        dp[i] = 1;
                    } else {
                        int d = i - j + 1;
                        dp[i] = min(dp[i], 1 + dp[i - d]);
                    }
                }
                mci[s[j]]--;
                if (mci[s[j]] == 0) mci.erase(s[j]);
                j++;
            }
        }

        return dp[n - 1];
    }

    bool is_good_mci(unordered_map<char, int> &mci) {
        int cc = -1;
        for (const auto &[ch, cnt] : mci) {
            if (cc == -1) {
                cc = cnt;
            } else {
                if (cnt != cc) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    sol.minimumSubstringsInPartition("fabccddg");
    sol.minimumSubstringsInPartition("abababaccddb");
}
