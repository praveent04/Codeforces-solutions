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
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    // Check if it's already a path graph
    bool isPath = true;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 2) {
            isPath = false;
            break;
        }
    }
    
    if (isPath) {
        cout << -1 << "\n";
        return;
    }
    
    // Find the vertex with maximum degree to use as b
    int maxDegree = 0;
    int b = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            b = i;
        }
    }
    
    // Choose a and c from neighbors of b
    // Strategy: choose a and c such that c can handle additional connections better
    vector<int> neighbors = adj[b];
    int a = neighbors[0];
    int c = neighbors[1];
    
    // Prefer c to be the neighbor with smaller degree (can handle more connections)
    if (degree[neighbors[0]] < degree[neighbors[1]]) {
        a = neighbors[1];
        c = neighbors[0];
    }
    
    cout << a << " " << b << " " << c << "\n";
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