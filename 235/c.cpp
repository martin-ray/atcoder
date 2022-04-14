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

    int n,q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(int i=0;i<n;i++)std::cin >> a[i];
    std::vector<int> x(q);
    std::vector<int> k(q);

    for(int i=0;i<q;i++)std::cin >> x[i] >> k[i];

    std::map<int,std::vector<int>> vmp;

    for(int i=0;i<n;i++){
        vmp[a[i]].push_back(i+1);
    }

    for(int i=0;i<q;i++){
        if(vmp.find(x[i]) ==vmp.end()){
            std::cout << -1 << std::endl;
        }
        else if(vmp[x[i]].size()<k[i]){
            std::cout << -1 << std::endl;
        }
        else{
            std::cout << vmp[x[i]][k[i]-1] << std::endl;
        }
    }


    return 0;
}