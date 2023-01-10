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

long long int N,M,K,S,T,X;
long long int ans = 0;
long long int md = 998244353;

// 一回深さ優先で全探索してみる
void dfs(vector<vector<int>>& graph, int rest, int now, int x_pass_time){
    if(now == X) x_pass_time++;

    if(rest == 0){
        if(x_pass_time%2 == 0 && now == T){
            ans++;
            ans%=md;
        }
    } else {
        for(auto next : graph[now]){
            dfs(graph,rest-1,next,x_pass_time);
        }
    }
}

int main(void){

    cin >> N >> M >> K >> S >> T >> X; S--;T--;X--;
    vector<vector<int>> graph(N,vector<int>());

    // dp[k][n][f] := k解移動した時にノードnにいるときにxをf回通った時の通り数
    vector<vector<vector<long long int>>> dp(K+1,vector<vector<long long int>>(N,vector<long long int>(2,0)));

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 初期化
    dp[0][S][0] = 1;
    dp[0][S][1] = 0;

    for(int k = 0;k < K; k++){
        for(int node = 0; node < N ; node++){
            for(int guki = 0;guki < 2;guki++){
                if(node == X){
                    for(auto adj : graph[node]){
                        dp[k+1][node][(guki+1)%2] += dp[k][adj][guki]%md;
                    } 
                } else {
                    for(auto adj : graph[node]){
                        dp[k+1][node][guki] += dp[k][adj][guki]%md;
                    }
                }
            }
        } 
    }


    cout << dp[K][T][0]%md << endl;

    return 0;
}