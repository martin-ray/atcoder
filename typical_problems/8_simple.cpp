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
#define MOD 1000000007

int main(void){
    int n;
    string s_tmp;
    std::cin >> n >> s_tmp;

    string atcoder = "atcoder";
    string s;

    // eliminate unnecessary strings 
    for(int i =0;i<s_tmp.length();i++){
        for(int j=0;j<atcoder.length();j++){
            if(s_tmp[i] == atcoder[j]){
                s += s_tmp[i];
                break;
            }
        }
    }

    map<char,vector<int>> dp;
    for(int i=0;i<atcoder.length();i++){
        dp[atcoder[i]].resize(s.length(),0);
    }

    // 一段目の初期化
    int tmp = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            tmp++;
        }
        dp[atcoder[0]][i] = tmp;
    }

    // dp[char][i] := 位置iまででcharまでの文字を使ったときの通り数
    for(int c=1;c<atcoder.length();c++){
        int tmp = 0;
        for(int i=1;i<s.length();i++){
            if(s[i] == atcoder[c]){
                dp[atcoder[c]][i] = dp[atcoder[c]][i-1]%MOD + dp[atcoder[c-1]][i]%MOD;
            }
            else{
                dp[atcoder[c]][i] = dp[atcoder[c]][i-1]%MOD;
            }
        }
    }

    std::cout << dp[atcoder[atcoder.length()-1]][s.length()-1]%MOD << std::endl;


    return 0;
}