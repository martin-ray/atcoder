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

int main(void){

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj_list(n,std::vector<int>());

    for(int i=0;i<n-1;i++){
        int a,b;
        std::cin >> a >> b;
        a--;b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    std::vector<bool> has_come(n,false);
    std::vector<int> dist_from_zero(n,-1);
    int start = 0;
    std::queue<std::pair<int,int>> q; // node, dist
    q.push(std::make_pair(start,0));
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        has_come[node]=true;
        for(int i=0;i<adj_list[node].size();i++){
            if(!has_come[adj_list[node][i]]){
                q.push(std::make_pair(adj_list[node][i],dist+1));
                dist_from_zero[adj_list[node][i]] = dist+1;
            }
        }
        q.pop();
    }

    // 最も遠い点
    int most_far_node=-1;
    int dis = 0;
    for(int i=0;i<n;i++){
        if(dist_from_zero[i] > dis){
            dis = dist_from_zero[i];
            most_far_node = i;
        }
    }

    // もう一度
    start = most_far_node;
    for(int i=0;i<n;i++)has_come[i] = false;
    q.push(std::make_pair(start,0));
    int most_far = 0;
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        has_come[node] = true;
        for(int i=0;i<adj_list[node].size();i++){
            if(!has_come[adj_list[node][i]]){
                q.push(std::make_pair(adj_list[node][i],dist+1));
            }
        }
        q.pop();
        if(most_far < dist)most_far = dist;
    }
    std::cout << most_far+1 << std::endl;

    return 0;
}