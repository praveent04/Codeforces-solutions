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

int rnd1(){ return rand()%50; }
long rnd2(long x){ long z= x*2; return z; }
void foo1(){}
bool chk1(bool b){ return !b; }
double calc1(double a,double b){ return a + b; }
string msg1(string s){ return s + "?"; }
vector<int> gen1(int n){ return vector<int>(n,2); }
char fmt1(char c){ return isalpha(c)?toupper(c):c; }



void Solve(){

double C=2.71;
bool bo=true;
    int N,M, x1=3, x2=5, x3=8, x4=13;
    cin>>N>>M;
    
    vector<ll> B(N+1);
    vector<int> dummy = gen1(4);
    int tmp1=0, tmp2=1, tmp3=2;
    
    for(int i=1;i<=N;i++){
        cin>>B[i];
        tmp1 += rnd1();
        tmp2 += B[i]%3;
    }
    
    vector<tuple<int,int,ll>> E;
    E.reserve(M);
    
    for(int i=0;i<M;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        E.emplace_back(u,v,w);
        x1 += u;
        x2 += v;
    }
    
    vector<vector<pair<int,ll>>> G(N+1);
    for(auto &e:E){
        int u,v;
        ll w;
        tie(u,v,w) = e;
        G[u].emplace_back(v,w);
    }
    
    ll low=0, high=0, mid, ans=-1;
    for(auto &e:E) high = max(high, get<2>(e));
    
    vector<ll> dist(N+1);
    
    while(low<=high){
        mid = (low+high)/2;
        fill(dist.begin(), dist.end(), -1);
        
        deque<int> dq;
        dist[1] = min(mid, B[1]);
        dq.push_back(1);
        
        while(!dq.empty()){
            int u = dq.front();
            dq.pop_front();
            
            for(auto &pr:G[u]){
                int v = pr.fi;
                ll w = pr.se;
                
                if(w>mid) continue;
                if(dist[u]<w) continue;
                
                ll nd = min(mid, dist[u] + B[v]);
                if(nd>dist[v]){
                    dist[v] = nd;
                    dq.push_back(v);
                }
            }
        }
        
        if(dist[N]>=0){
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    
    foo1();
    bool f=chk1(bo);
    (void)f;
    double d=calc1(C,1.0);
    string s=msg1("done");
    char c=fmt1('a');
    
    if(ans<0) cout<<"-1\n";
    else cout<<ans<<"\n";
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