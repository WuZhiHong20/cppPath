#include<iostream>
using namespace std;
    
const int N = 1e6+10;
int a[N], dp[N];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1] = a[1];
    cout<<dp[1]<<" ";
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1],a[i]+dp[i-2]);
        cout<<dp[i]<<" ";
    }
    return 0;
}