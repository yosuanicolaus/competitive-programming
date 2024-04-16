#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool need_increment(string &left, string &right) {
    int l = left.size() - 1, r = 0;
    while (l >= 0) {
        if (left[l] > right[r])
            return false;
        else if (left[l] < right[r])
            return true;
        l--;
        r++;
    }
    return true;
}

void increment(string &digits, int n) {
    int mid_digit, p;
    if (n % 2 == 1) {
        mid_digit = digits[n / 2] - '0';
        p = n / 2 - 1;
    } else {
        mid_digit = digits[n / 2 - 1] - '0';
        p = n / 2 - 2;
    }
    mid_digit++;
    if (mid_digit < 10) {
        if (n % 2 == 1)
            digits[n / 2] = mid_digit + '0';
        else
            digits[n / 2 - 1] = mid_digit + '0';
        return;
    } else {
        if (n % 2 == 1)
            digits[n / 2] = '0';
        else
            digits[n / 2 - 1] = '0';
    }

    while (p >= 0) {
        int digit = digits[p] - '0';
        digit++;
        if (digit < 10) {
            digits[p] = digit + '0';
            return;
        } else {
            digits[p] = '0';
        }
        p--;
    }
    digits = '1' + digits;
}

string solve() {
    string digits;
    cin >> digits;
    int n = digits.size();
    if (digits == "9") return "11";
    if (n == 1) return to_string(stoi(digits) + 1);

    string left, right;
    if (n % 2 == 0) {
        left = digits.substr(0, n / 2);
        right = digits.substr(n / 2);
    } else {
        left = digits.substr(0, n / 2);
        right = digits.substr(n / 2 + 1);
    }

    if (!need_increment(left, right)) {
        right = left;
        reverse(right.begin(), right.end());
        if (n % 2 == 0)
            return left + right;
        else
            return left + digits[n / 2] + right;
    }

    increment(digits, n);
    n = digits.size();
    int l = n / 2 - 1, r = n / 2;
    if (n % 2 == 1) r++;
    while (l >= 0 && r < n) {
        digits[r] = digits[l];
        l--;
        r++;
    }
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
