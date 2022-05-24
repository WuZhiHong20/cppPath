#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    m = 2*n;
    int x,y;
    vector<vector<int>> a(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = x-y;
    }
    sort(a.begin(),a.end(),[](vector<int> a, vector<int> b){
        return a[2] < b[2];
    });
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i][0] + a[n+i][1];
    }
    cout<<sum;
    return 0;
}