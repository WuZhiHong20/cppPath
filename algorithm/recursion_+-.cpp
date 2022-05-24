//stoi一次可以处理多个字符，“123”->123
//substr(0,i)是开区间，不包括i
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

vector<int> Get(string s){
    vector<int> a;
    bool flag = false;
    for(int i=0;i<s.length();i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            flag = true;
            vector<int> b = Get(s.substr(0,i));
            vector<int> c = Get(s.substr(i+1));
            switch (s[i])
            {
            case '+':
                for(int i=0;i<b.size();i++)
                {
                    for(int j=0;j<c.size();j++){
                        a.push_back(b[i]+c[j]);
                    }
                }
                break;
            case '-':
                for(int i=0;i<b.size();i++)
                {
                    for(int j=0;j<c.size();j++){
                        a.push_back(b[i]-c[j]);
                    }
                }
                break;
            case '*':
                for(int i=0;i<b.size();i++)
                {
                    for(int j=0;j<c.size();j++){
                        a.push_back(b[i]*c[j]);
                    }
                }
                break;
            }
        }
    }
    if(flag == false){
        a.push_back(stoi(s));
        return a;
    }
    return a;
}

int main(){
    string s;
    cin>>s;
    vector<int> a  = Get(s);
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}