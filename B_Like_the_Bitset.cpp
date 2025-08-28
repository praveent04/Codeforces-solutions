#include <bits/stdc++.h>
using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
template < typename T = int > using P = pair<T, T>;
vector<string> ANS = {"NO", "YES"};

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;

    int c = 0, x = 0;
    for (char ch : s) {
        if (ch == '1') {
            ++c;
            if (c >= k) { x = 1; break; }
        } else c = 0;
    }

    if (x) { cout << "NO"<<endl; return; }
    cout << "YES"<<endl;

    vector<int> p(n), z, o;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z.push_back(i);
        else o.push_back(i);
    }

    int v = n;
    int i=0;
    while(i<(int)z.size()) {p[z[i]] = v--;i++;}
    i=0;
    while(i<(int)o.size()) {p[o[i]] = v--;i++;}
    i=0;
    while(i<n) {
        if (i) cout << ' ';
        cout << p[i];
        i++;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
