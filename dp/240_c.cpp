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

    int n,x;
    cin >> n >> x;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];

    vector<vector<int>>  dp(n+1,vector<int>(x+1)); // dp[i][j]: i 回目のジャンプが終わった後にjに行けるか？
    
    for(int i=0;i<=n;i++){
        for(int j = 0;j <=x;j++){
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            bool flag1,flag2;
            if(j-a[i-1] >= 0){
                flag1 = dp[i-1][j-a[i-1]];
            }
            else flag1 = false;
            if(j-b[i-1] >= 0){
                flag2 = dp[i-1][j-b[i-1]];
            }
            else flag2 = false;

            dp[i][j] = flag1|flag2;
        }
    }

    if(dp[n][x])cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}