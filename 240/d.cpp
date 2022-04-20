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

int main(void){

    deque<pair<int,int>> que;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    int sum = 0;
    que.push_back(make_pair(a[0],1));
    cout << 1 << endl;
    sum = 1;

    for(int i=1;i<n;i++){
        if(!que.empty()){
            auto p = que.back();
            if(p.first == a[i]){
                que.pop_back();
                p.second++;
                sum++;
                que.push_back(p);
                p = que.back();
                if(p.first == p.second){
                    sum -= p.first;
                    que.pop_back();
                }
            }
            else{
                que.push_back(make_pair(a[i],1));
                sum++;
            }
        }
        else{
            que.push_back(make_pair(a[i],1));
             sum++;
        }
        
        cout << sum << endl;
    }


    return 0;
}