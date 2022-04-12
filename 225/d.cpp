#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

class union_find{

    std::vector<int> parent;
    std::vector<int> child;

public:
    //コンストラクタ
    union_find(int n){
        parent.resize(n);
        child.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i; //すべて根
            child[i] =-1;//最初はだれもいない
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
    //この問題では、
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
    void connect(int x,int y){
        parent[y] = x;
        child[x] = y;
        //cout << x << "+" << y << endl;
    }

    void disconnect(int x,int y){
        parent[y] = y;
        child[x] = -1;
        //cout << x << "-" << y << endl;
    }
    //ノードaとノードbが同じ根か判定
    bool is_same(int a,int b){
        return (find_root(a) == find_root(b));
    }

    void print_train(int x){
        int i = find_root(x);//先頭
        vector<int> tmp;
        tmp.push_back(i);
        while(child[i]!=-1){
            i = child[i]; 
            tmp.push_back(i);
        }
        cout << tmp.size() <<" ";
        for(int i=0;i<tmp.size();i++){
            cout << tmp[i] + 1 << " ";
        }
        cout << endl;
    }
    



};


int main(void){

    int n,q;
    cin >> n >> q;

    int num,x,y;

    union_find train(n);

    for(int i=0;i<q;i++){
        cin >> num;
        if(num==1){
            cin >> x >> y;
            x--;y--;
            train.connect(x,y);
        }
        else if(num==2){
            cin >> x >> y;
            x--;y--;
            train.disconnect(x,y);
        }
        else{
            cin >> x;
            x--;
            train.print_train(x);
        }

    }
    
    return 0;
}