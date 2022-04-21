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

    int n,m;
    cin >> n >> m;

    vector<pair<int,bool>> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = true;
    }
    for(int i=0;i<m;i++)cin >> b[i];

    bool flag = true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            flag = true;
            if(b[i]==a[j].first&&a[j].second==true){
                a[j].second = false;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;


    return 0;
}