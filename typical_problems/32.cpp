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
#define INF (long long int)1<<62

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    int m;
    cin >> m;
    vector<pair<int,int>> mith(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        mith[i] = std::make_pair(x,y);
    }

    vector<int> v(n);
    std::iota(v.begin(),v.end(),1);
    long long int min_time = INF;

    do{
        long long int tmp = 0;
        bool flag = true;

        // 不仲判定
        for(int i=0;i<n-1;i++){
            for(int k=0;k<m;k++){
                if((v[i]==mith[k].first&&v[i+1]==mith[k].second)||(v[i]==mith[k].second&&v[i+1]==mith[k].first)){
                    flag = false;
                }
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                tmp += a[v[i]][i+1];
            }
        }

        if(tmp < min_time && flag){
            min_time = tmp;
        }

    }while(std::next_permutation(v.begin(),v.end()));

    if(min_time == INF)cout << -1 << endl;
    else cout << min_time << endl;
    return 0;
}