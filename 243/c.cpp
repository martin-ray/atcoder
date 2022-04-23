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
//衝突の条件は、同じy軸上にいる二人以上の人が逆方向を向いていること。katuｘ座標が条件満たす
int main(void){

    int n;
    cin >> n;
    vector<int> x(n),y(n);
    string s;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    cin >> s;
    //y[i]==y[j] && s[i]!=s[j]。かつ、x[i]<x[j](s[i]==R) or x[i] > x[j](s[i]==L)

    map<int,vector<int>> mp;//y座標ごとのmap
    for(int i=0;i<n;i++)mp[y[i]].push_back(i);
    for(auto p : mp){
        auto v = p.second;
        vector<pair<int,char>> pr;
        for(int i=0;i<v.size();i++){
            pr.push_back(make_pair(x[v[i]],s[v[i]]));
        }
        sort(pr.begin(),pr.end());
        for(int i=0;i<pr.size()-1;i++){
            if(pr[i].second=='R'&&pr[i].second!=pr[i+1].second){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }


    cout << "No" << endl;

    return 0;
}