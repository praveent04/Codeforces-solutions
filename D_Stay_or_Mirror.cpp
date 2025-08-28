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

struct B {
    int m;
    vector<int> t;
    B(int c) : m(c), t(c + 2) {}
    void clr(int c) { m = c; fill(t.begin(), t.end(), 0);}
    void add(int j) { for (; j <= m; j += j & -j) t[j]++; }
    int sum(int j) { int r = 0; for (; j; j -= j & -j) r += t[j]; return r; }
};

void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1), x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    B bit(n);
    int inv = 0;

    bit.clr(n);
   int i=n;
    while(i>=1) {
        x[i] = bit.sum(a[i] - 1);
        inv += x[i];
        bit.add(a[i]);
        i--;
    }
    bit.clr(n);
    i=1;
    while(i<=n) {
        y[i] = (i - 1) - bit.sum(a[i]);
        bit.add(a[i]);
        i++;
    }
    ll tot = inv;
    i=1;
    while(i<=n) {
        ll d = (n - i) - x[i] - y[i];
        if(d >= 0) {i++; continue;}
        tot += d;
        i++;
    }
    cout << tot;
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
