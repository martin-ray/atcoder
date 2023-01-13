#include<vector>
#include<iostream>

class UnionFind{
public:
    std::vector<int> parent;
    
    // constructor
    UnionFind(int num_nodes){
        parent.resize(num_nodes,-1);
    }

    // find root node of "node"
    int root(int node){
        if(parent[node]==-1)return node;
        int p = parent[node];
        return root(p);
    }

    // unite b to a 
    void unite(int a, int b){
        a = root(a);b = root(b);
        if(a==b)return;
        parent[b] = a; //どっちがどっちにくっついても同じや
    }

    // is in the same graph?
    bool same(int u, int v){
        if(root(u)==root(v))return true;
        return false;
    }

};


// TLEを起こさない晩


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