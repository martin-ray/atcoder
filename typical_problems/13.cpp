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

#define INF (long long int)1<< 60
using namespace std;
void my_dijkstra(std::vector<std::vector<std::pair<int, long long int>>> Graph, int start_node, std::vector<long long int>& dis){
    for(int i=0;i<Graph.size();i++)dis[i] = INF;
    std::priority_queue<std::pair<long long int,int>, std::vector<std::pair<long long int,int>>, greater<std::pair<long long int,int>>> pq;
    dis[start_node] = 0;
    pq.push(std::make_pair(dis[start_node],start_node));
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        int pos = p.second;
        for(int i=0;i<Graph[pos].size();i++){
            int to = Graph[pos][i].first;
            long long int cost = Graph[pos][i].second;
            if(dis[to] > dis[pos] + cost){
                dis[to] = dis[pos] + cost;
                pq.push(std::make_pair(dis[to],to)); 
            }
        }
    }
}
// ダイクストラ法を2回使うだけなんだけどね。
int main(void){

    int n,m;
    cin >> n >> m;
    std::vector<long long int> route1(n,INF);// 1からkまでの最短距離
    std::vector<long long int> route2(n,INF);// kからnまでの最短距離
    std::vector<std::vector<std::pair<int,long long int>>> adj_mat(n);//adj_mat[i] = ノードiから行けるノードの番号とその距離
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj_mat[a].push_back(make_pair(b,c));
        adj_mat[b].push_back(make_pair(a,c));
    }

    // shortest path from 0 to k
    my_dijkstra(adj_mat,0,route1);

    // shortest path from n to k
    my_dijkstra(adj_mat,n-1,route2);
    for(int i=0;i<n;i++){
        std::cout << route1[i] + route2[i] << std::endl;
    }
    return 0;
}