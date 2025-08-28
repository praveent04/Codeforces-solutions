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
void Solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    cin >> a;
    for (int i = 0; i < n; ++i) {
        if(i % 2 == 0)
        b[i] = -a[i] ;
        else b[i] = a[i];
    }

    vector<ll> S(n, 0);
    if (n > 0) {
        S = b;
        int i=1;
        while(i<n) {
            S[i] = S[i - 1] + b[i];
            i++;
        }
    }

    ll ans = 0,c = 0,p = 0,nxt = 0;  
    int r=0;
    while(r<n) {
        ll b = S[r] + c;
         
        ll req = 0;
        if(r >= 1) req =  nxt ;
        else req = numeric_limits<ll>::min() / 2;
 
        ans += max(0LL, req - b);
        c += max(0LL, req - b);

        if (max(0LL, req - b) > 0 && (r % 2 == 1)) {
            p += max(0LL, req - b);
        }

        nxt = max(req, p);
        p = b + max(0LL, req - b);
        r++;
    }

    cout << ans <<endl;
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