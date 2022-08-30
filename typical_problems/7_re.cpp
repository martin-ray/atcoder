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


bool isOK(int index, int key,std::vector<int>& a) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int my_lover_bound(int key,std::vector<int>& a) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key, a)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main(void){

    // input
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++)std::cin >> a[i];
    int q;
    std::cin >> q;
    std::vector<int> b(q);
    for(int i=0;i<q;i++){
        std::cin >> b[i];
    }

    // sort a
    sort(a.begin(),a.end());

    for(int i=0;i<q;i++){
        // auto itr = std::lower_bound(a.begin(),a.end(),b[i]);
        // int index = std::distance(a.begin(),itr);
        // if(index==0){
        //     std::cout << "case1" << std::endl;
        //     std::cout << b[i] << "-" << a[index] << "=";
        //     std::cout << abs(b[i]-a[index]) << std::endl;;
        // }
        // else if(index == n){
        //     std::cout << "case2" << std::endl; 
        //     std::cout << abs(b[i]-a[n-1]) << std::endl;
        // }
        // else{
        //     std::cout << "case3" << std::endl;
        //     std::cout << std::min(abs(b[i]-a[index]),abs(b[i]-a[index-1]));
        // }
        int right = my_lover_bound(b[i],a);
        if(right==0){
            std::cout << abs(b[i]-a[right]) << std::endl;;
        }
        else if(right == n){
            std::cout << abs(b[i]-a[right-1]) << std::endl;
        }
        else{
            std::cout << std::min(abs(b[i]-a[right]),abs(b[i]-a[right-1])) << std::endl;
        }
    }

    return 0;
}