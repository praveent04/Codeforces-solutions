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
    vector<int> v(n);
    cin>>v;
    
    vector<bool> c(n, false);
    
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        if(v[i] <= mini){
            mini = v[i];
            c[i] = true;
        }
    }
    
    int maxi = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        if(v[i] >= maxi){
            maxi = v[i];
            c[i] = true;
        }
    }
    
    string str = "";
    for(int i = 0; i < n; i++){
        str += (c[i] ? '1' : '0');
    }
    
    cout << str << endl;
}
//1 3 5 4 7 2 
//13 10 12 20
// 1 2 3 4 5 6 7
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