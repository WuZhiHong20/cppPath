#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5+10;
int a[N], n, b[N], c[N];

int main(){
    cin>>n;
  	if(n == 0){
      cout<<0<<endl;
      return 0;
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
  if(n == 1){
    cout<<a[1]<<endl;
    return 0;
  }
    b[1] = a[1];
    for(int i = 2;i<=n-1; ++i){
        b[i] = max(b[i-2] + a[i], b[i-1]);
    }
    c[2] = a[2];
    for(int i = 3;i<=n;i++){
		c[i] = max(a[i] + c[i-2] , c[i-1]);
    }
    if(c[n] > b[n-1]) cout<<c[n]<<endl;
    else cout<<b[n-1]<<endl;
    return 0;
}
