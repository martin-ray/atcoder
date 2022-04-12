#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> takahasi(n);
    vector<vector<int>> aoki(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        takahasi[a].push_back(b);
        takahasi[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        aoki[a].push_back(b);
        aoki[b].push_back(a);
    }    

    vector<int> one_case;
    for (int i = 0; i < n; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    //探索    
    do {
        for (auto num : one_case) {
            //cout << num << " ";
        }
        //cout << "\n";
        //ここでもう順列はできている
        bool flag = true;
        for(int i=0;i<n;i++){
            //cout << "kita1" << endl;
            for(int j=0;j<takahasi[i].size();j++){
                //cout << "kita2" << endl;
                int count = 0;
                for(int k=0;k<aoki[one_case[i]].size();k++){
                    //1個でもあればok
                    if(count==aoki[one_case[i]].size()-1&&aoki[one_case[i]][k]!=one_case[takahasi[i][j]]){
                        flag = false;
                    }
                    else if(aoki[one_case[i]][k]==one_case[takahasi[i][j]]){
                        break;
                    }
                    count++;
                    //cout << "kita3" << endl;
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(one_case.begin(), one_case.end()));

    cout << "No" << endl;
    return 0;
}