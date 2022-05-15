//二分法逼近
#include<iostream>
using namespace std;
const int N = 1e4+10;
int a[N];
int n,k;
int main(){
    cin>>k>>n; 
    int sum = 0;
    for(int i=0;i<k;i++){
        cin>>a[i];
        a[i] = a[i]*a[i];
        sum+=a[i];
    }
    double Min = 0,Max = sum/n;
    double mid;
    while(Max-Min > 1e-6){
        mid = (Max + Min)/2;
        int cnt = 0;
        for(int i=0;i<k;i++){
            cnt+= (int)a[i]/mid; 
        }
        if(cnt < n) Max = mid;
        else Min = mid;
    }
    printf("%.4f",Max);
    return 0;
}