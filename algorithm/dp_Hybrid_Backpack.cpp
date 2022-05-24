#include<iostream>
#include<vector>
using namespace std;
class things{
public:
    int v,w,s;
    things(int vi,int wi, int si){
        v = vi; w = wi; s = si;
    }
    void print(){
        printf("%d %d %d\n",v,w,s);
    }
};
const int N = 1010;
vector<things> a;
int n, m, f[N];

int main(){
    int v,w,s;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v,&w,&s) ;
        if(s > 0){
            for(int j = 1;j<=s;j*=2){
                s-=j;
                a.push_back(things(v*j,w*j,-1));
            }
            if(s>0){
                a.push_back(things(v*s,w*s,-1));
            }
        }
        else a.push_back(things(v,w,s));
    }
    for(auto obj : a){
        if(obj.s == 0){
            for(int i = obj.v;i<=m;i++){
                f[i] = max(f[i], f[i - obj.v] + obj.w);
            }
        }
        else{
            for(int i = m; i>=obj.v;i--){
                f[i] = max(f[i], f[i - obj.v] + obj.w);
            }
        }
    }
    cout<<f[m];
    return 0;
}
