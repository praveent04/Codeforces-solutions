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

bool cmp (const pair<ll,ll> &x,const pair<ll,ll> &y){
        if(x.fi!=y.fi) return x.fi<y.fi;
        return x.se<y.se;
    }
void Solve(){
     ll n,m;
    cin>>n>>m;
    vector<ll> a(m);
    cin>>a;
    vector<pair<ll,ll>> v(m);
    for(ll i=0;i<m;i++){
        ll f = a[i]/100;
        v[i] = {f, a[i]};
    }
    sort(all(v), cmp);
    vector<ll> f(m), id(m);
    vector<ll> T(n);
    for(ll i=0;i<m;i++){
        f[i] = v[i].first;
        id[i] = v[i].second;
    }
    
    for(ll i=0;i<n;i++){
        T[i] = llabs((ll)f[i] - (ll)f[m-1-i]);
    }
    vector<ll> P(n+1,0);
    for(ll i=1;i<=n;i++) {P[i] = P[i-1] + T[i-1];}
    ll b = -1;
    ll bk = 0;
    for(ll k=0;k<n+1;k++){
        if(P[k] + P[n-k] > b){
            b = P[k] + P[n-k];
            bk = k;
        }
    }
    ll k = bk;
    vector<ll> A(n), B(n);
    ll cnt = 0;
    for(ll i=0;i<k;i++){
        A[cnt] = id[i];
        cnt++;
    }
    for(ll i=m-(n-k); i<m; i++){
        A[cnt] = id[i];
        cnt++;
    }
    int temp = 0;
    for(ll i=0;i<n-k;i++){
        B[temp] = id[i];
        temp++;
    }
    for(ll i=m-k;i<m;i++){
        B[temp] = id[i];
        temp++;
    }
    for(ll i=0;i<n;i++){
        ll ar = A[i];
        int x = n-1-i;
        ll br = B[x];
        for(ll j=0;j<=5;j++){
            if(j%2==0) cout<<ar;
            else cout<<br;
            if(j<5) {cout<<' ';}
        }
        cout<<endl;
    }
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