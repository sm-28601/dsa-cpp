// Problem: Count numbers in the range [a, b] that do not have adjacent equal digits.
// link - https://cses.fi/problemset/task/2220


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> digit;
ll dp[20][11][2][2];

ll dfs(int pos, int prevDigit, int tight, int leadingZero) {

    if (pos == digit.size()) {
        return 1;
    }

    ll &res = dp[pos][prevDigit][tight][leadingZero];

    if (res != -1) {
        return res;
    }

    res = 0;

    int limit = tight ? digit[pos] : 9;

    for (int d = 0; d <= limit; d++) {

        if (!leadingZero && prevDigit == d) {
            continue;
        }

        int nextTight = tight && (d == limit);

        int nextLeadingZero = leadingZero && (d == 0);

        int nextPrev;

        if (nextLeadingZero) {
            nextPrev = 10;
        }
        else {
            nextPrev = d;
        }

        res += dfs(pos + 1,nextPrev,nextTight,nextLeadingZero);
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

    return dfs(0, 10, 1, 1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll a, b;
    cin >> a >> b;

    cout << compute(b) - compute(a - 1);

    return 0;
}