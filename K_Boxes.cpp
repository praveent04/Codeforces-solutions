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
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    cin >> A >> B;

    vector<int> v(N + 1);
    for (int i = 0; i < N; ++i) {
        v[A[i]] = i;
    }

    vector<ll> ans(N);
    priority_queue<ll, vector<ll>, greater<ll>> pq;  
    ll cnt = 0;

    for (int i = 1; i <= N; ++i) {
        int j = v[i];
        ans[j] = cnt;
        
        if ((int)pq.size() < K) {
            pq.push(B[j]);
            cnt += B[j];
        } else if (K > 0 && !pq.empty()) { 
            if (pq.top() < B[j]) {
                cnt -= pq.top();
                pq.pop();
                pq.push(B[j]);
                cnt += B[j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i];
        if(i < N-1) cout << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        Solve();
    }
    return 0;
}