#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    while(k--){
        for(int i=0;i<s.size();i++){
            if(s[i] < s[i-1]){
                s = s.substr(0,i-1) + s.substr(i,s.size());
                break;
            }
            if(i == s.size() - 1){
                s = s.substr(0,i);
            }
        }
    }
    if(s.size()	){
    	int i = 0;
		while(s[i] == '0') i++;
		if(i == s.size()){
			cout<<0;
			return 0;
		}
		while(i<s.size()){
			cout<<s[i++];
		}
	}
    else{
    	cout<<0;
	}
    return 0;
}
