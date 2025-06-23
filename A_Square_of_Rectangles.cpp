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



bool Lsh(int l1, int b1, int l2, int b2, int l3, int b3) {
    
   
}

void Solve(){
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) {cout << "YES" << endl;
        return ;}
    
    if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) {cout << "YES" << endl;
    return;}

     int S = max(l1, b1);
    if ((l1 == S && b2 == b3 && b1 + max(b2, b3) == S && l2 + l3 == S) ||
        (b1 == S && l2 == l3 && l1 + max(l2, l3) == S && b2 + b3 == S))
        {cout << "YES" << endl;
        return;}

    S = max(l2, b2);
    if ((l2 == S && b1 == b3 && b2 + max(b1, b3) == S && l1 + l3 == S) ||
        (b2 == S && l1 == l3 && l2 + max(l1, l3) == S && b1 + b3 == S))
        {cout << "YES" << endl;
        return;}

    S = max(l3, b3);
    if ((l3 == S && b1 == b2 && b3 + max(b1, b2) == S && l1 + l2 == S) ||
        (b3 == S && l1 == l2 && l3 + max(l1, l2) == S && b1 + b2 == S))
        {cout << "YES" << endl;
        return;}

        cout << "NO" << endl;
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
