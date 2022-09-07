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

    // とりあえず愚直な実装
    int w,n;
    cin >> w >> n;
    vector<int> height(w,0);
    vector<pair<int,int>> height2kukan(n);

    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        l--;r--;
        for(int i=0;i<n;i++)


        std::cout << height[l] << std::endl;
    }
    return 0;
}