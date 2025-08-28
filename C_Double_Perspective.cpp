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

struct D {
    vector<int> fa;
    D(int N)   {
        fa = vector<int>(N+2);
    for(int i = 0; i < int(fa.size()); ++i)
        fa[i] = i;
}

    int get(int x) { return fa[x]==x?x:fa[x]=get(fa[x]); }
    bool join(int u, int v) {
        u = get(u); v = get(v);
        if(u==v) return 0;
        fa[v]=u; return 1;
    }
};

void Solve(){
    int n; cin >> n;
    struct s{ int u, v, d, i; };
    vector<s> ed(n);
    int mx = 0;
    int i=0;
    while(i<n) {
        int x, y;
        cin >> x >> y;
        ed[i] = {x, y, y-x, i+1};
        mx = max(mx, max(x, y));
        i++;
    }
    sort(all(ed), [](const s& a, const s& b){ return a.d > b.d; });

    D dsu(mx); 
    vector<int> res;
    for(auto &e : ed) {
        if(dsu.join(e.u, e.v)) res.push_back(e.i);
    }
    cout << sz(res);
    cout<<endl;
    i=0;
    while(i<sz(res))
        {cout << res[i] ;
            if(i+1 == sz(res))
            cout<<endl;
            else
            cout<<' ';
            i++;
         }
         
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int _ = 0; _ < t; ++_) {
        Solve();
    }
    return 0;
}
