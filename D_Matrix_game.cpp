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
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
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

ll F[100005], RF[100005];


void pre() {
    F[0] = 1;
    for (int i = 1; i <= 100004; i++) {
        F[i] = F[i - 1] * i % Mod;
    }

    ll r = 1;
    ll a = F[100005 - 1];
    ll b = Mod - 2;
    a %= Mod;
    while (b) {
        if (b & 1) r = r * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }

    RF[100005 - 1] = r;
    for (int i = 100005 - 2; i >= 0; i--) {
        RF[i] = RF[i + 1] * (i + 1) % Mod;
    }
}

ll comb(ll val, int r) {
    if (r == 0) return 1;
    if (r < 0) return 0;
    ll num = 1;
    for (int i = 0; i <= r-1; i++) {
        num = num * ((val - i + Mod) % Mod) % Mod;
    }
    return num * RF[r] % Mod;
}

void Solve(){
    ll a, b, k;
    cin >> a >> b >> k;

    ll x = (a - 1) * k + 1;
    ll res = ((b - 1) * k % Mod * comb(x, a) % Mod + 1) % Mod;

    cout << x % Mod << " " << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    pre();
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        Solve();
    }
    return 0;
}
