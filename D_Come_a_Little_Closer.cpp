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
        vector<pair<ll, ll>> a(n);
        unordered_map<ll, int> xc, yc;
        vector<ll> xv, yv;

        int i =0;
        while(i<n) {
            ll x,y;
            cin >> x >> y;
            a[i].first =x;
            a[i].second =y;
            i++;
            xc[x]++;
            yc[y]++;
            xv.push_back(x);
            yv.push_back(y);
            
        }
        sort(xv.begin(), xv.end());
        sort(yv.begin(), yv.end());
        ll area =( xv[n - 1] - xv[0] + 1) * (yv[n - 1] - yv[0] + 1);
        ll ans = area;
        if (n == 1) {
            cout << "1"<<endl;
            return;
        }

         i=1;
        while(i<=n) {
            ll xi = a[i-1].first, yi = a[i-1].second;
            i++;
            ll mininx = (xi == xv[0] && xc[xv[0]] == 1) ? xv[1] : xv[0];
            ll maxinx = (xi == xv[n - 1] && xc[xv[n - 1]] == 1) ? xv[n - 2] : xv[n - 1];
            ll mininy = (yi == yv[0] && yc[yv[0]] == 1) ? yv[1]: yv[0];
            ll maxiny = (yi == yv[n - 1] && yc[yv[n - 1]] == 1) ? yv[n - 2] : yv[n - 1];
 
            ll area = (maxinx - mininx + 1) * (maxiny - mininy + 1);
            if (area == n - 1) 
            area += min((maxinx - mininx + 1), (maxiny - mininy + 1));
            ans = min(ans, area);
        }
 
        cout << ans <<endl;
    
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