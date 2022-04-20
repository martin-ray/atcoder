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

    vector<int> h(n);
    for(int i=0;i<n;i++)cin >> h[i];

    //dp[i]:足場iに到達した時の最小コスト
    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout << dp[n-1] << endl;

    return 0;
}