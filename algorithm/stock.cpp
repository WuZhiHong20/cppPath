#include<iostream>
using namespace std;

const int N = 1e5+10;
int a[N], op, ed;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int money = 0;
    op = 0; ed = 1;
    while(ed < n && op <n){
        while(a[ed] >= a[ed-1]){
            ed++;
        }
        money+=a[ed-1]-a[op];
        op = ed;
        ed++;
    }
    cout<<money<<endl;
    return 0;
}