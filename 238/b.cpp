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

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    vector<bool> x(360,false);
    x[0] = true;
    int now = 0;
    for(int i=0;i<n;i++){
        now +=a[i];
        now = now%360;
        x[now] = true;
    }

    int max_deg = 0;
    int prev = 0;

    for(int i=1;i<360;i++){
        if(x[i] == true){
            if(i - prev > max_deg){
                max_deg = i - prev;
            }
            prev = i;
            // cout << i << endl;
        }
    }

    if(360 - prev > max_deg){
        max_deg = 360 - prev;
    }
    
    cout << max_deg << endl;

    
    return 0;
}