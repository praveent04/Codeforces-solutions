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

struct node {
    int l, r;
    bool f;
    
};

node check(int v, const vector<int>& a, int k) {
    int n = sz(a);
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + (a[i - 1] >= v ? 1 : -1);

    const ll INF = 4e18;
    ll minVal[2] = {INF, INF};
    int minIdx[2] = {-1, -1};

    for (int r = 1; r <= n; ++r) {
        int idx = r - k;
        if (idx >= 0) {
            int par = idx & 1;
            if (pref[idx] < minVal[par]) {
                minVal[par] = pref[idx];
                minIdx[par] = idx;
            }
        }

        int pr = r & 1;
        if (minIdx[pr] != -1 && pref[r] - minVal[pr] >= 0)
            return {true, minIdx[pr] + 1, r};

        int popp = pr ^ 1;
        if (minIdx[popp] != -1 && pref[r] - minVal[popp] >= 1)
            return {true, minIdx[popp] + 1, r};
    }
    return {false, -1, -1};
}

void Solve() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        cin >> a;

        int bestV = 1, bestL = 1, bestR = k;
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            node res = check(mid, a, k);
            if (res.f) {
                bestV = mid;
                bestL = res.l;
                bestR = res.r;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << bestV << ' ' << bestL << ' ' << bestR << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
