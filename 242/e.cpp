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
#define MOD 998244353
int main(void){

    int n;
    cin >> n;
    vector<vector<long long int>> dp(n+1,vector<long long int>(9+1));
    //dp[i][j] := i桁目にjを使ったときに条件を満たす数
    //initailization
    for(int i=0;i<=9;i++){
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    dp[2][1] = 2;
    for(int i=2;i<=8;i++)dp[2][i] = 3;
    dp[2][9] = 2;

    for(int i=2;i<n;i++){
        for(int j=1;j<=9;j++){
            if(j==1){
                dp[i+1][j] = (dp[i][2] + dp[i][1])%MOD;
            }
            else if(j==9){
                dp[i+1][j] = (dp[i][9] + dp[i][8])%MOD;
            }
            else{
                dp[i+1][j] = (dp[i][j-1] + dp[i][j] + dp[i][j+1])%MOD;
            }            
        }
    }

    long long int ans = 0;
    for(int i=1;i<=9;i++)ans = (ans + dp[n][i])%MOD;

    cout << ans << endl;
    return 0;
}