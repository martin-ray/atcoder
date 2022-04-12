#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

int h,w;
int max_step = 0;

void dfs(vector<vector<char>>& grid,int x,int y,int step){

    if(step > max_step){
        max_step = step;
    }    
    if(x+1 < h){
        if(grid[x+1][y]=='.'){
            dfs(grid,x+1,y,step+1);
            grid[x+1][y] = '#';
        }
    }
    if(y+1 < w){
        if(grid[x][y+1]=='.'){
            dfs(grid,x,y+1,step+1);
            grid[x][y+1] = '#';
        }
    }
}

int main(void){
    cin >> h >> w;
    vector<vector<char>> grid(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> grid[i][j];
        }
    }
    dfs(grid,0,0,0);
    cout << max_step + 1 << endl;
    return 0;
}