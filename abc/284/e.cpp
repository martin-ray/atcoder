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

int ans = 0;

void dfs(const vector<vector<int>>& graph,bool visited[],int now){
    for(auto next : graph[now]){
        if(visited[next])continue;
        visited[next] = true;
        ans++;
        if(ans>1000000){
            cout << 1000000 << endl;
            exit(0);
        }
        dfs(graph,visited,next);
        visited[next] = false;
    }
    return;
}

long long int my_min(long long int a , long long int b){
    return a > b ? b : a;
}


int main(void){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;u--;v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // vector<bool> visited(n,false);
    bool visited[n];
    for(int i=0;i<n;i++)visited[i]=false;
    visited[0] = true;

    dfs(adj_list,visited,0);

    cout << my_min(ans + 1,1000000) << endl;

    return 0;
}