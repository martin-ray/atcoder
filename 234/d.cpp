#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>

int main(void){

    //priority_queゲーだった
    int n,k;
    std::cin >> n >> k;

    std::vector<int> p(n);

    for(int i=0;i<n;i++){
        std::cin >> p[i];
    }

    std::priority_queue<int,std::vector<int>,std::greater<int> > pque;

    for(int i=0;i<k;i++){
        pque.push(p[i]);
    }

    std::cout << pque.top() << std::endl;

    for(int i = k ;i<n;i++){
        if(p[i] > pque.top()){
            pque.pop();
            pque.push(p[i]);
        }

        std::cout << pque.top() << std::endl;
    }
    return 0;
}