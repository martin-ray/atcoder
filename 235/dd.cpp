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

//入力された整数の桁の順番を並び替えて、aで割ることを再帰で繰り返す。aで割れなかったらout
//1になったらその時の操作回数をansに入力

long long  ans = 100100100100100;
int a;

//tleより、メモ化再帰を考えるわけです。

void dfs(long long int n,long long int op_time){
    //並び替えせずにそのまま割るoperation
    if(n==1){
        //std::cout << "kita" << std::endl;
        if(op_time < ans){
            ans = op_time;
        }
    }
    else{
        if(n%a==0){
            dfs(n/a,op_time+1);
           std::cout << "kita2"  << "n=" << n <<"::n/a==" <<n/a << std::endl;
        }

        std::string ns = std::to_string(n);
        //std::cout << "kita3" << std::endl;
        for(int i=1;i<ns.length();i++){
            ns = ns.substr(ns.length()-1) + ns.substr(0,ns.length()-1);
            int nextn = std::stoi(ns);
            std::cout << "nextn="<<nextn << std::endl;
            if(nextn%a==0){
                dfs(nextn/a,op_time+1+i);
            }
        }
        
    }

}


int main(void){

    
    return 0;
}