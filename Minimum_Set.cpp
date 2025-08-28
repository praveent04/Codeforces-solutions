#include <bits/stdc++.h>
using namespace std;
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size()))
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
 
namespace ns {
    struct Hs {
        size_t operator()(ll x) const { return std::hash<ll>()(x); }
    };
    static unordered_map<ll,ll,Hs> mh, mg;

    inline ll hp2(ll x) {
        
        return 1LL << (63 - __builtin_clzll((unsigned ll)x));
    }

    ll H(ll m) {
         
        if (mh.find(m) != mh.end()) return mh.find(m)->second;
        ll v;
        if (m > 0) {
            ll L = hp2(m);
            v = H(L - 1) + H(m - L) + L;
            mh.emplace(m, v);

        } else {
            
            v = 0;
            mh.emplace(m, v);
        }
        return v;
    }

    ll G(ll n) {
         
        if (mg.find(n) != mg.end()) return mg.find(n)->second;
        ll v;
        if (n > 1) {
            ll L = hp2(n);
            v = G(L - 1) + H(n - L) + L + (n - L == 0 ? 1 : 0);
            mg.emplace(n, v);
            
        } else {
           v = 0;
            mg.emplace(n, v);
        }
         
        return v;
    }
}

void Solve(){
    using namespace ns;

    ll N; 
    cin >> N;
    
    cout << G(N) <<endl;
    
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
