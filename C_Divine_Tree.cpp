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

void Solve() {
    ll n, m;
    cin >> n >> m;
    int root = -1;
    if (m < n || m > n * (n + 1) / 2) {
        cout<<-1<<endl;
        return;
    }

    ll maxi = 0;
    if(n == 1) maxi = 1 ;
    else
    maxi = n + (n - 1) * n / 2;

    if (m < n || m > maxi) {
        cout<<-1<<endl;
        return;
    }

    

    for (int R = 1; R <= n; ++R) {
        if ((ll)(m - R )>= (ll)(n - 1) && (ll)(m - R )<= ((ll)(R - 1) * R / 2 + (ll)(n - R) * R)) {
            root = R;
            break;
        }
    }

    if (root == -1) {
        cout<<-1<<endl;
        return;
    }

    cout << root << endl;

    vector<pair<int,int>> e;

    vector<pair<ll, int>> g;
    for (int i = 1; i < n+1; ++i) {
        if (i != root) {
            g.push_back({(ll)min(i, root) - 1, i});
        }
    }

    sort(all(g), greater<pair<ll, int>>());

    ll del = (m - root) - (n - 1);

    vector<bool> cr(n + 1, false);

    for (const auto& p : g) {
        
        if (del >= p.first) {
            cr[p.second] = true;
            del -= p.first;
        }
    }

    
    vector<bool> un(n + 1, false);
    un[root] = true;
    int pn = -1;

    if (del != 0) {
        cout<<-1<<endl;
        return;
    }
    
    if (n > 1) {
        if (root != 1) {
            pn = 1;
        } else {
            for (int i = 2; i < n+1; ++i) {
                if (i != root) {
                    pn = i;
                    break;
                }
            }
        }
    }

    if (n > 1 && pn != -1 && pn != root) {
        e.push_back({root, pn});
        un[pn] = true;
    }

    if (n == 1) {
        return;
    }

    for (int i = 1; i < n+1; ++i) {
        if (i == root) continue;
        if (cr[i]) {
            if (!un[i]) {
                e.push_back({root, i});
                un[i] = true;
            }
        }
    }

    for (int i = 1; i < n+1; ++i) {
        if (i == root) continue;
        if(un[i]) continue;
        e.push_back({pn, i});
        un[i] = true;
    }

    for (const auto& it : e) {
        cout << it.first << " " << it.second << endl;
    }

    return;
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