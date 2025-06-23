#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int INV6 = 166374059; // modular inverse of 6 mod 998244353

int mod_mul(long long a, long long b) {
    return (a * b) % MOD;
}

int mod_add(int a, int b) {
    return (a + b) % MOD;
}

int mod_sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mod_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> dice(N, vector<int>(6));
    set<int> all_values;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> dice[i][j];
            all_values.insert(dice[i][j]);
        }
    }

    // Compress all unique face values
    vector<int> sorted_vals(all_values.begin(), all_values.end());
    int M = sorted_vals.size();
    unordered_map<int, int> val_to_idx;
    for (int i = 0; i < M; ++i)
        val_to_idx[sorted_vals[i]] = i;

    // For each die, count how many faces are ≤ value x
    vector<vector<int>> die_counts(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        vector<int> cnt(M);
        for (int j = 0; j < 6; ++j) {
            int idx = val_to_idx[dice[i][j]];
            cnt[idx]++;
        }
        // prefix sum over sorted values
        for (int j = 1; j < M; ++j)
            cnt[j] += cnt[j - 1];
        die_counts[i] = cnt;
    }

    vector<int> F(M); // F[x] = prob that max of all dice ≤ x
    for (int i = 0; i < M; ++i) {
        int prob = 1;
        for (int j = 0; j < N; ++j) {
            int c = die_counts[j][i]; // how many faces ≤ val[i]
            prob = mod_mul(prob, mod_mul(c, INV6));
        }
        F[i] = prob;
    }

    // Compute expected value: E = sum x * (F(x) - F(x-1))
    int result = 0;
    int prevF = 0;
    for (int i = 0; i < M; ++i) {
        int diff = mod_sub(F[i], prevF);
        result = mod_add(result, mod_mul(sorted_vals[i], diff));
        prevF = F[i];
    }

    cout << result << '\n';
    return 0;
}
