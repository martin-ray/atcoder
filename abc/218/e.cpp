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


struct UnionFind {  // The range of node number is u 0 v n-1
    vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findRoot(int x) {
        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};

// 辺の定義
struct Edge {
    long long u;
    long long v;
    long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/


int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    UnionFind uf(V);

    for (int i = 0; i < E; i++) {
        long long s, t, w;
        cin >> s >> t >> w;
        s--;t--;
        Edge e = {s, t, w};
        edges[i] = e;
    }

    long long int ans = 0;
    sort(edges.begin(), edges.end(), comp_e);

    for(auto e : edges){
        if(e.cost < 0){
            uf.unite(e.v,e.u);
            continue;
        } else {
            if(uf.isSame(e.u,e.v)){
                ans += e.cost;
                continue;
            } else {
                uf.unite(e.v,e.u);
            }
        }
    }

    cout <<  ans << endl;

    return 0;
}