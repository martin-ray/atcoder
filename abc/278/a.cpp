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
#include <deque>
//std::cout << std::setprecision(2) << 3.141; // "3.1"
#define MOD 1000000007
using namespace std;

int main(void){

    deque<int> deq;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        deq.push_back(tmp);
    }

    for(int i=0;i<k;i++){
        deq.pop_front();
        deq.push_back(0);
    }

    for(auto i : deq)cout << i << " ";
    cout << endl;
    
    return 0;
}