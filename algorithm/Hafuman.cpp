#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int main(){
    int n,x, a,b;
    cin>>n;
    priority_queue<int, vector<int> , greater<int>> q;
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        q.push(x);
    }
    long sum = 0;
    while(q.size()>1){
        a = q.top();q.pop();
        b = q.top();q.pop();
        sum += a+b;
        q.push(a+b);
    }
    cout<<sum<<endl;
}
