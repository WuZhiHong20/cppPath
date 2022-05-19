//求逆序数，跟归并排序一模一样
#include<iostream>
#include<string>
using namespace std;
int cnt;
int res = 0;
const int N = 6e4+10;
int t[N],s[N];
void change(string s){
    cnt = 0;
    for(int i=0;i<s.length();){
        if(s[i] == ','){
            i++;
            continue;
        }
        int sum = 0;
        while(s[i]!=',' && i<s.length()){
            sum = sum*10 + s[i] - '0';  
            i++;
        }
        t[cnt++] = sum;
    }
}

void merge(int l,int r){
    if(l>=r) return;
    int mid = (l+r)>>1;
    merge(l,mid);merge(mid+1,r);

    int i = l,j = mid + 1, k = 0;
    while(i<=mid && j<=r)
    {
        if(t[i] > t[j]){
            res+=mid - i + 1;
            s[k++] = t[j++]; 
        }
        else{
            s[k++] = t[i++];
        }
    }
    while(i<=mid){
        s[k++] = t[i++];
    }
    while(j<=r){
        s[k++] = t[j++];
    }
    for(int i = l,k = 0;i<=r;i++,k++) t[i] = s[k];
}

int main(){
    string s;
    cin>>s;
    change(s);
    merge(0,cnt-1);
    cout<<res;
    return 0;
}