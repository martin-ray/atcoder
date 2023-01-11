#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include <iomanip>
#include<queue> //do not forget about priority_queue;
//std::cout << std::setprecision(2) << 3.141; // "3.1"
#define MOD 1000000007
using namespace std;


vector<vector<char>> crop(vector<vector<char>> grid,int n){
    int w_min=n-1,w_max=0,h_min=n-1,h_max=0;

    // find w_min
    for(int h=0;h<n;h++){
        for(int w=0;w<n;w++){
            if(grid[h][w] == '#' && w < w_min){
                w_min = w;
            }
        }
    }

    // find w_max
    for(int h=0;h<n;h++){
        for(int w=0;w<n;w++){
            if(grid[h][w] == '#' && w > w_max){
                w_max = w;
            }
        }
    }

    // find h_min
    for(int h=0;h<n;h++){
        for(int w=0;w<n;w++){
            if(grid[h][w] == '#' && h > h_max){
                h_max = h;
            }
        }
    }

    // find w_max
    for(int h=0;h<n;h++){
        for(int w=0;w<n;w++){
            if(grid[h][w] == '#' && h < h_min){
                h_min = h;
            }
        }
    }

    vector<vector<char>> cropped_grid(h_max-h_min+1,vector<char>(w_max-w_min+1));
    
    for(int h=h_min;h<=h_max;h++){
        for(int w=w_min;w<=w_max;w++){
            // cout << h << " " << w << endl;
            cropped_grid[h-h_min][w-w_min] = grid[h][w];
        }
    }

    return cropped_grid;

}


vector<vector<char>> rotate(vector<vector<char>> grid){
    vector<vector<char>> t_grid(grid[0].size(),vector<char>(grid.size()));
    vector<vector<char>> rotated_grid(grid[0].size(),vector<char>(grid.size()));

    
    // 転置
    for(int i=0;i<grid[0].size();i++){
        for(int j=0;j<grid.size();j++){
            t_grid[i][j] = grid[j][i];
        }
    }

    // 上下逆
    for(int i=0;i<grid[0].size();i++){
        for(int j=0;j<grid.size();j++){
            rotated_grid[i][j] = t_grid[grid[0].size() - i - 1][j];
        }
    }

    return rotated_grid;
}

bool Issame(vector<vector<char>> grid_s,vector<vector<char>> grid_t){

    for(int i=0;i<grid_s.size();i++){
        for(int j=0;j<grid_s[0].size();j++){
            if(grid_s[i][j] != grid_t[i][j])return false;
        }
    }

    return true;    
}

int main(void){

    int n;
    cin >> n;

    vector<vector<char>> grid_s(n,vector<char>(n));

    vector<vector<char>> grid_t(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid_s[i][j];
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid_t[i][j];
        }
    }

    vector<vector<char>> c_grid_t = crop(grid_t,n);
    vector<vector<char>> c_grid_s = crop(grid_s,n);

    for(int k=0;k<4;k++){
        c_grid_s = rotate(c_grid_s);
        if(!(c_grid_t.size() == c_grid_s.size() && c_grid_t[0].size() == c_grid_s[0].size()))continue;
        
        if(Issame(c_grid_s,c_grid_t)){
            cout << "Yes" << endl;
            return 0;
        }

    }

    cout << "No" << endl;
    return 0;
}