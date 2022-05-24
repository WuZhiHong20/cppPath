#include<iostream>
using namespace std;

const int N = 70;
long long a[N];

void init(){
    a[0] = 0;
    for(int i=1;i<65;i++){
        a[i] = a[i-1]*2 + 1; 
    }
}

long long cal(long long x){
	if(x==0) return 0;
    long long sum = 0;
    for(int i=0; i<=65;i++){
        if(a[i] == x) return a[i]/2 + 1;
        if(a[i] > x){
            sum += x - a[i-1];
            sum += cal(a[i] - x);
            break;
        }
    }
    return sum;
}

int main(){
    init();
    int t;
    long long l,r;
    cin>>t;
    while(t--){
        scanf("%lld%lld",&l,&r);
        cout<<cal(r) - cal(l-1)<<endl;
    }
    return 0;
}
