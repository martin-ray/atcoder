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



// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(long long int N) {
    // テーブル
    vector<bool> isprime(N+1, true);


    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (long long int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (long long int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main(void){

    int T;
    cin >> T;
    long long int max = 200000000;
    vector<bool> prime_flag = Eratosthenes(max);
    vector<unsigned long long int> prime_list;

    for(int i=0;i<prime_flag.size();i++){
        if(prime_flag[i]){
            prime_list.push_back(i);
            //cout << i << endl;
        }
    }

    vector<int> q_min_list = {2,3,5,7,11,13,17,19,23};

    for(int t=0;t<T;t++){
        unsigned long long int n;
        cin >> n;

        bool flag = false;

        // for(auto q : q_min_list){
        //     if(n%q==0 && n%(q*q)!=0 && n/q > max){
        //         for(long long int p=max+1; p<max)
        //     }
        // }

        for(auto q : q_min_list){
            if(n%q==0 && n%(q*q)!=0 && n/q > max){
                cout << sqrtl(n/q) << " " << q << endl;
                flag = true;
            }
        }

        if(flag)continue;

        for(auto p : prime_list){
            if(n%(p*p)==0){
                cout << p  << " " << n/(p*p) << endl;
            }
        }
    }




    return 0;
}