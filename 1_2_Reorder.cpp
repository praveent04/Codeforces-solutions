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
constexpr int INF = 1 << 30, MOD = 1e9 + 7;
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
        vector<int> arr(n + 2);
        int j=1;
        while(j<=n) {
            cin >> arr[j];
            j++;
        }

        vector<int> v(n + 2);
        v[n + 1] = 1;
        ll sum = 0;

        for (int i = n; i >= 1; --i) {
            if (arr[i] != 2) {
                int sub = 0;
                if (i + 1 <= n && arr[i + 1] == 2) {
                    sub = v[i + 1];
                }
                ll nxt = (sum - sub + MOD) % MOD;
                int a = (v[i + 1] + nxt) % MOD;
                v[i] =a;
                
            } else {
                v[i] = v[i + 1];
                sum = (sum + v[i]) % MOD;
            }
        }
        int i=1;
        while(i<=n) {
            if(i<n)
            cout << v[i] <<' ';
            else
            cout << v[i] <<endl;
            i++;
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