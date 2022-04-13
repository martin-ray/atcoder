#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>

float len(int x1,int y1,int x2,int y2){
    return sqrtf64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(void){

    int n;
    std::cin >> n;
    std::pair<int,int> p[n];

    for(int i=0;i<n;i++){
        std::cin >> p[i].first >> p[i].second;
    }
    
    float ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float l = len(p[i].first,p[i].second,p[j].first,p[j].second);
            if(ans < l){
                ans = l;
            }
        }
    }

    std::cout << std::setprecision(12) << ans << std::endl;

    return 0;
}