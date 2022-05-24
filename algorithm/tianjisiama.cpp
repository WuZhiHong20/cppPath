/*
田忌赛马：
首先拿齐王和田忌最快的马进行对比，
若比不过，则让最慢的相比，若还比不过
让田忌最慢的和齐王最快的比，
若比不过，田忌胜场减一，
若平局，则平局
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int gang[N],zhi[N], n, m, money = 0;

int main(){
    while(cin>>n, n)
    {
        cin>>m;
        for(int i=0;i<n;++i){
            scanf("%d",&gang[i]);
        } 
        for(int i=0;i<n;++i){
            scanf("%d",&zhi[i]);
        } 
        sort(gang,gang+n);
        sort(zhi,zhi+n);
        reverse(gang,gang+n);
        reverse(zhi,zhi+n);
        int l1 = 0,l2 = 0,r1 = n-1,r2 = n-1, cnt = 0;
        while(l1<=r1){
            if(zhi[l1] > gang[l2]){
                ++cnt;
                ++l1;
                ++l2;
            }
            else if(zhi[r1] > gang[r2]){
                ++cnt;
                --r1;
                --r2;
            }
            else if(zhi[r1] == gang[l2]){
                --r1;
                ++l2;
            }
            else{
                --cnt;
                --r1;
                ++l2;
            }
        }
        cout<<m*cnt<<endl;
    }
    return 0;
}