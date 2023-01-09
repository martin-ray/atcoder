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
#define MOD 1000000007
using namespace std;

int main(void){

    int T;
    cin >> T;

    vector<int> ans(T,0);
    for(int t=0;t<T;t++){
        int n;
        int a;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a;
            if(a%2!=0)ans[t]++;
        }
    }

    for(int t=0;t<T;t++)cout << ans[t] << endl;
    return 0;
}