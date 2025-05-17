#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAX = 501;
 
int fact[MAX], invfact[MAX];
 
// Fast exponentiation
int power(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
// Modular inverse using Fermat's little theorem
int modinv(int a) {
    return power(a, MOD - 2);
}
 
// nCk modulo MOD
int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
 
// Precompute factorials and inverse factorials
void init_factorials() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = modinv(fact[i]);
    }
}
 //chunkcode01
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init_factorials();
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
 //chunkcode01
        vector<int> dp(k + 1);
        dp[0] = 1;  // Base case: one way to do 0 operations
 
        for (int i = n - 1; i >= 0; --i) {
            vector<int> ndp(k + 1, 0);
            for (int len = 0; len <= k; ++len) {
                if (dp[len] == 0) continue;
                for (int cnt = 0; len + cnt <= k; ++cnt) {
                    int T = len + cnt;//chunkcode01
                    int even = (T + 1) / 2;
                    int odd = T / 2;
                    int parity = s[i] - '0';
                    int P = (parity == 0) ? even : odd;
                    int ways = comb(P, cnt);
                    ndp[T] = (ndp[T] + dp[len] * ways % MOD) % MOD;
                }
            }
            dp = ndp;
        }//chunkcode01
 
        cout << dp[k] << '\n';
    }
 
    return 0;
}