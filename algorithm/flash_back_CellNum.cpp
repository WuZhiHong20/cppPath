#include<bits/stdc++.h>
using namespace std;

const int N = 110;
bool visit[N][N];
int row,column;
string s;
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};

void dfs(vector<vector<int>>& a,int x, int y){
    int xx ,yy;
    for(int i=0 ;i<4;++i){
        xx = x + fx[i];
        yy = y + fy[i];
        if(xx>=0 && xx<row && yy>=0 && yy<column && a[xx][yy] != 0 && visit[xx][yy] == false){
            visit[xx][yy] = true;
            dfs(a,xx,yy);
        }
    }
}

int main(){
    memset(visit, false, sizeof(visit));
    cin>>row>>column;
    vector<vector<int>> a(row,vector<int>(column,0));
    for(int i=0;i<row;++i){
        cin>>s;
        for(int j=0; j<column; ++j){
            a[i][j] = s[j] - '0';
        }
    } 
    for(int i=0;i<row;i++){
        for(int j=0;j<column;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int cnt = 0;
    for(int i = 0;i<row;++i){
        for(int j = 0;j<column; ++j){
            if(a[i][j] != 0 && visit[i][j] == false){
                cnt++;
                visit[i][j] = true;
                dfs(a,i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
