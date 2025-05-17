#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 998244353;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

const int MAXN = 501;
ll fact[MAXN], inv_fact[MAXN];

ll ncr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % Mod * inv_fact[n - r] % Mod;
}

ll bin(ll b, ll ee) {
    ll ans = 1;
    b %= Mod;
    while (ee > 0) {
        if (ee & 1) ans = ans * b % Mod;
        b = b * b % Mod;
        ee >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return bin(a, Mod - 2);
}



void fac() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % Mod;
        inv_fact[i] = inv(fact[i]);
    }
}

void Solve(){
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;

    for (int idx = n - 1;idx >= 0;--idx) {
        vector<ll> next_dp(k + 1, 0);
        for (int i = 0; i <= k; ++i) {
            if (dp[i] == 0){
                continue;
            } 

            for (int j = 0; i + j <= k; ++j) {
                int tot = i + j;
                int even = (tot + 1) / 2;
                int odd = tot / 2;

                int dig = str[idx] - '0';
                int ava = 0;
                if(dig == 0){
                   ava = even;
                }
                else{
                    ava= odd;
                }
                ll ways = ncr(ava, j);
                next_dp[tot] = (next_dp[tot] + dp[i] * ways % Mod) % Mod;
            }
        }
        dp = move(next_dp);
    }

    cout << dp[k] <<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    fac();
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
