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
using namespace std;

using graph = std::vector<vector<int>>;

void dfs(graph &G, int now,int color,std::vector<int> &v,std::vector<bool> &has_come){
    v[now] = color;
    has_come[now] = true;
    for(auto i : G[now]){
        if(has_come[i]==true)continue;
        dfs(G,i,(color+1)%2,v,has_come);
    }
}

int main(void){
    int n;
    cin >> n;
    graph G(n);
    std::vector<bool> has_come(n,false);
    std::vector<int> color_vec(n,-1);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G,0,0,color_vec,has_come);
    
    // 0と1の数を数える
    long long int zero=0;
    long long int one=0;
    for(auto node : color_vec){
        if(node)one++;
        else zero++;
    }
    
    int num = 0;
    if(zero>=one){
        for(int i=0;i<n;i++){
            if(color_vec[i]==0){
                std::cout << i+1 << " ";
                num++;
            }
            if(num>=n/2)break;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(color_vec[i]==1){
                std::cout << i+1 << " ";
                num++;
            }
            if(num>=n/2)break;
        }
    }
    cout << endl;
    return 0;
}