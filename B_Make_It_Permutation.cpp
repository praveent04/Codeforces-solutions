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
   cin>>n;
   vector<ll> A(n);
   cin>>A;
   vector<ll> B(n);
   cin>>B;
   ll maxi = 0, sum = 0;
        for(ll i = 0; i < n; i++){
            maxi = max(maxi, A[i]);
        }
        for(ll i = 0; i < n; i++){
            sum += B[i];
        }

        ll l = maxi, h = maxi + 2 * sum;
        while(l < h){
            ll m = l + ((h - l)/ 2);
            __int128 O = 0, C = 0;
            for(int i = 0; i < n; i++){
                ll a = A[i];
                ll b = B[i];
                __int128 d = (__int128)m - a;
                __int128 u = -1;
                if(b >= d) u = d ; 
                else u= b;
                O += b - u;
                C += (d - u) / 2;
            }
            if(C < O)
            l = m + 1 ;
            else h = m;
        }
        cout << l << endl;
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