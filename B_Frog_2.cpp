#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[100001];
int dp[100001];
int rec(int ind){
    if(ind==n-1)return 0;
    int ans = INT_MAX;
    if(dp[ind] !=-1) return dp[ind];
    for(int i=1;i<=k;i++){
        if(ind+i<n){
            ans= min(ans,abs(arr[ind+i] - arr[ind])+ rec(ind+i));
        }
    }
    return dp[ind]= ans;
}
int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0)<<endl;
    return 0;
}