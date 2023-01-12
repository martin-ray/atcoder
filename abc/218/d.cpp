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

int main(void){

    int N;
    cin >> N;
    vector<pair<int,int>> p(N);
    map<pair<int,int>,int> mp; 
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        p[i] = make_pair(x,y);
        mp[p[i]]++;
    }


    long long int ans = 0;


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i == j)continue;
            pair<int,int> diag = make_pair(p[i].first - p[j].first, p[i].second - p[j].second);
            if(diag.first == 0 || diag.second == 0)continue;
            pair<int,int> v1 = make_pair(p[i].first,p[j].second);
            pair<int,int> v2 = make_pair(p[j].first,p[i].second);
            if(mp[v1] == 1 && mp[v2] == 1)ans++;
        }
    }

    cout << ans/4 << endl;


    return 0;
}