#include <bits/stdc++.h>
using namespace std;

constexpr int Mod = 1e9 + 7;

long long s(int n, vector<long long>& dp){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    long long ans = 0;
    for(int i = 1; i <= 6; i++){
        ans = (ans + s(n - i, dp)) % Mod;  // Apply modulo here
    }
    return dp[n] = ans;
}

void Solve(){
    int n;
    cin >> n;
    vector<long long> dp(n + 1, -1);  // Change to long long
    long long cnt = s(n, dp);
    cout << cnt << endl;  // No need for %Mod here as it's already applied
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        Solve();
    }
    return 0;
}
