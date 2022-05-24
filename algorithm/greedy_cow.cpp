#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,x,y;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(3,0));
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = x+y;
    }
    sort(a.begin(),a.end(),[](vector<int> a,vector<int> b){
        if(a[2]!=b[2]) return a[2]<b[2];
        return a[1]<b[1];
    });
    long sum = 0, res = -1e9;
    for(int i=0;i<n;++i){
        sum -= a[i][1];
        res = max(res,sum);
        sum+=a[i][2];
    }
    cout<<res<<endl;
    return 0;
}