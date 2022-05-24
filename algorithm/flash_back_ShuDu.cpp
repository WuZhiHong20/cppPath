/*
数独游戏
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。

数字 1-9 在每一列只能出现一次。

数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

数独部分空格内已填入了数字，空白格用 '.' 表示。
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 9;
bool row[N][N],column[N][N],block[3][3][N];
vector<pair<int,int>> a;
bool done;

void dfs(vector<vector<char>>& num, int pos){
    if(pos == a.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;++j){
                printf("%c",num[i][j]);
            }
            printf("\n");
        }
        done = true;
    }
    int i = a[pos].first, j = a[pos].second; 
    for(int k = 0;k<9 && !done;k++){
        if(!row[i][k] && !column[j][k] && !block[i/3][j/3][k]){
            row[i][k] = column[j][k] = block[i/3][j/3][k] = true;
            num[i][j] = k + '0' + 1;
            dfs(num,pos+1);
            row[i][k] = column[j][k] = block[i/3][j/3][k] = false;
        }
    }
}

void solve(vector<vector<char>>& num){
    memset(row, false, sizeof(row));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    int x,y;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(num[i][j] == '.'){
                a.push_back({i,j});
            }
            else{
                x = num[i][j] - '0' - 1;
                row[i][x] = column[j][x] = block[i/3][j/3][x] = true;
            }
        }
    }
    dfs(num,0);
    return;
}

int main(){
    vector<vector<char>> num(9,vector<char>(9,0));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>num[i][j];
        }
    }
    solve(num);
    return 0;
}
