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

int main(void){

    int n;
    std::cin >> n;

    std::vector<int> h(n);

    for(int i=0;i<n;i++){
        std::cin >> h[i];
    }

    int ans = h[0];

    for(int i=1;i<n;i++){
        if(ans < h[i]){
            ans = h[i];
        }
        else{
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}