#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 305;
double dp[N];
int n;

int main(){
    cin>>n;
    if(n == 0){
        cout<<0;
        return 0;
    }
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int k = 0;k<=i;k++){
            dp[i] = min(dp[i], 2*dp[i-k] + pow(2,k) - 1);
        }
    }
    cout<<dp[n];
    return 0;
}