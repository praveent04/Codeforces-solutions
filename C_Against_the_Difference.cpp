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


struct S {
    int l, r, v;
    bool operator<(const S &o) const {
        return (r != o.r ? r < o.r : l < o.l);
    }
};

void Solve() {
    int n; cin >> n;
    vector<int> a(n);
    cin>>a;

    vector<vector<int>> p(n + 1);
    int i=0;
    while(i<n) {if (a[i] <= n) p[a[i]].push_back(i);i++;}

    vector<S> b;
    i = 1;
while (i <= n) {
    auto &x = p[i];
    int c = sz(x);
    if (c < i) {
        i++;        
        continue;
    }
    int j=i;
    while(j<=c)
        {b.push_back({x[j - i], x[j - 1], i});j++;}
    i++;
}


    if (b.empty()) {
        cout << 0 << endl;
        return;
    }

    sort(all(b));
   
    vector<int> L(sz(b)), R(sz(b)), W(sz(b));
    i=0;
    while(i<sz(b)) {
        L[i] = b[i].l;
        R[i] = b[i].r;
        W[i] = b[i].v;
        i++;
    }

    vector<int> v(sz(b) + 2, 0);
    i=1;
    while(i<=sz(b)) {
        int j = int(lower_bound(all(R), L[i - 1]) - R.begin());
        v[i] = max(v[i - 1], v[j] + W[i - 1]);
        i++;
    }

    cout << v[sz(b)] << endl;
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