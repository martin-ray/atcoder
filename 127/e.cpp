#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<queue>

using namespace std;

int main(void){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> node(n);
    vector<bool> is_revealed(n,false);
    map<int,int> card_info;

    int x,y,z;
    for(int i=0;i<m;i++){
        cin >> x >> y >> z;
        x--;
        y--;
        node[x].push_back(y);
        node[y].push_back(x);
        card_info[x]++;
        card_info[y]++;
    }


    int ans = 0;

    while(card_info.size()!=0){
        queue<int> q;
        q.push((card_info.rbegin()->first));
        ans++;
        while(!q.empty()){
            int next = q.front();
            q.pop();
            is_revealed[next] = true;
            card_info.erase(next);
            for(int i=0;i<node[next].size();i++){
                if(is_revealed[node[next][i]]!=true){
                    q.push(node[next][i]);
                }

            }
        }
    }

    //最後に、与えられた情報だけでは明らかにならなかったカードは一個づつ明らかに
    for(int i=0;i<n;i++){
        if(is_revealed[i]==false){
            ans++;
        }
    }
    cout << ans << endl;

    
    return 0;
}