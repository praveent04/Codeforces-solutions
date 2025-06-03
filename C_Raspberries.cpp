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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    cin>>v;
    if(k==4){
        int a =0;
        int b = INT_MAX;
        int c =0;
        for(int i=0;i<n;i++){
            int rem = v[i]%4;
            if(rem==0){
                cout<<0<<endl;
                return;
            }
            if(v[i]%2==1){
                a++;
            }else if(v[i]%2==0){
                c++;
            }
            b = min(b,4-rem);
        }
        if(c>=2){
            cout<<0<<endl;
        }
        else if(a>0 && c>0){
            cout<<1<<endl;
        }
        else if(b==1){
            cout<<1<<endl;
        }
        else if(a>=2){
            cout<<2<<endl;
        }
        else{
            cout<<b<<endl;
        }
    }
    else{
        int a = INT_MAX;
        for(int i=0;i<n;i++){
            int rem = v[i]%k;
            if(rem==0){
                cout<<0<<endl;
                return;
            }
            a = min(k-rem,a);
        }
        cout<<a<<endl;
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