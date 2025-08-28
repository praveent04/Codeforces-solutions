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

template < typename T = int >
istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int >
ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
 
static inline ll nrm(ll a, ll m){
    a %= m;
    if (a < 0) a += m;
    return a;
}
 
static ll ex(ll a, ll b, ll &x, ll &y){
    if (!b){ x = (a >= 0 ? 1 : -1); y = 0; return llabs(a); }
    ll x1, y1;
    ll g = ex(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
 
static inline ll inv(ll a, ll m){
    ll x, y;
    ex(a, m, x, y);
    x = x%m;
    if (x < 0) x += m;
    return x;
}
 
static inline ll fac1(ll x){
    for (ll d = 2; d * d <= x; ++d){
        if (x % d == 0) return d;
    }
    return x;
}

void Solve(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

        int n; ll k;
        cin >> n >> k;
        vector<ll> a(n);
         cin >> a ;
 
        ll x = k + 1;
        ll p = fac1(x);
 
        ll u = nrm(k, p);
        ll v = inv(u, p);

        int i=0;
        while(i<n){
             
            ll w = (p - nrm(a[i], p)) % p;
            ll m = (w * v) % p;   
            ll l = m*k; 
            a[i] += l;  
            i++;       
        }
        i=0;
        while(i<n){
            if (i) cout << ' ';
            cout << a[i];
            i++;
        }
        cout <<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
     cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
