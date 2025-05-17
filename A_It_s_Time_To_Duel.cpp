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
        int m = n - 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> ass(m + 1, -1);
        vector<vector<int>> imp(m + 1);
        vector<pair<int, bool>> un;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (i > 1) un.emplace_back(i - 1, true);
                if (i < n) un.emplace_back(i, false);
            } else {
                if (i == 1) {
                    un.emplace_back(1, true);
                } else if (i == n) {
                    un.emplace_back(n - 1, false);
                } else {
                    imp[i - 1].push_back(i);
                }
            }
        }
        
        deque<pair<int, bool>> dq;
        for (auto &u: un) dq.push_back(u);
        bool bad = false;
        while (!dq.empty() && !bad) {
            auto p = dq.front();
            dq.pop_front();
            int v = p.first;
            bool val = p.second;
            if (ass[v] != -1) {
                if (ass[v] != (val ? 1 : 0)) {
                    bad = true;
                }
                continue;
            }
            ass[v] = val ? 1 : 0;
            if (val) {
                for (int to : imp[v]) {
                    dq.emplace_back(to, true);
                }
            }
        }
        if(bad){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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