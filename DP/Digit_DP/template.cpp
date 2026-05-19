#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> digit;

ll dp[20][2][2];

ll dfs(int pos, int tight, int leadingZero) {

    if (pos == digit.size()) {
        return 1;
    }

    ll &res = dp[pos][tight][leadingZero];

    if (res != -1) {
        return res;
    }

    res = 0;

    int limit = tight ? digit[pos] : 9;

    for (int d = 0; d <= limit; d++) {

        int nextTight = tight && (d == limit);

        int nextLeadingZero = leadingZero && (d == 0);

        res += dfs(pos + 1,
                   nextTight,
                   nextLeadingZero);
    }

    return res;
}

ll compute(ll n) {

    if (n < 0) {
        return 0;
    }

    digit.clear();

    if (n == 0) {
        digit.push_back(0);
    }

    while (n > 0) {
        digit.push_back(n % 10);
        n /= 10;
    }

    reverse(digit.begin(), digit.end());

    memset(dp, -1, sizeof(dp));

    return dfs(0, 1, 1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    return 0;
}