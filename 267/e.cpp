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

int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    vector<vector<int>> adj_mat(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj_mat[u].push_back(v);
        adj_mat[v].push_back(u);
    }

    
    return 0;
}