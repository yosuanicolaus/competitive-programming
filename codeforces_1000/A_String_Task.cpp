#include <bits/stdc++.h>
using ll = long long;

void solve() {
    std::string inp;
    std::cin >> inp;
    std::string ans = "";
    std::string vowels = "aoyeuiAOYEUI";

    for (auto &ch : inp) {
        if (std::find(vowels.begin(), vowels.end(), ch) != vowels.end()) {
            continue;
        }
        ans += ".";
        ans += std::tolower(ch);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
