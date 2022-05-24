#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
int dp_left[N],dp_right[N];
int a[N];
int n;

int main(){
     cin>>n;
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
     for(int i=0;i<n;i++){
         dp_left[i] = dp_right[i] = 1;
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
             if(a[i] > a[j]){
                 dp_left[i] = max(dp_left[i], dp_left[j] + 1);
             }
         }
     }
     for(int i=n-1;i>=0;i--){
         for(int j=n-1;j>i;j--){
             if(a[i] > a[j]){
                 dp_right[i] = max(dp_right[i],dp_right[j]+1);
             }
         }
     }
     int max = 0;
     for(int i=0;i<n;i++){
        a[i] = dp_left[i]+dp_right[i];
        if(a[i] > max) max = a[i] - 1;
     }
     cout<<n - a[i];
    return 0;
}