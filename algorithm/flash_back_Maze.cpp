#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int m[N][N], n;
vector<pair<int,int>> path;
bool flag;
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
bool visit[N][N];

void dfs(int x,int y){
    path.push_back({x,y});
    visit[x][y] = true;
    if(x == n-2 && y == n-2){
        flag = true;
        for(auto p : path){
            printf("(%d,%d)",p.first,p.second);
        }
    }
    int xx;int yy;
    for(int i=0;i<4;++i){
        xx = x + fx[i];
        yy = y + fy[i];
        if(!flag && xx >0 && yy > 0 && xx < n-1 && yy < n-1 &&visit[xx][yy] == false && m[xx][yy] == 0){
            dfs(xx,yy);
        }
    }
    path.erase(path.begin()+path.size()-1, path.begin() + path.size());
    visit[xx][yy] = false;
}

int main(){
    flag = false;
    memset(visit,false,sizeof visit);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;++j){
            scanf("%d",&m[i][j]);
        }
    }
    dfs(1,1);
    return 0;
}
