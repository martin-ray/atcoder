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

long long int dp[2001][2001]; // dp[i][j] i番目の数までで、jこの部分和の最大値

int main(void){
    int n,m;
    cin >> n >> m;
    vector<long long int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    long long int max = -(long long int)1 << 60;

    
    // dp初期化
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
        dp[1][i+1] = a[0];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>j)continue;
            dp[i][j] = std::max(dp[i-1][j-1]+(j)*a[i-1],dp[i-1][j]);
        }
    }

    std::cout << dp[n][m] << std::endl;

    return 0;
}