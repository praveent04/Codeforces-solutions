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

vector<vector<int>> g;
vector<pair<int,int>> res;

void dfs1(int x, int p, int d) {
    for(int y : g[x]) {
        if(y == p) continue;
        if(d & 1) res.emplace_back(y, x);
        else res.emplace_back(x, y);
        dfs1(y, x, d+1);
    }
}

void dfs2(int x, int p, int d) {
    for(int y : g[x]) {
        if(y == p) continue;
        if(!(d & 1)) res.emplace_back(y, x);
        else res.emplace_back(x, y);
        dfs2(y, x, d+1);
    }
}

int mid(int n) {
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 2) {
            return i;
        }
    }
    return -1;
}

void Solve(){
    int n;
    cin >> n;
    g.assign(n+1, vector<int>());
    res.clear();
    
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    if(n == 2){
        cout << "NO"<<endl;
        return;
    }
    
    int m = mid(n);
    if(m == -1){
        cout << "NO"<<endl;
        return;
    }
    
    res.emplace_back(g[m][0], m);
    res.emplace_back(m, g[m][1]);
    
    cout << "YES"<<endl;
    auto it1 = find(g[g[m][0]].begin(), g[g[m][0]].end(), m);
    if(it1 != g[g[m][0]].end()) g[g[m][0]].erase(it1);
    
    auto it2 = find(g[g[m][1]].begin(), g[g[m][1]].end(), m);
    if(it2 != g[g[m][1]].end()) g[g[m][1]].erase(it2);
    
    dfs1(g[m][0], -1, 0);
    dfs2(g[m][1], -1, 0);
    
    for(auto& e : res){
        int a = e.first;
        int b = e.second;
        cout << a << " " << b <<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        Solve();
    }
    return 0;
}
