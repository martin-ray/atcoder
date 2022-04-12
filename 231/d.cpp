#include<iostream>
#include<vector>
#include<queue>

class union_find{

    std::vector<int> parent;

public:
    //コンストラクタ
    union_find(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i; //すべて根
        }
    }

public:
    //ノードnの根探索
    int find_root(int n){
        if(parent[n]==n){
            return n;
        }
        else{
            return find_root(parent[n]);
        } 
    }

    //ノードaとノードbをマージ
    void merge(int a,int b){
        int ra = find_root(a);
        int rb = find_root(b);
        if(ra == rb){
            return ;
        }
        else{
            parent[ra] = rb;
        }
    }
    //ノードaとノードbが同じ根か判定
    bool is_same(int a,int b){
        return (find_root(a) == find_root(b));
    }



};

int main(void){

    int n,m;
    std::cin >> n >> m;

    union_find un(n);
    
    std::vector<int> a(m);
    std::vector<int> b(m);
    std::vector<int> ans(n,0);

    for(int i=0;i<m;i++){
        std::cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if(un.is_same(a[i],b[i])){
            std::cout << "No" <<std::endl;
            return 0;
        }
        else{
            un.merge(a[i],b[i]);
        }
        ans[a[i]]++;
        ans[b[i]]++;
    }

    long long int tmp = 0;

    for(int i=0;i<n;i++){
        if(ans[i]>=3){
            std::cout << "No" << std::endl;
            return 0;
        }
        tmp+=ans[i];
    }
    
    std::cout << "Yes" << std::endl;
}