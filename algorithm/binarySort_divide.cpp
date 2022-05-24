//二分法逼近
#include<iostream>
using namespace std;
const int N = 1e4+10;
int a[N];

int main(){
    double sum = 0, n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i] = a[i]*a[i];
        sum += a[i];
    }
    double min = 0.0, max = sum/m,mid;
    while(max - min >1e-5){
        mid = (min+max)/2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=(int)a[i]/mid;
        }
        if(cnt < m) max = mid;
        else min = mid;
    }
    printf("%.4f",min);
    return 0;
}
