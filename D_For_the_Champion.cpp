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
constexpr int INF = 1 << 30, Mod = 1000000000LL;
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

inline ll q(char dir, ll s){
    cout << "?"<<" " ;
    cout<< dir << " " ;
    cout<< s << endl << flush;
    ll ans;
    if (!(cin >> ans)) exit(0);
    if (ans == -1) exit(0);
    return ans;
}

void Solve(){
    int n; cin >> n;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i];

    ll maxi = LLONG_MIN;
    ll diff = LLONG_MIN;
    int i=0;
    while(i<n){
        ll a = X[i] + Y[i] ;
        ll b = X[i] - Y[i];
        maxi = max(maxi, a);
        diff = max(diff, b);
        i++;
    }

    const ll s = Mod;
 
    q('R', s);
    q('R', s);
    q('U', s);
    ll rU = q('U', s);

    q('D', s);
    q('D', s);
    q('D', s);
    ll rD = q('D', s);

    maxi = max(maxi,-LINF);
    diff = max(diff,-LINF);

    ll S1 = rU - 4LL * s + maxi;
    ll S2 = rD - 4LL * s + diff;


    cout << "!"<<" ";
    cout << (S1 + S2) / 2;
    cout << " ";
    cout << (S1 - S2) / 2 ;
    cout<< endl << flush;
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
