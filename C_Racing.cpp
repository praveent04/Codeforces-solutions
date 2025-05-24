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

void print(int n, int j, vector<int>& ans){
     
        while(j<n) {
            int a =0;
            if(j == n-1){
                cout<<ans[j]<<endl;
            }
            else{
                cout<<ans[j]<<' ';
            }
            
            j++;
        }
}

void Solve(){
     int n; 
     cin >> n;
    vector<int> d(n);
    vector<int> l(n), r(n);
    vector<pair<int,int>> dp(n+1);

    cin>>d;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
 
    
    
 
        bool p = true;
        int i=1;
        dp[0] = {0, 0}; 
       while(i<= d.size()) {
            int Li = l[i-1], Ri = r[i-1];
            pair<int,int> prev = dp[i-1];
            int mini, maxi;
 
            if (d[i-1] == 1) {
              mini = prev.first + 1;
                maxi = prev.second + 1;
                
            } else if (d[i-1] == 0) {
                maxi = prev.second;
                mini = prev.first;
                
            } else {
                maxi = prev.second + 1;
                mini = prev.first;
                
            }

            maxi = min(maxi, Ri);
            mini = max(mini, Li);
            


            if (mini > maxi) {
                p = false;
                break;
            }
            dp[i] = {mini, maxi};
            i++;
        }
 
        if ( p == false) {
            int a =-1;
            cout << a << endl;
            return;
        }
 

        vector<int> ans(n);
        int h = dp[n].first; 

        i=n;
        while(i>=1) {
            pair<int,int> prev = dp[i-1];
 
            if (d[i-1] == 1) {
                ans[i-1] = 1;
                h -= 1;
            } else if (d[i-1] == 0) {
                ans[i-1] = 0;
                h -= 0;
            } else {
                if (!(h >= prev.first && h <= prev.second)) {
                    ans[i-1] = 1;
                    h -= 1;
                } else {
                    
                    ans[i-1] = 0;
                }
            }
            i--;
        }
 
        if (h != 0) {
            int a =-1;
            cout << a<< endl;
            return;
        }

        print(n,0,ans);
        
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