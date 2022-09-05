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


using graph = std::vector<std::vector<int>>;

std::vector<bool> has_come;
std::vector<bool> has_come2;
std::vector<int> last_v; 
std::vector<int> first_v;

void dfs(graph &G, int node, int &first_ptr, int &last_ptr){
    has_come[node] = true;
    first_v[node] = first_ptr++;
    for(auto next : G[node]){
        if(has_come[next]==true)continue;
        dfs(G,next,first_ptr,last_ptr);
    }
    last_v.push_back(node);
}

void dfs2(graph &G, int node, int &first_ptr, int &last_ptr,long long int &t_tmp){
    has_come2[node] = true;
    t_tmp++;
    for(auto next : G[node]){
        if(has_come2[next]==true)continue;
        //std::cout << node << " to " << next << " " << std::endl;
        dfs2(G,next,first_ptr,last_ptr,t_tmp);
    }
}

int main(void){
    int n,m;
    std::cin >> n >> m;
    graph G(n);
    graph inv_G(n);
    has_come.assign(n,false);
    has_come2.assign(n,false);
    last_v.assign(n,0);
    first_v.assign(n,0);

    int first_ptr=0;
    int last_ptr=0;

    for(int i=0;i<m;i++){
        int a,b;
        std::cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        inv_G[b].push_back(a);
    }

    // 1回目で帰りがけ順で番号をつけるlast_v
    for(int i=0;i<n;i++){
        if(has_come[i]==true)continue;
        dfs(G,i,first_ptr,last_ptr);
    }

    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;

    // 2回目で強連結成{分分解
    long long int t_tmp=0;
    long long int ans=0;
    std::reverse(last_v.begin(),last_v.end());
    for(auto v: last_v){
        if(has_come2[v]==true)continue;
        dfs2(inv_G,v,first_ptr,last_ptr,t_tmp);
        // std::cout << t_tmp << std::endl;
        ans+= t_tmp*(t_tmp-1)/2;
        t_tmp=0;
    }

    std::cout << ans << std::endl;
    return 0;
}