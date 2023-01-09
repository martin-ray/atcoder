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

    vector<bool> visited(n,false);
    int ans = 0;


    for(int i=0;i<n;i++){
        if(visited[i])continue;

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            auto now = q.front();q.pop();
            for(auto next : adj_list[now]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}