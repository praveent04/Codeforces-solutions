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



void temp(int un, int pn, ll a, ll b,vector<ll>& val, vector<ll>& rel, vector<vector<int>>& adj) {
    rel[un] = val[un] + b;
    for (int& it : adj[un]) {
        if (it == pn) 
        continue;
        temp(it, un, max(0LL, val[un] + b), max(0LL, -val[un] + a),val,rel, adj);
    }
}

void print(vector<ll>& rel, int n){
    int i=0;
while(i<n) {
    if(i==n-1)
    cout << rel[i] << "";
    else
    cout << rel[i] << " ";
    i++;
    
}
}

void adjmake( vector<vector<int>>& adj, int n){
    int u,v;
for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Solve(){
    int n;
    cin >> n;
    vector<ll> val(n,0);
    cin >> val; 
    vector<vector<int>> adj(n, vector<int>());
    vector<ll> rel(n,0);
    adjmake(adj,n);
    temp(0, -1, 0LL, 0LL,val,rel, adj);
    print(rel,n);
    cout << endl;
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