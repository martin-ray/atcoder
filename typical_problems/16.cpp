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
#define INF 10010001
int main(void){
    int n;
    std::cin >> n;
    int a,b,c;
    std::cin >> a >> b >> c;
    int min_coin = 9999;
    for(int i=0;i<=10000;i++){
        if(i*a>n)break;
        for(int j=0;j<10000-i;j++){
            if(i*a+b*j>n)break;
            if((n-i*a-b*j)%c==0){
                if(min_coin > i + j + (n-i*a-b*j)/c){
                    min_coin =  i + j + (n-i*a-b*j)/c;
                }
            }
        }
    }

    std::cout << min_coin << std::endl;
    return 0;
}