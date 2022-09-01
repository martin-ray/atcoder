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
        parent[a] = b; //どっちがどっちにくっついても同じや。と思っていたんだが、parent[b] = aにすると、union_findのグラフがどんどん大きくなって実行時間が増えてしまうんや。後から
        //後からくっついてくるやつをでかいやつにマージする感じで頼む。
    }

    // is in the same graph?
    bool same(int u, int v){
        if(root(u)==root(v))return true;
        return false;
    }

};

int main(void){

    int H,W;
    std::cin >> H >> W;

    // init board
    UnionFind UF(H*W);

    std::vector<std::vector<bool>> has_come(H,std::vector<bool>(W,false));

    int q;
    std::cin >> q;
    for(int i=0;i<q;i++){
        int t;
        std::cin >> t;
        if(t==1){
            int r,c;
            std::cin >> r >> c;
            r--;c--;
            has_come[r][c] = true;
            int hash1 = r*W+ c;
            int dx[4] = {-1,0,0,1};
            int dy[4] = {0,1,-1,0};
            for(int i=0;i<4;i++){
                if(r+dx[i]>=0&&c+dy[i]>=0&&r+dx[i]<H&&c+dy[i]<W){
                        if(has_come[r+dx[i]][c+dy[i]]==true){
                            int hash2 = (r+dx[i])*W + c+dy[i];
                            UF.unite(hash1,hash2);
                        }
                }
            }
        }
        else{
            int ra,ca,rb,cb;
            std::cin >> ra >> ca >> rb >> cb;
            ra--;ca--;rb--;cb--;
            int hash1 = ra*W+ca;
            int hash2 = rb*W+cb;
            if(has_come[ra][ca]==true&&has_come[rb][cb]==true){
                if(UF.same(hash1,hash2)){
                    std::cout << "Yes"<< std::endl;
                }else{
                    std::cout << "No" << std::endl;
                }
            }
            else{
                std::cout << "No" << std::endl;
            }

        }

    }
    return 0;
}